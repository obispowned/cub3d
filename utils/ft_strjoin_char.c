#include "../header/utils.h"

char	*ft_strjoin_char(char *str, char c)
{
	char 	*finally;
	int		i;

	i = 0;
	if (!(finally = (char *)malloc((sizeof(char *)) * ft_strlen(str)) + 2))
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
	return(finally);
}
