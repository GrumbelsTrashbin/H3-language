#ifndef H3_AST
#define H3_AST

#include "environment.h"
#include "value.h"
#include "visitor.h"

class Visitor;

class AST_node {
	public:
		virtual Value accept(Environment environment, Visitor& visitor) { return Value(); }
};

class AST_constant: public AST_node {
	public:
		int value;
		virtual Value accept(Environment environment, Visitor& visitor);
};

class AST_statement: public AST_node {

};

#endif