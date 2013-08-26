/*
 * Return.h
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#ifndef RETURN_H_
#define RETURN_H_
#include "../Expression.h"

namespace JazExpression {

class Return : public Expression {
public:
	void interpret(Context*);
	Return(std::string);
	virtual ~Return();
};

} /* namespace JazExpression */
#endif /* RETURN_H_ */
