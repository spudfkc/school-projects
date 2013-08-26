/*
 * Push.cpp
 *
 *  Created on: Jan 28, 2013
 *      Author: ncc
 */

#include "Push.h"
#include "../Context.h"

namespace JazExpression {

void Push::interpret(Context *context) {
	context->push(arguments);
	
}

int Push::stringToInt(std::string str) {
	int result = 0;
	// TODO
	return result;
}

Push::Push(std::string args) : Expression(args) {
}

Push::~Push() {
	// TODO Auto-generated destructor stub
}

} /* namespace JazExpression */
