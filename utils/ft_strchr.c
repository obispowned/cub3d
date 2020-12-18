/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:28:06 by agutierr          #+#    #+#             */
/*   Updated: 2020/12/18 11:28:09 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/utils.h"

char		*ft_strchr(const char *s, int c)
{
	char	*sc;

	sc = (char *)s;
	while (*sc && *sc != (char)c)
		sc++;
	return ((*sc == (char)c) ? sc : 0);
}
