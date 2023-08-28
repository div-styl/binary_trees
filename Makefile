# Colors
RED = \033[0;31m
GREEN = \033[0;32m
NC = \033[0m
YELLOW = \033[0;33m
MAGENTA = \033[0;35m

# Program variables
PROG = binary_exe
SRC = $(wildcard *.c)
OBJ = $(filter-out, $(SRC:.c=.o))

# Compiler variables
CC = gcc
CFLAGS = -Wall -pedantic -Werror -Wextra -std=gnu89 -g

# Rules
build: $(PROG)

$(PROG): $(OBJ)
	@echo -e "$(YELLOW)In process... to compile the $(MAGENTA)$(PROG)$(NC)"
	@$(CC) $(CFLAGS) -o $@ $^
	@echo -e "$(GREEN) $(PROG) compiled$(NC) \n"

%.o: %.c
	@if [ -s $< ]; then \
		echo -e "$(YELLOW)Compiling $(MAGENTA)$<$(NC)"; \
		$(CC) $(CFLAGS) -c -o $@ $<; \
	fi

run: build
	@./$(PROG)

clean:
	@echo -e "$(RED)Cleaning...$(NC)"
	@rm -f *.o $(PROG) *~ $(OBJ)
	@echo -e "$(GREEN)Cleaned$(NC) \n"

.PHONY: build run clean
