/*
** algorithm.c for algorithms.c in /home/cheval_8/rendu/dante/profondeur
**
** Made by Nicolas Chevalier
** Login   <cheval_8@epitech.net>
**
** Started on  Sat May 21 07:20:16 2016 Nicolas Chevalier
** Last update Sat May 21 08:33:50 2016 Nicolas Chevalier
*/

#include "my.h"

static int	check_neighbour(t_solver *maze, char **map)
{
  if ((maze->x + 1 != maze->height) && map[maze->x + 1][maze->y] == UNVISITED)
    maze->x += 1;
  else if (((maze->y + 1) != maze->width)
	   && map[maze->x][maze->y + 1] == UNVISITED)
    maze->y += 1;
  else if ((maze->x - 1 != -1) && map[maze->x - 1][maze->y] == UNVISITED)
    maze->x -= 1;
  else if ((maze->y - 1 != -1) && map[maze->x][maze->y - 1] == UNVISITED)
    maze->y -= 1;
  else
    return (0);
  return (1);
}

static char	**start_algorithm(t_solver *maze, t_pile **list, char **map)
{
  if (check_neighbour(maze, map) == 0)
    {
      map[maze->x][maze->y] = VISITED;
      pile_pop(list);
      maze->x = (*list)->x;
      maze->y = (*list)->y;
      while ((*list)->prev != NULL && check_neighbour(maze, map) == 0)
	{
	  map[maze->x][maze->y] = VISITED;
	  pile_pop(list);
	  if ((*list)->prev != NULL)
	    {
	      maze->x = (*list)->x;
	      maze->y = (*list)->y;
	    }
	}
      if (maze->x == 0 && maze->y == 0)
	return (NULL);
    }
  return (map);
}

char		**algorithm(t_pile *list, t_solver *maze, char **map)
{
  maze->x = 0;
  maze->y = 0;
  pile_push(&list, maze->x, maze->y);
  map[maze->x][maze->y] = PATH;
  while (list != NULL)
    {
      if ((start_algorithm(maze, &list, map)) == NULL)
	return (NULL);
      map[maze->x][maze->y] = PATH;
      pile_push(&list, maze->x, maze->y);
      if (maze->x == maze->height - 1 && maze->y == maze->width - 1)
	return (map);
    }
  return (NULL);
}
