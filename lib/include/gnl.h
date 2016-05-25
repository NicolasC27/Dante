/*
** gnl.h for gnl.h in /home/cheval_8/rendu/dante/generateur
**
** Made by Nicolas Chevalier
** Login   <cheval_8@epitech.net>
**
** Started on  Fri May 20 03:44:32 2016 Nicolas Chevalier
** Last update Fri May 20 03:44:36 2016 Nicolas Chevalier
*/

#ifndef GNL_H_
# define GNL_H_

/*
** Includes
*/
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

/*
** Define
*/
# define BUFF_SIZE	4096

/*
** Get_next_line.c
*/
char		*get_next_line(const int);

/*
** my_strlen.c
*/
int		my_strlen(char *);

/*
** my_realloc.c
*/
char		*my_realloc(char *, int);

/*
** my_memset.c
*/
void		*my_memset(void *, int, int);

#endif /* !GNL_H_ */
