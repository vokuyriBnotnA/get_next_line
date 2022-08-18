/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:58:04 by klemongr          #+#    #+#             */
/*   Updated: 2021/11/14 18:12:38 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s[i])
	{
		while (s[i])
			i++;
	}
	return (i);
}

char	*ft_strdup(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = 0;
	if (s1[0] != 0)
		free(s1);
	return (res);
}

char	*get_last_line(char *s, int i, char *res)
{
	if (s[0] != 0 && BUFFER_SIZE > 0)
	{
		s[i] = 0;
		res = ft_strdup(res, s);
		s[0] = 0;
		return (res);
	}
	return (NULL);
}
