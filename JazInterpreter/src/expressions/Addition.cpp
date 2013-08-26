/*
 * Addition.cpp
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#include "Addition.h"

namespace JazExpression {

void Addition::interpret(Context *context) {
	std::string value1 = context->pop();
	std::string value2 = context->pop();

	int result = Expression::stringToInt(value2) + Expression::stringToInt(value1);
	context->push(Expression::intToString(result));
	
}

Addition::Addition(std::string args) : Expression(args) {
	// TODO Auto-generated constructor stub

}

Addition::~Addition() {
	// TODO Auto-generated destructor stub
}

} /* namespace JazExpression */
