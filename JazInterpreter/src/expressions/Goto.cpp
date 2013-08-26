/*
 * Goto.cpp
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#include "Goto.h"
#include <iostream>

namespace JazExpression {

void Goto::interpret(Context *context) {
//	std::cout << "This is a GOTO" << std::endl;
	int result = context->getIndexForLabel(arguments);
//	std::cout << "Found label: " << arguments << " @ " << result << std::endl;
	context->instructions.push(result);
}

Goto::Goto(std::string args) : Expression(args) {
	// TODO Auto-generated constructor stub

}

Goto::~Goto() {
	// TODO Auto-generated destructor stub
}

} /* namespace JazExpression */
