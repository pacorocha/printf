/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:49:41 by jfrancis          #+#    #+#             */
/*   Updated: 2021/05/06 19:41:47 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_utoa(unsigned int n)
{
	char			*s;
	size_t			number_size;

	number_size = num_size(n);
	if (n > 0)
		number_size--;
	if (!(s = (char*)malloc(number_size + 1 * sizeof(char))))
		return (NULL);
	if (n == 0)
		s[0] = '0';
	s[number_size + 1] = '\0';
	while (n > 0)
	{
		s[number_size - 1] = n % 10 + '0';
		n = n / 10;
		number_size--;
	}
	return (s);
}
