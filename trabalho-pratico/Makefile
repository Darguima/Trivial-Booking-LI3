CC=gcc
CFLAGS=-Wall -Wextra -pedantic -O2
LIBS=-lm

# Arguments passed after make command - will be passed to the executable
args = `arg="$(filter-out $@,$(MAKECMDGOALS))" && echo $${arg:-${1}}`

# Find all .c files
SOURCES := $(shell find ./src -type f -name '*.c')
# And convert them to .o files
OBJECTS := $(patsubst %.c, %.o, $(SOURCES))

trabalho-principal: $(OBJECTS)
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
	@./trabalho-principal $(call args)

# Ignore unmatched commands - to allow store the arguments inside a variable
%:
	@: