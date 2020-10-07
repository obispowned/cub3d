#include "cub3d.h"

int		my_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return(i);
}

char	*my_strjoin(char *str, char c)
{
	char 	*finally;
	int		i;

	i = 0;
	if (!(finally = (char *)malloc((sizeof(char *)) * my_strlen(str)) + 2))
	{
		printf("ERROR: malloc my_strjoin ha fallado");
		exit(-1);
	}
	while (str[i] != '\0')
	{
		finally[i] = str[i];
		i++;
	}
	finally[i] = c;
	finally[i+1] = '\0';
	str = NULL;
	return(finally);
}

char *my_strdup(char *str)
{
	char *finally;
	int	i;

	i = 0;
	if (!(finally = (char *)malloc((sizeof(char *)) * my_strlen(str)) + 1))
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
