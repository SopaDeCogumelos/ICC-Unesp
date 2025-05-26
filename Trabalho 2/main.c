/*
*	Trabalho 2
*	Luis Felipe Marcon Brunhara
*	
*/

/* BEGIN Std Includes */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <stdint.h>
/* END Std Includes */

/* BEGIN User Includes */
#include "esc_macros.h"
/* END User Includes */

/* BEGIN Macros */

/* END Macros */

/* BEGIN Typedefs */

/* END Typedefs */

/* BEGIN Global Vars */

/* END Global Vars*/

/* BEGIN Main */
int main(void) {
	/* BEGIN Localizacao pt-BR */
	#ifdef _WIN32
	if (setlocale(LC_CTYPE, "Portuguese_Brazil.1252") == NULL) {
		fprintf(stderr, "Falha ao definir locale Portuguese_Brazil.1252\n");
		return EXIT_FAILURE;
	}
	#else
	if (setlocale(LC_CTYPE, "pt_BR.UTF-8") == NULL) {
		fprintf(stderr, "Falha ao definir locale pt_BR.UTF-8\n");
		return EXIT_FAILURE;
	}
	#endif
	/* END Localizacao pt-BR */
	
	/* BEGIN Variaveis main */
	unsigned short int	menuIn;
	unsigned short int	returnVar;
	char ch_buf;
	/* END Variaveis main */
	
	/* BEGIN main block 0 */
	/* END main block 0 */
	
	/* BEGIN main loop */
	while (1){
		
		printf("\nPressione qualquer tecla para continuar...\n");
		GETCH();
	}	
	/* END main loop*/
	
	/* BEGIN main block 1 */
	
	/* END main block 1 */
	
	return 0;
}
/* END Main */
