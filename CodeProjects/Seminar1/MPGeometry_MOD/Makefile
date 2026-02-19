#Obtención del ejecutable
mpgeometry: main.o Point2D.o Rectangle.o
	g++ -o mpgeometry main.o Point2D.o Rectangle.o


# ************ Compilación de módulos ************
Point2D.o : src/Point2D.cpp include/Point2D.h
	g++ -Wall -g -c -Iinclude src/Point2D.cpp -o Point2D.o

Rectangle.o : src/Rectangle.cpp include/Point2D.h include/Rectangle.h
	g++ -Wall -g -c -Iinclude src/Rectangle.cpp -o Rectangle.o
	
main.o : src/main.cpp include/Point2D.h include/Rectangle.h
	g++ -Wall -g -c -Iinclude src/main.cpp -o main.o


# ************ Limpieza ************
clean :
	-rm *.o
	-rm mpgeometry

