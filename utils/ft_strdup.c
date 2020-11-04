#include "../header/utils.h"

char *ft_strdup(char *str)
{
	char *finally;
	int	i;

	i = 0;
	if (!(finally = (char *)malloc(sizeof(char) * ft_strlen(str) + 1)))
		printf("Malloc ha fallado en: ft_strdup.c");
	while (str[i] != '\0')
	{
		finally[i] = str[i];
		i++;
	}
	finally[i] = '\0';
	return(finally);
}

char *ft_strdup_sustitute_char(char *str, char now, char final, int max)
{
	char *finally;
	int i, j;

	i = 0;
	j = 0;
	if (!(finally = (char *)malloc(sizeof(char) * max + 1)))
		print_error("Malloc ha fallado en: ft_strdup.c");
	while (str[i] != '\0')
	{
		if (str[i] == '\t')
		{
			change_tabs(&finally[j], final, 8);
			j += 7;
		}
		else if (str[i] == now)
			finally[j] = final;
		else
			finally[j] = str[i];
		j++;
		i++;
	}
	while (j < max + 1)
	{
		finally[j] = '9';
		j++;
	}
	finally[j] = '\0';
	return (finally);
}

void	change_tabs(char *finally, char c, int n)
{
	int i;

	i = 0;
	while (i < n)
		finally[i++] = c;
}

/*
	char *finally;
	int	i, j;

	i = 0;
	j = 0;
	if (!(finally = (char *)malloc(sizeof(char) * max + 1)))
	{
		printf("ERROR: malloc my_strdup ha fallado");
		exit(-1);
	}
	while (str[i] != '\0')
	{
		if (str[i] == now)
			finally[j] = final;
		else if (str[i] == '\t')
		{
			finally[j++] = final;
			finally[j++] = final;
			finally[j++] = final;
			finally[j] = final;
		}
		else
			finally[j] = str[i];
		i++;
		j++;
	}
	finally[i] = '\0';
	return(finally);
*/
