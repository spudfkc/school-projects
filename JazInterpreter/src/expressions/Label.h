/*
 * Label.h
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#ifndef LABEL_H_
#define LABEL_H_

#include "../Expression.h"

namespace JazExpression {

class Label : public Expression {
public:
	void interpret(Context*);
	Label(std::string);
	virtual ~Label();
};

} /* namespace JazExpression */
#endif /* LABEL_H_ */
