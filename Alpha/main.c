#include "main.h"

int modoLSD(void){
	while (1){
		for (int i=0; i < 256; i++){
			printf(BG"%dm\n", i);
			/*printf(FG"%dm", i);
			printf("\n"
				"                          __    _" 					"\n"                                   
				"                    _wr^^        ^-q__"    				"\n"                         
				"                 _dP                 9m_"  				"\n"
				"               _#P                     9#_"         			"\n"               
				"              d#@                       9#m"           		"\n"            
				"             d##                         ###"        			"\n"              
				"            J###                         ###L"      			"\n"               
				"            {###K                       J###K"     			"\n"                
				"            ]####K      ___aaa___      J####F"    			"\n"                 
				"        __gmM######_  w#P^^   ^^9#m  _d#####Mmw__"  			"\n"               
				"     _g##############mZ_         __g##############m_"    		"\n"           
				"   _d####M@PPPP@@M#######Mmp gm#########@@PPP9@M####m_"       		"\n"     
				"  a###^^          ,Z^#####@^ '######^|g          ^^M##m"    		"\n"       
				" J#@^             0L  ^*##     ##@^  J#              *#K"     		"\n"     
				" #^               `#    ^_gmwgm_~    dF               `#_" 		"\n"        
				"7F                 ^#_   ]#####F   _dK                 JE"     	"\n"    
				"]                    *m__ ##### __g@^                   F"      	"\n"   
				"                       ^PJ#####LP^                       "     	"\n"   
				" `                       0######_                      ' "   		"\n"      
				"                       _0########_                       "    		"\n"       
				"     .               _d#####^#####m__              ,     "   		"\n"     
				"      ^*w_________am#####P^   ~9#####mw_________w*^      "		"\n"           
				"          ^^9@#####@M^^           ^^P@#####@M^^^	"		"\n"
			);*/
		}
	}
	printf(RESET LIMPA);
	return 0;
}

/* Menu principal de Selção de programas */
int main(void) {
	/* Define variaveis de Debug	
	*	error 	-> variavel que recebe o return das chamadas de função
	*	pError	-> mesmo de error, porem para ponteiros
	*	input	-> variavel para seleção de programa
	*/
	uint8_t 	error 	= 0;
	uint8_t* 	pError 	= &error;
	uint8_t 	input 	= 0;
	
	/* Define idioma escrito para PT-Br */
	setlocale(LC_CTYPE, "");
	
	while(1){
		printf(	
		CAZUL	"===================================================="	"\n"	
		CBRAN	"        Selecione o programa a ser executado"		"\n"
		CAZUL	"===================================================="	"\n"
		CBRAN	" 1- helloWorld - 	Printa Hello World!"		"\n"
			" 2- Prog2 - 		Printa exemplos de variaveis"	"\n"
			" 3- Prog3 - 		Lê nome e idade e printa"	"\n"
			" 4- Prog4 - 		Nulo Positivo Negativo"		"\n"
			" 5- Prog5 - 		Calcula f(x)"			"\n"
			" 6- Prog6 - 		Maior ou menor de idade"	"\n"
			" 7- Senha - 		Testa input de senha"		"\n"
			" 8- Média - 		Calcula média de 3 números"	"\n"
			" 9- Compara String - 	Compara o tamanho de strings"	"\n"
			" 10-Tarefas - 		Bloco de Tarefas"		"\n"
			" 11-Média de números Positivos"			"\n"
			" 12-Imprime uma sequêcia a partir de N"		"\n"
			" 13-Modo LSD"						"\n"
			" 0-Exit"						"\n"
		CAZUL	"===================================================="	"\n"
		RESET);
		
		//printf("Debug: error = %d pError = %d->%d\n", error, pError, *pError);
		
		error = scanf("%d",&input);
		printf(LIMPA);
		
		if (input == 0) 		exit(0);
		if (input == 1) 	error = mainHelloWorld();
		if (input == 2) 	error = prog2main();
		if (input == 3) 	error = prog3main();
		if (input == 4) 	error = prog4main();
		if (input == 5) 	error = prog5main();
		if (input == 6) 	error = prog6main();
		if (input == 7) 	error = senhaMain();
		if (input == 8) 	error = med10main();
		if (input == 9) 	error = stringCompare();
		if (input == 10) 	error = tarefasMain();
		if (input == 11) 	error = mediaLoopMain();
		if (input == 12) 	error = sequenciaN();
		if (input == 13) 	error = modoLSD();

		printf("\nPressione qualquer tecla para continuar...\n");
		pError = gets(&input); pError = gets(&input);
		printf(LIMPA);
	}
	
	return 0;
}
