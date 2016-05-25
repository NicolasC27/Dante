/*
** neighbours.c for neighbours.c in /home/cheval_8/rendu/dante/generateur
**
** Made by Nicolas Chevalier
** Login   <cheval_8@epitech.net>
**
** Started on  Fri May 20 01:08:16 2016 Nicolas Chevalier
** Last update Fri May 20 03:22:11 2016 Nicolas Chevalier
*/

#include "my.h"

static int	check_cell_end(t_maze *data, int x, int y)
{
  if (x == data->height - 1 && y == data->width - 2
      && (data->maze[data->height - 2][data->width - 1] == VISITED
  	  && data->maze[data->height - 2][data->width - 1] != WALL))
    return (2);
  if (x == data->height - 2 && y == data->width - 1
      && (data->maze[data->height - 1][data->width - 2] == VISITED
  	  && data->maze[data->height - 1][data->width - 2] != WALL))
    return (2);
  if (x == data->height - 2 && y == data->width - 1
      && (data->maze[data->height - 1][data->width - 2] != VISITED))
    return (0);
  if (x == data->height - 1 && y == data->width - 2
      && (data->maze[data->height - 2][data->width - 1] != VISITED))
    return (0);
  return (1);
}

static int	check_cell_start(t_maze *data, int x, int y)
{
  if (x == 1 && y == 0
      && (data->maze[0][1] == VISITED
  	  && data->maze[0][1] != WALL))
    return (2);
  if (x == 0 && y == 1
      && (data->maze[1][0] == VISITED
  	  && data->maze[1][0] != WALL))
    return (2);
  if (x == 0 && y == 1
      && (data->maze[0][1] != VISITED))
    return (0);
  if (x == 1 && y == 0
      && (data->maze[0][1] != VISITED))
    return (0);
  return (1);
}

int		neighbour(t_maze *data, int x, int y)
{
  int		count;
  int		cell_start;
  int		cell_end;

  count = 0;
  cell_start = check_cell_start(data, x, y);
  cell_end = check_cell_end(data, x, y);
  if (cell_start == 0 || cell_end == 0)
    return (0);
  else if (cell_start == 2 || cell_end == 2)
    return (2);
  if (y != 0 && data->maze[x][y - 1] == VISITED)
    count += 1;
  if (y != data->width - 1)
    if (data->maze[x][y + 1] == VISITED)
      count += 1;
  if (x != data->height - 1 && data->maze[x + 1][y] == VISITED)
    count += 1;
  if (x != 0 && data->maze[x - 1][y] == VISITED)
    count += 1;
  return (count);
}
