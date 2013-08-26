/*
 * Call.cpp
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#include "Call.h"
#include <iostream>

namespace JazExpression {

void Call::interpret(Context *context) {
	int index = context->getIndexForLabel(arguments);
	context->instructions.push(index);
	context->getScope()->afterCall = -1;
}

Call::Call(std::string args) : Expression(args) {
	// TODO Auto-generated constructor stub

}

Call::~Call() {
	// TODO Auto-generated destructor stub
}

} /* namespace JazExpression */
