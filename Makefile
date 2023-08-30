#colors

RED = \033[0;31m
GREEN = \033[0;32m
NC = \033[0m
YELLOW = \033[0;33m
MAGENTA = \033[0;35m

#program variables

PROG = rum_me
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

#compiler variables

CC = gcc
CFLAGS = -Wall -pedantic -Werror -Wextra -std=gnu89  -g 

#rules

build: $(PROG)

$(PROG): $(OBJ)
	@echo -e "$(YELLOW)In process... to compile the $(MAGENTA)$(PROG)$(NC)"
	@$(CC) $(CFLAGS) -o $@ $^
	@echo -e "$(GREEN) $(PROG) compiled$(NC) \n"

%.o: %.c
	@$(CC) $(CFLAGS) -c -o  $@ $^

run: build
	@./$(PROG)

clean: run
	@echo -e "$(RED)Cleaning...$(NC)"
	@rm -f *.o $(PROG) *~ $(OBJ)
	@echo -e "$(GREEN)Cleaned$(NC) \n"

.PHONY: build run clean
