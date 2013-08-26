/*
 * Equal.cpp
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#include "Equal.h"

namespace JazExpression {

void Equal::interpret(Context *context) {
	// get the top two values from context...
	int value1 = stringToInt(context->pop());
	int value2 = stringToInt(context->pop());

	// checks to see if value2 equal to value1
	if (value2 == value1)	
		context->push("1");
	else {
		context->push("0");
	}

	
}

Equal::Equal(std::string args) : Expression(args) {
	// TODO Auto-generated constructor stub

}

Equal::~Equal() {
	// TODO Auto-generated destructor stub
}

} /* namespace JazExpression */
