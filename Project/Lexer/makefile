# makefile
#
# build lex.yy.c as well as an executable "test"
#
# author: Huizhe Li, Master Student, Dartmouth College



TARGET = scan
LEXER = lex.yy.c
CC = gcc
SOURCE = C57.l
FLEX = flex

target: $(TARGET)

$(TARGET): main.o lexer.o
	@$(CC) -o $(TARGET) main.o lexer.o -lfl

main.o: main.c token.h
	@$(CC) -o main.o -c main.c 

lexer.o: $(LEXER) token.h
	@$(CC) -o lexer.o -c $(LEXER)

$(LEXER): $(SOURCE)
	@$(FLEX) C57.l

.PHONY: clean

clean: 
	@-rm -f  main.o lexer.o $(TARGET) $(LEXER)

