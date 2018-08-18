# CS50 Crack

This is a possible solution to the CS50x (2018) problem [Crack](https://docs.cs50.net/2018/x/psets/2/crack/crack.html).

## Features

This solution has two features:

- It has only one layer of nested loop
- It utilizes the pointer feature of `C`

## Build

```shell
make
```

If the build fails and you have `crypt` installed on your Linux, try adding `-lcrypt` to the `LDLIBS` in the `Makefile` to link to the library.
