/*
 * Pop.h
 *
 *  Created on: Jan 29, 2013
 *      Author: ncc
 */

#ifndef POP_H_
#define POP_H_
#include "../Expression.h"

namespace JazExpression {

class Pop : public Expression {
public:
	void interpret(Context*);
	Pop(std::string);
	virtual ~Pop();
};

} /* namespace JazExpression */
#endif /* POP_H_ */
