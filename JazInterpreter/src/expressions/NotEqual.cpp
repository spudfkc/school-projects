/*
 * NotEqual.cpp
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#include "NotEqual.h"

namespace JazExpression {

void NotEqual::interpret(Context *context) {
	int value1 = stringToInt(context->pop());
	int value2 = stringToInt(context->pop());

	if (value2 != value1) {
		context->push("1");
	}
	else {
		context->push("0");
	}

	
}

NotEqual::NotEqual(std::string args) : Expression(args) {
	// TODO Auto-generated constructor stub

}

NotEqual::~NotEqual() {
	// TODO Auto-generated destructor stub
}

} /* namespace JazExpression */
