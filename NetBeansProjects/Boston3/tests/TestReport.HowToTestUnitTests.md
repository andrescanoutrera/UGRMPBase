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
const int DIM_VECTOR_CRIMES_LOC = 2000;
const string OTHER = "1,111,222,333,444,555,666,1,2025-02-17 12:30:00,999,90.000000,180.000000 ";
const int MAX = 10;
const int MAXH = 24;
```
