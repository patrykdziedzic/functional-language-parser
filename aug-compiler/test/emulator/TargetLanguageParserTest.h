#ifndef TARGETLANGUAGEPARSERTEST_H
#define TARGETLANGUAGEPARSERTEST_H

#include "../TestFixture.h"
#include "./mock/TargetLanguageEngineMock.h"
#include <string>
#include <ostream>

class TargetLanguageParserTest: public TestFixture{
    public:
        TargetLanguageParserTest(Logger* logger);
        virtual void Run();
        virtual ~TargetLanguageParserTest();
    private:
        void TestIfDataIsParsedCorrectly();
        void TestSimpleFlow();
        void TestJump();
        void TestJumpIfZero();
        void TestJumpIfNotZero();
        void TestComments();
        void TestJumpIfNegative();
        void TestJumpIfPositive();
        void TestJumpIfNotNegative();
        void TestJumpIfNotPositive();
        void TestTargetLanguageFile(
            std::string filePath,
            std::vector<NUMERIC> initialStackSequence,
            std::vector<OperationResult> expectedOperationsSequence,
            std::vector<NUMERIC> expectedOperationalMemory
        );
        void AssertParserResult(
            EngineMock* engine,
            std::vector<OperationResult> expectedOperationsSequence,
            std::vector<NUMERIC> expectedOperationalMemory
        );
        void TestOperationsSequence(
            std::vector<OperationResult> expectedSequence,
            std::vector<OperationResult*> actualSequence
        );
        void LogOperations(std::vector<OperationResult> operations, std::string operationsName);
        void FlushOperationResultToStream(OperationResult operation, std::ostream* logStream);
};

#endif