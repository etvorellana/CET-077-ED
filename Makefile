CC = gcc
CFLAGS = -O2 -lm -fopenmp

all: 	./bin/exemplo_00 ./bin/exemplo_01 ./bin/exemplo_02 ./bin/exemplo_03 \
		./bin/exemplo_04 ./bin/exemplo_05 ./bin/exemplo_06 ./bin/exemplo_07 \
		./bin/exemplo_08 ./bin/exemplo_09 ./bin/exemplo_10 ./bin/exemplo_11 \
		./bin/exemplo_12 ./bin/exemplo_13

run: all
	./bin/exemplo_09

./bin/exemplo_00: main_00.c ./bin/ferramentas.o
	$(CC) $(CFLAGS) -I ./include -c main_00.c -o ./bin/main_00.o
	$(CC) $(CFLAGS)  ./bin/ferramentas.o ./bin/main_00.o -o ./bin/exemplo_00

./bin/exemplo_01: main_01.c ./bin/ferramentas.o
	$(CC) $(CFLAGS) -I ./include -c main_01.c -o ./bin/main_01.o
	$(CC) $(CFLAGS)  ./bin/ferramentas.o ./bin/main_01.o -o ./bin/exemplo_01

./bin/exemplo_02: main_02.c ./bin/ferramentas.o
	$(CC) $(CFLAGS) -I ./include -c main_02.c -o ./bin/main_02.o
	$(CC) $(CFLAGS)  ./bin/ferramentas.o ./bin/main_02.o -o ./bin/exemplo_02

./bin/exemplo_03: main_03.c ./bin/ferramentas.o
	$(CC) $(CFLAGS) -I ./include -c main_03.c -o ./bin/main_03.o
	$(CC) $(CFLAGS)  ./bin/ferramentas.o ./bin/main_03.o -o ./bin/exemplo_03

./bin/exemplo_04: main_04.c ./bin/ferramentas.o
	$(CC) $(CFLAGS) -I ./include -c main_04.c -o ./bin/main_04.o
	$(CC) $(CFLAGS)  ./bin/ferramentas.o ./bin/main_04.o -o ./bin/exemplo_04

./bin/exemplo_05: main_05.c ./bin/ferramentas.o
	$(CC) $(CFLAGS) -I ./include -c main_05.c -o ./bin/main_05.o
	$(CC) $(CFLAGS)  ./bin/ferramentas.o ./bin/main_05.o -o ./bin/exemplo_05

./bin/exemplo_06: main_06.c ./bin/ferramentas.o
	$(CC) $(CFLAGS) -I ./include -c main_06.c -o ./bin/main_06.o
	$(CC) $(CFLAGS)  ./bin/ferramentas.o ./bin/main_06.o -o ./bin/exemplo_06

./bin/exemplo_07: main_07.c ./bin/ferramentas.o
	$(CC) $(CFLAGS) -I ./include -c main_07.c -o ./bin/main_07.o
	$(CC) $(CFLAGS)  ./bin/ferramentas.o ./bin/main_07.o -o ./bin/exemplo_07

./bin/exemplo_08: main_08.c ./bin/ferramentas.o
	$(CC) $(CFLAGS) -I ./include -c main_08.c -o ./bin/main_08.o
	$(CC) $(CFLAGS)  ./bin/ferramentas.o ./bin/main_08.o -o ./bin/exemplo_08

./bin/exemplo_09: main_09.c ./bin/ferramentas.o
	$(CC) $(CFLAGS) -I ./include -c main_09.c -o ./bin/main_09.o
	$(CC) $(CFLAGS)  ./bin/ferramentas.o ./bin/main_09.o -o ./bin/exemplo_09

./bin/exemplo_10: main_10.c ./bin/ferramentas.o
	$(CC) $(CFLAGS) -I ./include -c main_10.c -o ./bin/main_10.o
	$(CC) $(CFLAGS)  ./bin/ferramentas.o ./bin/main_10.o -o ./bin/exemplo_10

./bin/exemplo_11: main_11.c ./bin/ferramentas.o
	$(CC) $(CFLAGS) -I ./include -c main_11.c -o ./bin/main_11.o
	$(CC) $(CFLAGS)  ./bin/ferramentas.o ./bin/main_11.o -o ./bin/exemplo_11

./bin/exemplo_12: main_12.c ./bin/ferramentas.o
	$(CC) $(CFLAGS) -I ./include -c main_12.c -o ./bin/main_12.o
	$(CC) $(CFLAGS)  ./bin/ferramentas.o ./bin/main_12.o -o ./bin/exemplo_12

./bin/exemplo_13: main_13.c ./bin/ferramentas.o
	$(CC) $(CFLAGS) -I ./include -c main_13.c -o ./bin/main_13.o
	$(CC) $(CFLAGS)  ./bin/ferramentas.o ./bin/main_13.o -o ./bin/exemplo_13

./bin/ferramentas.o: ferramentas.c
	$(CC) $(CFLAGS) -I ./include -c ferramentas.c -o ./bin/ferramentas.o 

clean:
	rm bin/exemplo_*
	rm bin/*.o

