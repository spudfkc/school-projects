/*
 * LessEqual.h
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#ifndef LESSEQUAL_H_
#define LESSEQUAL_H_
#include "../Expression.h"
namespace JazExpression {

class LessEqual : public Expression {
public:
	void interpret(Context*);
	LessEqual(std::string);
	virtual ~LessEqual();
};

} /* namespace JazExpression */
#endif /* LESSEQUAL_H_ */
