# Base variables for lem-in

CC = gcc
CFLAGS = -g -c -Wall -Wextra -Werror
HEADER_H = -I ../includes/
COMPILING = $(CC) $(CFLAGS) $(HEADER_H)
EXECUTABLE = lem-in
LIBNAME = libft.a
