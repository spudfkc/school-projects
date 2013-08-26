/*
 * Multiplication.cpp
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#include "Multiplication.h"

namespace JazExpression {

void Multiplication::interpret(Context *context) {
	int value1 = stringToInt(context->pop());
	int value2 = stringToInt(context->pop());

	int value = value2 * value1;
	context->push(intToString(value));
	
}

Multiplication::Multiplication(std::string args) : Expression(args) {
	// TODO Auto-generated constructor stub

}

Multiplication::~Multiplication() {
	// TODO Auto-generated destructor stub
}

} /* namespace JazExpression */
