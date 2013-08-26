/*
 * Modulo.h
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#ifndef MODULO_H_
#define MODULO_H_
#include "../Expression.h"
namespace JazExpression {

class Modulo : public Expression {
public:
	void interpret(Context*);
	Modulo(std::string);
	virtual ~Modulo();
};

} /* namespace JazExpression */
#endif /* MODULO_H_ */
