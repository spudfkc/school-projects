/*
 * Goto.h
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#ifndef GOTO_H_
#define GOTO_H_
#include "../Expression.h"

namespace JazExpression {

class Goto : public Expression {
public:
	void interpret(Context*);
	Goto(std::string);
	virtual ~Goto();
};

} /* namespace JazExpression */
#endif /* GOTO_H_ */
