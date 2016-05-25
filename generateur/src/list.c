/*
** list.c for list.c in /home/cheval_8/rendu/dante/generateur
**
** Made by Nicolas Chevalier
** Login   <cheval_8@epitech.net>
**
** Started on  Fri May 20 00:57:41 2016 Nicolas Chevalier
** Last update Sun May 22 23:03:19 2016 Nicolas Chevalier
*/

#include "my.h"

/*
** Function debug
*/
void		display_list(t_list *list)
{
  t_way		*tmp;

  tmp = list->first;
  my_putstr("\n[");
  while (tmp != NULL)
    {
      my_putstr("x = ");
      my_put_nbr(tmp->x);
      my_putstr("y = ");
      my_put_nbr(tmp->y);
      tmp = tmp->next;
    }
  my_putstr("]\n");
}

void		init_list(t_list *list)
{
  list->first = NULL;
  list->last = NULL;
}

int		pushfront(t_list *list, int x, int y)
{
  t_way		*tmp;

  if ((tmp = malloc(sizeof(t_way))) == NULL)
    return (0);
  tmp->x = x;
  tmp->y = y;
  tmp->prev = list->last;
  tmp->next = NULL;
  if (list->last)
    list->last->next = tmp;
  else
    list->first = tmp;
  list->last = tmp;
  return (1);
}

int		popback(t_list *list)
{
  t_way		*tmp;

  tmp = list->last;
  if (!tmp)
    return (-1);
  list->last = tmp->prev;
  if (list->last)
    list->last->next = NULL;
  else
    list->last = NULL;
  free(tmp);
  return (0);
}
