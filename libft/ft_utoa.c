/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:49:41 by jfrancis          #+#    #+#             */
/*   Updated: 2021/05/12 21:53:25 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_utoa(unsigned int n)
{
	char			*s;
	unsigned int	number;
	unsigned		number_size;

	number = n;
	number_size = num_size(number);
	if (!(s = (char*)malloc(number_size + 1 * sizeof(char))))
		return (NULL);
	if (n == 0)
		s[0] = '0';
	s[number_size] = '\0';
	while (number > 0)
	{
		s[number_size - 1] = number % 10 + '0';
		number = number / 10;
		number_size--;
	}
	free(s);
	return (s);
}
