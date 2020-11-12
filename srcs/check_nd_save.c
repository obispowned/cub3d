/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nd_save.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 08:32:54 by agutierr          #+#    #+#             */
/*   Updated: 2020/11/12 11:14:44 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	check_R(char *line, t_config *config)
{
	char	**splitter;

	line = change_char(line, '\t', ' ');
	splitter = ft_split(line, ' ');
	if ((splitter[3]) || (ft_isdigit(splitter[1]) != 1)
	|| (ft_isdigit(splitter[2]) != 1))
		print_error("Formato de Resolucion incorrecto.");
	config->width = atoi(splitter[1]);
	config->height = atoi(splitter[2]);
	config->flag += 1;
	double_kill(splitter);
}

char		*change_char(char *line, char a, char b)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == a)
			line[i] = b;
		i++;
	}
	return (line);
}

void	check_path(char *line, t_config *config, int i)
{
	if ((line[i] == 'N') && (line[i + 1] == 'O')
	&& (white_spaces(line[i + 2])) && (!config->NO))
		config->NO = give_me_a_path(line);
	else if ((line[i] == 'S') && (line[i + 1] == 'O')
	&& (white_spaces(line[i + 2])) && (!config->SO))
		config->SO = give_me_a_path(line);
	else if ((line[i] == 'W') && (line[i + 1] == 'E')
	&& (white_spaces(line[i + 2])) && (!config->WE))
		config->WE = give_me_a_path(line);
	else if ((line[i] == 'E') && (line[i + 1] == 'A')
	&& (white_spaces(line[i + 2])) && (!config->EA))
		config->EA = give_me_a_path(line);
	else if ((line[i] == 'S') && (white_spaces(line[i + 1])) && (!config->S))
		config->S = give_me_a_path(line);
	else
		print_error("Formato de texturas incorrecto.");
	config->flag += 1;
}

char		*give_me_a_path(char *line)
{
	char	*final;
	int		i;
	int		j;

	i = 0;
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
	if ((final[ft_strlen(final) - 1] != 'm') &&
	(final[ft_strlen(final) - 2] != 'p') &&
	(final[ft_strlen(final) - 3] != 'x') &&
	(final[ft_strlen(final) - 4] != '.'))
		print_error("Formato de texturas incorrecto. La textura debe ser una: ./ruta.xmp");
	return (final);
}

void	check_ceil_floor(char *line, t_config *config, int i)
{
	char	**splitter;
	char	conmut;

	conmut = line[i]; /*para saber si lo guardaremos en config.ceil[3] o en config.floor[3]*/
	while ((line[i] != '\0') && ((line[i] < '0') || (line[i] > '9')))
		i++;
	splitter = ft_split(&line[i], ',');
	if (ft_isdigit(splitter[2]) != 1)
		splitter[2] = give_me_digit_without_spaces(splitter[2]);
	if ((splitter[3]) || (ft_isdigit(splitter[0]) != 1) ||
	(ft_isdigit(splitter[1]) != 1) || (ft_isdigit(splitter[2]) != 1))
		print_error("Formato de ceil/floor incorrecto.");
	check_ceil_floor2(conmut, splitter, config);
	while (line[i])
		i++;
	double_kill(splitter);
}

void		check_ceil_floor2(char conmut, char **splitter, t_config *config)
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



/*t_config check_path(char *line, t_config config)
{
	char **splitter;

	splitter = ft_split((const char *)line, ' ');
	if ((splitter[2]) || ((splitter[1][ft_strlen(splitter[1]) -1] != 'm') && (splitter[1][ft_strlen(splitter[1]) -2] != 'p')
	 && (splitter[1][ft_strlen(splitter[1]) -3] != 'x')  && (splitter[1][ft_strlen(splitter[1]) -4] != '.')))
		print_error("Formato de texturas incorrecto.");
	if ((line[config.i] == 'N') && (line[config.i+1] == 'O') && (line[config.i+2] == ' ') && (!config.NO))
		config.NO = ft_strdup(splitter[1]);
	else if ((line[config.i] == 'S') && (line[config.i+1] == 'O') && (line[config.i+2] == ' ') && (!config.SO))
		config.SO = ft_strdup(splitter[1]);
	else if	((line[config.i] == 'W') && (line[config.i+1] == 'E') && (line[config.i+2] == ' ') && (!config.WE))
		config.WE = ft_strdup(splitter[1]);
	else if ((line[config.i] == 'E') && (line[config.i+1] == 'A') && (line[config.i+2] == ' ') && (!config.EA))
		config.EA = ft_strdup(splitter[1]);
	else if ((line[config.i] == 'S') && (line[config.i+1] == ' ') && (!config.S))
		config.S = ft_strdup(splitter[1]);
	else
		print_error("Formato de texturas incorrecto.");
	double_kill(splitter);
	config.flag += 1;
	return (config);
}
*/