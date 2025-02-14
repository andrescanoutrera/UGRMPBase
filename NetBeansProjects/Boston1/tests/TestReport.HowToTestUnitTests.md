Para probar si te funciona un test de unidad de esta práctica, tienes que comentar temporalmente el código incluido en tu función main() e insertar en main() el código del test de unidad que quieras probar. También es necesario incluir previamente las siguientes declaraciones:

``` cpp
#include <sstream>
#include <regex>

const float INVALID_COORDINATE=181.0; 

const string EMPTY_FIELD = "UNKNOWN";
const string DATETIME_DEFAULT = "2017-01-20 02:00:00";
const string DATETIME_CLASS_DEFAULT = "2000-01-01 00:00:00";
const string CRIME_DEFAULT("0," + EMPTY_FIELD + "," + EMPTY_FIELD + "," +
        EMPTY_FIELD + "," + EMPTY_FIELD + "," + EMPTY_FIELD + "," + EMPTY_FIELD +
        "," + ((std::string)"1") + "," + DATETIME_DEFAULT + "," +
        EMPTY_FIELD + ",181.000000,181.000000");

#define ENDL "\n"
const int MAX = 10;
const int MAXH = 24;

/** This function replace the values for the id and the dateTime for 3
 * secuential crimes. Be carefull the string sd, are used for the second
 * so correct values are string from "00" to "59". 
 * By default the resuting records are in ascendent values in id, and dateTime
 */
void fillACrimes(Crime *arrayC, const std::string &ss1="111", const std::string &ss2="222", 
        const std::string &ss3="333", const std::string &sd1="10", const std::string &sd2="20", const std::string &sd3="30") {
    int i=0;
    string sdate;
    
    sdate = arrayC[i].getDateTime().toString() ; 
    sdate.replace(sdate.end()-2,sdate.end(),sd1); //update sec
    arrayC[i].setId(ss1); // setID
    arrayC[i].setDateTime(sdate);      // setDate

    i++;
    arrayC[i].setId(ss2);   // setID
    sdate.replace(sdate.end()-2,sdate.end(),sd2); //update sec
    arrayC[i].setDateTime(sdate);      // setDate
    i++;
    arrayC[i].setId(ss3);   // setID
    sdate.replace(sdate.end()-2,sdate.end(),sd3); //update sec
    arrayC[i].setDateTime(sdate);      // setDate 
}

std::string toStringCrimes(const Crime *arrayC, int nElements) {
    string res = "";
    for (int i = 0; i < nElements; i++) {
        res += arrayC[i].toString() + " ";
    }
    return res;
}

```
