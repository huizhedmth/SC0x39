# author: Huizhe Li, Dartmouth College
# 
# this file builds an lexical analyzer in the form of
# an executable 'test' in the same directory, form the
# source file 'sub.l'. 
#
# the program must be provided an input file named "input"
# in the same directory in order to run.
#
# modify the following vars accordingly if your machine
# is using different configurations :)

TARGET = lexer
SOURCE = sub.l

CC = gcc
FLEX = flex

target: $(TARGET)

$(TARGET): lexer.o
	@$(CC) -o $(TARGET) lexer.o -lfl

lexer.o: lex.yy.c
	@$(CC) -o lexer.o -c lex.yy.c

lex.yy.c: $(SOURCE) 
	@$(FLEX) $(SOURCE)

clean:
	@rm -f lex.yy.c lexer.o $(TARGET)
