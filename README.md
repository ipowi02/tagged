### Usage: 
This implementation contains a global field of X macros called `TAGGED_TYPES`, which you extend by adding fields like 
```c
X(<enum member name>, <type>, <union member name>, __VA_ARGS__)
```
What enum and union this updates are the ones used in `tagged_t`, so recompiling header is neccessary after extending it.

A `tagged_t` has two fields: a `.kind`, and a union of different types, defined in the X macro list, so iterating over the fields is possible by:
```c
tagged_t x = tag(1337);
switch(x.kind) {
  case INTEGER:
    ...
  break;
  case STRING:
    ...
  break;

}
```
This implementation also has a linear array of strings in `tagged_type_name`, which store the kinds as strings, with their respective index.<br>
So for instance: `strcmp(tagged_type_name[FLOAT], "FLOAT") == 0`.

Have fun using it :p
