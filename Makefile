OPCIONS = -D_GLIBCXX_DEBUG -D_JUDGE_ -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11

program.exe: program.o Alfabeto.o Mensaje.o Cjt_Alfabetos.o Cjt_Mensajes.o
	g++ $(OPCIONS) -o program.exe program.o Alfabeto.o Mensaje.o Cjt_Alfabetos.o Cjt_Mensajes.o

program.o: program.cc
	g++ $(OPCIONS) -c program.cc

Alfabeto.o: Alfabeto.cc Alfabeto.hh
	g++ $(OPCIONS) -c Alfabeto.cc

Mensaje.o: Mensaje.cc Mensaje.hh
	g++ $(OPCIONS) -c Mensaje.cc

Cjt_Alfabetos.o: Cjt_Alfabetos.cc Cjt_Alfabetos.hh
	g++ $(OPCIONS) -c Cjt_Alfabetos.cc

Cjt_Mensajes.o: Cjt_Mensajes.cc Cjt_Mensajes.hh
	g++ $(OPCIONS) -c Cjt_Mensajes.cc

clean:
	rm -f *.exe *.o

all:
	make clean
	make
	make tar
	doxygen

tar: program.cc Makefile html.zip BinTree.hh Alfabeto.cc  BinTree.hh Cjt_Alfabetos.hh  Cjt_Mensajes.hh Mensaje.hh Alfabeto.hh Cjt_Alfabetos.cc Cjt_Mensajes.cc Mensaje.cc jp_feiyang.wang.zip
	tar -cvf practica.tar Alfabeto.cc Makefile html.zip BinTree.hh Cjt_Alfabetos.hh  Cjt_Mensajes.hh Mensaje.hh Alfabeto.hh Cjt_Alfabetos.cc Cjt_Mensajes.cc Mensaje.cc program.cc jp_feiyang.wang.zip
