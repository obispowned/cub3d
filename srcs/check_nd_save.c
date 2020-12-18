/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nd_save.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 08:32:54 by agutierr          #+#    #+#             */
/*   Updated: 2020/12/18 11:22:40 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

t_config		check_r(char *line, t_config config)
{
	char		**splitter;

	line = change_char(line, '\t', ' ');
	splitter = ft_split(line, ' ');
	if (config.height != -1 || config.width != -1)
		print_err("Resolucion duplicada");
	if ((splitter[3]) || (ft_isdigit(splitter[1]) != 1)
	|| (ft_isdigit(splitter[2]) != 1))
		print_err("Formato de Resolucion incorrecto.");
	config.width = atoi(splitter[1]);
	config.height = atoi(splitter[2]);
	config.flag += 1;
	double_kill(splitter);
	return (config);
}

t_config		check_path(char *line, t_config config)
{
	if ((line[0] == 'N') && (line[1] == 'O')
	&& (white_spaces(line[config.i + 2]) == 1) && (!config.no))
		config.no = give_me_a_path(line, 0);
	else if ((line[0] == 'S') && (line[1] == 'O')
	&& (white_spaces(line[2])) && (!config.so))
		config.so = give_me_a_path(line, 0);
	else if ((line[0] == 'W') && (line[1] == 'E')
	&& (white_spaces(line[2])) && (!config.we))
		config.we = give_me_a_path(line, 0);
	else if ((line[0] == 'E') && (line[1] == 'A')
	&& (white_spaces(line[2])) && (!config.ea))
		config.ea = give_me_a_path(line, 0);
	else if ((line[0] == 'S') &&
	(white_spaces(line[1])) && (!config.s))
		config.s = give_me_a_path(line, 0);
	else
		print_err("Formato de texturas incorrecto.");
	config.flag += 1;
	return (config);
}

char			*give_me_a_path(char *line, int i)
{
	char		*final;
	int			j;

	j = 0;
	final = ft_calloc(ft_strlen(line), 1);
	while (line[i])
	{
		if ((line[i] == '.') && (line[i + 1] == '/'))
		{
			while ((line[i]))
			{
				final[j] = line[i];
				j++;
				i++;
			}
		}
		if (line[i])
			i++;
	}
	final[i] = '\0';
	error_xpm(final);
	return (final);
}
