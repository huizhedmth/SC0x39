/*
 * idt.h
 *
 * identifier table declaration 
 *
 * By Huizhe Li, Master Student, Dartmouth College
 *
 */

#ifndef IDT_H
#define IDT_H

#define INIT_TABLE_SIZE 1	/* easily be filled up, for testing's convenience */

/* ID table structure */
struct ID_table{
		char** ids;
		int size;
		int max_size;
};

typedef struct ID_table ID_table;

void init_table(ID_table** table);		/* allocate memory */
char* add_id(ID_table* table, char* new_id);	/* append given id into id table */
char* retrieve_id(ID_table* table, char* id);	/* retrieve the pointer to the given id from the id table */

#endif
