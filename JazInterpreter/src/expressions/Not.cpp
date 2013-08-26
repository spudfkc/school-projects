/*
 * Not.cpp
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#include "Not.h"

namespace JazExpression {

void Not::interpret(Context *context) {
	unsigned int val = stringToInt(context->pop());
	val = ~val;
	context->push(intToString(val));
	
}

Not::Not(std::string args) : Expression(args) {
	// TODO Auto-generated constructor stub

}

Not::~Not() {
	// TODO Auto-generated destructor stub
}

} /* namespace JazExpression */
