# main.c
#
# build the parser program "parse" for C57 language
#
# author: Huizhe Li, Master Student, Dartmouth College
#


LANGUAGE = C57
TARGET = parse
FLEX_SOURCE = $(LANGUAGE).l
BISON_SOURCE = $(LANGUAGE).y

CC = gcc
FLEX = flex
BISON = bison





target: $(TARGET)

$(TARGET): main.o $(TARGET).o lex.yy.o err.yy.o
	@$(CC) -o $(TARGET) main.o $(TARGET).o lex.yy.o err.yy.o -lfl

main.o: main.c
	@$(CC) -o main.o -c main.c

$(TARGET).o: $(LANGUAGE).tab.c
	@$(CC) -o $(TARGET).o -c $(LANGUAGE).tab.c

lex.yy.o: lex.yy.c
	@$(CC) -o lex.yy.o -c lex.yy.c

err.yy.o: err.yy.c
	@$(CC) -o err.yy.o -c err.yy.c

lex.yy.c: $(FLEX_SOURCE) 
	@$(FLEX) $(FLEX_SOURCE)

$(LANGUAGE).tab.c: $(BISON_SOURCE)
	@$(BISON) -d $(BISON_SOURCE)

clean:
	@rm -f err.yy.o lex.yy.o $(TARGET).o main.o $(TARGET) $(LANGUAGE).tab.c $(LANGUAGE).tab.h lex.yy.c
