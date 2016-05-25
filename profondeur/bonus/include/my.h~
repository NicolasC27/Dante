/*
** my.h for my.h in /home/cheval_8/rendu/dante/profondeur
**
** Made by Nicolas Chevalier
** Login   <cheval_8@epitech.net>
**
** Started on  Wed May 18 21:43:53 2016 Nicolas Chevalier
** Last update Sat May 21 07:58:44 2016 Nicolas Chevalier
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
#define UNUSED(x) (void)(x)
#define DEBUG	  0
#define READ_SIZE 15000
#define KO	  -1
#define UNVISITED '*'
#define VISITED	  'V'
#define WALL	  'X'
#define PATH	  'O'
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

typedef struct	s_solver
{
  int		height;
  int		width;
  int		x;
  int		y;
}		t_solver;

/*
** src/algorithm.c
*/
char		**algorithm(t_pile *, t_solver *, char **);

/*
** src/parser.c
*/
char		**parser(char *, t_solver *);

/*
** src/list.c
*/
void		pile_push(t_pile **, int, int);
void		pile_pop(t_pile **);

#endif /* !MY_H_ */
