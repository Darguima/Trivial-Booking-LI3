# Trivial Booking

## Contribute

### Install dependencies

```bash
# Ubuntu
$ sudo apt-get install libglib2.0-dev clang-format

# Arch
$ sudo pacman -S glib2 clang
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
$ ./programa-principal <path to *.csv files> <path to input file>

# Or all at once
$ make dev
```

If you want active DEBUG mode pass the DEBUG variable to the make command:

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
