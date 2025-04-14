#define	ANSI_ESCAPE_MACROS_H

#define	CSI		"\e["
#define	VARN(n)		#n
#define VARM(m)		#m
#define CUP(n,m)	(CSI VARN(n)";" VARM(m)"H")
#define	ED(n)		(CSI VARN(n)"J")

#define	RESET		CSI"0m"
#define	BOLD		CSI"1m"
#define FEINT		CSI"2m"
#define	ITALIC		CSI"3m"
#define	UNDERLINE	CSI"4m"
#define	SLOWBLINK	CSI"5m"
#define	RAPIDBLINK	CSI"6m"
#define	CROSSED		CSI"9m"
#define	SUPERSCRIPT	CSI"73m"
#define	SUBSCRIPT	CSI"74m"

#define	SFGC(n)		(CSI "38:5:" VARN(n)"m")
#define	SBGC(n)		(CSI "48:5:" VARN(n)"m")

