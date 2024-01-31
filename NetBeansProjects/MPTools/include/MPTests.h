/**
 * @file MPtest.h
 * @brief Extension to Googletest to cover formatted reporting of tests
 * @author DECSAI
 */
//#define __WINDOWS__
#ifdef __WINDOWS__
#define SLASH (std::string) "\\"
#define CVAL std::clog 
#define INSPECT(VAR) CVAL << std::endl<< "["<<#VAR<<"] "<< VAR.inspect() << std::endl;
#else
#define SLASH (std::string) "/"
#endif


#ifdef __TDD__
#define __USE_MP_SCALE__
#include "MPTestsV2.h"  
#endif

#ifdef __TDD_V3__
#define __USE_MP_SCALE__
#include "MPTestsV3.h"  
#endif
