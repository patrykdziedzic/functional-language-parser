#include "ProgramMemory.h"
#include <algorithm>

namespace TargetLanguage{
    ProgramMemory::ProgramMemory(std::istream* programStream){
        ReadProgramFromStream(programStream);
        ReadLinesPositionMapping();
    }

    void ProgramMemory::ReadLinesPositionMapping(){
        linesPositionMapping = new std::map<unsigned long, unsigned long>();
        linesPositionMapping->insert(std::make_pair(0, 0));
        linesCount = 0;

        for(unsigned long i = 0; i < programLength; i++)
            if(program[i] == '\n'){
                linesCount++;
                if(i < programLength - 1)
                    linesPositionMapping->insert(std::make_pair(linesCount, i + 1));
            }
    }

    void ProgramMemory::ReadProgramFromStream(std::istream* programStream){
        std::vector<char> charsCollection;
        ReadStreamToCharsVector(programStream, &charsCollection);
        programLength = charsCollection.size();
        charsCollection.push_back('\0');
        program = new char[programLength + 1];
        std::copy(charsCollection.begin(), charsCollection.end(), program);
    }

    void ProgramMemory::ReadStreamToCharsVector(std::istream* programStream, std::vector<char>* output){
        char* buffer = new char[BufferSize];

        while(programStream->read(buffer, BufferSize))
            InsertBufferContentToVector(programStream, output, buffer);

        InsertBufferContentToVector(programStream, output, buffer);
        delete buffer;
    }

    void ProgramMemory::InsertBufferContentToVector(std::istream* stream, std::vector<char>* output, char* buffer){
        int readCharsCount = stream->gcount() - output->size();
        output->insert(output->end(), buffer, buffer + readCharsCount);
    }

    char* ProgramMemory::GetPosition(unsigned long lineIndex){
        return program + linesPositionMapping->find(lineIndex)->second;
    }

    unsigned long ProgramMemory::GetLinesCount(){
        return linesCount;
    }

    unsigned long ProgramMemory::GetProgramLength(){
        return programLength;
    }

    ProgramMemory::~ProgramMemory(){
        delete linesPositionMapping;
        delete program;
    }
}
