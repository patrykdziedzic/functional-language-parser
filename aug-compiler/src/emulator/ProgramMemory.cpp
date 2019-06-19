#include "ProgramMemory.h"
#include <algorithm>
#include <iostream>
#include <sstream>

namespace TargetLanguage{
    ProgramMemory::ProgramMemory(std::istream* programStream){
        ReadProgramFromStream(programStream);
        ReadLinesPositionMapping();
    }

    void ProgramMemory::ReadLinesPositionMapping(){
        linesPositionMapping = new std::map<size_t, size_t>();
        size_t position = 0;
        linesCount = 0;
        while(position < programLength){
            ReadLine(&position);
            linesCount++;
        }
    }

    void ProgramMemory::ReadLine(size_t* position){
        size_t lineStart = *position;
        InstructionNumberResult instructionNumberResult = ReadInstructionNumber(position);
        if(instructionNumberResult.Succeeded)
            linesPositionMapping->insert(std::make_pair(instructionNumberResult.InstructionNumber, lineStart));
        
        ReadUntilNextLine(position);
    }

    InstructionNumberResult ProgramMemory::ReadInstructionNumber(size_t* position){
        if(!isdigit(program[*position]))
            return InstructionNumberResult(false);
        
        std::stringstream stream;
        while(isdigit(program[*position])){
            stream << program[*position];
            *position = *position + 1;
        }

        size_t result = 0;
        stream >> result;
        return InstructionNumberResult(result);
    }

    void ProgramMemory::ReadUntilNextLine(size_t* position){
        while(program[*position] != '\n' && program[*position] != '\0')
            *position = *position + 1;

        *position = *position + 1;
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
        output->insert(output->end(), buffer, buffer + stream->gcount());
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
