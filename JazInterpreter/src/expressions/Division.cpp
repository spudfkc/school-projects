/*
 * Division.cpp
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#include "Division.h"

namespace JazExpression {

void Division::interpret(Context *context) {
	// get the top two values from context
	int value1 = stringToInt(context->pop());
	int value2 = stringToInt(context->pop());

	// divide value2 by value1 and return the push
	int value = value2 / value1;
	context->push(intToString(value));

	
}

Division::Division(std::string args) : Expression(args) {
	// TODO Auto-generated constructor stub

}

Division::~Division() {
	// TODO Auto-generated destructor stub
}

} /* namespace JazExpression */
