/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:57:15 by klemongr          #+#    #+#             */
/*   Updated: 2021/11/14 20:42:38 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	s[BUFFER_SIZE + 1];
	char		*res;
	int			i;

	i = 0;
	res = "";
	s[0] = 0;
	while (read(fd, &s[i], 1) && i <= BUFFER_SIZE && BUFFER_SIZE > 0 && fd >= 0
		&& (fd < 100 || BUFFER_SIZE < 1000) && s[i] != 0)
	{
		if ((i + 1) == BUFFER_SIZE && s[i] != '\n' && s[i] != 0)
		{
			s[i + 1] = 0;
			res = ft_strdup(res, s);
			i = -1;
		}
		if (s[i] == '\n')
		{
			s[i + 1] = 0;
			res = ft_strdup(res, s);
			return (res);
		}
		i++;
	}
	return (get_last_line(s, i, res));
}
