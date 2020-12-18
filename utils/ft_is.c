/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 08:53:07 by agutierr          #+#    #+#             */
/*   Updated: 2020/12/18 09:18:45 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/utils.h"

int			ft_isdigit(char *str)
{
	int		i;
	int		x;

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
	return (x);
}

char		*give_me_digit_without_spaces(char *str)
{
	int		i;
	int		x;
	char	*finally;

	i = 0;
	x = 0;
	if (!(finally = ft_calloc(ft_strlen(str), 1)))
		return (NULL);
	while (str[i])
	{
		if ((str[i] != ' ' && str[i] != '\t') && (str[i] < '0' || str[i] > '9'))
			return ("FAIL");
		i++;
	}
	i = 0;
	while (str[i++])
		if (str[i] <= '9' && str[i] >= '0')
			finally[x++] = str[i];
	return (finally);
}
