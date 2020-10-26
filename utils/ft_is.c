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

char  *give_me_digit_without_spaces(char *str)
{	//Devuelve 1 si el string es todo numeros, devuelve 0 si hay algun caracter que no sea numero, devuelve -1 en caso de error.
	int i;
	int x;
	char *finally;

	i = 0;
	x = 0;
	if(!(finally = calloc(ft_strlen(str), 1)))
		return(NULL);
	while (str[i++])
		if(str[i] != ' ' && (str[i] < 0 || str[i] > 9))
			return ("FAIL");
	i = 0;
	while(str[i++])
		if(str[i] <= 9 && str[i] >= 0)
			finally[x++] = str[i];
	return(finally);
}