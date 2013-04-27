/*
 * idt.c
 *
 * identifier table implementation 
 *
 * By Huizhe Li, Master Student, Dartmouth College
 *
 */

#include "idt.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* allocate memory */
void init_table(ID_table **table)
{
	ID_table* tmp = (ID_table*)malloc(sizeof(ID_table));
	tmp->max_size = INIT_TABLE_SIZE;	
	tmp->size	= 0;
	tmp->ids = (char**)malloc(sizeof(char*)*tmp->max_size);
	*table = tmp;
}

/* append given id into id table */
char* add_id(ID_table *table, char* new_id)
{
	if (table->size < table->max_size)
		table->ids[table->size++] = strdup(new_id);
	else{	// table full, double its size
		table->max_size = 2*table->max_size;
		char** temp = (char**)malloc(sizeof(char*)*table->max_size);
		int i;
		for (i = 0; i < table->size; i++)
			temp[i] = table->ids[i];
		free(table->ids);
		table->ids = temp;

		table->ids[table->size++] = strdup(new_id);
	}
	return table->ids[table->size-1];
}

/* retrieve the pointer to the given id from the id table */
char* retrieve_id(ID_table *table, char* id)
{
	int i;
	for (i = 0; i < table->size; i++){
		if (strcmp(table->ids[i], id)==0)
			return table->ids[i];
	}
	/* id not in table, append this id into table  */
	return add_id(table, id);
}
