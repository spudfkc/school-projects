/*
 * Gofalse.cpp
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#include "Gofalse.h"
#include <iostream>

namespace JazExpression {

void Gofalse::interpret(Context *context) {
	bool result = false;

	std::string s;

	// TODO - clean this up - it's awful
	if (context->getStackSize() > 0) {
		s = context->pop();

		if (s.empty()) {
			result = false;
		}
		else if (stringToInt(s) == 0) {
			result = false;
		}
//		else if (context->getVariable(s) == 0) {
//			result = false;
//		}
		else {
			result = true;
		}
	}
	else {
		result = false;
	}

	if (!result) {
		context->instructions.pop();
		int index = context->getIndexForLabel(arguments);
		context->instructions.push(index);
	}
}

Gofalse::Gofalse(std::string args) : Expression(args) {
	// TODO Auto-generated constructor stub

}

Gofalse::~Gofalse() {
	// TODO Auto-generated destructor stub
}

} /* namespace JazExpression */
