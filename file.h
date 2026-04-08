#ifndef _FILE_H_
#define _FILE_H_ 
#include <stdio.h>

FILE *file_open(const char *fileName);
int file_getSize(const char *fileName);

int calculate(int a,int b){
	return a+b+1;
} 

#endif
