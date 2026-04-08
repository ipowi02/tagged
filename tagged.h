#ifndef TAGGED_H
#define TAGGED_H
#include <stddef.h>
#define TAGGED_TYPES(X, ...)				\
     X(INTEGER, int, i, __VA_ARGS__)		\
	  X(FLOAT, float, f, __VA_ARGS__)	\
	  X(DOUBLE, double, lf, __VA_ARGS__)	\
	  X(CHAR, char, c, __VA_ARGS__)		\
	  X(USIZE, size_t, zu, __VA_ARGS__)	\
	  X(STRING, char*, s, __VA_ARGS__)	\

typedef enum {
#define EXPAND_ENUM(kind, ...) kind,
     TAGGED_TYPES(EXPAND_ENUM)
#undef EXPAND_ENUM
     POINTER,
} tagged_kind_e;

typedef union {
#define EXPAND_UNION(kind, ctype, field, ...) ctype field;
     TAGGED_TYPES(EXPAND_UNION)
#undef EXPAND_UNION
	  void *p;
} tagged_raw_t;

static const char *tagged_type_name[] = {
#define EXPAND_NAME(kind, ...) #kind,
     TAGGED_TYPES(EXPAND_NAME)
#undef EXPAND_NAME
};


typedef struct tagged {
     union {
#define EXPAND_UNION(kind, ctype, field, ...) ctype field;
	  TAGGED_TYPES(EXPAND_UNION)
#undef EXPAND_UNION
	       void *p;
     };
     tagged_kind_e kind;
} tagged_t;



#define EXPAND_TAG(_kind, ctype, field, val)		\
     ctype: (tagged_t){ .field = *(ctype *)(val), .kind = _kind },

#define tag(_val) _Generic((_val),					\
			   TAGGED_TYPES(EXPAND_TAG, _val)			\
			   default: (tagged_t){ .p = (void*)(_val), .kind = POINTER } \
	  )


#endif // TAGGED_H
  
