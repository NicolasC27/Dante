/*
** neigbors.c for neigbors.c in /home/cheval_8/rendu/dante/generateur
**
** Made by Nicolas Chevalier
** Login   <cheval_8@epitech.net>
**
** Started on  Fri May 20 00:54:58 2016 Nicolas Chevalier
** Last update Sun May 22 23:01:47 2016 Nicolas Chevalier
*/

#include "my.h"

int		rand_neighbour(t_maze *data, t_generating *var)
{
  int		direction;

  direction = 0;
  while ((direction < 5 || direction > 9) && direction != 10)
    direction = my_rand() % 9;
  if ((var->y - 1 != -1) && data->maze[var->x][var->y - 1] == UNVISITED
      && direction == NORTH)
    (var->y) -= 1;
  else if (((var->y + 1) != data->width)
	   && data->maze[var->x][var->y + 1] == UNVISITED
	   && direction == SOUTH)
    var->y += 1;
  else if ((var->x + 1 != data->height)
	   && data->maze[var->x + 1][var->y] == UNVISITED
	   && direction == WEST)
    var->x += 1;
  else if ((var->x - 1 != -1) && data->maze[var->x - 1][var->y] == UNVISITED
	   && direction == EAST)
    var->x -= 1;
  else
    rand_neighbour(data, var);
  return (0);
}

int		neighbour_unvisited(t_maze *data, int x, int y)
{
  int		count;

  count = 0;
  if (y != 0 && (data->maze[x][y - 1] == UNVISITED))
    count += 1;
  if (y != data->width - 1)
    if (data->maze[x][y + 1] == UNVISITED)
      count += 1;
  if (x != data->height - 1 && data->maze[x + 1][y] == UNVISITED)
    count += 1;
  if (x != 0 && data->maze[x - 1][y] == UNVISITED)
    count += 1;
  return (count);
}

static int	in_the_corner(t_maze *data, int x, int y)
{
  if (x == 0 && y == 0)
    return ((data->maze[0][1] == UNVISITED
	     || data->maze[1][0] == UNVISITED) ? OK : KO);
  if (x == 0 && y == data->width - 1)
    return ((data->maze[x + 1][y] == UNVISITED
	     || data->maze[x][y - 1] == UNVISITED) ? (OK) : (KO));
  if (y == 0 && x == data->height - 1)
    return ((data->maze[x - 1][y] == UNVISITED
	     || data->maze[x][y + 1] == UNVISITED) ? (OK) : (KO));
  if (y == data->width - 1 && x == data->height - 1)
    return ((data->maze[x - 1][y] == UNVISITED
	     || data->maze[x][y - 1] == UNVISITED) ? (OK) : (KO));
  return (0);
}

int		neighbors_around(t_maze *data, int x, int y)
{
  if ((x == 0 && y == 0) || (x == 0 && y == data->width - 1)
      || (x == data->height - 1 && y == 0)
      || (x == data->height - 1 && y == data->width - 1))
    return (in_the_corner(data, x, y));
  if (x == 0 || x == data->height - 1)
    {
      if ((data->maze[x][y - 1] == UVISITED
	   || data->maze[x][y + 1] == UVISITED)
	  || (x == 0 && data->maze[x + 1][y] == UNVISITED)
	  || (x == data->height - 1 && data->maze[x - 1][y] == UNVISITED))
  	return (OK);
    }
  else if (y == 0 || y == data->width - 1)
    {
      if (data->maze[x - 1][y] == UVISITED || data->maze[x + 1][y] == UVISITED
	  || ((y == data->width - 1 && data->maze[x][y - 1]) == UNVISITED)
	  || (y == 0 && data->maze[x][y + 1] == UNVISITED))
      	return (OK);
    }
  else
    if (data->maze[x - 1][y] == UNVISITED || data->maze[x + 1][y] == UNVISITED
	|| data->maze[x][y + 1] == UNVISITED || data->maze[x][y - 1] == UNVISITED)
      return (OK);
  return (KO);
}
