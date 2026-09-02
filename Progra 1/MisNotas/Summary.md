# C Beginner Cheatsheet

## 1. Strings

C does not have a built-in string type. A string is an array of `char` ending with `'\0'`.

```
char name[] = "Carlos";
```

Memory contains:

```
'C' 'a' 'r' 'l' 'o' 's' '\0'
```

The `'\0'` is not printed, but it marks where the string ends.

Useful functions:

```
#include <string.h>

strlen(text);              // length, excluding '\0'
strcpy(destination, source);
strncpy(destination, source, limit);
strcat(destination, source);
strncat(destination, source, limit);
strcmp(first, second);     // returns 0 if equal
```

Always make sure the destination has enough space:

```
char result[20];
```

For safer copying:

```
strncpy(result, source, sizeof(result) - 1);
result[sizeof(result) - 1] = '\0';
```

---

## 2. Arrays

An array stores several values of the same type in consecutive positions.

```
int numbers[5] = {10, 20, 30, 40, 50};
```

Indexes start at zero:

```
numbers[0]; // 10
numbers[4]; // 50
```

The last valid index is always:

```
length - 1
```

Never access outside the array:

```
numbers[5]; // invalid
```

Loop through an array:

```
for (size_t i = 0; i < 5; i++) {
    printf("%d\n", numbers[i]);
}
```

---

## 3. `sizeof`

`sizeof` tells you how much memory something occupies, in bytes.

```
int numbers[5];

sizeof(numbers);       // total bytes
sizeof(numbers[0]);    // bytes occupied by one element
```

Number of elements:

```
size_t count = sizeof(numbers) / sizeof(numbers[0]);
```

This works only while `numbers` is still an actual array. It does not work after passing it to a function, because there it becomes a pointer.

Use `%zu` to print a `size_t` value:

```
printf("%zu\n", count);
```

---

## 4. Arrays in functions

When passed to a function, an array behaves like a pointer to its first element.

```
void print_numbers(int numbers[], size_t count)
{
    for (size_t i = 0; i < count; i++) {
        printf("%d\n", numbers[i]);
    }
}
```

These parameter declarations mean essentially the same thing:

```
void function(int numbers[], size_t count);
void function(int *numbers, size_t count);
```

The function cannot automatically know the array length, so pass it separately:

```
print_numbers(numbers, count);
```

Changes made to the elements inside the function affect the original array.

---

## 5. Returning arrays from functions

C cannot return a normal local array directly:

```
int *wrong(void)
{
    int numbers[3] = {1, 2, 3};
    return numbers; // wrong: array disappears after the function ends
}
```

Possible solutions:

### Let the caller provide the array

```
void fill_array(int numbers[], size_t count)
{
    for (size_t i = 0; i < count; i++) {
        numbers[i] = 0;
    }
}
```

### Use `static`

```
int *get_numbers(void)
{
    static int numbers[3] = {1, 2, 3};
    return numbers;
}
```

The array remains available, but calling the function again can replace its contents.

### Allocate memory dynamically

```
int *numbers = malloc(3 * sizeof(int));
```

This requires:

```
#include <stdlib.h>
```

And later:

```
free(numbers);
```

---

## 6. VLA arrays

A VLA, or variable-length array, has a size determined while the program is running.

```
void process(size_t count)
{
    int numbers[count];
}
```

The size is not fixed when compiling.

Important limitations:

- Usually stored in temporary function memory.
- Cannot safely be returned from the function.
- Large VLAs can cause problems.
- Support is optional in newer C versions.

For flexible or large arrays, dynamic memory is often better:

```
int *numbers = malloc(count * sizeof(int));

if (numbers != NULL) {
    /* use numbers */
    free(numbers);
}
```

---

## 7. Constants and `const`

`const` means “do not modify this through this name.”

```
const int limit = 10;
```

Pointer examples:

```
const int *p;
```

You can change `p`, but not the value accessed through `p`.

```
int *const p = &number;
```

You can change the value through `p`, but not where `p` points.

```
const int *const p = &number;
```

You can change neither the value nor the pointer.

For strings:

```
const char *message = "Hello";
```

Do not modify the text through `message`.

---

## 8. Pointers

A pointer stores the location of another variable.

```
int number = 10;
int *pointer = &number;
```

Here:

- `&number` means “the location of `number`”.
- `pointer` stores that location.
- `*pointer` means “the value at that location”.

```
printf("%d\n", *pointer); // 10

*pointer = 20;

printf("%d\n", number);   // 20
```

Pointers are useful for modifying variables inside functions:

```
void double_value(int *number)
{
    *number = *number * 2;
}
```

Call it like this:

```
int value = 5;
double_value(&value);
```

---

## 9. `&` and `*`

### `&`: get a location

```
int age = 20;
int *p = &age;
```

Read this as:

> Put the location of `age` into `p`.

### `*`: access the value at a location

```
printf("%d\n", *p);
```

Read this as:

> Show me the value stored where `p` points.

The same symbol has two meanings depending on where it appears:

```
int *p; // p is a pointer
*p = 10; // access the value pointed to by p
```

---

## 10. Memory structure

A running C program commonly uses these areas:

### Code

The program instructions.

### Static/global memory

Global variables and variables declared with `static`.

```
int global_value;
static int saved_value;
```

They exist for the entire program.

### Stack

Temporary local variables and function calls.

```
void function(void)
{
    int number = 10;
}
```

`number` normally disappears when the function ends.

### Heap

Memory requested manually with `malloc`, `calloc`, or `realloc`.

```
int *number = malloc(sizeof(int));

if (number != NULL) {
    *number = 10;
    free(number);
}
```

Every successful `malloc` should eventually have a matching `free`.

---

## 11. Safer array practices

C does not automatically check array boundaries. You must do it yourself.

Good practice:

```
#define COUNT 5

int numbers[COUNT];

for (size_t i = 0; i < COUNT; i++) {
    numbers[i] = 0;
}
```

For strings:

```
char text[20];

fgets(text, sizeof(text), stdin);
```

Prefer `fgets` over unsafe input functions such as `gets`.

Always:

- Track the array size.
- Check indexes before using them.
- Leave space for `'\0'` in strings.
- Use `%zu` for `size_t`.
- Check whether `malloc` returned `NULL`.
- Call `free` for dynamically allocated memory.
- Do not use pointers after the memory they point to has disappeared.