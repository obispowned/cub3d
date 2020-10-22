#include "../header/utils.h"

int  ft_isdigit(char *str)
{	//Devuelve 1 si el string es todo numeros, devuelve 0 si hay algun caracter que no sea numero, devuelve -1 en caso de error.
	int i;
	int x;

	i = 0;
	x = 1;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if ((str[i] > '9') || (str[i] < '0'))
			x = 0;
		i++;
	}
	return(x);
}
