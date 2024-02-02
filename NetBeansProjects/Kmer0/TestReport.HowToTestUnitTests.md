Los tests de integración que vamos a pasar a vuestros programas son más o menos los que se ejecutan si usáis el script runTests.sh. Sin embargo, los tests de unidad son un poco más engorrosos de probar, pero es posible hacerlo. Para probar si te funciona un test de unidad, tienes que comentar temporalmente el código incluido en tu función main() e insertar el código del test de unidad que quieras probar. También es necesario incluir previamente las siguientes declaraciones:


``` cpp
const string VALID_NUCLEOTIDES_ADN = "ACGT";
const string COMPLEMENTARY_NUCLEOTIDES_ADN = "TGCA";
const string VALID_NUCLEOTIDES_ARN = "ACGU";
const string COMPLEMENTARY_NUCLEOTIDES_ARN = "UGCA";

```


Por ejemplo, supongamos que queremos probar el test T01_Basics.Kmer_Kmer_int_1 de Kmer0. Este test, como podemos ver en el fichero [TestReport.md](TestReport.md), tiene el siguiente contenido:

``` cpp
Kmer kmer;
kmer.inspectT() should give "_"
```

Como puedes ver, se usa el método inspectT() con un objeto de la clase Kmer. Este método no tenéis que hacerlo vosotros. Es un método que hemos hecho los profesores. En vuestra prueba del test, sustituid la llamada a inspectT() por una llamada al método toString().

De esta forma, el contenido que debería tener main() para probar el anterior test de unidad sería:

``` cpp
const string VALID_NUCLEOTIDES_ADN = "ACGT";
const string COMPLEMENTARY_NUCLEOTIDES_ADN = "TGCA";
const string VALID_NUCLEOTIDES_ARN = "ACGU";
const string COMPLEMENTARY_NUCLEOTIDES_ARN = "UGCA";

int main(int argc, char* argv[]) {
    Kmer kmer;
    cout << kmer.toString();

    return 1;

    /**
    Código de la práctica Kmer, temporalmente comentado
    */
}
```
Al ejecutar el programa, debería mostrarse en la salida estándar el contenido que se indicaba para ese test en  [TestReport.md](TestReport.md). En este caso, el programa debería mostrar el carácter "_". Si no se muestra ese contenido, entonces es que falla el test, y por tanto hay algo mal en alguno de los métodos o funciones de vuestra práctica.
