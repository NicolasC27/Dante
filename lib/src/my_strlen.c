/*
** my_strlen.c for my_strlen.c in /home/cheval_8/rendu/PSU_2015_minitalk/lib
**
** Made by Nicolas Chevalier
** Login   <cheval_8@epitech.net>
**
** Started on  Sat Feb  6 16:56:38 2016 Nicolas Chevalier
** Last update Mon May  2 11:46:07 2016 Nicolas Chevalier
*/

#include	"lib.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  if (str == NULL)
    return (0);
  while (*str && str[i++]);
  return (i);
}
