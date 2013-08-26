/*
 * End.cpp
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#include "End.h"
#include <iostream>

namespace JazExpression {

void End::interpret(Context *context) {
	context->popScope();
}

End::End(std::string args) : Expression(args) {
	// TODO Auto-generated constructor stub

}

End::~End() {
	// TODO Auto-generated destructor stub
}

} /* namespace JazExpression */
