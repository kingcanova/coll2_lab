#Makefile for MonteCarloPi
#
#Tristan Canova and Keith Grable
#
#
#
all:	main

# Define our C compiler
CC=mpicc

#
# Now define the list of C files which are part of our project
CFILES=mpi_pi.c	timer.c
#
# From the CFILES, obtain OFILES, a list of objects
OFILES=$(CFILES:.c=.o)

# how to build a .o from a .c (this is actually the same as the default)
# means, use the compiler defined by CC, compile only (no link) and
# $< is the name of the current target
.c.o:
	$(CC) -c $<

# define the link line.  $(OFILES) means the target main depends on the
# things in OFILES.  We'll use the compilers in $(CC) as the linker,
# -o main means call the output "main", $(OFILES) lists the objects
# to link, then -lm means also link with the math library libm.a
main:	$(OFILES)
	$(CC) -o main $(OFILES) -lm

timer.o:	timer.h

# When we just want to clean up all of the object and executable files
# we often provide a "clean" rule.  This rule has no dependencies, and
# the statements are always executed when someone executes "make clean"
clean::
	/bin/rm main mpi_pi.o	timer.o
