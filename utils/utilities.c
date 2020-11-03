#include "../header/utils.h"

void		ace(char *str, ...)
{	//FUNCION PARA LIBERAR TODOS LOS CHAR * PREVIAMENTE ALOCADOS. IMPORTANTE!! ULTIMO PARAMETRO NULL
	va_list	ap;

	va_start(ap, str);
	kill(str);
	while((str = va_arg(ap, char * )))
		kill(str);
	va_end(ap);
}

void		kill(char *str)
{
	free(str);
	str = NULL;
}

void		double_kill(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		kill(str[i]);
		i++;
	}
	free(str);
}

int 		what_is_higher(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int		white_spaces(char c)
{ //devuelve 1 si es espacio o tabulador
	if (c == ' ' || c == '\t')
		return (1);
	return (0);	
}

void 		print_error(char *str)
{
	printf("ERROR: %s\n", str);
	exit(-1);
}

