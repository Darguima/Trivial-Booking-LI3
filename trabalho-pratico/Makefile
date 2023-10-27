EXECUTABLE=programa-principal

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
# Compile project
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean-objects:
# Delete recursively all objects (.o) files
	@find . -type f -name '*.o' -delete && echo "[Cleaning] Object Files"

clean:
	@make -s clean-objects
	@rm -f ${EXECUTABLE} && rm -f programa-testes && echo "[Cleaning] ${EXECUTABLE}"

format:
# Check if clang is installed
	@command -v clang-format &> /dev/null || echo "[Warning] Please install `clang`. Read documentation."
# Run clang-format against the code files
	@clang-format -i src/**/*.[ch] && echo "[Formating]"

dev:
	@printf "=====  Formating, Compiling, Cleaning and executing project   =====\n"
	@make -s clean
	@make -s format
	@make -s && echo "[Compiling]"
	@make -s clean-objects
	@printf "===================================================================\n"

	@./$(EXECUTABLE) $(call MAKE_ARGS)

%:
# Ignore unmatched commands - to allow store the arguments inside a variable MAKE_ARGS
	@:
