/**
 * @file MPtest.h
 * @brief Extension to Googletest to cover formatted reporting of tests
 * @author DECSAI
 */

#ifndef MP__TESTS__
#define MP__TESTS__

#include <fstream>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <regex>
#include <cinttypes>
#include "gtest/gtest.h"
#include "MPTools.h"
using namespace std;

//#define MAX 256

#define MAXFILE 10
extern string stype, sreal_result, sdue_result,
sexpression, sgoodmessage, sbadvalue,
sexception,
sreal_exception, sdue_exception, sfilename[MAXFILE], sfilecontent[MAXFILE];
extern bool bexception, breal_result, bdue_result;
extern exception etype;
extern char cgetType, creal_result, cdue_result;
extern int ireal_result, idue_result, nfilenames;
extern double dreal_result, ddue_result;



#define __TIME_OUT_CALL__ "timeout --preserve-status -k "
#define __BASE__ __COUNTER__
#define FILEDATA "./out.bgr"
#define FILEINPUT "./tests/validation/" + stestname + ".keyboard"
#define FILEOUTPUT "./tests/output/" + stestname + ".output"
#define FILEDIFF "./tests/output/" + stestname + ".wdiff"
#define FILEKEYBOARD "./tests/validation/" + stestname + ".keyboard"
#define FILECOUT "./tests/output/" + stestname + ".cout"
#define FILEEXPECTED "./tests/validation/" + stestname + ".expected"
#define FILEMLEAKS "./tests/output/" + stestname + ".mleaks.compact"
#define FILEMLEAKSMD "./tests/output/" + stestname + ".mleaks.simplified.md"
#define FILESTOP "./tests/output/stop.detected"
#define FILESTOPMLEAKS "./tests/output/mleaks.detected"
#define FILEREPORT_APPEND "./tests/output/TestReportAppend.md"
#define FILEREPORT_HEAD_CSV "./tests/output/TestReport_head.csv"
#define FILEREPORT_CSV "./tests/output/TestReport_body.csv"
#define __VALGRIND__ "-valgrind"
#define __DRMEMORY__ "-drmemory"
#define __RUN_OUTPUT__ FILEOUTPUT("output")
#define MAX_STRING_OUTPUT 1000
#define INTEGER_TYPE 'i'
#define DOUBLE_TYPE 'd'
#define STRING_TYPE 'N'
#define CHAR_TYPE 'c'
#define BOOL_TYPE 'b'
#define GET_TYPE(EXPR) (typeid(EXPR).name()[0]);


#define EMPTYS  ""
#define SPACE " "
#define TAB "\t"
#define NEWLINE "\n"
#define SEP SPACE
#define SEPCSV TAB
#define TESTING_FLAG false
#define BOOL_STR(b) ((b)?string("true"):string("false"))

#define SETUP_TEST(...) sexpression=#__VA_ARGS__; \
TEST_EXPRESSION(__VA_ARGS__)\
__VA_ARGS__

#define OBTAINED_STRING sreal_result
#define OBTAINED_BOOL breal_result
#define OBTAINED_CHAR creal_result
#define OBTAINED_INT ireal_result
#define OBTAINED_DOUBLE dreal_result
#define OBTAINED_EXCEPTION sreal_exception
#define EXPECTED_STRING sdue_result
#define EXPECTED_BOOL bdue_result
#define EXPECTED_CHAR cdue_result
#define EXPECTED_INT idue_result
#define EXPECTED_DOUBLE ddue_result
#define EXPECTED_EXCEPTION sdue_exception

#define TEST_EXCEPTION(EXPR)\
    EXPECTED_EXCEPTION==#EXPR;\
    sgoodmessage=EXPECTED_EXCEPTION;

#define TEST_OUTCOME_STRING(EXPR)\
if (stype=="string") {\
    EXPECTED_STRING=EXPR;\
    sgoodmessage="\""+EXPECTED_STRING+"\"";\
    } else if (stype=="bool") {\
    EXPECTED_BOOL=EXPR;\
    sgoodmessage=BOOL_STR(EXPECTED_BOOL);\
    }

#define TEST_OUTCOME_INT(EXPR)\
if (stype=="int") {\
    EXPECTED_INT=EXPR;\
    sgoodmessage=std::to_string(EXPECTED_INT);\
    } 

#define TEST_OUTCOME_DOUBLE(EXPR)\
if (stype=="double") {\
    EXPECTED_DOUBLE=EXPR;\
    sgoodmessage=std::to_string(EXPECTED_DOUBLE);\
    } 


#define GOOD_OUTCOME_ASCII sexpression+" should give "+sgoodmessage
#define BAD_OUTCOME_ASCII " but gives "+sbadvalue

#define GOOD_OUTCOME_MD string("```")+sexpression+"```|\n| | | |"+" should give ```"+sgoodmessage+"```"
#define BAD_OUTCOME_MD " but gives "+sbadvalue

#define GOOD_EXCEPTION_ASCII sexpression+" should THROW an exception "+sdue_exception
#define BAD_EXCEPTION_ASCII " but throws "+sbadvalue
#define NO_EXCEPTION_ASCII " but THROWS none"

#define GOOD_EXCEPTION_MD string("```")+sexpression+"```|\n| | | | should THROW an exception "+sdue_exception+"|\n"+
#define BAD_EXCEPTION_MD "| | | | but throws "+sreal_exception
#define NO_EXCEPTION_MD " | | | | but THROWS none"

#ifndef BRANCH
#define BRANCH "Debug"
#define PATHTOBIN "Debug"
//#define __PATH__ "./dist/Debug/GNU-Linux/"
#else
#define PATHTOBIN BRANCH
//#define __PATH__ std::string("./dist/")+BRANCH+"/GNU-Linux/"
#endif

#define TEST_EXPRESSION(EXPR)\
try {\
    EXPR;\
    bexception=false;\
    sreal_exception="none";\
    sexception="none";\
} catch(const std::exception &e) {\
    bexception=true;\
    etype = e;\
    sreal_exception=typeid(e).name();\
    REPLACE(sreal_exception,"St12","std::")\
    sexception=e.what();\
}

#define TEST_STRING(EXPR) stype="string";\
sexpression+=#EXPR;\
TEST_EXPRESSION(EXPR)\
if (!bexception){\
OBTAINED_STRING=EXPR;\
sbadvalue=string("\"")+OBTAINED_STRING+"\"";\
} else {\
sbadvalue=string(" an unexpected exception ")+sreal_exception;\
}

#define TEST_BOOL(EXPR) stype="bool";\
sexpression+=#EXPR;\
TEST_EXPRESSION(EXPR)\
if (!bexception){\
OBTAINED_BOOL=EXPR;\
sbadvalue=string("")+BOOL_STR(OBTAINED_BOOL)+"";\
} else {\
sbadvalue=string(" an unexpected exception ")+sreal_exception;\
}

#define TEST_INT(EXPR) stype="int";\
sexpression+=#EXPR;\
TEST_EXPRESSION(EXPR)\
if (!bexception){\
OBTAINED_INT=EXPR;\
sbadvalue=std::to_string(OBTAINED_INT);\
} else {\
sbadvalue=string(" an unexpected exception ")+sreal_exception;\
}

#define TEST_DOUBLE(EXPR) stype="double";\
sexpression+=#EXPR;\
TEST_EXPRESSION(EXPR)\
if (!bexception){\
OBTAINED_DOUBLE=EXPR;\
sbadvalue=std::to_string(OBTAINED_DOUBLE);\
} else {\
sbadvalue=string(" an unexpected exception ")+sreal_exception;\
}

#define TEST_VOID(EXPR) stype="void";\
sexpression+=#EXPR;\
TEST_EXPRESSION(EXPR)\
if (!bexception){\
sbadvalue=" nothing ";\
} else {\
sbadvalue=string(" an unexpected exception ")+sreal_exception;\
}



#define FILEREPORT "./tests/TestReport.md"
#define __defReport false
#define CAPTCHAREPORT ""
#define ASSERTNE(...) ASSERT_NE(__VA_ARGS__) <<CAPTCHAREPORT<< idtest<< " "
#define ASSERTEQ(...) ASSERT_EQ(__VA_ARGS__) <<CAPTCHAREPORT<< idtest<< " "
#define ASSERTTRUE(...) ASSERT_TRUE(__VA_ARGS__) <<CAPTCHAREPORT<< idtest<< " "
#define ASSERTFALSE(...) ASSERT_FALSE(__VA_ARGS__) <<CAPTCHAREPORT<< idtest<< " "
#define ASSERTSTREQ(...) ASSERT_STREQ(__VA_ARGS__) <<CAPTCHAREPORT<< idtest<< " "
#define ASSERTSTRNE(...) ASSERT_STRNE(__VA_ARGS__) <<CAPTCHAREPORT<< idtest<< " "
#define EXPECTNE(...) EXPECT_NE(__VA_A_ARGS__) <<CAPTCHAREPORT<< idtest<< " "
#define EXPECTEQ(...) EXPECT_EQ(__VA_A_ARGS__) <<CAPTCHAREPORT<< idtest<< " "
#define EXPECTSTREQ(...) EXPECT_STREQ(__VA_A_ARGS__) <<CAPTCHAREPORT<< idtest<< " "
#define EXPECTSTRNE(...) EXPECT_STRNE(__VA_A_ARGS__) <<CAPTCHAREPORT<< idtest<< " "


#define CHECK_TRUE \
    UPDATEIDTEST();\
    IDTEST(idtest);\
    TEST_OUTCOME_STRING(true);\
    if (!bexception) {\
    REPORT_UNIT_TEST(OBTAINED_BOOL == EXPECTED_BOOL)\
    ASSERT_EQ(EXPECTED_BOOL,OBTAINED_BOOL) << GOOD_OUTCOME_ASCII+BAD_OUTCOME_ASCII << endl;\
    } else {\
    REPORT_UNIT_TEST(false)\
    ASSERT_FALSE(bexception) << string("Unexpected exception ")+sreal_exception << endl;\
    }

#define CHECK_FALSE \
    UPDATEIDTEST();\
    IDTEST(idtest);\
    TEST_OUTCOME_STRING(false);\
    if (!bexception) {\
    REPORT_UNIT_TEST(OBTAINED_BOOL == EXPECTED_BOOL)\
    ASSERT_EQ(EXPECTED_BOOL,OBTAINED_BOOL) << GOOD_OUTCOME_ASCII+BAD_OUTCOME_ASCII << endl;\
    } else {\
    REPORT_UNIT_TEST(false)\
    ASSERT_FALSE(bexception) << string("Unexpected exception ")+sreal_exception << endl;\
    }

#define CHECK_STRING_EQ(EXPR) \
    UPDATEIDTEST();\
    IDTEST(idtest);\
    TEST_OUTCOME_STRING(EXPR);\
    if (!bexception) {\
    REPORT_UNIT_TEST(OBTAINED_STRING == EXPECTED_STRING)\
    ASSERT_STREQ(EXPECTED_STRING.c_str(),OBTAINED_STRING.c_str()) << GOOD_OUTCOME_ASCII+BAD_OUTCOME_ASCII << endl;\
    } else {\
    REPORT_UNIT_TEST(false)\
    ASSERT_FALSE(bexception) << string("Unexpected exception  ")+sreal_exception << endl;\
    }

#define CHECK_STRING_NEQ(EXPR) \
    UPDATEIDTEST();\
    IDTEST(idtest);\
    TEST_OUTCOME_STRING(EXPR);\
    if (!bexception) {\
    REPORT_UNIT_TEST(OBTAINED_STRING != EXPECTED_STRING)\
    ASSERT_STRNE(EXPECTED_STRING.c_str(),OBTAINED_STRING.c_str()) << GOOD_OUTCOME_ASCII+BAD_OUTCOME_ASCII << endl;\
    } else {\
    REPORT_UNIT_TEST(false)\
    ASSERT_FALSE(bexception) << string("Unexpected exception  ")+sreal_exception << endl;\
    }

#define CHECK_INT_EQ(EXPR) \
    UPDATEIDTEST();\
    IDTEST(idtest);\
    TEST_OUTCOME_INT(EXPR);\
    if (!bexception) {\
    REPORT_UNIT_TEST(OBTAINED_INT == EXPECTED_INT)\
    ASSERT_EQ(EXPECTED_INT,OBTAINED_INT) << GOOD_OUTCOME_ASCII+BAD_OUTCOME_ASCII << endl;\
    } else {\
    REPORT_UNIT_TEST(false)\
    ASSERT_FALSE(bexception) << string("Unexpected exception  ")+sreal_exception << endl;\
    }

#define CHECK_INT_NEQ(EXPR) \
    UPDATEIDTEST();\
    IDTEST(idtest);\
    TEST_OUTCOME_INT(EXPR);\
    if (!bexception) {\
    REPORT_UNIT_TEST(OBTAINED_INT != EXPECTED_INT)\
    ASSERT_NE(EXPECTED_INT,OBTAINED_INT) << GOOD_OUTCOME_ASCII+BAD_OUTCOME_ASCII << endl;\
    } else {\
    REPORT_UNIT_TEST(false)\
    ASSERT_FALSE(bexception) << string("Unexpected exception  ")+sreal_exception << endl;\
    }

#define CHECK_DOUBLE_EQ(EXPR) \
    UPDATEIDTEST();\
    IDTEST(idtest);\
    TEST_OUTCOME_DOUBLE(EXPR);\
    if (!bexception) {\
    REPORT_UNIT_TEST(OBTAINED_DOUBLE == EXPECTED_DOUBLE)\
    ASSERT_EQ(EXPECTED_DOUBLE,OBTAINED_DOUBLE) << GOOD_OUTCOME_ASCII+BAD_OUTCOME_ASCII << endl;\
    } else {\
    REPORT_UNIT_TEST(false)\
    ASSERT_FALSE(bexception) << string("Unexpected exception  ")+sreal_exception << endl;\
    }

#define CHECK_DOUBLE_NEQ(EXPR) \
    UPDATEIDTEST();\
    IDTEST(idtest);\
    TEST_OUTCOME_DOUBLE(EXPR);\
    if (!bexception) {\
    REPORT_UNIT_TEST(OBTAINED_DOUBLE != EXPECTED_DOUBLE)\
    ASSERT_NE(EXPECTED_DOUBLE,OBTAINED_DOUBLE) << GOOD_OUTCOME_ASCII+BAD_OUTCOME_ASCII << endl;\
    } else {\
    REPORT_UNIT_TEST(false)\
    ASSERT_FALSE(bexception) << string("Unexpected exception  ")+sreal_exception << endl;\
    }

#define CHECK_EXCEPTION(TYPE) \
    UPDATEIDTEST();\
    IDTEST(idtest);\
    TEST_EXCEPTION(TYPE);\
    if (!bexception) {\
    REPORT_UNIT_TEST_EXCEPTION(false)\
    ASSERT_TRUE(bexception) << GOOD_EXCEPTION_ASCII+NO_EXCEPTION_ASCII<< endl;\
    } else {\
       EXPECTED_EXCEPTION=#TYPE;\
       REPLACE(OBTAINED_EXCEPTION,"St12","");\
       if(EXPECTED_EXCEPTION==OBTAINED_EXCEPTION) {\
            REPORT_UNIT_TEST_EXCEPTION(true)\
            ASSERT_TRUE(bexception) << GOOD_EXCEPTION_ASCII+BAD_EXCEPTION_ASCII<<endl;\
       } else {\
            REPORT_UNIT_TEST_EXCEPTION(false)\
            ASSERT_FALSE(bexception) << GOOD_EXCEPTION_ASCII+BAD_EXCEPTION_ASCII<<endl;\
      }\
    }

class T01_Basics : public ::testing::Test {
public:

    T01_Basics() : Test() {
    }

protected:

    virtual void SetUp() {
        ofreport.open(FILEREPORT, std::ios_base::app);
    }

    virtual void TearDown() {
        ofreport.close();
    }

    std::ofstream ofreport;
    std::string idtest;
};

class T02_Intermediate : public ::testing::Test {
public:

    T02_Intermediate() : Test() {
    }

protected:

    virtual void SetUp() {
        ofreport.open(FILEREPORT, std::ios_base::app);
    }

    virtual void TearDown() {
        ofreport.close();
    }

    std::ofstream ofreport;
    std::string idtest;
};

class T03_Advanced : public ::testing::Test {
public:

    T03_Advanced() : Test() {
    }

protected:

    virtual void SetUp() {
        ofreport.open(FILEREPORT, std::ios_base::app);
    }

    virtual void TearDown() {
        ofreport.close();
    }

    std::ofstream ofreport;
    std::string idtest;
};

/////////////////////////////////////////////
// Tools
/////////////////////////////////////////////

/**
 * @brief Simmulates a breakpoint by stoping and reading a fictitious data
 */
#define BREAKPOINT(X)\
    if (X){\
        char c;\
        cout <<endl<<"Press a key: ";\
        cin>>c;\
    }

/**
 * @brief Removes spare left spaces
 */
#define LTRIM(STRINGVAR) \
    do { \
    std::string aux="", orig=STRINGVAR; \
    bool trim=true; \
    for (int i=0; i<orig.length(); i++)  \
        if (!trim || orig[i] != SPACE[0]) { \
        aux= aux + orig[i]; \
        trim=false; } \
    STRINGVAR = aux; \
    } while(0); 

/**
 * @brief Remove spare right spaces
 */
#define RTRIM(STRINGVAR) \
    do { \
    std::string aux="", orig=STRINGVAR; \
    bool trim=true; \
    for (int i=orig.length()-1; i>=0; i--)  \
        if (!trim || orig[i] != SPACE[0]) { \
        aux = orig[i]+aux; \
        trim=false; } \
    STRINGVAR = aux; \
    } while(0); 
/**
 * @brief Remove spare middle spaces
 */
#define MTRIM(STRINGVAR) \
    do { \
    std::string aux="", orig=STRINGVAR; \
    int i=0; \
    while(i<orig.length())  \
        if (i<orig.length()-1 && orig[i] == SPACE[0] && orig[i+1] == SPACE[0]) { \
            i++;}\
        else {\
            aux= aux + orig[i++];} \
    STRINGVAR = aux; \
    } while(0); 

/**
 * @brief Recursively replaces a ssubstring by another
 */
#define REPLACE(STRINGVAR, SUBS1, SUBS2) \
    do { \
    size_t index = 0, len = ((std::string)SUBS1).length(); \
    while (true) { \
        index = STRINGVAR.find(SUBS1, index); \
        if (index == std::string::npos) break; \
         STRINGVAR.replace(index, len, SUBS2); \
         index += len;  \
     }; \
     } while(0); 

/**
 * @brief Preprocesses an output string for comparison
 */
#define CLEANUP(STRINGVAR)  \
    REPLACE(STRINGVAR,NEWLINE,SEP); \
    REPLACE(STRINGVAR,TAB,SEP); \
    REPLACE(STRINGVAR,SPACE,SEP); \
    LTRIM(STRINGVAR); \
    RTRIM(STRINGVAR); \
    MTRIM(STRINGVAR); 

/**
 * Load the whole content of a file in a single-lined string, replacing separators by spaces
 */
#define LOAD(STRINGVAR, FILENAME) \
    do { \
    std::ifstream fi(FILENAME); \
    if (fi) {\
        std::stringstream ss;\
        ss << fi.rdbuf(); \
        STRINGVAR = ss.str();\
    } else {\
        STRINGVAR=""; \
    }\
    } while(0); \
    CLEANUP(STRINGVAR);

/**
 * Save the content of a std::string into a file
 */
#define SAVE(TEXT, FILENAME) \
    do { \
    std::ofstream fo##__LINE__(FILENAME); \
    fo##__LINE__ << TEXT << std::endl; \
    } while(0);

/**
 * Appends the content of a std::string into a file
 */
#define APPEND(TEXT, FILENAME) \
    do { \
    std::ofstream fo##__LINE__(FILENAME, std::ios_base::app); \
    fo##__LINE__ << TEXT; \
    } while(0);


#define getFCounter(filecounter, i)\
    do {\
    std::string svalue;\
    LOAD(svalue, filecounter);\
    i=(int)std::stoi(svalue.c_str());\
    }while(0);

#define setFCounter(filecounter, i)\
    do {\
    std::string svalue=std::to_string(i);\
    SAVE(svalue, filecounter);\
    }while(0);

#define resetFCounter(filecounter)\
    setFCounter(filecounter, 0)\
    
#define deltaFCounter(filecounter, delta)\
    do{\
        int i;\
        getFCounter(filecounter, i);\
        i  += delta;\
        setFCounter(filecounter,i);\
    }while(0);


//#define __DEBUG__

#ifdef __DEBUG__
#define __TESTING__
#endif 

#define __TESTING__


#ifdef __TESTING__




/////////////////////////////////////////////
// FAIL / SUCCESS OF TESTS
/////////////////////////////////////////////


/**
 * @brief If the previous tests failed, then
 */
#define SKIP_IF_FAILED_BEFORE() \
    do{ \
    std::string sfail; \
    LOAD(sfail, FILESTOP);\
    if (sfail != "PASS") { \
        SKIP_TEST();\
     } \
    }while(0);

/**
 * @brief Records that a test has SUCCEDED
 */
#define PASS_TEST() \
    SAVE("PASS", FILESTOP);

/**
 * @brief Record that a test has failed
 */
#define FAIL_TEST() \
    if (__defReport){ \
    PASS_TEST();\
    }else{ \
    SAVE("FAIL", FILESTOP);\
    }

/**
 * @brief If the previous tests failed, then
 */
#define SKIP_IF_MEMORY_LEAKS() \
    do{ \
    std::string sfail; \
    LOAD(sfail, FILESTOPMLEAKS);\
    if (sfail != "MEM_OK") { \
        SKIP_TEST();\
     } \
    }while(0);

/**
 * @brief Records that a test has SUCCEDED
 */
#define PASS_MEMORY_LEAKS() \
    SAVE("MEM_OK", FILESTOPMLEAKS);

/**
 * @brief Record that a test has failed
 */
#define FAIL_MEMORY_LEAKS() \
    SAVE("MEM_LEAKS", FILESTOPMLEAKS);

#define SKIP_TEST() \
    REPORT_SKIPPED_TEST();\
    GTEST_SKIP();    

/////////////////////////////////////////////
// Control the process of testing
/////////////////////////////////////////////

/**
 * @brief Must be the first thing in the test process. Warm up GoogleTest and 
 * prepares the MPTest environment
 */
#define INIT_MAIN() \
::testing::InitGoogleTest(); \
BEGIN_TESTING();\

/**
 * @brief Must be the last thing in the test process. It really launches 
 * the tests, and closes the reports
 * 
 */
#define RETURN_MAIN(X)  \
do {\
int ret= RUN_ALL_TESTS();\
END_TESTING();\
return ret;\
}while(0);


/**
 * @brief Starts the process of MPTests, including report, skip of test and execution 
 * environments
 */
#define BEGIN_TESTING() \
    system("../Scripts/getProjectName.sh");\
    ofstream ofreport;\
    resetFCounter("__nReport");\
    resetFCounter("__nTest");\
    SAVE("","__nTestname");\
    HEAD_REPORT(); \
    SAVE("",FILEREPORT_APPEND);\
    SAVE("",FILEREPORT_HEAD_CSV);\
    SAVE("",FILEREPORT_CSV);\
    PASS_MEMORY_LEAKS();\
    PASS_TEST();

/**
 * @brief Closes the process of MPTests
 */
#define END_TESTING() \
    do {\
    std::string footnote;\
    LOAD(footnote,FILEREPORT_APPEND);\
    REPLACE(footnote, "#", "\n(!) ");\
    REPLACE(footnote, " 1.", "\n\n   *");\
    REPLACE(footnote, " a.", "\n      -");\
    APPEND(footnote,FILEREPORT);\
    LOAD(footnote,FILEREPORT_CSV);\
    APPEND("\n"+footnote,FILEREPORT_HEAD_CSV);\
    } while(0);


/////////////////////////////////////////////
// Integration tests
/////////////////////////////////////////////

/**
 * Prepares the environment for every single Integration test
 */
//SKIP_IF_FAILED_BEFORE();
#define DEF_EXECUTION_ENVIRONMENT(NAME, ...) \
    std::string stestname= #NAME; \
    long timeout=30;\
    bool breakpoint=false;\
    CLEAN_TO_FILE();\
    std::string _output, _wdiff, _expected, __PROJECT__, __BIN__; \
    char REAL_OUTPUT[MAX_STRING_OUTPUT], EXPECTED_OUTPUT[MAX_STRING_OUTPUT];\
    std::string cmdline="", binary="", leakdetector="", leakreport; \
    if (BRANCH == "Debug") {\
    LOAD(__PROJECT__,"./.projectname");\
    } else {\
    __PROJECT__ = BRANCH;\
    }\
    sexpression=#__VA_ARGS__;\
    __BIN__ = std::string("./dist/")+BRANCH+"/GNU-Linux/"+ __PROJECT__;\
    cmdline=cmdline+"rm -f "+FILEOUTPUT +" " +FILECOUT+ " " +FILEEXPECTED; \
    std::system(cmdline.c_str()); \
    cmdline="";

/**
 * @brief Defines a timeout (seconds) for the execution of every integration test. By 
 * default this timeout is 30 secs.
 */
#define SET_TIMEOUT_S(NUMBER) \
     timeout = NUMBER;


/**
 * @brief Save the text as a simmulated keyboard input. It saves it into a file
 * for further processing
 */
#define FROM_KEYBOARD(TEXT) \
    SAVE(TEXT, FILEKEYBOARD );

/**
 * @brief Save the text as a simmulated keyboard input. It saves it into a file
 * for further processing
 */
#define FROM_FILE(FILENAME) \
    LOAD(_output, FILENAME)\
    SAVE(_output,FILEKEYBOARD)

/**
 * @brief Some programs produce the output on certain datafiles. These two macros
 * define which are those files in  order to validate them after the execution ends
 */
#define TO_FILE(FILENAME,...)\
sfilename[nfilenames]=FILENAME;\
sfilecontent[nfilenames++]=toISO(#__VA_ARGS__);

#define CLEAN_TO_FILE()\
nfilenames=0;

/**
 * @brief Defines the expected outcome of the integration tests, and temporally
 * saves it into a file for further processing. The outcome is treated as sequence
 * of symbols
 */
#define EXPECTED_COUT(...) \
    SAVE(#__VA_ARGS__, FILEEXPECTED );

/**
 * @brief Defines the expected outcome of the integration tests, and temporally
 * saves it into a file for further processing. The outcome is treates as a std::string
 */
#define EXPECTED_TEXT_OUTPUT(TEXT) \
    SAVE(TEXT, FILEEXPECTED );

/**
 * @brief Calls the main binary redirecting the stdin from a file with keyboard strokes.
 * It also supports main arguments
 */
//
// #define CALL_FROM_KEYBOARD(ARGS) \
//    binary = __BIN__ + " " + ARGS ; \
//    DETECT_MEMORY_LEAKS(); \
//    cmdline="";\
//    cmdline = cmdline+ __TIME_OUT_CALL__+" "+ std::to_string(timeout).c_str()+" "+std::to_string(timeout).c_str()+" ";\
//    cmdline = cmdline + binary +" < " +FILEKEYBOARD+ " 1> "+FILECOUT + " 2> " + FILEOUTPUT; \
//    std::system(cmdline.c_str());\
//    LOAD(_output, FILEOUTPUT); \
//    SAVE(_output, FILEOUTPUT); \
//    cmdline=(string)"../Scripts/getDifferenceOutputs.sh "+stestname+" > "+FILEDIFF;\
//    std::system(cmdline.c_str());\
//    COMPARE_OUTPUTS() 

/**
 * @brief Calls the main binary redirecting the stdin from a file with keyboard strokes
 * It also supports main arguments
 */
//#define CALL_FROM_FILE(ARGS) \
//    binary = __BIN__+ " " + ARGS ; \
//    DETECT_MEMORY_LEAKS(); \
//    cmdline="";\
//    cmdline = cmdline + binary +" < " +FILEINPUT+ " > " + FILEOUTPUT; \
//    std::system(cmdline.c_str());\
//    LOAD(_output, FILEOUTPUT); \
//    SAVE(_output, FILEOUTPUT); \
//    cmdline=(string)"../Scripts/getDifferenceOutputs.sh "+stestname+" > "+FILEDIFF;\
//    COMPARE_OUTPUTS()

#define CALL_FROM_FILE(ARGS) \
    binary = __BIN__+ " " + ARGS ; \
    DETECT_MEMORY_LEAKS(); \
    cmdline="";\
    cmdline = cmdline+ __TIME_OUT_CALL__+" "+ std::to_string(timeout).c_str()+" "+std::to_string(timeout).c_str()+" ";\
    cmdline = cmdline + binary +" < " +FILEINPUT+ " 1> " + FILEOUTPUT+" 2> " + FILEOUTPUT; \
    std::system(cmdline.c_str());\
    LOAD(_output, FILEOUTPUT); \
    SAVE(_output, FILEOUTPUT); \
    cmdline=(string)"../Scripts/getDifferenceOutputs.sh "+stestname+" > "+FILEDIFF;\
    std::system(cmdline.c_str());\
    COMPARE_OUTPUTS()

//    if (std::system(cmdline.c_str()) > 1){\
//        APPEND(string("\nXXX THE PROGRAM FREEZES AT THIS POINT AFTER ")+std::to_string(timeout)+" SECONDS XXX", FILEOUTPUT);\
//    }\

//    cmdline = cmdline + binary +" < " +FILEINPUT+ " 1> "+FILECOUT + " 2> " + FILEOUTPUT; \


/**
 * @brief Calls the main binary with only main arguments
 */
#define CALL(ARGS) \
    binary = __BIN__+ " " + ARGS ; \
    DETECT_MEMORY_LEAKS(); \
    cmdline="";\
    cmdline = cmdline + binary +  " 1> " + FILEOUTPUT+" 2> " + FILEOUTPUT; \
    std::system(cmdline.c_str());\
    LOAD(_output, FILEOUTPUT); \
    SAVE(_output, FILEOUTPUT); \
    cmdline=(string)"../Scripts/getDifferenceOutputs.sh "+stestname+" > "+FILEDIFF;\
    std::system(cmdline.c_str());\
    COMPARE_OUTPUTS()

/**
 * @brief Calls the main binary with only main arguments
 */
#define CALL_TO_FILES(ARGS) \
    binary = __BIN__+ " " + ARGS ; \
    DETECT_MEMORY_LEAKS(); \
    cmdline="";\
    cmdline = cmdline + binary +  " 1> " + FILEOUTPUT+" 2> " + FILEOUTPUT; \
    std::system(cmdline.c_str());\
    COMPARE_OUTPUT_FILES()


/////////////////////////////////////////////
// Memory leak integration
/////////////////////////////////////////////

/**
 * Defines the use of a certain memory leak detector, either __VALGRIND__
 * or __DRMEMORY__
 */
#define USE_MEMORY_LEAKS(which) \
    leakdetector= which;\

/**
 * @brief Executes the binary within Valgrind or DrMemory, by using an external
 * script which simplifies the process and produces a unified report for both
 * Valgrind and DrMemory. If no memory leak has been requested is does nothing
 */
#define DETECT_MEMORY_LEAKS() \
    if (!__defReport) {\
        SKIP_IF_MEMORY_LEAKS();\
        if (leakdetector.length()>0){\
            cmdline=""; \
            cmdline = cmdline +"../Scripts/doCheckMemoryLeaks.sh " + leakdetector+ " "+stestname+ "  \"" + binary+"\""; \
            cout << "[ MEMCHECK ] "<<stestname<< leakdetector;\
            std::system(cmdline.c_str()); \
            cmdline="";\
            LOAD(_output, FILEMLEAKS); \
            strncpy(REAL_OUTPUT, _output.c_str(),50); \
            strcpy(EXPECTED_OUTPUT, ""); \
            SKIP_ASSERT_MEM_R(EXPECTED_OUTPUT,REAL_OUTPUT);\
        }\
    }

/**
 * @brief Checks if the previous execution has produced a memory leak and
 * reports it
 */
#define CHECK_MEMORY_LEAKS() \
    do {\
    std::string MLHead ="";\
    std::string idtest;\
    UPDATEIDTEST();\
    IDTEST(idtest);\
    LOAD(leakreport,FILEMLEAKS);\
    if(leakreport == "") {\
        cout << "\n[       OK ] "<<stestname << leakdetector << std::endl;\
        MLHead = MLHead +"| "+ idtest + "| "+::testing::UnitTest::GetInstance()->current_test_info()->test_suite_name()+"."+ ::testing::UnitTest::GetInstance()->current_test_info()->name()+ leakdetector+" | ";\
        APPEND(MLHead, FILEREPORT);\
        APPEND((string)(string)"PASSED | NO LEAKS |\n", FILEREPORT);\
        PASS_TEST();\
        PASS_MEMORY_LEAKS();\
        deltaFCounter("__nReport", (-1));\
    } else {\
        MLHead = MLHead +"| "+ idtest + "| "+::testing::UnitTest::GetInstance()->current_test_info()->test_suite_name()+"."+ ::testing::UnitTest::GetInstance()->current_test_info()->name()+ leakdetector+"** | ";\
        APPEND(MLHead, FILEREPORT);\
        APPEND("**FAILED** | **HAS MEMORY LEAKS** (!) |\n", FILEREPORT);\
        REPLACE(leakreport,"#[", "\n[");\
           cout << leakreport <<endl;\
        FAIL_TEST();\
        FAIL_MEMORY_LEAKS();\
        LOAD(MLHead,FILEMLEAKSMD);\
        SAVE(MLHead,FILEREPORT_APPEND);\
     }\
     } while(0); \


/////////////////////////////////////////////
// MPTest special assertions
/////////////////////////////////////////////


/**
 * @brief Checks that the real output of the binary and the expected output matches
 * This is the basis of an integration test. If both matches, the integration test
 * succeds, otherwise, it fails
 */
#define COMPARE_OUTPUTS() \
    PASS_TEST();\
    LOAD(_wdiff, FILEDIFF); \
    REPORT_INTEGRATION_TEST(_wdiff);\
    ASSERTSTREQ("", _wdiff.c_str())

/**
 * @brief It checks that all the content of the output datafiles declared in the test 
 * is right
 */
#define COMPARE_OUTPUT_FILES() \
    for (int i=0; i<nfilenames; i++){ \
        string filedata;\
        LOAD(filedata, sfilename[i]);\
        ASSERTSTREQ(filedata.c_str(), sfilecontent[i].c_str()) << "The outpout obtained in file "+sfilename[i] << " is wrong " <<endl;\
        }

//#define ASSERT_OUTPUT() \
//    LOAD(_output, FILEOUTPUT); \
//    LOAD(_expected, FILEEXPECTED);\
//    strcpy(REAL_OUTPUT, _output.c_str()); \
//    strcpy(EXPECTED_OUTPUT, _expected.c_str()); \
//    ASSERT_INTEGRATION_CHECK_R(EXPECTED_OUTPUT,REAL_OUTPUT)


/**
 * @brief Checks if the previous test has failed, in this case, skip the following tests
 * otherwise, report the test and record its outcome
 */
#define SKIP_AND_REPORT(MESSAGE, ...) \
    SKIP_IF_FAILED_BEFORE();\
    REPORT_UNIT_TEST(MESSAGE, __VA_ARGS__);\
    if(__VA_ARGS__) {\
        PASS_TEST();\
    } else {\
        FAIL_TEST();\
    } 

/**
 * @brief Just report the test and record its outcome
 */
#define CONTINUE_AND_REPORT(MESSAGE, ...) \
 REPORT_UNIT_TEST(MESSAGE, __VA_ARGS__);\
    if(__VA_ARGS__) {\
        PASS_TEST();\
    } else {\
        FAIL_TEST();\
    } 

/**
 * @brief Checks if the previous test has failed, 
 * otherwise, report the test and record its outcome.
 * If the previous tests has failed, it does not stop the following tests
 */
#define DONT_FAIL_AND_REPORT(MESSAGE, ...) \
    SKIP_IF_FAILED_BEFORE();\
    REPORT_UNIT_TEST(MESSAGE, __VA_ARGS__);\
    if(__VA_ARGS__) {\
        PASS_TEST();\
    } else {\
        PASS_TEST();\
    } 


//
// ASSERTIONS THAT JUST REPORT . If a test fails, the next ones are executed, 
// the whole set fails
//
#define ASSERT_TRUE_R(...) \
    CONTINUE_AND_REPORT(#__VA_ARGS__ " must have been true", __VA_ARGS__);\
    ASSERTNE(false, __VA_ARGS__)

#define ASSERT_FALSE_R(...) \
    CONTINUE_AND_REPORT(#__VA_ARGS__  " must have been false", ! __VA_ARGS__);\
    ASSERTEQ(false,  __VA_ARGS__ )

#define ASSERT_EQ_R(expr1, expr2) \
    CONTINUE_AND_REPORT(#expr1 " must have been equal to " #expr2 , expr1 == expr2);\
    ASSERTEQ(expr1, expr2)

#define ASSERT_STREQ_R(expr1, expr2) \
    CONTINUE_AND_REPORT(#expr1 " must have been equal to " #expr2 , !strcmp(expr1,expr2));\
    ASSERTSTREQ(expr1, expr2)

#define ASSERT_NE_R(expr1, expr2) \
    CONTINUE_AND_REPORT(#expr1 " must have been equal to " #expr2 , expr1 != expr2);\
    ASSERTNE(expr1, expr2)

#define ASSERT_STRNE_R(expr1, expr2) \
    CONTINUE_AND_REPORT(#expr1 " must have been equal to " #expr2 , strcmp(expr1,expr2));\
    ASSERTSTRNE(expr1, expr2)

//
// Assertions that fail and report. It a test fails, the next ones are skipped 
// whole set fails
//

#define SKIP_ASSERT_TRUE_R(...) \
    SKIP_AND_REPORT(#__VA_ARGS__ " must have been true", __VA_ARGS__);\
    ASSERTNE(false, __VA_ARGS__)

#define SKIP_ASSERT_FALSE_R(...) \
    SKIP_AND_REPORT(#__VA_ARGS__  " must have been false", ! __VA_ARGS__);\
    ASSERTEQ(false,  __VA_ARGS__ )

#define SKIP_ASSERT_EQ_R(expr1, expr2) \
    SKIP_AND_REPORT(#expr1 " must have been equal to " #expr2 , expr1 == expr2);\
    ASSERTEQ(expr1, expr2)

#define SKIP_ASSERT_STREQ_R(expr1, expr2) \
    SKIP_AND_REPORT(#expr1 " must have been equal to " #expr2 , !strcmp(expr1,expr2));\
    ASSERTSTREQ(expr1, expr2)

#define SKIP_ASSERT_STRNE_R(expr1, expr2) \
    SKIP_AND_REPORT(#expr1 " must have been equal to " #expr2 , strcmp(expr1,expr2));\
    ASSERTSTRNE(expr1, expr2)  

//
// Assertions that do not fail. If a test fail, it does not affect the whole
// set
//
#define EXPECT_TRUE_R(...) \
    DONT_FAIL_AND_REPORT(#__VA_ARGS__  " must have been true", __VA_ARGS__);\
    EXPECTNE(false, __VA_ARGS__)

#define EXPECT_FALSE_R(...) \
    DONT_FAIL_AND_REPORT(#__VA_ARGS__  " must have been false", ! __VA_ARGS__);\
    EXPECTEQ(false,  __VA_ARGS__ )

#define EXPECT_EQ_R(expr1, expr2) \
    DONT_FAIL_AND_REPORT(#expr1 " must have been equal to " #expr2 , expr1 == expr2);\
    EXPECTEQ(expr1, expr2)

#define EXPECT_STREQ_R(expr1, expr2) \
    DONT_FAIL_AND_REPORT(#expr1 " must have been equal to " #expr2 , !strcmp(expr1,expr2));\
    EXPECTSTREQ(expr1, expr2)

//
// Specially devoted to memory checks. If memory leaks appear, then 
//
#define SKIP_ASSERT_MEM_R(expr1, expr2) \
    CHECK_MEMORY_LEAKS();\
    EXPECT_TRUE(strcmp(expr1, expr2)==0)

/////////////////////////////////////////////
// Reporting
/////////////////////////////////////////////

/**
 * Draws the head of the memory leak report
 */
#define HEAD_REPORT() \
    do{\
    std::string sproject;\
    LOAD(sproject,"./.projectname");\
    if (__defReport) {\
        SAVE((string)"# TESTS REPORT OF PROJECT "+sproject, FILEREPORT);\
        APPEND("\nAs of " __DATE__ " " __TIME__ "\n", FILEREPORT);\
        APPEND("\nThis is the list of tests of the project\n ", FILEREPORT);\
        APPEND("\n| ID | NAME | DESCRIPTION |\n", FILEREPORT); \
        APPEND("| :----- | :------ | :---- |\n", FILEREPORT); \
    }\
    else {\
        SAVE((string)"# OUTCOME OF TESTS FOR PROJECT "+sproject, FILEREPORT); \
        APPEND("\nAs of " __DATE__ " " __TIME__ "\n", FILEREPORT);\
        APPEND("\n| ID | NAME | RESULT | DESCRIPTION | \n", FILEREPORT); \
        APPEND("| :--- | :--- | :--- | :--- |\n", FILEREPORT); \
    }\
} while(0);

/**
 * @brief Draws the first columns of every row in the memory leak report
 */
//#define HEAD_REPORT_ROW() \
//    do {\
//    std::string head ="";\
//    __nReport++;\
//    head = head + "| CHECK#"+std::to_string(__nReport)+" "+::testing::UnitTest::GetInstance()->current_test_info()->test_suite_name()+"."+::testing::UnitTest::GetInstance()->current_test_info()->name()+ " | ";\
//    APPEND(head, FILEREPORT);\
//    }while(0);

#define UPDATEIDTEST()\
    do {\
    deltaFCounter("__nReport", (+1));\
    std::string testname, current=::testing::UnitTest::GetInstance()->current_test_info()->name();\
    LOAD(testname,"__nTestname");\
    if (testname != current){\
        SAVE(current,"__nTestname");\
        resetFCounter("__nReport");\
        deltaFCounter("__nReport", (+1));\
        deltaFCounter("__nTest", (+1));\
    }\
    } while(0);

#define IDTEST(label) \
    do {\
    int ncheck, ntest;\
    getFCounter("__nReport", ncheck);\
    getFCounter("__nTest", ntest);\
    label=std::to_string(ntest);\
    }while(0);

//    label=std::to_string(ntest)+"::"+std::to_string(ncheck);\


/**
 * @brief Report the success or failure of a test
 */
//#define REPORT_TEST(...) \
//    do {\
//    std::string RTHead ="";\
//    UPDATEIDTEST();\
//    IDTEST(idtest);\
//    if (! __defReport) {\
//        if(__VA_ARGS__) {\
//            smessage=sexpression+" should give \""+EXPECTED_STRING+"\"";\
//            RTHead = RTHead + "| "+ idtest +" | "+::testing::UnitTest::GetInstance()->current_test_info()->test_suite_name()+"."+::testing::UnitTest::GetInstance()->current_test_info()->name()+ " | ";\
//            APPEND(RTHead, FILEREPORT);\
//            APPEND("```"+(smessage)+"```| PASSED |\n", FILEREPORT);\
//        } else {\
//            RTHead = RTHead + "| "+ idtest +" | **"+::testing::UnitTest::GetInstance()->current_test_info()->test_suite_name()+"."+::testing::UnitTest::GetInstance()->current_test_info()->name()+ "** | ";\
//            APPEND(RTHead, FILEREPORT);\
//            APPEND(""+(MESSAGE) +"|**FAILED** |\n", FILEREPORT);\
//        } \
//    } else {\
//        RTHead = RTHead + "| "+ idtest +" | "+::testing::UnitTest::GetInstance()->current_test_info()->test_suite_name()+"."+::testing::UnitTest::GetInstance()->current_test_info()->name()+ " | ";\
//        APPEND(RTHead, FILEREPORT);\
//            APPEND(""+(MESSAGE)+" |\n", FILEREPORT);\
//    }\
//    }while(0);

//#define REPORT_UNIT_TEST(MESSAGE, ...) \
//    do {\
//    std::string RTHead ="";\
//    UPDATEIDTEST();\
//    IDTEST(idtest);\
//    if (! __defReport) {\
//        if(__VA_ARGS__) {\
//            RTHead = RTHead + "| "+ idtest +" | "+::testing::UnitTest::GetInstance()->current_test_info()->test_suite_name()+"."+::testing::UnitTest::GetInstance()->current_test_info()->name()+ " | ";\
//            APPEND(RTHead, FILEREPORT);\
//            APPEND((MESSAGE) +"| PASSED |\n", FILEREPORT);\
//        } else {\
//            RTHead = RTHead + "| "+ idtest +" | **"+::testing::UnitTest::GetInstance()->current_test_info()->test_suite_name()+"."+::testing::UnitTest::GetInstance()->current_test_info()->name()+ "** | ";\
//            APPEND(RTHead, FILEREPORT);\
//            APPEND(""+(MESSAGE) +"|**FAILED** |\n", FILEREPORT);\
//        } \
//    } else {\
//        RTHead = RTHead + "| "+ idtest +" | "+::testing::UnitTest::GetInstance()->current_test_info()->test_suite_name()+"."+::testing::UnitTest::GetInstance()->current_test_info()->name()+ " | ";\
//        APPEND(RTHead, FILEREPORT);\
//            APPEND(""+(MESSAGE)+" |\n", FILEREPORT);\
//    }\
//    }while(0);

#define REPORT_UNIT_TEST(...) \
    do {\
    std::string RTHead ="";\
    UPDATEIDTEST();\
    IDTEST(idtest);\
    if (! __defReport) {\
        if(__VA_ARGS__) {\
            RTHead = RTHead + "| "+ idtest +" | "+::testing::UnitTest::GetInstance()->current_test_info()->test_suite_name()+"."+::testing::UnitTest::GetInstance()->current_test_info()->name()+ " | ";\
            APPEND(RTHead, FILEREPORT);\
            APPEND(" PASSED |"+GOOD_OUTCOME_MD +"|\n", FILEREPORT);\
            APPEND("T"+idtest+SEPCSV, FILEREPORT_HEAD_CSV);\
            APPEND((string)"T"+idtest+" PASSED"+SEPCSV, FILEREPORT_CSV);\
        } else {\
            RTHead = RTHead + "| "+ idtest +" | **"+::testing::UnitTest::GetInstance()->current_test_info()->test_suite_name()+"."+::testing::UnitTest::GetInstance()->current_test_info()->name()+ "** | ";\
            APPEND(RTHead, FILEREPORT);\
            APPEND(" **FAILED** |"+GOOD_OUTCOME_MD+BAD_OUTCOME_MD+"|\n", FILEREPORT);\
            APPEND("T"+idtest+SEPCSV, FILEREPORT_HEAD_CSV);\
            APPEND("T"+idtest+" FAILED "+GOOD_OUTCOME_ASCII+BAD_OUTCOME_ASCII+SEPCSV, FILEREPORT_CSV);\
        } \
    } else {\
        RTHead = RTHead + "| "+ idtest +" | "+::testing::UnitTest::GetInstance()->current_test_info()->test_suite_name()+"."+::testing::UnitTest::GetInstance()->current_test_info()->name()+ " | ";\
        APPEND(RTHead, FILEREPORT);\
            APPEND(GOOD_OUTCOME_MD+" |\n", FILEREPORT);\
    }\
    }while(0);

#define REPORT_UNIT_TEST_EXCEPTION(...) \
    do {\
    std::string RTHead ="";\
    UPDATEIDTEST();\
    IDTEST(idtest);\
    if (! __defReport) {\
        if(__VA_ARGS__) {\
            RTHead = RTHead + "| "+ idtest +" | "+::testing::UnitTest::GetInstance()->current_test_info()->test_suite_name()+"."+::testing::UnitTest::GetInstance()->current_test_info()->name()+ " | ";\
            APPEND(RTHead, FILEREPORT);\
                APPEND(" PASSED |"+GOOD_EXCEPTION_MD+"", FILEREPORT);\
            APPEND("T"+idtest+SEPCSV, FILEREPORT_HEAD_CSV);\
            APPEND((string)"PASSED"+SEPCSV, FILEREPORT_CSV);\
        } else {\
            RTHead = RTHead + "| "+ idtest +" | **"+::testing::UnitTest::GetInstance()->current_test_info()->test_suite_name()+"."+::testing::UnitTest::GetInstance()->current_test_info()->name()+ "** | ";\
            APPEND(RTHead, FILEREPORT);\
            APPEND("**FAILED** |"+GOOD_EXCEPTION_MD+BAD_EXCEPTION_MD+" ", FILEREPORT);\
            APPEND("T"+idtest+SEPCSV, FILEREPORT_HEAD_CSV);\
            APPEND("FAILED "+GOOD_EXCEPTION_ASCII+BAD_EXCEPTION_ASCII+SEPCSV, FILEREPORT_CSV);\
        } \
    } else {\
        RTHead = RTHead + "| "+ idtest +" | "+::testing::UnitTest::GetInstance()->current_test_info()->test_suite_name()+"."+::testing::UnitTest::GetInstance()->current_test_info()->name()+ " | ";\
        APPEND(RTHead, FILEREPORT);\
            APPEND(GOOD_OUTCOME_MD+" |\n", FILEREPORT);\
    }\
    }while(0);

#define REPORT_INTEGRATION_TEST(MESSAGE) \
    do {\
    std::string RTHead ="";\
    UPDATEIDTEST();\
    IDTEST(idtest);\
    if (! __defReport) {\
        if(MESSAGE == "") {\
            RTHead = RTHead + "| "+ idtest +" | "+::testing::UnitTest::GetInstance()->current_test_info()->test_suite_name()+"."+::testing::UnitTest::GetInstance()->current_test_info()->name()+ " | ";\
            APPEND(RTHead, FILEREPORT);\
            APPEND((string)"PASSED | "+sexpression+"|\n", FILEREPORT);\
            APPEND("T"+idtest+SEPCSV, FILEREPORT_HEAD_CSV);\
            APPEND("T"+idtest+" PASSED"+SEPCSV, FILEREPORT_CSV);\
} else {\
            std::string msg;\
            RTHead = RTHead + "| "+ idtest +" | **"+::testing::UnitTest::GetInstance()->current_test_info()->test_suite_name()+"."+::testing::UnitTest::GetInstance()->current_test_info()->name()+ "** | ";\
            APPEND(RTHead, FILEREPORT);\
            msg=(string)"**FAILED** |"+sexpression+"\n||||"+" **"+MESSAGE +"** |\n";\
            APPEND(msg, FILEREPORT);\
            APPEND("T"+idtest+SEPCSV, FILEREPORT_HEAD_CSV);\
            APPEND((string)"T"+idtest+" FAILED: "+sexpression+" "+MESSAGE+SEPCSV, FILEREPORT_CSV);\
        } \
    } else {\
        RTHead = RTHead + "| "+ idtest +" | "+::testing::UnitTest::GetInstance()->current_test_info()->test_suite_name()+"."+::testing::UnitTest::GetInstance()->current_test_info()->name()+ " | ";\
        APPEND(RTHead, FILEREPORT);\
    }\
    }while(0);

#define REPORT_SKIPPED_TEST() \
    do {\
    std::string STHead ="";\
    std::string idtest;\
    UPDATEIDTEST();\
    IDTEST(idtest);\
    STHead = STHead + "| "+ idtest + "| **"+::testing::UnitTest::GetInstance()->current_test_info()->test_suite_name()+"."+::testing::UnitTest::GetInstance()->current_test_info()->name()+ "** | ";\
    APPEND(STHead, FILEREPORT);\
    APPEND("**SKIPPED** | **The previous test failed** |\n", FILEREPORT);\
    }while(0);



#else
#define TESTING_FLAG true
#define INIT_MAIN() ;
#define RETURN_MAIN(X)  return X;
#endif

#define MAIN_BODY() \
INIT_MAIN(); \
if(TESTING_FLAG)

#endif

