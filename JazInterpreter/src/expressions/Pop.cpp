/*
 * Pop.cpp
 *
 *  Created on: Jan 29, 2013
 *      Author: ncc
 */

#include "Pop.h"

namespace JazExpression {

void Pop::interpret(Context *context) {
	context->pop();
}

Pop::Pop(std::string args) : Expression(args) {
}

Pop::~Pop() {
	// TODO Auto-generated destructor stub
}

} /* namespace JazExpression */
