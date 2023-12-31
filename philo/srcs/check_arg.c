/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:26:21 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/20 16:58:07 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

bool	check_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i] == NULL)
			return (false);
		if (argv[i][0] == '\0')
			return (false);
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) == false)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	if (str == NULL)
		return (-1);
	if (str[i] < '0' && str[i] > '9')
		return (-1);
	while (str[i] != '\0' && '0' <= str[i] && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
		if (result > INT_MAX)
			return (-1);
	}
	return ((int)result);
}

bool	check_arg_value(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argv == NULL)
		return (false);
	while (i < argc)
	{
		if (ft_atoi(argv[i]) < 0)
			return (false);
		i++;
	}
	return (true);
}
