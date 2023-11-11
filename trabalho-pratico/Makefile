# The name of the final executable file
EXECUTABLE=programa-principal

# Find all .c files (SOURCES), and also replace the extension to .o (OBJECTS)
SOURCES := $(shell find ./src -type f -name '*.c')
OBJECTS := $(patsubst %.c, %.o, $(SOURCES))

# Storing the extra arguments passed to the make command, to pass it then to, for exemple, the executable (make dev)
MAKE_ARGS = `arg="$(filter-out $@,$(MAKECMDGOALS))" && echo $${arg:-${1}}`

# Compiler Flags
CC=gcc
INC=-I include/ # Including local headers
CFLAGS=-Wall -Wextra -pedantic -O2 ${INC}
LIBS=-lm

# Compile project
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@ 

# Delete recursively all objects (.o) files
clean-objects:
	@find . -type f -name '*.o' -delete && echo "[Cleaning] Object Files"

clean:
	@make -s clean-objects
	@rm -f ${EXECUTABLE} && rm -f programa-testes && echo "[Cleaning] ${EXECUTABLE}"

# Format Code
format:
# Check if clang is installed
	@command -v clang-format &> /dev/null || echo "[Warning] Please install `clang`. Read documentation."
# Run clang-format against the code files
	@find . -name '*.[ch]' -exec clang-format -i {} -style=Chromium \; && echo "[Formating]"	

dev:
	@printf "=====  Formating, Compiling, Cleaning and executing project   =====\n"
	@make -s clean
	@make -s format
	@make -s && echo "[Compiling]"
	@make -s clean-objects
	@printf "===================================================================\n"

	@./$(EXECUTABLE) $(call MAKE_ARGS)

# Ignore unmatched commands - to allow store the arguments inside a variable MAKE_ARGS
%:
	@echo "Invalid command"; exit 1
