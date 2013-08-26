/*
 * Return.cpp
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#include "Return.h"
#include <iostream>

namespace JazExpression {

void Return::interpret(Context *context) {
	context->instructions.pop();
	context->getScope()->afterCall = 1;
}

Return::Return(std::string args) : Expression(args) {
	// TODO Auto-generated constructor stub

}

Return::~Return() {
	// TODO Auto-generated destructor stub
}

} /* namespace JazExpression */
