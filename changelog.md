# 27/FEB/2024
* En el proyecto Netbeans MPGeometry, se han modificado tres líneas (12, 25 y 53) del fichero main.cpp para arreglar pequeñas erratas en los comentarios doxygen de main() que hacían que no apareciese la sección mainpage en el html generado por doxygen.

# 3/MAR/2024
* Se añade la carpeta NetBeansProjects/Genomes que contiene archivos fragmentos de secuencias genómicas (.dna o .rna) y archivos profile (.prf) de varias especies.

# 8/MAR/2024
* Cambiado File por @file en main.cpp de los proyectos Kmer0, Kmer1, Kmer2, Kmer3 y Kmer4
* Arreglada una errata en un comentario doxygen en ArrayKmerFreqFunctions.h: UNKNOWN_NUCLEOTIDE cambiado por MISSING_NUCLEOTIDE

# 15/MAR/2024
* Modificado el fichero NetBeansProjects/Kmer1/tests/TestReport.HowToTestUnitTests.md para añadir la declaración de la constante MAX usada en algunos tests de unidad
* Se cambia /* por /** en los comentarios iniciales de main.cpp de los proyectos Kmer0, Kmer1, Kmer2, Kmer3 y Kmer4

# 18/MAR/2024
Modificados los ficheros TestReport.HowToTestUnitTests.md de Kmer1 hasta Kmer5 para añadir algunas declaración adicionales necesarias para poder probar algunos tests de unidad

# 9/ABR/2024
* El fichero test_noHeader.prf ha sido añadido a carpeta Genomes. Es usado en algún test de unidad de la clase Profile
* Se sustituye en algunos tests el uso de \n por la macro ENDL, pues daba problema en el report generado en caso de fallo del test que lo usaba
* Se modifica el test de unidad Profile_loadLoad para que use ../Genomes/12pairsDNA.prf como fichero de entrada en lugar de tests/output/test_save1.prf

# 10/ABR/2024
* Se actualizan ficheros tests/TestReport.md de Kmer2 y Kmer3 debido a los cambios del 9/ABR/2024

# 11/ABR/2024
* Se actualizan ficheros tests/TestReport.md de Kmer4 y Kmer5 debido a la inclusión del test de unidad Profile_loadLoad en Kmer4 y Kmer5

# 14/ABR/2024
* Se arregla una pequeña errata en el Ejemplo 1 de kmer3.pdf: los kmeros de las líneas 5 y 6 del primer cuadro del ejemplo se han intercambiado

# 29/ABR/2024
* En métodos Profile::load() y  Profile::append() de Kmer4 y Kmer5 se cambian comentarios respecto a las excepciones a lanzar. En load() no hay que lanzar ahora excepción std::out_of_range si se agota la capacidad, pues con memoria dinámica no ocurrirá. Solo hay que lanzar esta excepción si el número de kmeros fuese negativo. En append() ya no hay que lanzar excepción std::out_of_range al agotar la capacidad, pues de nuevo, con memoria dinámica no ocurrirá.

# 14/MAY/2024
* Se corrigen erratas en los comentarios de los parámetros de las funciones para la sobrecarga de los operadores de entrada/salida (operator>> y operator<<)

# 20/MAY/2024
* Se incluyen 6 nuevos tests de unidad en clase Profile, para probar constructor de copia y operador de asignación. Los nuevos tests son: T01_Basics.Profile_OperatorAssign_0, T01_Basics.Profile_ProfileCopy_0, T02_Intermediate.Profile_OperatorAssign_1, T02_Intermediate.Profile_OperatorAssign_2, T02_Intermediate.Profile_ProfileCopy_1, T02_Intermediate.Profile_ProfileCopy_2

# 22/MAY/2024
* Modificaciones en Kmer5/tests/03.6learn_unknownACGU.rna_k3.test pues había una errata. Faltaba el párametro -n ACGU en el comando de ejecución del programa
* Actualización de Kmer5/tests/TestReport.md tras arreglar algunas erratas de algunos tests
