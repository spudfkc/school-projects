/*
 * Or.cpp
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#include "Or.h"

namespace JazExpression {

void Or::interpret(Context *context) {
	unsigned int val1 = stringToInt(context->pop());
	unsigned int val2 = stringToInt(context->pop());

	unsigned int result = val1 | val2;
	context->push(intToString(result));
	
}

Or::Or(std::string args) : Expression(args) {
	// TODO Auto-generated constructor stub

}

Or::~Or() {
	// TODO Auto-generated destructor stub
}

} /* namespace JazExpression */
