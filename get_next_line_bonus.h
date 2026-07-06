/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamsilva <jamsilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 11:20:42 by jamsilva          #+#    #+#             */
/*   Updated: 2026/07/06 13:56:11 by jamsilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef  BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef  FD_MAX
#  define FD_MAX 1024
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

int		ft_strlen(const char *str);
int		check_newline(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*extract_line(char *stash);
char	*clean_stash(char *stash);
char	*fill_stash(int fd, char *stash);

#endif