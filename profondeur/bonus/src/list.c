/*
** list.c for list.c in /home/cheval_8/rendu/dante/profondeur
**
** Made by Nicolas Chevalier
** Login   <cheval_8@epitech.net>
**
** Started on  Thu May  5 22:05:12 2016 Nicolas Chevalier
** Last update Sat May 21 08:09:29 2016 Nicolas Chevalier
*/

#include "my.h"

void		pile_push(t_pile **list, int x, int y)
{
  t_pile	*tmp;

  if ((tmp = malloc(sizeof(t_pile))) == NULL)
    exit (0);
  if (tmp != NULL)
    {
      tmp->x = x;
      tmp->y = y;
      tmp->prev = (*list);
      (*list)  = tmp;
    }
}

void		pile_pop(t_pile **list)
{
  t_pile	*tmp;

  if (list != NULL)
    {
      tmp = (*list)->prev;
      free(*list);
      (*list) = NULL;
      (*list) = tmp;
    }
}
