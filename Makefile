FLAGS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers
FILES = $(wildcard *.cc) $(wildcard *.hh) Makefile

all: program.exe

program.exe: program.o Estacion.o Cjt_estaciones.o Bicicleta.o Cjt_bicicletas.o
	g++ -o program.exe program.o Estacion.o Cjt_estaciones.o Bicicleta.o Cjt_bicicletas.o

Bicicleta.o: Bicicleta.cc Bicicleta.hh
	g++ $(FLAGS) -c Bicicleta.cc

Estacion.o: Estacion.cc Estacion.hh
	g++ $(FLAGS) -c Estacion.cc

Cjt_bicicletas.o: Cjt_bicicletas.cc Cjt_bicicletas.hh Bicicleta.hh
	g++ $(FLAGS) -c Cjt_bicicletas.cc

Cjt_estaciones.o: Cjt_estaciones.cc Cjt_estaciones.hh Estacion.hh
	g++ $(FLAGS) -c Cjt_estaciones.cc

program.o: program.cc Cjt_bicicletas.hh Cjt_estaciones.hh Bicicleta.hh Estacion.hh
	g++ $(FLAGS) -c program.cc

tar:
	tar -cvf practica.tar $(FILES)

clean:
	rm -f program.exe *.o practica.tar
	rm -f *.o
	rem -f *.exe
