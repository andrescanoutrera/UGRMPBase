Para probar si te funciona un test de unidad de esta práctica, tienes que comentar temporalmente el código incluido en tu función main() e insertar en main() el código del test de unidad que quieras probar. También es necesario incluir previamente las siguientes declaraciones:

``` cpp
// Inclusión de ficheros .h que deben eliminarse tras comprobar los tests de unidad
#include <sstream>
#include <regex>
#include <cmath>
#include <string>

// Macros que deben eliminarse tras comprobar los tests de unidad
#define ENDL "\n"
#define LOCATION_DEFAULT "0.000000 0.000000"
#define LOCATION_OTHER "37.200000 -3.600000 Granada"
#define VECTOR_527 "5 7 7 7 7 7 "
#define VECTOR_DEFAULT5 "5 0 0 0 0 0 "

// Función auxiliar que usa algún test
void fill_vlocation(VectorLocation & locs, int size){
    Location loc;
    for (int i=0; i < size; i++) {
        loc.set(i,i,string("Location"+std::to_string(i)));
        locs.append(loc);
    }
}

```

Por ejemplo, supongamos que queremos probar el test T01_Basics.VectorLocation_VectorLocation_def1  de Fraud1. Este test, como podemos ver en el fichero [TestReport.md](TestReport.md), tiene el siguiente contenido:

``` cpp
VectorLocation vloc;
std::regex_replace(vloc.inspectT(), std::regex(ENDL), " ")
should give 0
```

Como puedes ver, se usa el método inspectT() con un objeto de la clase VectorLocation. Este método no tenéis que hacerlo vosotros. Es un método que hemos hecho los profesores en cada una de las clases que usaremos. En vuestra prueba del test, sustituid la llamada a inspectT() por una llamada al método toString() de la clase correspondiente.

De esta forma, el contenido que debería tener main() para probar el anterior test de unidad sería:

``` cpp
// Inclusión de ficheros .h que deben eliminarse tras comprobar los tests de unidad
#include <sstream>
#include <regex>
#include <cmath>
#include <string>

// Macros que deben eliminarse tras comprobar los tests de unidad
#define ENDL "\n"
#define LOCATION_DEFAULT "0.000000 0.000000"
#define LOCATION_OTHER "37.200000 -3.600000 Granada"
#define VECTOR_527 "5 7 7 7 7 7 "
#define VECTOR_DEFAULT5 "5 0 0 0 0 0 "

void fill_vlocation(VectorLocation & locs, int size){
    Location loc;
    for (int i=0; i < size; i++) {
        loc.set(i,i,string("Location"+std::to_string(i)));
        locs.append(loc);
    }
}

int main(int argc, char* argv[]) {
    VectorLocation vloc;
    std::regex_replace(vloc.inspectT(), std::regex(ENDL), " ");
    cout << loc.toString(); 

    return 1;

    /**
    Código de la práctica Fraud, temporalmente comentado
    */
}
```
Al ejecutar el programa, debería mostrarse en la salida estándar el contenido que se indicaba para ese test en  [TestReport.md](TestReport.md). En este caso, el programa debería mostrar "0". Si no se muestra ese contenido, entonces es que falla el test, y por tanto hay algo mal en alguno de los métodos o funciones de vuestra práctica.
