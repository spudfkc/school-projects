/*
 * Call.h
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#ifndef CALL_H_
#define CALL_H_
#include "../Expression.h"

namespace JazExpression {

class Call : public Expression {
public:
	void interpret(Context*);
	Call(std::string);
	virtual ~Call();
};

} /* namespace JazExpression */
#endif /* CALL_H_ */
