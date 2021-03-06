/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:50:35 by leda-sil          #+#    #+#             */
/*   Updated: 2022/05/20 22:02:28 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	root;

	root = 1;
	while (nb / root >= root)
	{
		if (root * root == nb)
			return (root);
		root++;
	}
	return (0);
}
