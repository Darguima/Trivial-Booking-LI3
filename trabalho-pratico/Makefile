EXECUTABLE=trabalho-principal

CC=gcc
INC=-I includes/
CFLAGS=-Wall -Wextra -pedantic -O2 ${INC}
LIBS=-lm

# Find all .c files
SOURCES := $(shell find ./src -type f -name '*.c')
# And convert them to .o files
OBJECTS := $(patsubst %.c, %.o, $(SOURCES))

# Arguments passed after make command - will be passed for example to the executable
MAKE_ARGS = `arg="$(filter-out $@,$(MAKECMDGOALS))" && echo $${arg:-${1}}`

$(EXECUTABLE): $(OBJECTS)
    # Compile main.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
    # Delete recursively all objects (.o) files
	@find . -type f -name '*.o' -delete

dev:
    # Clean, compile and run 
	@printf "\n===== Compiling, Cleaning and executing project =====\n\n"
	@make -s clean
	@make -s
	@make -s clean
	@./$(EXECUTABLE) $(call MAKE_ARGS)

# Ignore unmatched commands - to allow store the arguments inside a variable MAKE_ARGS
%:
	@: