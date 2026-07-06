/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamsilva <jamsilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:20:35 by jamsilva          #+#    #+#             */
/*   Updated: 2026/07/06 14:11:30 by jamsilva         ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*rest;
	size_t	i;
	size_t	j;

	if (!s2)
		return (0);
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	rest = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!rest)
	{
		free (s1);
		return (0);
	}
	i = 0;
	j = i;
	while (s1[i] != '\0')
		rest[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		rest[j++] = s2[i++];
	rest[j] = '\0';
	free(s1);
	return (rest);
}

//char	*ft_strjoin(char *s1, char *s2)
//{
//	size_t					i;
//	size_t					j;
//	char				*rest;
//
//	j = 0;
//	if (!s1)
//		s1 = empty_str();
//	rest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
////	if (!s1)
////		return (NULL);
//	i = 0;
//	if (!rest)
//		return (NULL);
//	while (s1[i])
//	{
//		rest[i] = s1[i];
//		i++;
//	}
//	while (s2[j])
//		rest[i++] = s2[j++];
//	rest[i] = '\0';
//	free(s1);
//	return (rest);
//}
