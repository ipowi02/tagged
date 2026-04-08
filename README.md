## Prerequisites
- C11
---
### Usage 
This implementation contains a global field of X macros called `TAGGED_TYPES`, which are extensible like the following: 
```c
X(<enum member name>, <type>, <union member name>, __VA_ARGS__) // "__VA_ARGS__" is necessary at the end
```
What enum and union this updates are the ones used in `tagged_t`, so recompiling the header is necessary after extending it with types.

The macro `tag` uses `_Generic` for switching on the tags, defaulting to a `void*`.


A `tagged_t` has two fields: a `.kind`, and a union of the different types defined in the X macro list, so iterating over the fields is possible by:
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
This implementation also has a linear array of strings in `tagged_type_name`, which stores the kinds as strings, with their respective index.<br>
So for instance: `strcmp(tagged_type_name[FLOAT], "FLOAT") == 0`.

Have fun using it :p
