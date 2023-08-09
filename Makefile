CC = gcc
CFLAGS = -Wall -ansi -pedantic -Werror 
OBJ = main.o map.o movement.o
EXEC = laserTank

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c map.h movement.h
	$(CC) -c main.c $(CFLAGS)

map.o : map.c map.h
	$(CC) -c map.c $(CFLAGS)

movement.o : movement.c movement.h
	$(CC) -c movement.c $(CFLAGS)

clean :
	rm -f $(OBJ) $(OBJ_NE) $(EXEC) $(NOEXTRAS)


