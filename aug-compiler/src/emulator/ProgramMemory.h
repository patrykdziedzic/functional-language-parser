#ifndef PROGRAMMEMORY_H
#define PROGRAMMEMORY_H

#include <istream>
#include <map>
#include <vector>

namespace TargetLanguage{
    struct InstructionNumberResult;

    class ProgramMemory{
        public:
            ProgramMemory(std::istream* programStream);
            char* GetPosition(unsigned long lineIndex);
            unsigned long GetLinesCount();
            unsigned long GetProgramLength();
            ~ProgramMemory();
        private:
            char* program;
            size_t programLength;
            size_t linesCount;
            std::map<size_t, size_t>* linesPositionMapping;
            void ReadLinesPositionMapping();
            void ReadProgramFromStream(std::istream* programStream);
            void ReadStreamToCharsVector(std::istream* programStream, std::vector<char>* output);
            void InsertBufferContentToVector(std::istream* stream, std::vector<char>* output, char* buffer);
            void ReadLine(size_t* position);
            InstructionNumberResult ReadInstructionNumber(size_t* position);
            void ReadUntilNextLine(size_t* position);
            static const unsigned BufferSize = 4096;
    };

    struct InstructionNumberResult{
        bool Succeeded;
        size_t InstructionNumber;
        InstructionNumberResult(size_t instructionNumber) :
            Succeeded(true),
            InstructionNumber(instructionNumber)
        {}

        InstructionNumberResult(bool succeeded) :
            Succeeded(succeeded)
        {}
    };
}

#endif
