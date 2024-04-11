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
* Se actualizan ficheros tests/TestReport.md de Kmer2 y Kmer3 debido a los cambios anteriores

# 11/ABR/2024
* Se actualizan ficheros tests/TestReport.md de Kmer4 y Kmer5 debido a la inclusión del test de unidad Profile_loadLoad en Kmer4 y Kmer5
