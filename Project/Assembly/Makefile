# Makefile
#
# 05/24/2013
#
# Builds an executable that parses an input file as well as 
# generates a symbol table and does type checking
#
# by Huizhe Li, Master Student, Dartmouth College



TARGET = driver
LEXER = lex.yy.c
CC = gcc
SOURCE = C57.l
FLEX = flex
BISON = bison
CFLAG = -w

target: $(TARGET) 

$(TARGET): driver.o  parser.o lexer.o ast.o symtab.o typecheck.o address.o quad.o
	@$(CC) $(CFLAG) -o $(TARGET) driver.o lexer.o parser.o ast.o symtab.o address.o typecheck.o quad.o -lfl

test_quad.o: test_quad.c
	@$(CC) $(CFLAG) -o test_quad.o -c test_quad.c

quad.o:	quad.c
	@$(CC) $(CFLAG) -o quad.o -c quad.c 

address.o: address.c
	@$(CC) $(CFLAG) -o address.o -c address.c

typecheck.o: typecheck.c
	@$(CC) $(CFLAG) -o typecheck.o -c typecheck.c

symtab.o: symtab.c
	@$(CC) $(CFLAG) -o symtab.o -c symtab.c

ast.o:	ast.c
	@$(CC) $(CFLAG) -o ast.o -c ast.c

driver.o: driver.c
	@$(CC) $(CFLAG) -o driver.o -c driver.c 

lexer.o: $(LEXER) 
	@$(CC) $(CFLAG) -o lexer.o -c $(LEXER)

parser.o: C57.tab.c
	@$(CC) $(CFLAG) -o parser.o -c C57.tab.c

$(LEXER): $(SOURCE)
	@$(FLEX) C57.l

C57.tab.c: C57.y
	@$(BISON) -d C57.y

.PHONY: clean

clean: 
	@-rm -f  driver.o lexer.o parser.o ast.o C57.tab.c C57.tab.h symtab.o typecheck.o address.o quad.o $(TARGET) $(LEXER)
	@-rm -f C57.output
