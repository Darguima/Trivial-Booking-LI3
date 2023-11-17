# Trivial Booking

## Contribute

### Install dependencies

```bash
# Ubuntu
$ sudo apt-get install libglib2.0-dev clang-format valgrind doxygen

# Arch
$ sudo pacman -S glib2 clang valgrind doxygen
```

#### Cloning the repository
```bash
$ git clone https://github.com/dium-li3/grupo-45.git
```

#### Compiling

Inside the project folder:

```bash
$ cd trabalho-pratico
$ make
# You can run the program without params (interactive mode)
$ ./programa-principal <path to *.csv folder> <path to input file>

# Or all at once (also possible without params)
$ make dev <path to *.csv folder> <path to input file>
```

If you want active DEBUG mode (the default for `make dev`) pass the DEBUG variable to the make command:

```bash
# Will compile faster and with debugging symbols
$ DEBUG=1 make
```

# WhiteBoard for ideas for the presentation

1. Show the data flow (catalog_creator, catalog_filler, filer_parser, ...)
2. GitHub Actions

# Developed by:

- [Afonso Pedreira](https://github.com/afooonso)
- [Dário Guimarães](https://github.com/darguima)
- [Hugo Rauber](https://github.com/HugoLRauber)
