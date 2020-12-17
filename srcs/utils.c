/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 09:15:17 by agutierr          #+#    #+#             */
/*   Updated: 2020/12/17 13:47:14 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

char			*change_char(char *line, char a, char b)
{
	int			i;

	i = 0;
	while (line[i])
	{
		if (line[i] == a)
			line[i] = b;
		i++;
	}
	return (line);
}

void			error_xpm(char *final)
{
	if ((final[ft_strlen(final) - 1] != 'm') &&
	(final[ft_strlen(final) - 2] != 'p') &&
	(final[ft_strlen(final) - 3] != 'x') &&
	(final[ft_strlen(final) - 4] != '.'))
		print_err("Formato de texturas incorrecto.");
}
