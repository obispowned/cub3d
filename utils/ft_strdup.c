#include "../header/utils.h"

char *ft_strdup(char *str)
{
	char *finally;
	int	i;

	i = 0;
	if (!(finally = (char *)malloc((sizeof(char *)) * ft_strlen(str)) + 1))
	{
		printf("ERROR: malloc my_strdup ha fallado");
		exit(-1);
	}
	while (str[i] != '\0')
	{
		finally[i] = str[i];
		i++;
	}
	finally[i] = '\0';
	return(finally);
}
