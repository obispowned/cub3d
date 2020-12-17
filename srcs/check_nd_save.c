/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nd_save.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 08:32:54 by agutierr          #+#    #+#             */
/*   Updated: 2020/12/17 13:46:31 by agutierr         ###   ########.fr       */
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
	if ((line[config.i] == 'N') && (line[config.i + 1] == 'O')
	&& (white_spaces(line[config.i + 2])) && (!config.no))
		config.no = give_me_a_path(line, 0);
	else if ((line[config.i] == 'S') && (line[config.i + 1] == 'O')
	&& (white_spaces(line[config.i + 2])) && (!config.so))
		config.so = give_me_a_path(line, 0);
	else if ((line[config.i] == 'W') && (line[config.i + 1] == 'E')
	&& (white_spaces(line[config.i + 2])) && (!config.we))
		config.we = give_me_a_path(line, 0);
	else if ((line[config.i] == 'E') && (line[config.i + 1] == 'A')
	&& (white_spaces(line[config.i + 2])) && (!config.ea))
		config.ea = give_me_a_path(line, 0);
	else if ((line[config.i] == 'S') &&
	(white_spaces(line[config.i + 1])) && (!config.s))
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
	final = calloc(ft_strlen(line), 1);
	while (line[i])
	{
		if ((line[i] == '.') && (line[i + 1] == '/'))
		{
			while ((line[i]))
			{
				while (white_spaces(line[i]) == 1)
					i++;
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

t_config		check_ceil_floor(char *line, t_config config)
{
	char		**splitter;
	char		conmut;

	if ((line[config.i] == 'C' && config.ceil[0] != -1) ||
	(line[config.i] == 'F' && config.floor[0] != -1))
		print_err("Duplicados los valores de ceil/floor");
	conmut = line[config.i];
	while ((line[config.i] != '\0') && ((line[config.i] < '0')
	|| (line[config.i] > '9')))
		config.i++;
	splitter = ft_split(&line[config.i], ',');
	if (ft_isdigit(splitter[2]) != 1)
		splitter[2] = give_me_digit_without_spaces(splitter[2]);
	if ((splitter[3]) || (ft_isdigit(splitter[0]) != 1) ||
	(ft_isdigit(splitter[1]) != 1) || (ft_isdigit(splitter[2]) != 1))
		print_err("Formato de ceil/floor incorrecto.");
	check_cf(conmut, splitter, &config);
	while (line[config.i])
		config.i++;
	double_kill(splitter);
	return (config);
}

void			check_cf(char conmut, char **splitter, t_config *config)
{
	if (conmut == 'C')
	{
		config->ceil[0] = atoi(splitter[0]);
		config->ceil[1] = atoi(splitter[1]);
		config->ceil[2] = atoi(splitter[2]);
		config->flag += 1;
	}
	if (conmut == 'F')
	{
		config->floor[0] = atoi(splitter[0]);
		config->floor[1] = atoi(splitter[1]);
		config->floor[2] = atoi(splitter[2]);
		config->flag += 1;
	}
}
