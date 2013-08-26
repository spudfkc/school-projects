/*
 * Gofalse.h
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#ifndef GOFALSE_H_
#define GOFALSE_H_
#include "../Expression.h"
namespace JazExpression {

class Gofalse : public Expression {
public:
	void interpret(Context*);
	Gofalse(std::string);
	virtual ~Gofalse();
};

} /* namespace JazExpression */
#endif /* GOFALSE_H_ */
