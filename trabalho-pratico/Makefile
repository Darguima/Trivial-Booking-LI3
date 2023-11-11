# The name of the final executable file
EXECUTABLE := programa-principal

# Find all .c files (SOURCES), and also replace the extension to .o (OBJECTS)
SOURCES := $(shell find ./src -type f -name '*.c')
OBJECTS := $(patsubst %.c, %.o, $(SOURCES))

# Storing the extra arguments passed to the make command, to pass it then to, for exemple, the executable (make dev)
MAKE_ARGS := `arg="$(filter-out $@,$(MAKECMDGOALS))" && echo $${arg:-${1}}`

# Compiler Flags ====
CC := gcc

FLAGS := -Wall -Wextra -pedantic -std=gnu17 -Werror=pedantic -Werror=vla -fstack-protector-all -fstrict-aliasing -Wconversion -Wformat-security -Wundef -Wshadow

# Add correct optimization flags to FLAGS
# To active DEBUG flags call the make file like this: `DEBUG=1 make ...`
DEBUG ?= 0
ifeq ($(DEBUG), 1)
# Low optimization/fast compilation at debuging/development compilation
	FLAGS += -O0 -g 
else
# Lot of optimization/slow compilation at final compilation
	FLAGS += -O3 -Werror
endif


LOCAL_INC := -I include/ # Including local headers
GLIB_INC := $(shell pkg-config --cflags glib-2.0) # pkg-config will convert the lib name to the correct flag
CFLAGS := ${FLAGS} ${LOCAL_INC} ${GLIB_INC}

LDFLAGS := -lm `pkg-config --libs glib-2.0` # pkg-config will convert the lib name to the correct flag

# Commands ===

# Compile project
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@ 

clean:
	@find . -type f -name '*.o' -delete && echo "[Cleaning] Object Files"
	@rm -f ${EXECUTABLE} && rm -f programa-testes && echo "[Cleaning] ${EXECUTABLE}"

# Format Code
format:
# Check if clang is installed
	@command -v clang-format &> /dev/null || echo "[Warning] Please install `clang`. Read documentation."
# Run clang-format against the code files
	@find . -name '*.[ch]' -exec clang-format -i {} -style=Chromium \; && echo "[Formating]"	

dev:
	@printf "=====  Formating, Compiling and executing project   =====\n"
	@make -s format
	@DEBUG=1 make -s && echo "[Compiling]"
	@printf "===================================================================\n"

	@./$(EXECUTABLE) $(call MAKE_ARGS)

# Ignore unmatched commands - to allow store the arguments inside a variable MAKE_ARGS
%:
	@echo "Invalid command"; exit 1
