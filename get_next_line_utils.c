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

int ft_strlen(char *s)
{
    int i = 0;

    while (s && s[i])
        i++;
    return i;
}

static void	create_list(int fd, const char *ac)
{
	int	*buff;

	if (!fd || !ac)
		return (NULL);
	while (read(fd, buff, BUFFER_SIZE));
	char buff[BUFFER_SIZE + 1];
	buff = malloc(sizeof(int));
	free(buff);
	buff = NULL;
	return (0);
}

char *extract_line(char *stash) //pega tudo ate "\n"
{
    int     i = 0;
    char    *line;

    if (!stash || !stash[0])
        return NULL;

    while (stash[i] && stash[i] != '\n')
        i++;

    line = malloc(i + (stash[i] == '\n' ? 2 : 1));
    if (!line)
        return NULL;

    i = 0;
    while (stash[i] && stash[i] != '\n')
    {
        line[i] = stash[i];
        i++;
    }

    if (stash[i] == '\n')
        line[i++] = '\n';

    line[i] = '\0';

    return line;
}

static char *stash; // coraçao da GNL, sem isso ele nao funciona (Ele guarda o que sobrou da leitura anterior)

char *clean_stash(char *stash)
{
	int	polish_list;

	extract_line();
}

char *read_and_join(int fd, char *stash) //objetivo: acumular tudo até ter pelo menos 1 '\n'
{
    char    *buffer;
    int     bytes;

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return NULL;

    bytes = 1;
    while (!has_newline(stash) && bytes > 0)
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        if (bytes < 0)
        {
            free(buffer);
            return NULL;
        }
        buffer[bytes] = '\0';
        stash = ft_strjoin(stash, buffer);
    }

    free(buffer);
    return stash;
}

int check_newline(char *s) // checar se tem '\n'
{
    if (!s)
        return 0;

    while (*s)
    {
        if (*s == '\n')
            return 1;
        s++;
    }
    return 0;
}

char *ft_strjoin(char *s1, char *s2)
{
    int     i = 0, j = 0;
    char    *res;

    if (!s1)
    {
        s1 = malloc(1);
        s1[0] = '\0';
    }

    res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!res)
        return NULL;

    while (s1[i])
        res[i++] = s1[i - i]; // ajustaremos abaixo

		pode ser assim tbm:
//		 while (s1[i])
// 	 res[i] = s1[i++];

    i = 0;
    while (s1[i])
    {
        res[i] = s1[i];
        i++;
    }

    while (s2[j])
        res[i++] = s2[j++];

    res[i] = '\0';

    free(s1);
    return res;
}