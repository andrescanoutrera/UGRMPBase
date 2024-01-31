
#ifndef MPTOOLS_H
#define MPTOOLS_H

#ifndef __RELEASE__
    #define CVAL std::cerr
    #define INSPECT(VAR) CVAL << std::endl<< "["<<#VAR<<"] "<< VAR.inspect() << std::endl;
    #define REPORT_TEXT(TEXT) CVAL << TEXT << std::endl;
#else
    #define CVAL std::cout
    #define INSPECT(VAR) ;
    #define REPORT_TEXT(TEXT) ;
#endif

#ifdef __WINDOWS__
    #define SLASH (std::string) "\\"
#else
    #define SLASH (std::string) "/"
#endif

#define CA 54059 /* a prime */
#define CB 76963 /* another prime */
#define CC 86969 /* yet another prime */
#define CFIRSTH 37 /* also prime */

inline unsigned mphash(const unsigned char * s, int size) {
    unsigned h = CFIRSTH;
    while (size > 0) {
        h = (h * CA) ^ (s[0] * CB);
        s++;
        size--;
    }
    return h;
}

//void mpDisplayImage(std::string filename, std::string windowtitle);
//bool mpSavePGMImage(std::string filename, const unsigned char *buffer,int width, int height);
std::string toUTF(char in);
std::string toUTF(const std::string &s);
std::string toUTF(const char * i);

std::string toISO(const char * in);
std::string toISO(const std::string &h);
bool isUTF8(const char * string);

#endif /* MPTOOLS_H */


