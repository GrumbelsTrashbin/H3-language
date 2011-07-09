#include "value.h"

Value::Value() {
}

Value::Value(std::string type, int data) {
	this->type = type;
	this->data = data;
}
