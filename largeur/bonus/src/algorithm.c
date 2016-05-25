/*
** algorithm.c for algorithm in /home/cheval_8/rendu/dante/largeur
**
** Made by Nicolas Chevalier
** Login   <cheval_8@epitech.net>
**
** Started on  Sat May 21 05:23:32 2016 Nicolas Chevalier
** Last update Sun May 22 23:33:16 2016 Nicolas Chevalier
*/

#include "ncurses.h"
#include "my.h"


static t_pos	*delete_pos(t_list *list, t_pos *pos)
{
  t_pos		*tmp;
  t_pos		*tmp2;

  tmp2 = pos;
  tmp = pos;
  if (tmp->prev)
    tmp->prev->next = tmp->next;
  else
    list->first = tmp->next;
  if (tmp->next)
    tmp->next->prev = tmp->prev;
  else
    list->last = tmp->prev;
  tmp = tmp->next;
  free(tmp2);
  return (tmp);
}

static void	make_way(t_pile *list, char **map)
{
  t_pile	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      if (map[tmp->x][tmp->y])
	map[tmp->x][tmp->y] = PATH;
      tmp = tmp->prev;
    }
}

char		**algorithm(t_list *list, t_solver *maze, char **map)
{
  t_pos		*pos;

  pos = NULL;
  push_front(pos, list, 0, 0);
  pos = list->first;
  map[pos->x][pos->y] = PATH;
  while (pos)
    {
      map[pos->x][pos->y] = VISITED;
      if ((check_neighbours(pos, list, maze, map)) == 0)
	pos = delete_pos(list, pos);
      if (pos && pos->x == maze->height - 1 && pos->y == maze->width - 1)
	{
	  make_way(pos->hist, map);
	  return (map);
	}
     if (pos)
       map[pos->x][pos->y] = VISITED;
     display_ncurses(maze, map);
     getch();
     if (pos)
       pos = pos->next;
     if (pos == NULL)
       pos = list->first;
    }
  return (NULL);
}
