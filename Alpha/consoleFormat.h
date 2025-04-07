#ifndef	CONSOLEFORMAT_H
#define CONSOLEFORMAT_H

/* Seção que define macros para formatação de texto do terminal
*	RESET	-> Remove formatação
*	BOLD	-> Negrito
*	ITAL	-> Italico
*	FG	-> Muda a cor do texto
*	BG	-> Muda a cor do fundo
*	LIMPA	-> Limpa a tela
*/
#define RESET	"\e[0m"
#define	BOLD 	"\e[1m"
#define	ITAL	"\e[3m"
#define	FG	"\e[38:5:"
#define	BG	"\e[48:5:"
#define LIMPA	"\e[1;1H\e[2J"

/* Macros de cor */
#define CBRAN	FG"7m"
#define CCINZ	FG"8m"
#define	CVERM	FG"9m"
#define	CVERD	FG"10m"
#define	CAMAR	FG"11m"
#define CAZUL	FG"12m"

#endif
