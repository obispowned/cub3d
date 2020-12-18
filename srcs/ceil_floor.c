/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceil_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 09:21:34 by agutierr          #+#    #+#             */
/*   Updated: 2020/12/18 11:22:21 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

t_config		check_ceil_floor(char *line, t_config config)
{
	char		**splitter;
	char		conmut;

	if ((line[config.i] == 'C' && config.ceil[0] != -1) ||
	(line[config.i] == 'F' && config.floor[0] != -1))
		print_err("Duplicados los valores de ceil/floor");
	conmut = line[config.i];
	check_ceil_floor2(line);
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

void			check_ceil_floor2(char *line)
{
	int			i;

	i = 0;
	while (line[i] != '\0')
	{
		while (line[i] == ' ')
			i++;
		if ((line[i] == ',' && (line[i - 1] < '0' || line[i - 1] > '9')) ||
		(line[i] == ',' && (line[i + 1] < '0' || line[i + 1] > '9')))
			print_err("Ceil/Floor debe tener el formato: 'x,x,x'");
		i++;
	}
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
