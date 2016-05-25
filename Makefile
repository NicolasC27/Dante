##
## Makefile for Makefile in /home/cheval_8/rendu/dante
## 
## Made by Nicolas Chevalier
## Login   <cheval_8@epitech.net>
## 
## Started on  Sun May 22 23:10:11 2016 Nicolas Chevalier
## Last update Sun May 22 23:15:44 2016 Nicolas Chevalier
##

RM	= rm -rf

all	:
		make -s -C profondeur/
		make -s -C astar/
		make -s -C generateur/
		make -s -C tournoi/
		make -s -C largeur/

clean	:
		make clean -s -C profondeur/
		make clean -s -C astar/
		make clean -s -C generateur/
		make clean -s -C tournoi/
		make clean -s -C largeur/

fclean	:	clean
		make fclean -s -C profondeur/
		make fclean -s -C astar/
		make fclean -s -C generateur/
		make fclean -s -C tournoi/
		make fclean -s -C largeur/

re	:	fclean all

.PHONY	:	all clean fclean re
