CC=gcc

main: main.o BBS.o
	$(CC) -o BBS main.o BBS.o -lssl -lcrypto


clean:
	rm *.o BBS 
