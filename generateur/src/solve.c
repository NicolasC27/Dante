/*
** solve.c for solve.c in /home/cheval_8/rendu/dante/generateur
**
** Made by Nicolas Chevalier
** Login   <cheval_8@epitech.net>
**
** Started on  Fri May 20 01:02:41 2016 Nicolas Chevalier
** Last update Fri May 20 03:41:17 2016 Nicolas Chevalier
*/

#include "my.h"

void		solve_cell(t_list *list, t_maze *data, t_generating *var)
{
  int		nb;

  nb = (data->type == PARFAIT) ? (1) : (0);
  if (data->type == IMPARFAIT)
    while (nb == 0)
      nb = my_rand() % 3;
  if (data->maze[var->x][var->y] == UNVISITED)
    {
      if (neighbour(data, var->x, var->y) > nb)
	{
	  data->maze[var->x][var->y] = WALL;
	  var->x = list->last->x;
	  var->y = list->last->y;
	  popback(list);
	  while (list->last != NULL && neighbors_around(data, var->x, var->y) == KO)
	    {
	      var->x = list->last->x;
	      var->y = list->last->y;
	      popback(list);
	    }
	}
      else
	data->maze[var->x][var->y] = VISITED;
    }
}
