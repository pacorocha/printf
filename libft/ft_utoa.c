/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:49:41 by jfrancis          #+#    #+#             */
/*   Updated: 2021/05/12 13:20:45 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_utoa(unsigned int n)
{
	char			*s;
	unsigned int	number;
	size_t			number_size;
	int	i;

	i = 0;
	number = be_positive(n);
	number_size = num_size(number);
	if (n < 0)
		i = 1;
	if (!(s = (char*)malloc(number_size + 1 + i * sizeof(char))))
		return (NULL);
	if (n < 0)
		s[0] = '-';
	else if (n == 0)
		s[0] = '0';
	s[number_size + i] = '\0';
	while (number > 0)
	{
		s[number_size - 1 + i] = number % 10 + '0';
		number = number / 10;
		number_size--;
	}
	free(s);
	return (s);
}
