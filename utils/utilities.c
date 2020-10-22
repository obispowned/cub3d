#include "../header/utils.h"

void		ace(char *str, ...)
{	//FUNCION PARA LIBERAR TODOS LOS CHAR * PREVIAMENTE ALOCADOS. IMPORTANTE!! ULTIMO PARAMETRO NULL
	va_list	ap;

	va_start(ap, str);
	free(str);
	while((str = va_arg(ap, char * )))
		free(str);
	va_end(ap);
}

void		double_kill(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
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
