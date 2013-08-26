/*
 * Greater.cpp
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#include "Greater.h"

namespace JazExpression {

void Greater::interpret(Context *context) {
	int value1 = stringToInt(context->pop());
	int value2 = stringToInt(context->pop());

	if (value2 > value1) {
		context->push("1");
	}
	else {
		context->push("0");
	}
	
}

Greater::Greater(std::string args) : Expression(args) {
	// TODO Auto-generated constructor stub

}

Greater::~Greater() {
	// TODO Auto-generated destructor stub
}

} /* namespace JazExpression */
