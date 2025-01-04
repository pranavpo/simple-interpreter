Final.exe:token.o lexer.o interpreter.o main.o
	gcc token.o lexer.o interpreter.o main.o -o Final

token.o: token.c token.h
	gcc -c token.c -o token.o

lexer.o: lexer.c lexer.h
	gcc -c lexer.c -o lexer.o

interpreter.o: interpreter.c interpreter.h
	gcc -c interpreter	.c -o interpreter.o

main.o: main.c
	gcc -c main.c -o main.o

