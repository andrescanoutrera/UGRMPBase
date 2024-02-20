![image](https://user-images.githubusercontent.com/9058636/218943684-ca9d21ba-4bfe-4cb0-9cd8-7ace0827c742.png)

# UGRMPBase Un repo base para la asignatura Metodología de la programación

<!-- ![image](https://user-images.githubusercontent.com/9058636/154716516-2ef804b3-e2f4-4cdc-971e-771049323063.png)
Para estar al día de las incidencias de la asignatura y tener contacto directo con los profesores puedes unirte al grupo de Telegram de algunas titulaciones
 - Grupo de Telegram del [Doble Grado Informática y Matemáticas](https://t.me/+QJjPGdaLXrRkOTVk) -->

# <a name="preping"></a>Preparándolo todo
-  [Videotutorial](https://drive.google.com/file/d/1VO7ib1QnUlEk1pHtn4F7D6QJwZZykgbo/view?usp=sharing) Preparando el entorno de trabajo.
<!--- introducción a la asignatura.-->
<!--- Documentos de apoyo al videotutorial para la preparación del entorno de trabajo en el ordenador. En él se describe, a rasgos generales, cómo preparar el ordenador para la asignatura e incluye enlaces a otros videotutoriales, PDF, o Webs con descripciones más precisas de cada aspecto concreto. Este documento en PDF que aparece aquí son las transparencias del videotutorial y contiene los enlaces desde los que acceder a las herramientas y documentos que se citan en el vídeo.  -->
<!--  - Las transparencias del vídeo con enlaces  -->
- Repositorio en github de las prácticas de la asignatura:  https://github.com/andrescanoutrera/UGRMPBase

  - <a name="repo"></a>Descargar el repo:
    ```
    git clone https://github.com/andrescanoutrera/UGRMPBase UGRMPBase
    ``` 
  - Mantener el repo actualizado con los últimos cambios
    ```
    cd UGRMPBase
    git pull
    ```
- [Videotutorial](https://drive.google.com/file/d/1HkdEueUfbA9n8aLdPhaF0WxcK4q6xl70/view?usp=drive_link) Primeros pasos (descarga del repositorio UGMPBase).
- Paquetes de Linux que deben estar presentes durante las prácticas (sudo apt install) `gcc` `make` `valgrind`  `wdiff`  `meld` `doxygen`    `ImageMagick` `git` `graphviz`
- Para aquellos que decidáis la opción de VirtualBox, el profesorado de MP hemos preparado una copia de una máquina virtual ya preparada con Linux, NetBeans y C++. Aquí tenéis las instrucciones  para instalarla. Son tres pasos muy sencillos ![MP_VBOXc](https://user-images.githubusercontent.com/9058636/152649408-c228ab4f-d8c1-4ef8-8e56-81230dd63986.png)
 
   - <a name="virtualbox"></a>Descargar e Instalar [Virtualbox](https://www.oracle.com/emea/virtualization/solutions/try-oracle-vm-virtualbox/?source=:ad:pas:go:dg:a_emea:71700000086137880-58700007342953610-p65823631225:RC_WWMK201210P00009C0001:&SC=:ad:pas:go:dg:a_emea::RC_WWMK201210P00009C0001::&gclid=CjwKCAiAl-6PBhBCEiwAc2GOVOk47paaZegmnUyyKtx-WFrjIcTIDntJfqxW40Kk8E3DFxK2_RPZBBoCUzwQAvD_BwE&gclsrc=aw.ds)
   - Descargar la [Máquina virtual oficial de la asignatura](https://drive.google.com/drive/u/1/folders/1HMwctEsaFuICZpuHUF5rZuM6IpXPJqy8) desde Google Drive (tardará un poco porque son más de 4 GB). Es una versión de `Ubuntu 20` conocida como `LUbuntu 16.04 LTS` la cual ya viene empaquetada para consumir la mínima cantidad de recursos dado que se va a usar dentro de una VirtualBox sobre Windows. Esta imagen ya está configurada para la asignatura MP y lleva todo el software necesario instalado.
   - Importar la máquina virtual  y acceder a ella. [guía de importación](PDFs/importVBOX.pdf)
   - Usuario `mp`
   - Password `.CambiaEsto`
   - En febrero de 2024, la oficina de Software Libre de la UGR nos ha proporcionado una nueva [Máquina virtual oficial de la asignatura](https://drive.google.com/file/d/199qZAdcO_iIb1QTubGkuF7APseNESvNk/view?usp=sharing) disponible también a través de Google Drive (que ocupa en este caso algo más de 10GB). Es una versión de `Ubuntu 22` que también está configurada para la asignatura MP y lleva todo el software necesario instalado.
   - Usuario `usuario`
   - Password `usuario`
- Laboratorios de prácticas de la ETSIIT. Arranque con Ubuntu 20.04. El resto de herramientas ya están instaladas.
- Y, finalmente una última opción: el servidor de imágenes virtuales de la [ETSIIT](https://turing.ugr.es/). Arrancar con Ubuntu 18. Ya tiene instalado NetBeans 11.2 y C++. 
- Enlaces interesantes
   - [Descargar la imagen de Ubuntu](https://ubuntu.com/download/desktop)
   - [Tutorial sobre la instalación dual Linux/Windows](https://www.youtube.com/watch?v=qSbRnYWwnxI)
   - [Tutorial instalación NetBeans](https://www.youtube.com/watch?v=zCJpPZ548Oo)
   - [Tutorial instalación plugin C++ para NetBeans](https://www.youtube.com/watch?v=ZA1iRNznGug)

# Secuencia de prácticas

Mira los vídeos de [introducción a la asignatura](https://drive.google.com/file/d/1VO7ib1QnUlEk1pHtn4F7D6QJwZZykgbo/view?usp=sharing)  y de [introducción a las prácticas](https://drive.google.com/file/d/1fJgfQACE46PscCkA4pj5bTEtSuzMwCSz/view)
<!-- (https://drive.google.com/file/d/1peiNfwzRKYvCFHCJlSH2licuhCIuEeqL/view?usp=share_link) -->

|Comienzo | Práctica <br> Entregable en Prado | Herramientas | Metodología
| -----| -----|-----| ----- |
|Semana1 19/feb/2024 || <ol><li>[**NetBeans 1**](#netbeans) <ul><li>Primeros pasos <li>HelloWorld <li>Directivas del precompilador</ul> <li> Gestión de la documentación con [Doxygen](#doxygen) </ol>| <ol><li>Caso práctico: Análisis del proyecto [MP Geometry](#mpgeometry)<ul><li>Métodos `const`.<li>Parámetros por valor y por referencia. <li>Funciones friend<li>Validación simple de programas. Lectura de datos con redirección de la enrtada</ul><li>Caso práctico: Separación de la declaración e implementación de los métodos con el proyecto [MP Geometry](#mpgeometry)<li> Caso práctico: Compilación separada con el proyecto [MP Geometry](#mpgeometry)  <li> Opcional: Uso de bibliotecas con el proyecto [MP Geometry](#mpgeometry) </ol>|
|<a name="Semana2"></a>Semana2	26/feb/2024 | [**Kmer0**](PDFs/kmer0.pdf) Identificación de Kmeros. Clase Kmer <br>[Tests detallados](NetBeansProjects/Kmer0/TestReport.md) <br>[Cómo probar tests de unidad](NetBeansProjects/Kmer0/TestReport.HowToTestUnitTests.md) | <ol><li>[**NetBeans 2**](#netbeans) <ul><li>Compilación separada</ul>| <ol> <li>Calificador const para métodos y parámetros <li>Paso de parámetros por valor y referencia  <li> Devolución por valor y referencia </ol> |
|Semana3	4/mar/2024 | |<ol><li>[**NetBeans 3**](#netbeans) <ul><li>El [depurador](#depurador) de programas</ul>|  |
|Semana4	11/mar/2024 |[**Kmer1**](PDFs/kmer1.pdf)  Kmeros y frecuencias asociadas. Clase KmerFreq <br>[Tests detallados](NetBeansProjects/Kmer1/tests/TestReport.md) <br>[Cómo probar tests de unidad](NetBeansProjects/Kmer1/tests/TestReport.HowToTestUnitTests.md)  |  |  <ol> <li>Calificador const para métodos y parámetros <li>Paso de parámetros por valor y referencia  <li> Devolución por valor y referencia <li>Paso de vectores a funciones y métodos </ol>|
|Semana5	18/mar/2024 |  || |
|Semana Santa	25/mar/2024 | **Semana Santa**| | |
|Semana6	1/abr/2024 | [**Kmer2**](PDFs/kmer2.pdf) Modelo de una especie. Clase Profile con vector estático <br>[Tests detallados](NetBeansProjects/Kmer2/tests/TestReport.md) <br>[Cómo probar tests de unidad](NetBeansProjects/Kmer2/tests/TestReport.HowToTestUnitTests.md)| | <ol><li> Clases con vectores estáticos. <li>Acceso a [datos en disco](#ficheros). Lectura y escritura. Errores frecuentes <li> Uso de [parámetros](#parametrosmain) desde la línea de comandos.  CStrings  </ol>|
|Semana7	8/abr/2024 | |
|Semana8	15/abr/2024 |[**Kmer3**](PDFs/kmer3.pdf) Cálculo de distancias entre profiles. Clase Profile con vector estático <br>[Tests detallados](NetBeansProjects/Kmer3/tests/TestReport.md) <br>[Cómo probar tests de unidad](NetBeansProjects/Kmer3/tests/TestReport.HowToTestUnitTests.md) | [**valgrind**](PDFs/valgrind.pdf) Detección de pérdidas de memoria| <ol> <li> Uso de memoria dinámica en C++. <li> Arrays dinámicos. <li> Detección de pérdidas de memoria </ol>|
|Semana9	22/abr/2024 ||||
|Semana10	29/abril/2024 | [**Kmer4**](PDFs/kmer4.pdf) Cálculo de distancias entre profiles. Clase Profile con vector en memoria dinámica <br>[Tests detallados](NetBeansProjects/Kmer4/tests/TestReport.md) <br>[Cómo probar tests de unidad](NetBeansProjects/Kmer4/tests/TestReport.HowToTestUnitTests.md) | | <ol><li>Clases que contienen datos en memoria dinámica <li>Constructor de copia <li>Operador de asignación <li>Destructor</ol>|
|Semana11	6/may/2024 |**Kmer4** <br>**Examen de laboratorio**<br>1 PUNTO | | |
|Semana12	13/may/2024 |[**Kmer5**](PDFs/kmer5.pdf) Aprendizaje y clasificación. Clase KmerCounter <br>[Tests detallados](NetBeansProjects/Kmer5/tests/TestReport.md) <br>[Cómo probar tests de unidad](NetBeansProjects/Kmer5/tests/TestReport.HowToTestUnitTests.md) <br>2 PUNTOS | | <ol> <li>Sobrecarga de operadores. <li>Matrices bidimensionales dinámicas <li> Ficheros binarios .</ol>|
|Semana13	20/may/2024 | | | |
|Semana14	27/may/2024 | | | |
|Semana15	3/jun/2024 | | | |
|||||

# Técnicas, herramientas y metodologías de prácticas

En esta sección encontrarás manuales y videotutoriales sobre temas específicos de las prácticas que irán complementando al tema principal de la práctica.

## <a name="netbeans"></a> El entorno de desarrollo NetBeans
NetBeans es un entorno de desarrollo integrado libre y multiplataforma, creado principalmente para el lenguaje de programación Java, pero que ofrece soporte para otros muchos lenguajes de programación. Existe además un número importante de módulos para extenderlo. NetBeans es un producto libre y gratuito sin restricciones de uso. 
- [Manual de referencia](PDFs/netbeans.pdf)
- <a name="prmerospasos"></a>Primeros pasos <ul><li>[Videotutorial](https://drive.google.com/file/d/1MFbCDJAiMJctlN_jPIfwlhWqPi0TGWiI/view?usp=sharing)</li>
   </ul>
- <a name="helloworld"></a>Hello world!<ul><li>[Videotutorial](https://drive.google.com/drive/u/1/folders/1QOu1xYpdQd_FwKzcOo-HlXZ8dlmMcCSs)<li>Abrir [Proyecto Netbeans](NetBeansProjects/HelloWorld)<li>Vistas Lógica (Projects) y Física (Files) <li> Editor<li>Estándar C++14<li>Compilar y enlazar<li> Carpetas build y dist<li> Ejecutar<ul><li>Pestaña de salida del programa<li>Desde Netbeans<li>Desde la terminal de ordenes<li>Ficheros de datos de validación</ul></ul>
- Directivas del precompilador<ul><li>[Videotutorial](https://drive.google.com/file/d/1-nneQyafIa58DgtlcD3x2bCDXL93N1au/view?usp=sharing)</ul>

## <a name="doxygen"></a> Documentación con Doxygen

Doxygen es un programa de apoyo a la documentación (comentarios) de proyectos de software que usa una sintaxis de anotación de los comentarios en el código que podríamos llamar, estándar, y común a otros lenguajes.

- [Manual de doxygen](PDFs/doxygen.pdf)
- [Videotutorial](https://drive.google.com/drive/u/1/folders/1Ki1RYMaBIORurj7MiQUqWsCBt_lsbPfv) 

## Compilación separada
Es una metodología de desarrollo de proyectos de software que divide el proyecto en unidades funcionales, llamados módulos o paquetes o bibliotecas (librerías), que se compilan por separado y se enlazan en un único fichero

- Primera parte.De un proyecto monolítico a un proyecto modularizado.
  - <a name="mpgeometry"></a>Proyecto NetBeans [MPGeometry monolítico](NetBeansProjects/MPGeometry)
  - [Videotutorial]( https://drive.google.com/file/d/1-KiBquuuHJ5_zNeSLqWH88PqazuoTVmy/view?usp=sharin) modularización y compilación  separada
  - Proyecto NetBeans [MPGeometry sep](NetBeansProjects/MPGeometrySep)

  - Proyecto NetBeans [MPGeometry modularizado](NetBeansProjects/MPGeometry_MOD)
- Segunda parte. Uso de bibliotecas (librerías)
  - [Videotutorial](https://drive.google.com/file/d/1m9pC3XWjz6BS9Srfu_4B_Bimw_jfw5xP/view?usp=sharing)

<!--
## Test-Driven Development

Es una metodología de desarrollo de proyectos software en la que primero se definen los tests de validez que debe pasar el proyecto y después es cuando se codifica el proyecto. Un proyecto se considera válido si pasa todos los tests previstos.

- Introducción a Test-Driven Development. [Videotutorial](https://drive.google.com/file/d/132dXXwUCx0Jrrzq2S2y2BN6lLsvEGrPJ/view?usp=sharing)
- Creando el proyecto. [Videotutorial](https://drive.google.com/file/d/1V7FCuVPR1PQ5GM-jU_s44neWG6RZwKZp/view?usp=sharing)
- Pasar los primeros tests unitarios . [Videotutorial](https://drive.google.com/file/d/1VWcj4jr0keKv0-Gy_Mz9JRmSpbCpPAWq/view?usp=sharing)
- Pasar todos los tests unitarios. [Videotutorial](https://drive.google.com/file/d/1R0zEd_yxQ51Yo0N3VTNH-s7pYzgefXMg/view?usp=sharing)
- Los tests de integración. [Videotutorial](https://drive.google.com/file/d/13weHJA5zQhC9YADoqyVhUHxc7WHoPE1O/view?usp=sharing)
- Proyecto `MyVector`  
- [Manual completo TDD](PDFs/Adicional/TDDGTEST_V2.pdf)
-->

## <a name="depurador"></a>Depuración de programas
El depurador es una herramienta que suele estar incorporada en los IDE (Integrated Development Environment) como NetBeans. Se utiliza para ejecutar el programa paso a paso e intentar encontrar errores en el código.

- Manual sobre el [depurador de NetBeans](PDFs/Debugger.pdf)
- [Videotutorial 1](https://drive.google.com/file/d/1vtFSsMQKnaHpsGD25TCPHCAdmDVJ_a1k/view?usp=sharing)
- [Videotutorial 2](https://drive.google.com/file/d/1cStDUlagLLo_UQk5HOvZNWuqg3dxxCNl/view?usp=sharing)
- Proyectos de NetBeans para depurar incluídos en el videotutorial: `Debugger1` `Debugger2` `Debugger3`

## Detección de pérdidas de memoria y errores en la gestión de la memoria
Valgrind es una herramienta para la detección, sobre todo, de pérdidas de memoria, pero también de otros problemas de gestión de la memoria dinámica.

- Manual sobre el uso de [Valgrind](PDFs/valgrind.pdf)
<!-- - Manual sobre el uso de [Dr Memory](Adicional/drmemory.pdf) -->
- Proyecto Interactivo [ValgrindShowcase](NetBeansProjects/ValgrindShowcase)
  - Descomprimir
  - Cargar en Netbeans
  - Ejecutar y seguir las instrucciones. Se puede volver a empezar de nuevo sin más que descomprimir de nuevo.

## <a name="ficheros"></a>Manejo de ficheros de texto (muy básico)
Los ficheros de texto permiten almacenar datos que  pueden leer los programas de forma masiva para procesarlos. Este apartado es una (muy breve) introducción al manejo de ficheros que se verá en teoría.

- Manual sobre el manejo (muy básico) de [ficheros de texto](PDFs/Ficheros.pdf)
- Videotutorial 1. [Ficheros de entrada](https://drive.google.com/file/d/1A3ToJaVXrF1k2bl0dz2xz1e3Hu4arvR8/view?usp=sharing)
- Videotutorial 2. [Ficheros de salida](https://drive.google.com/file/d/1xllMQyf0sQP-cfrGSabFi5shA4bUzMZc/view?usp=sharing)
- Videotutorial 3. Gestión de [errores en el manejo de ficheros](https://drive.google.com/file/d/19us64WCMXZyEd5um_MuZpLp5IqQU3nMV/view?usp=sharing)

## <a name="parametrosmain"></a>Paso de parámetros a la función main() desde la línea de órdenes

Esta es una técnica muy habitual para introducir datos en un programa desde la línea de comandos. Absolutamente imprescindible en programas de consola de Linux/Unix.

- Manual sobre el [paso de argumentos a main()](PDFs/ArgumentosMain.pdf)
- [Videotutorial 1](https://drive.google.com/file/d/1xlVzVTwbFSWfhdaHGgNSq67bQo0c46nJ/view?usp=sharing)
- [Videotutorial 2](https://drive.google.com/file/d/1HaYIyECXYuZ1FAMSlSB1P7PSj9qCXlXG/view?usp=sharing)

## Construcción manual de makefiles (Material de ampliación)
- Manual para la elaboración de [makefiles](PDFs/Adicional/makefile.pdf)

## Manejo de errores y excepciones  (Material de ampliación)
Breve introducción a la gestión de señales de error durante la ejecución de un programa y la gestión controlada de estos mediante el uso de excepciones. Videotutorial 

- Manejo de señales de error. [Videotutorial](https://drive.google.com/file/d/1U0pBUxBrklBKLkZcgsIkClCeQxyf1Bv0/view?usp=sharing)
- Manejo de excepciones [Videotutorial](https://drive.google.com/file/d/1aPJP1ft4OiQZED2dVGs7pbzy3nf7kQ1J/view?usp=sharing)



# Erratas

En esta sección incluimos erratas que se detecten en los distintos guiones y proyectos Netbeans. Esperemos que no sean muchas.






