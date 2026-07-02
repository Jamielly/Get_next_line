/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamsilva <jamsilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:20:35 by jamsilva          #+#    #+#             */
/*   Updated: 2026/06/23 12:28:52 by jamsilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	check_newline(char	*s)
{
	if (!s)
		return (0);
	while (*s)
		if (*s++ == '\n')
			return (1);
	return (0);
}

static	char	*empty_str(void)
{
	char	*s;

	s = malloc(1);
	if (!s)
		return (NULL);
	s[0] = '\n';
	return (s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int					i;
	int					j;
	char				*res;

	j = 0;
	if (!s1)
		s1 = empty_str();
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}

char	*clean_stash(char	*stash)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = malloc(ft_strlen(stash) - i + 1);
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	i++;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}
