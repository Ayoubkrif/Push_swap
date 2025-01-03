/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:33:21 by aykrifa           #+#    #+#             */
/*   Updated: 2024/12/11 10:09:02 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

# ifndef TRUE
#  define TRUE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <string.h>
# include<stdio.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_substrf(char *s, unsigned int start, size_t len);
char	*ft_strjoinf(char *s1, char const *s2);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
/*static variable*/
