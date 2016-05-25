/*
** generating.c for my.h in /home/cheval_8/rendu/dante/generateur
**
** Made by Nicolas Chevalier
** Login   <cheval_8@epitech.net>
**
** Started on  Fri May 20 00:34:03 2016 Nicolas Chevalier
** Last update Fri May 20 03:31:53 2016 Nicolas Chevalier
*/

#include <time.h>
#include "my.h"

/*
** Randon for roads
*/
int		my_rand(void)
{
  static int	first = 0;

  if (first == 0)
    {
      srand(time(NULL));
      first += 1;
    }
  return (rand());
}

/*
** Initialize struct for algorithm growing three
*/
static void	init_struct(t_generating *var, t_maze *data)
{
  var->x = 0;
  var->y = 0;
  var->solve = 0;
  while (var->x == 0 && var->x < data->height)
    var->x = my_rand() % (data->height);
  while (var->y == 0 && var->y < data->width)
    var->y = my_rand() % (data->width);
  data->maze[var->x][var->y] = VISITED;
  var->x_start = var->x;
  var->y_start = var->y;
  data->maze[0][0] = VISITED;
  data->maze[data->height - 1][data->width - 1] = VISITED;
}

/*
** Algorithm of type "growing three"
*/
static int	growing_three(t_list *list, t_maze *data, t_generating *var)
{
  while (var->solve == 0)
    {
      pushfront(list, var->x, var->y);
      rand_neighbour(data, var);
      solve_cell(list, data, var);
      while (list->last != NULL && neighbors_around(data, var->x, var->y) == KO)
  	{
  	  var->x = list->last->x;
  	  var->y = list->last->y;
  	  popback(list);
  	}
      if  (var->x == var->x_start && var->y == var->y_start)
  	if (neighbour_unvisited(data, var->x, var->y) == 0)
  	  return (0);
      if (list->first == NULL)
  	{
  	  my_putstr_err("Error with algorithm growing tree");
  	  return (0);
  	}
    }
  return (0);
}

/*
** Prepare generating before to start algorithm
*/
int		start_maze(t_maze *data, t_list *list)
{
  t_generating	variable;

  init_struct(&variable, data);
  growing_three(list, data, &variable);
  return (0);
}
