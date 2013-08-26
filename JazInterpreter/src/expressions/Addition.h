/*
 * Addition.h
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#ifndef ADDITION_H_
#define ADDITION_H_
#include <string.h>
#include "../Expression.h"

namespace JazExpression {

class Addition : public Expression {
public:
	void interpret(Context*);
	Addition(std::string);
	virtual ~Addition();
};

} /* namespace JazExpression */
#endif /* ADDITION_H_ */
