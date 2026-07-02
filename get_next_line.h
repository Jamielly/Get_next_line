/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamsilva <jamsilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:20:56 by jamsilva          #+#    #+#             */
/*   Updated: 2026/06/23 10:20:50 by jamsilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

char	*fill_stash(int fd, char *stash);
int		ft_strlen(const char *str);
int		check_newline(char	*s);
char	*ft_strjoin(char *s1, char *s2);
char	*extract_line(char	*stash);
char	*clean_stash(char	*stash);

#endif