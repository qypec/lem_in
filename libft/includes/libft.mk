# Base variables for libft library

CC = gcc
CFLAGS = -g -c -Wall -Wextra -Werror
LIBFT_H = -I ../includes/
COMPILING = $(CC) $(CFLAGS) $(LIBFT_H)
DIR_O = ../lib
NAME = libft.a
