/*
 * Or.h
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#ifndef OR_H_
#define OR_H_
#include "../Expression.h"
namespace JazExpression {

class Or : public Expression {
public:
	void interpret(Context*);
	Or(std::string);
	virtual ~Or();
};

} /* namespace JazExpression */
#endif /* OR_H_ */
