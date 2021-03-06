/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 03:51:22 by leda-sil          #+#    #+#             */
/*   Updated: 2022/04/23 03:31:01 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	check_base(char *str)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = ft_strlen(str);
	while (i < size - 1)
	{
		j = i + i;
		while (j < size)
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		if (str[i] == '-' || str[i] == '+'
			|| str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			return (0);
		i++;
	}
	if (str[i] == '-' || str[i] == '+'
		|| str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		return (0);
	return (size);
}

int	char_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != c)
	{
		if (base[i] == '\0')
			return (-1);
		i++;
	}
	return (i - 1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	res;
	int	size;

	i = 0;
	res = 0;
	sign = 1;
	size = check_base(base);
	if (size > 1)
	{
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		while (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				sign = -1 * sign;
			i++;
		}
		while (char_in_base(str[i], base) >= 0)
		{
			res = (res * size) + (sign * char_in_base(str[i], base));
			i++;
		}		
	}
	return (res);
}
