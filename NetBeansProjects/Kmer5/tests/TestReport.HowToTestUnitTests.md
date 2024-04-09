Para probar si te funciona un test de unidad de esta práctica, tienes que comentar temporalmente el código incluido en tu función main() e insertar en main() el código del test de unidad que quieras probar. También es necesario incluir previamente las siguientes declaraciones:

``` cpp
#include <regex>
#include <cmath>

const string VALID_NUCLEOTIDES_ADN = "ACGT";
const string COMPLEMENTARY_NUCLEOTIDES_ADN = "TGCA";
const string VALID_NUCLEOTIDES_ARN = "ACGU";
const string COMPLEMENTARY_NUCLEOTIDES_ARN = "UGCA";
const int DIM_VECTOR_KMER_FREQ = 2000;
#define ENDL "\n"
```
