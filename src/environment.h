#ifndef H3_ENVIRONMENT
#define H3_ENVIRONMENT

#include <string>

#include "value.h"
#include "environment.h"
#include "constants.h"

class Environment {
	public:
		virtual Environment insert(std::string name, Value value) { return Environment(); }
		virtual Value lookup(std::string name) { return Value(); }
};

class NonEmptyEnvironment: public Environment {
	public:
		std::string name;
		Value value;
		Environment* parent;
		virtual Environment insert(std::string name, Value value);
		NonEmptyEnvironment(std::string name, Value value, Environment* parent);
};

class EmptyEnvironment: public Environment {
	public:
		virtual Environment insert(std::string name, Value value);
		virtual Value lookup(std::string name);
};

#endif