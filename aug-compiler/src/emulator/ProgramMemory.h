#ifndef PROGRAMMEMORY_H
#define PROGRAMMEMORY_H

#include <istream>
#include <map>
#include <vector>

namespace TargetLanguage{
    class ProgramMemory{
        public:
            ProgramMemory(std::istream* programStream);
            char* GetPosition(unsigned long lineIndex);
            unsigned long GetLinesCount();
            unsigned long GetProgramLength();
            ~ProgramMemory();
        private:
            char* program;
            unsigned long programLength;
            unsigned long currentPosition;
            unsigned long linesCount;
            std::map<unsigned long, unsigned long>* linesPositionMapping;
            void ReadLinesPositionMapping();
            void ReadProgramFromStream(std::istream* programStream);
            void InsertBufferContentToVector(std::istream* stream, std::vector<char>* output, char* buffer);
            static const unsigned BufferSize = 4096;
    };
}

#endif
