/*
** my.h for my.h in /home/cheval_8/rendu/dante/largeur
**
** Made by Nicolas Chevalier
** Login   <cheval_8@epitech.net>
**
** Started on  Wed May 18 04:33:23 2016 Nicolas Chevalier
** Last update Sun May 22 22:55:02 2016 Nicolas Chevalier
*/


#ifndef MY_H_
# define MY_H_

/*
** Includes
*/
#include "lib.h"
#include <stdbool.h>
#include <ncurses.h>

/*
** Defines
*/
#define UNUSED(x) (void)(x)
#define DEBUG	  0
#define READ_SIZE 4096
#define KO	  -1
#define UNVISITED '*'
#define VISITED	  'V'
#define WALL	  'X'
#define PATH	  'O'
#define TEST	  'T'
#define NORTH	  5
#define SOUTH	  6
#define WEST	  7
#define EAST	  8

typedef struct	s_pile
{
  int		x;
  int		y;
  struct s_pile	*prev;
}		t_pile;

typedef struct	s_pos
{
  int		x;
  int		y;
  int		father_x;
  int		father_y;
  t_pile	*hist;
  struct s_pos	*next;
  struct s_pos	*prev;
}		t_pos;

typedef struct	s_list
{
  t_pos		*first;
  t_pos		*last;
}		t_list;

typedef struct	s_solver
{
  int		height;
  int		width;
}		t_solver;

/*
** src/main.c
*/
void		display_ncurses(t_solver *, char **);

/*
** src/display.c
*/
void		display_ncurses(t_solver *, char **);

/*
** src/parser.c
*/
char		**parser(char *, t_solver *);

/*
** src/neighbours.c
*/
int		check_neighbours(t_pos *, t_list *, t_solver *, char **);

/*
** src/algorithm.c
*/
char		**algorithm(t_list *, t_solver *, char **, t_pos *pos);

/*
** src/list.c
*/
void		pile_push(t_pile **, int, int);
void		init_list(t_list *);
void		pile_pop(t_pile **);
void		push_front(t_pos *, t_list *, int, int);

#endif /* !MY_H_ */
