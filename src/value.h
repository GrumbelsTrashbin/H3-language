#ifndef H3_VALUE
#define H3_VALUE

#include <string>

class Value {
	public:
		std::string type;
		//void* data; //Let's be serious later
		int data;
		Value();
		Value(std::string type, int data);
};

#endif