/*
 * Assign.cpp
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#include "Assign.h"

namespace JazExpression {

void Assign::interpret(Context *context) {
	int value = stringToInt(context->pop());
	std::string variable = context->pop();
	context->assignVariable(variable, value);
	context->push(variable);
}

Assign::Assign(std::string args) : Expression(args) {
	// TODO Auto-generated constructor stub

}

Assign::~Assign() {
	// TODO Auto-generated destructor stub
}

} /* namespace JazExpression */
