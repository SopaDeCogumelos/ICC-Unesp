/* main.c
*	LISTA 3 ICC
*
* Prof: 	Erica
* Autor:	Luis Felipe Marcon Brunhara
*
*/

#include "main.h"


int main(void) {
	
	setlocale(LC_CTYPE, "");
	
	printf(BOLD() SFGC(0) SBGC(15));
	printf("Debug0\n");
	printf(RESET);
	return 0;
}
