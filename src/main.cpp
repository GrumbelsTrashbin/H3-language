#include <string>

const int VARIABLE_NOT_FOUND = 1201;


class Value {
	public:
		std::string type;
		//void* data; //Let's be serious later
		int data;
		Value(std::string type, int data) {
			this->type = type;
			this->data = data;
		}
};

class Environment {
	public:
		virtual Environment insert(std::string name, Value value);
		virtual Value lookup(std::string name);
};

class NonEmptyEnvironment: public Environment {
	public:
		std::string name;
		Value value;
		Environment* parent;
		virtual Environment insert(std::string name, Value value) {
			return NonEmptyEnvironment(name, value, this);
		}
		NonEmptyEnvironment(std::string name, Value value, Environment* parent) {
			this->name=name;
			this->value=value;
			this->parent=parent;
		}
};

class EmptyEnvironment: public Environment {
	public:
		virtual Environment insert(std::string name, Value value) {
			return NonEmptyEnvironment(name, value, this);
		}
		virtual Value lookup(std::string name) { throw VARIABLE_NOT_FOUND; }
};

class AST_node {
	virtual Value visit();
};

int main() {
	return 0;
}