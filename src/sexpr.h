#ifndef SEXPR_H
#define SEXPR_H

#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

#ifndef MAX_ATOMS
#define MAX_ATOMS 512
#endif

#ifndef MAX_SEXPRS
#define MAX_SEXPRS 512
#endif

typedef enum AtomType {
  ATYPE_STRING,  // "hello world", bye
  ATYPE_INT,     // 1, 2, 5
  ATYPE_FLOAT,   // 1.0, 3.33
  ATYPE_BOOLEAN, // t or f
  ATYPE_NIL,     // nil
  ATYPE_ATOM     // itself i.e my-atom => my-atom
} AtomType;

typedef struct Atom {
  char *name;
  AtomType type;
  void *val;
} Atom;

typedef struct SExpr {
  bool atom_p;
  // addr and decr can be either another SExpr
  // or an atom
  void *addr;
  void *decr;
} SExpr;

void *car(SExpr *s);
void *cdr(SExpr *s);
SExpr *atom_p(SExpr *s);
SExpr *eq_p(SExpr *ls, SExpr *rs);
SExpr *cons(SExpr *car, SExpr *cdr);

#endif
