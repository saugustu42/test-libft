#include "print_output.h"

void	print_result(char *exp, char *got) //print expected-result and got-result with yellow dollar (emuleted cat -e)
{
	printf("EXP: %s%s\n", exp, DOLLAR);
	printf("GOT: %s%s\n", got, DOLLAR);

}

void	print_title(char *title) //print blue bold font text
{
		printf(MAGENTA"\n**********************************************************************\n");
		printf("%35s\n", title);
		printf("**********************************************************************\n\n"RESET);
}

void	print_tester_name()
{
	printf("\n"YELLOW" $$$$$$ $$$$$   $$$$  $$$$$$        $$     $$$$$$ $$$$$  $$$$$$ $$$$$$\n"
					"   $$   $$     $$       $$          $$       $$   $$  $$ $$       $$\n"
					"   $$   $$$$    $$$$    $$   $$$$$  $$       $$   $$$$$  $$$$     $$\n"
					"   $$   $$         $$   $$          $$       $$   $$  $$ $$       $$\n"
					"   $$   $$$$$   $$$$    $$          $$$$$$ $$$$$$ $$$$$  $$       $$\n"RESET);
}
