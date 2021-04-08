/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 18:22:20 by jfrancis          #+#    #+#             */
/*   Updated: 2021/02/25 18:12:26 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t			wc;
	unsigned int	i;
	int				temp;

	wc = 0;
	i = 0;
	temp = 0;
	if (!s)
		return (wc);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			temp = 1;
		if (s[i] != c && temp == 0)
		{
			wc++;
			temp = 1;
		}
		else if (s[i] == c && temp == 1)
		{
			temp = 0;
		}
		i++;
	}
	return (wc);
}

int				ln(char *s, int i, char c)
{
	int count;

	count = 0;
	while (s[i] != c && s[i])
	{
		count++;
		i++;
	}
	return (count);
}

char			**ft_split(char const *s, char c)
{
	char	**s_array;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!s || !(s_array = malloc(sizeof(char*) * (count_words(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			k = 0;
			if (!(s_array[j] = malloc(sizeof(char) * ln((char *)s, i, c) + 1)))
				return (NULL);
			while (s[i] != c && s[i])
				s_array[j][k++] = s[i++];
			s_array[j++][k] = '\0';
		}
	}
	s_array[j] = NULL;
	return (s_array);
}
