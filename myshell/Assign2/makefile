all : myls.o mycp.o mymv.o mygrep.o	
	gcc myls.o mycp.o mymv.o mygrep.o -lreadline -o out.o
myls.o : myls.c
	gcc -c myls.c -lreadline -o myls.o
mycp.o : mycp.c
	gcc -c mycp.c -lreadline -o mycp.o
mymv.o : mymv.c
	gcc -c mymv.c -lreadline -o mymv.o
mygrep.o :	mygrep.c
	gcc -c mygrep.c -lreadline -o mygrep.o

