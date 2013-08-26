/*
 * Subtraction.cpp
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#include "Subtraction.h"

namespace JazExpression {

void Subtraction::interpret(Context *context) {
	int value1 = stringToInt(context->pop());
	int value2 = stringToInt(context->pop());

	int value = value2 - value1;
	context->push(intToString(value));

	
}

Subtraction::Subtraction(std::string args) : Expression(args) {
	// TODO Auto-generated constructor stub
}

Subtraction::~Subtraction() {
	// TODO Auto-generated destructor stub
}

} /* namespace JazExpression */
