/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 13:35:33 by agutierr          #+#    #+#             */
/*   Updated: 2020/12/18 13:35:36 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/utils.h"

int							ft_atoi(const char *str)
{
	unsigned long long int	num;
	int						sign;
	int						i;

	sign = 1;
	i = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == '\f') || (str[i] == '\r') || (str[i] == '\n'))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	num = 0;
	while (str[i] >= 48 && str[i] <= 57 && str[i] != '\0')
	{
		if (num < 9223372036854775807)
			num = num * 10 + str[i++] - 48;
		else
			return (sign == 1 ? -1 : 0);
	}
	return (sign * num);
}
