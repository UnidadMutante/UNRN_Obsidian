# C Format Modifiers Cheatsheet

## General format

```c

printf("%[flags][width][.precision][length]specifier", value);

scanf("%[width][length]specifier", &value);

```

Example:

```c

printf("%+08.2f", amount);

// +00012.35

```

## Conversion specifiers

<<<<<<< HEAD
| Specifier | Meaning                        | Example |
| `%d`, `%i` | Signed decimal integer | `-42` |
| `%u`         | Unsigned decimal integer | `42` |
| `%o`         | Octal integer | `52` |
| `%x`, `%X` | Hexadecimal integer | `2a`, `2A` |
| `%f`         | Decimal floating-point | `3.14` |
| `%e`, `%E` | Scientific notation | `3.14e+00` |
| `%g`, `%G` | Compact `%f` or `%e` form | `3.14` |
| `%c`         | Character | `'A'` |
| `%s`         | String | `"hello"` |
| `%p`         | Pointer address | `0x7ffe...` |
| `%%`         | Literal percent sign | `%` |
=======
| Specifier | Meaning | Example |

|---|---|---|

| `%d`, `%i` | Signed decimal integer | `-42` |

| `%u` | Unsigned decimal integer | `42` |

| `%o` | Octal integer | `52` |

| `%x`, `%X` | Hexadecimal integer | `2a`, `2A` |

| `%f` | Decimal floating-point | `3.14` |

| `%e`, `%E` | Scientific notation | `3.14e+00` |

| `%g`, `%G` | Compact `%f` or `%e` form | `3.14` |

| `%c` | Character | `'A'` |

| `%s` | String | `"hello"` |

| `%p` | Pointer address | `0x7ffe...` |

| `%%` | Literal percent sign | `%` |
>>>>>>> 2267219ee76e7ed787f005c1eed539b6cb28413b

## Flags (`printf`)

| Flag | Effect | Example |

|---|---|---|

| `-` | Left-align within the field | `%-10s` |

| `+` | Always show the sign | `%+d` → `+42` |

| space | Add a leading space to positive numbers | `% d` → ` 42` |

| `0` | Pad numeric values with zeroes | `%05d` → `00042` |

| `#` | Alternate form: prefixes or decimal point | `%#x` → `0x2a` |

If `-` is used, `0` padding is ignored.

## Field width

Width specifies the minimum number of characters used:

```c

printf("%8d", 42); // " 42"

printf("%-8d", 42); // "42 "

printf("%*d", 8, 42); // width supplied at runtime

```

Width does not truncate a value that is longer than the specified width.

## Precision

Precision begins with `.`. Its meaning depends on the conversion:

| Conversion | Precision controls | Example |

|---|---|---|

| `%f`, `%e`, `%g` | Decimal digits / significant digits | `%.2f` → `3.14` |

| `%d`, `%u`, `%x` | Minimum number of digits, zero-padded | `%.5d` → `00042` |

| `%s` | Maximum characters printed | `%.5s` → `hello` |

```c

printf("%.3f", 3.14159); // 3.142

printf("%10.2f", 3.14159); // 3.14

printf("%.5s", "hello world"); // hello

printf("%.*f", 3, 3.14159); // precision supplied at runtime: 3.142

```

For `%g`, precision means significant digits rather than digits after the decimal point.

## Length modifiers

| Modifier | Used with | Example |

|---|---|---|

| `hh` | `signed char` / `unsigned char` | `%hhd`, `%hhu` |

| `h` | `short` / `unsigned short` | `%hd`, `%hu` |

| `l` | `long`; with `%c`/`%s`, wide character/string | `%ld`, `%ls` |

| `ll` | `long long` | `%lld`, `%llu` |

| `j` | `intmax_t` / `uintmax_t` | `%jd`, `%ju` |

| `z` | `size_t` | `%zu` |

| `t` | `ptrdiff_t` | `%td` |

| `L` | `long double` | `%Lf` |

## `printf` vs `scanf`

```c

long count;

size_t length;

double price;

printf("%ld %zu %.2f\n", count, length, price);

scanf("%ld %zu %lf", &count, &length, &price);

```

Important differences:

- `printf` receives values; `scanf` receives addresses, so use `&` for ordinary variables.

- For `scanf`, `%f` reads into a `float`, while `%lf` reads into a `double`.

- For `printf`, both `float` and `double` use `%f` because `float` is promoted to `double`.

- Always check the return value of `scanf` to confirm that input was parsed successfully.

## Common combinations

```c

%8d // width 8

%-8s // left-aligned, width 8

%08d // zero-padded, width 8

%+.2f // sign and 2 decimal places

%#x // hexadecimal with 0x prefix

%10.3f // width 10, 3 digits after decimal

%*.*f // runtime width and precision

%lld // long long integer

%zu // size_t value

```

## Quick safety note

The format string and arguments must match. A mismatch can produce incorrect output or undefined behavior. Prefer a width limit when reading strings:

```c

char name[20];

scanf("%19s", name); // leaves room for the terminating '\0'

```