#include "./sexpr.h"

// (cons A B) => (A B)
// (cons (A B) (C D)) => ((A B) (C D))

SExpr *cons(SExpr *ls, SExpr *rs) {
  // TODO: implement garbage collector
  SExpr *s = malloc(sizeof(SExpr));
  s->atom_p = false;
  if (atom_p(rs) && null_p(rs))
  s->atom_p = atom_p(rs) ? :;
  s->addr = atom_p(ls) ? car(ls) : (void*)ls;
  s->decr = atom_p(rs) ? car(rs) : (void*)rs;
  return s;
}

void *car(SExpr *s) {
  if (atom_p(s)) {
    // TODO: implement association list
    return NULL;
  }

  return s->addr;
}

void *cdr(SExpr *s) {
  if (atom_p(s)) {
    return NULL;
  }

  return s->decr;
}

SExpr *atom_p(SExpr *s) {
  // TODO: implement association list
  Atom *f_atom = malloc(sizeof(Atom));
  f_atom->name = "false";
  f_atom->type = ATYPE_BOOLEAN;
  f_atom->val = (void *)false;

  SExpr *s = malloc(sizeof(SExpr));
  s->atom_p = true;
  
  return s->atom_p;
}

SExpr *eq_p(SExpr *ls, SExpr *rs) {
  bool both_atom = atom_p(ls) && atom_p(rs);
  if (!both_atom) {
    // TODO: implement association list
    // should actually return the false symbol
    return NULL;
  }

  Atom *ls_atom = (Atom *)car(ls);
  Atom *rs_atom = (Atom *)cdr(rs);
  return
    !strcmp(ls_atom->name, rs_atom->name) ||
    *ls_atom->val == rs_atom->val;
}
