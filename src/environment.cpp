#include "environment.h"

Environment NonEmptyEnvironment::insert(std::string name, Value value) {
	return NonEmptyEnvironment(name, value, this);
}

NonEmptyEnvironment::NonEmptyEnvironment(std::string name, Value value, Environment* parent) {
	this->name=name;
	this->value=value;
	this->parent=parent;
}

Environment EmptyEnvironment::insert(std::string name, Value value) {
	return NonEmptyEnvironment(name, value, this);
}

Value EmptyEnvironment::lookup(std::string name) { throw VARIABLE_NOT_FOUND; }