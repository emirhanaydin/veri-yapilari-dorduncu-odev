CC=g++
BIN=bin
INCL=include
LIB=lib
SRC=src
EXE=main

all: make_dirs gen_libs compile run

make_dirs:
	IF NOT EXIST $(BIN) (MD "$(BIN)")
	IF NOT EXIST $(INCL) (MD "$(INCL)")
	IF NOT EXIST $(LIB) (MD "$(LIB)")
	IF NOT EXIST $(SRC) (MD "$(SRC)")
	
gen_libs: main.o bagilListe.o dosya.o dugum.o gezici.o hata.o ikiliHeap.o islem.o konsol.o sayi.o

compile:
	$(CC) $(LIB)/main.o $(LIB)/bagilListe.o $(LIB)/dosya.o $(LIB)/dugum.o $(LIB)/gezici.o $(LIB)/hata.o $(LIB)/ikiliHeap.o $(LIB)/islem.o $(LIB)/konsol.o $(LIB)/sayi.o -o $(BIN)/$(EXE)

run:
	$(BIN)/$(EXE).exe
	
main.o:
	$(CC) -I $(INCL) -c $(SRC)/main.cpp -o $(LIB)/main.o
bagilListe.o:
	$(CC) -I $(INCL) -c $(SRC)/bagilListe.cpp -o $(LIB)/bagilListe.o
dosya.o:
	$(CC) -I $(INCL) -c $(SRC)/dosya.cpp -o $(LIB)/dosya.o
dugum.o:
	$(CC) -I $(INCL) -c $(SRC)/dugum.cpp -o $(LIB)/dugum.o
gezici.o:
	$(CC) -I $(INCL) -c $(SRC)/gezici.cpp -o $(LIB)/gezici.o
hata.o:
	$(CC) -I $(INCL) -c $(SRC)/hata.cpp -o $(LIB)/hata.o
ikiliHeap.o:
	$(CC) -I $(INCL) -c $(SRC)/ikiliHeap.cpp -o $(LIB)/ikiliHeap.o
islem.o:
	$(CC) -I $(INCL) -c $(SRC)/islem.cpp -o $(LIB)/islem.o
konsol.o:
	$(CC) -I $(INCL) -c $(SRC)/konsol.cpp -o $(LIB)/konsol.o
sayi.o:
	$(CC) -I $(INCL) -c $(SRC)/sayi.cpp -o $(LIB)/sayi.o
	
clear:
	DEL "$(BIN)\$(EXE).exe"
	DEL "$(LIB)\*.o"