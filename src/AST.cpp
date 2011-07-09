#include "AST.h"

Value AST_constant::accept(Environment environment, Visitor& visitor) { return visitor.visit(environment, *this); }

//Value AST_addition::accept(Environment environment, Visitor visitor) { return visitor.visit(environment, *this); }
