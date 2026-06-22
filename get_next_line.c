/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamsilva <jamsilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:41:05 by jamsilva          #+#    #+#             */
/*   Updated: 2026/06/22 13:41:05 by jamsilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *get_next_line(int fd)
{
    static t_list *list;
    char    *next_line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
        return (NULL);

    create_list(&list, fd);

    if (list == NULL)
        return (NULL);

    next_line = get_line(list);
    polish_list(&list);
    return (next_line);
}
