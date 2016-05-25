/*
** neighbours.c for neighbours.c in /home/cheval_8/rendu/dante/largeur
**
** Made by Nicolas Chevalier
** Login   <cheval_8@epitech.net>
**
** Started on  Sat May 21 05:25:30 2016 Nicolas Chevalier
** Last update Sun May 22 22:10:54 2016 Nicolas Chevalier
*/

#include "my.h"

static int	east(t_pos *pos, t_list *list, t_solver *maze, char **map)
{
  if (((pos->y + 1) != maze->width) && map[pos->x][pos->y + 1] == UNVISITED)
    {
      if ((((pos->x + 1) != maze->height)
	   && map[pos->x + 1][pos->y] == UNVISITED))
	{
	  push_front(pos, list, pos->x + 1, pos->y);
	  map[pos->x + 1][pos->y] = VISITED;
	}
      if ((pos->y - 1 != -1) && map[pos->x][pos->y - 1] == UNVISITED)
	{
	  push_front(pos, list, pos->x, pos->y - 1);
	  map[pos->x][pos->y - 1] = VISITED;
	}
      if ((pos->x - 1) != -1 && map[pos->x - 1][pos->y] == UNVISITED)
	{
	  push_front(pos, list, pos->x - 1, pos->y);
	  map[pos->x - 1][pos->y] = VISITED;
	}
      pos->y += 1;
      pile_push(&pos->hist, pos->x, pos->y);
      return (1);
    }
  return (0);
}

static int	north(t_pos *pos, t_list *list, t_solver *maze, char **map)
{
  if (((pos->x + 1) != maze->height) && map[pos->x + 1][pos->y] == UNVISITED)
    {
      if (((pos->y + 1) != maze->width) && map[pos->x][pos->y + 1] == UNVISITED)
	{
	  push_front(pos, list, pos->x, pos->y + 1);
	  map[pos->x][pos->y + 1] = VISITED;
	}
      if ((pos->y - 1 != -1) && map[pos->x][pos->y - 1] == UNVISITED)
	{
	  push_front(pos, list, pos->x, pos->y - 1);
	  map[pos->x][pos->y - 1] = VISITED;
 	}
      if ((pos->x - 1) != -1 && map[pos->x - 1][pos->y] == UNVISITED)
	{
	  push_front(pos, list, pos->x - 1, pos->y);
	  map[pos->x - 1][pos->y] = VISITED;
 	}
      pos->x += 1;
      pile_push(&pos->hist, pos->x, pos->y);
      return (1);
    }
  return (0);
}

static int	south(t_pos *pos, t_list *list, t_solver *maze, char **map)
{
  if ((pos->x - 1) != -1 && map[pos->x - 1][pos->y] == UNVISITED)
    {
      if (((pos->x + 1) != maze->height)
	  && map[pos->x + 1][pos->y] == UNVISITED)
	{
	  push_front(pos, list, pos->x + 1, pos->y);
	  map[pos->x + 1][pos->y] = VISITED;
	}
      if (((pos->y + 1) != maze->width) && map[pos->x][pos->y + 1] == UNVISITED)
	{
	  push_front(pos, list, pos->x, pos->y + 1);
	  map[pos->x][pos->y + 1] = VISITED;
	}
      if ((pos->y - 1 != -1) && map[pos->x][pos->y - 1] == UNVISITED)
	{
	  push_front(pos, list, pos->x, pos->y - 1);
	  map[pos->x][pos->y - 1] = VISITED;
	}
      pos->x -= 1;
      pile_push(&pos->hist, pos->x, pos->y);
      return (1);
    }
  return (0);
}

static int	west(t_pos *pos, t_list *list, t_solver *maze, char **map)
{
  if ((pos->y - 1 != -1) && map[pos->x][pos->y - 1] == UNVISITED)
    {
      if (((pos->x + 1) != maze->height)
	  && map[pos->x + 1][pos->y] == UNVISITED)
	{
	  push_front(pos, list, pos->x + 1, pos->y);
	  map[pos->x][pos->y - 1] = VISITED;
	}
      if (((pos->y + 1) != maze->width) && map[pos->x][pos->y + 1] == UNVISITED)
	{
	  push_front(pos, list, pos->x, pos->y + 1);
	  map[pos->x][pos->y + 1] = VISITED;
	}
      if ((pos->x - 1) != -1 && map[pos->x - 1][pos->y] == UNVISITED)
	{
	  push_front(pos, list, pos->x - 1, pos->y);
	  map[pos->x - 1][pos->y] = VISITED;
	}
      pos->y -= 1;
      pile_push(&pos->hist, pos->x, pos->y);
      return (1);
    }
  return (0);
}

int		check_neighbours(t_pos *pos, t_list *list, t_solver *maze, char **map)
{
  if ((east(pos, list, maze, map) == 1))
    return (1);
  else if ((north(pos, list, maze, map) == 1))
    return (1);
  else if ((south(pos, list, maze, map) == 1))
    return (1);
  else if ((west(pos, list, maze, map) == 1))
    return (1);
  return (0);
}
