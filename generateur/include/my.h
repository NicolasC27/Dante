/*
** my.h for my.j in /home/cheval_8/rendu/dante/generateur
**
** Made by Nicolas Chevalier
** Login   <cheval_8@epitech.net>
**
** Started on  Fri May 20 00:31:21 2016 Nicolas Chevalier
** Last update Sat May 21 03:12:40 2016 Nicolas Chevalier
*/


#ifndef MY_H_
# define MY_H_

/*
** Includes
*/
#include "lib.h"
#include <stdbool.h>

/*
** Defines
*/
# define UNUSED(x)	(void)(x)
# define DEBUG		0
# define OK		1
# define KO		-1
# define UNVISITED	' '
# define UVISITED	' '
# define VISITED	'*'
# define WALL		'X'
# define NORTH		5
# define SOUTH		6
# define WEST		7
# define EAST		8
# define PARFAIT	1
# define IMPARFAIT	2

typedef struct	s_maze
{
  int		width;
  int		height;
  int		type;
  char		**maze;
}		t_maze;

typedef struct	s_way
{
  int		x;
  int		y;
  struct s_way	*next;
  struct s_way	*prev;
}		t_way;

typedef struct	s_list
{
  t_way		*first;
  t_way		*last;
}		t_list;

typedef struct s_generating
{
  int		x;
  int		y;
  int		solve;
  int		x_start;
  int		y_start;
}		t_generating;

/*
** src/main.c
*/
void		help();

/*
** src/parser.c
*/
void		parser(t_maze *, char **);

/*
** src/generating_maze.c
*/
int		start_maze(t_maze *, t_list *);
int		my_rand(void);

/*
** src/neighbours.c
*/
int		neighbour(t_maze *, int, int);

/*
** src/neighbors.c
*/
int		rand_neighbour(t_maze *, t_generating *);
int		neighbour_unvisited(t_maze *, int, int);
int		neighbors_around(t_maze *, int, int);

/*
** src/solve.c
*/
void		solve_cell(t_list *, t_maze *, t_generating *);

/*
** src/list.c
*/
void		display_list(t_list *);
void		init_list(t_list *);
int		pushfront(t_list *, int, int);
int		popback(t_list *);

#endif /* !MY_H_ */
