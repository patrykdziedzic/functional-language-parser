#include "TargetLanguageParserTest.h"
#include "../../src/emulator/TargetLanguageEmulatorParser.h"
#include "../../src/emulator/ProgramMemory.h"
#include <fstream>
#include <sstream>

using namespace std;
using namespace TargetLanguage;

void TargetLanguageParserTest::Run(){
    logger->LogInfoMessage("Target language parser test start");
    TestIfDataIsParsedCorrectly();
    TestSimpleFlow();
    TestJump();
    TestJumpIfZero();
    TestJumpIfNotZero();
    TestComments();
    TestJumpIfNegative();
    TestJumpIfPositive();
    TestJumpIfNotNegative();
    TestJumpIfNotPositive();
    logger->LogInfoMessage("Target language parser test finish");
}

void TargetLanguageParserTest::TestIfDataIsParsedCorrectly(){
    logger->LogInfoMessage("Test if data is parsed correctly");
    TestTargetLanguageFile(
        "./../test/data/parser/target-language-data.txt",
        {},
        {OperationResult(OperationCode::CopyAsInitialMemory)},
        {1, 2, 5, 2});
}

void TargetLanguageParserTest::TestSimpleFlow(){
    logger->LogInfoMessage("Test simple flow");
    TestTargetLanguageFile(
        "./../test/data/parser/target-language-simple-flow.txt",
        {},
        {
            OperationResult(OperationCode::PushValue, 2),
            OperationResult(OperationCode::PushFromAddress, 1),
            OperationResult(OperationCode::Pop),
            OperationResult(OperationCode::PopToAddress, 1),
            OperationResult(OperationCode::Duplicate),
            OperationResult(OperationCode::Add),
            OperationResult(OperationCode::Multiply),
            OperationResult(OperationCode::Divide),
            OperationResult(OperationCode::Negate),
            OperationResult(OperationCode::Read),
            OperationResult(OperationCode::Print)},
        {});
}

void TargetLanguageParserTest::TestJump(){
    logger->LogInfoMessage("Test jump");
    TestTargetLanguageFile(
        "./../test/data/parser/target-language-jump.txt",
        {},
        {
            OperationResult(OperationCode::PushValue, 4),
            OperationResult(OperationCode::PushFromAddress, 2),
            OperationResult(OperationCode::Add),
            OperationResult(OperationCode::Negate)},
        {});
}

void TargetLanguageParserTest::TestJumpIfZero(){
    logger->LogInfoMessage("Test jump if zero");
    TestTargetLanguageFile(
        "./../test/data/parser/target-language-jump-if-zero.txt",
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {
            OperationResult(OperationCode::Pop, 1),
            OperationResult(OperationCode::Pop, 1),
            OperationResult(OperationCode::Pop, 1),
            OperationResult(OperationCode::Pop, 0),
            OperationResult(OperationCode::Pop, 1),
            OperationResult(OperationCode::Pop, 1),
            OperationResult(OperationCode::Pop, 1),
            OperationResult(OperationCode::Pop, 1),
            OperationResult(OperationCode::Pop, 0),
            OperationResult(OperationCode::Pop, 1)},
        {});
}

void TargetLanguageParserTest::TestJumpIfNotZero(){
    logger->LogInfoMessage("Test jump if not zero");
    TestTargetLanguageFile(
        "./../test/data/parser/target-language-jump-if-not-zero.txt",
        {0, 1, 0, 0, 0, 0, -2, 0, 0, 0},
        {
            OperationResult(OperationCode::Pop, 0),
            OperationResult(OperationCode::Pop, 0),
            OperationResult(OperationCode::Pop, 0),
            OperationResult(OperationCode::Pop, -2),
            OperationResult(OperationCode::Pop, 0),
            OperationResult(OperationCode::Pop, 0),
            OperationResult(OperationCode::Pop, 0),
            OperationResult(OperationCode::Pop, 0),
            OperationResult(OperationCode::Pop, 1),
            OperationResult(OperationCode::Pop, 0)},
        {});
}

void TargetLanguageParserTest::TestComments(){
    logger->LogInfoMessage("Test comments");
    TestTargetLanguageFile(
        "./../test/data/parser/target-language-comments.txt",
        {-2, 3},
        {
            OperationResult(OperationCode::Pop, 3),
            OperationResult(OperationCode::Pop, -2),
            OperationResult(OperationCode::PushValue, 4)},
        {1, 2, 3});
}

void TargetLanguageParserTest::TestJumpIfNegative(){
    logger->LogInfoMessage("Test jump if negative");
    TestTargetLanguageFile(
        "./../test/data/parser/target-language-jump-if-negative.txt",
        {-1, 0, 1, -12},
        {
            OperationResult(OperationCode::Pop, -12),
            OperationResult(OperationCode::Pop, 1),
            OperationResult(OperationCode::Pop, 0),
            OperationResult(OperationCode::Pop, -1),
            OperationResult(OperationCode::Add)},
        {});
}

void TargetLanguageParserTest::TestJumpIfPositive(){
    logger->LogInfoMessage("Test jump if positive");
    TestTargetLanguageFile(
        "./../test/data/parser/target-language-jump-if-positive.txt",
        {1, 0, -1, 12},
        {
            OperationResult(OperationCode::Pop, 12),
            OperationResult(OperationCode::Pop, -1),
            OperationResult(OperationCode::Pop, 0),
            OperationResult(OperationCode::Pop, 1),
            OperationResult(OperationCode::Multiply)},
        {});
}

void TargetLanguageParserTest::TestJumpIfNotNegative(){

}

void TargetLanguageParserTest::TestJumpIfNotPositive(){

}


void TargetLanguageParserTest::TestTargetLanguageFile(
    string filePath,
    vector<NUMERIC> initialStackSequence,
    vector<OperationResult> expectedOperationsSequence,
    vector<NUMERIC> expectedOperationalMemory
){
    EngineMock* engine = new EngineMock(logger, initialStackSequence);
    EmulatorParser* parser = new EmulatorParser(engine);
    ifstream testFile;
    testFile.open(filePath);
    ProgramMemory* programMemory = new ProgramMemory(&testFile);
    parser->ParseLanguage(programMemory);
    AssertParserResult(engine, expectedOperationsSequence, expectedOperationalMemory);
    delete engine;
    delete programMemory;
    delete parser;
}

void TargetLanguageParserTest::AssertParserResult(
    EngineMock* engine,
    vector<OperationResult> expectedOperationsSequence,
    vector<NUMERIC> expectedOperationalMemory
){
    auto operationalMemory = engine->GetOperationalMemory();
    AssertIsTrue(equal(operationalMemory.begin(), operationalMemory.end(), expectedOperationalMemory.begin()));
    auto operations = engine->GetOperations();
    TestOperationsSequence(expectedOperationsSequence, operations);
}

void TargetLanguageParserTest::TestOperationsSequence(
    vector<OperationResult> expectedSequence,
    vector<OperationResult*> actualSequence
){
    vector<OperationResult> unboxedActualSequence;
    for(auto const &operation : actualSequence)
        unboxedActualSequence.push_back(*operation);

    LogOperations(expectedSequence, "Expected operations sequence:");
    LogOperations(unboxedActualSequence, "Actual operations sequence");
    AssertIsTrue(equal(unboxedActualSequence.begin(), unboxedActualSequence.end(), expectedSequence.begin()));
}

void TargetLanguageParserTest::LogOperations(vector<OperationResult> operations, string operationsName){
    stringstream* logStream = new stringstream();
    *logStream << operationsName << endl;
    for(auto const &operation : operations)
        FlushOperationResultToStream(operation, logStream);
    logger->LogDebugMessage(logStream->str());
    delete logStream;
}

void TargetLanguageParserTest::FlushOperationResultToStream(
    OperationResult operation,
    ostream* logStream
){
    *logStream << "[Code: " << operation.Code;
    if(operation.Argument != nullptr)
        *logStream << ", Argument: " << *operation.Argument;
    
    *logStream << "]" << endl;
}

TargetLanguageParserTest::TargetLanguageParserTest(Logger* logger) : TestFixture(logger) {}

TargetLanguageParserTest::~TargetLanguageParserTest() {}