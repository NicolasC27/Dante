/*
** list.c for list.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Sat Mar  5 17:16:51 2016 Chevalier Nicolas
** Last update Sat May 21 06:42:42 2016 Nicolas Chevalier
*/

#include "my.h"

void		init_list(t_list *list)
{
  list->first = NULL;
  list->last = NULL;
}

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

void		push_front(t_pos *pos, t_list *list, int x, int y)
{
  t_pos		*tmp;

  if ((tmp = malloc(sizeof(t_pos))) == NULL)
    exit (0);
  if ((tmp->hist = malloc(sizeof(t_pos))) == NULL)
    exit (0);
  tmp->hist->prev = NULL;
  if (pos)
    tmp->hist = pos->hist;
  else
    tmp->hist = NULL;
  tmp->x = x;
  tmp->y = y;
  tmp->father_x = x;
  tmp->father_y = y;
  pile_push(&tmp->hist, x, y);;
  tmp->next = list->first;
  tmp->prev = NULL;
  if (list->first)
    list->first->prev = tmp;
  else
    list->last = tmp;
  list->first = tmp;
}
