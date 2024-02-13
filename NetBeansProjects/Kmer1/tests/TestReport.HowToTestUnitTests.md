Para probar si te funciona un test de unidad de esta práctica, tienes que comentar temporalmente el código incluido en tu función main() e insertar en main() el código del test de unidad que quieras probar. También es necesario incluir previamente las siguientes declaraciones:

``` cpp
const string VALID_NUCLEOTIDES_ADN = "ACGT";
const string COMPLEMENTARY_NUCLEOTIDES_ADN = "TGCA";
const string VALID_NUCLEOTIDES_ARN = "ACGU";
const string COMPLEMENTARY_NUCLEOTIDES_ARN = "UGCA";

std::string printAKF(const KmerFreq array[], int nElements) {
    string res = "";
    res += std::to_string(nElements) + " ";
    for (int i = 0; i < nElements; i++) {
        res += array[i].toString() + " ";
    }
    return res;
}
void fillAKF_aa_cc_gg(KmerFreq *kfa, int &nKmers, const std::string &ss1="aa", const std::string &ss2="cc",
        const std::string &ss3="gg", int i1=1, int i2=11, int i3=111) {
    nKmers = 0;
    kfa[nKmers].setKmer(ss1);
    kfa[nKmers++].setFrequency(i1);
    kfa[nKmers].setKmer(ss2);
    kfa[nKmers++].setFrequency(i2);
    kfa[nKmers].setKmer(ss3);
    kfa[nKmers++].setFrequency(i3);
}

```
