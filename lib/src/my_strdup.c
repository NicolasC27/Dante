/*
** my_strdup.c for my_strdup.c in /home/cheval_8/rendu/CPE_2015_lemin/src
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Fri Apr 15 17:56:35 2016 Chevalier Nicolas
** Last update Sun Apr 17 03:20:39 2016 Chevalier Nicolas
*/

#include "lib.h"

char		*my_strdup(char *str)
{
  char		*tmp;
  int		i;

  if ((tmp = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  i = 0;
  while (str[i])
    {
      tmp[i] = str[i];
      i += 1;
    }
  tmp[i] = '\0';
  return (tmp);
}
