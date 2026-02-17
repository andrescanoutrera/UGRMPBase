Los tests de integración que vamos a pasar a vuestros programas son más o menos los que se ejecutan si usáis el script runTests.sh. Sin embargo, los tests de unidad son un poco más engorrosos de probar, pero es posible hacerlo. Para probar si te funciona un test de unidad, tienes que comentar temporalmente el código incluido en tu función main() e insertar el código del test de unidad que quieras probar. 

También es necesario incluir previamente las siguientes declaraciones (que tras probar los tests, deberías eliminar):


``` cpp
#include <sstream>
#include <regex>

```

Por ejemplo, supongamos que queremos probar el test T01_Basics.Location_Location_def1  de Fraud0. Este test, como podemos ver en el fichero [TestReport.md](TestReport.md), tiene el siguiente contenido:

``` cpp
Location loc; 
string s=to_string(0.0)+string(" ")+to_string(0.0);
loc.inspectT() should give "0.000000 0.000000"
```

Como puedes ver, se usa el método inspectT() con un objeto de la clase Location. Este método no tenéis que hacerlo vosotros. Es un método que hemos hecho los profesores en cada una de las clases que usaremos. En vuestra prueba del test, sustituid la llamada a inspectT() por una llamada al método toString() de la clase correspondiente.

De esta forma, el contenido que debería tener main() para probar el anterior test de unidad sería:

``` cpp
#include <sstream>
#include <regex>

int main(int argc, char* argv[]) {
    Location loc; 
    string s=to_string(0.0)+string(" ")+to_string(0.0);
    cout << loc.toString(); 

    return 1;

    /**
    Código de la práctica Fraud, temporalmente comentado
    */
}
```
Al ejecutar el programa, debería mostrarse en la salida estándar el contenido que se indicaba para ese test en  [TestReport.md](TestReport.md). En este caso, el programa debería mostrar "0.000000 0.000000". Si no se muestra ese contenido, entonces es que falla el test, y por tanto hay algo mal en alguno de los métodos o funciones de vuestra práctica.
