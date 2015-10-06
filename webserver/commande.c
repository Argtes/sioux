#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


	int my_strcmp(const char *s1, const char *s2, int n){

	char *p1= (char*) s1;
	char *p2= (char*) s2;
	int count=0;

	while(count!=n){

		if(*p1<*p2){
			return -1;
		}

		if(*p1>*p2){
			return 1;
		}

		p1++; p2++; count++;
	}	
	return 0;
}