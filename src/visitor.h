#ifndef H3_VISITOR
#define H3_VISITOR

#include "environment.h"
#include "value.h"
#include "AST.h"

class AST_constant;

class Visitor {
	public:
		virtual Value visit(Environment environment, AST_constant node);
};

#endif