/*
 * Halt.h
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#ifndef HALT_H_
#define HALT_H_
#include "../Expression.h"
namespace JazExpression {


class Halt : public Expression {
public:
	void interpret(Context*);
	Halt(std::string);
	virtual ~Halt();
};

} /* namespace JazExpression */
#endif /* HALT_H_ */
