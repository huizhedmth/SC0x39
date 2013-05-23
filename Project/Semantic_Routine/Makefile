# Makefile
#
# 05/19/2013
#
# Builds an executable that parses an input file as well as 
# generates a symbol table and does type checking
#
# by Huizhe Li, Master Student, Dartmouth College



TARGET = typecheck
LEXER = lex.yy.c
CC = gcc
SOURCE = C57.l
FLEX = flex
BISON = bison

target: $(TARGET)

$(TARGET): main.o  parser.o lexer.o ast.o symtab.o typecheck.o
	@$(CC) -o $(TARGET) main.o lexer.o parser.o ast.o symtab.o typecheck.o -lfl

typecheck.o: typecheck.c
	@$(CC) -o typecheck.o -c typecheck.c

symtab.o: symtab.c
	@$(CC) -o symtab.o -c symtab.c

ast.o:	ast.c
	@$(CC) -o ast.o -c ast.c

main.o: main.c 
	@$(CC) -o main.o -c main.c 

lexer.o: $(LEXER) 
	@$(CC) -o lexer.o -c $(LEXER)

parser.o: C57.tab.c
	@$(CC) -o parser.o -c C57.tab.c

$(LEXER): $(SOURCE)
	@$(FLEX) C57.l

C57.tab.c: C57.y
	@$(BISON) -d C57.y

.PHONY: clean

clean: 
	@-rm -f  main.o lexer.o parser.o C57.tab.c C57.tab.h symtab.o typecheck.o $(TARGET) $(LEXER)
