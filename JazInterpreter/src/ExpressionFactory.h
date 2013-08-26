/*
 * ExpressionFactory.h
 *
 *  Created on: Jan 29, 2013
 *      Author: ncc
 */

#ifndef EXPRESSIONFACTORY_H_
#define EXPRESSIONFACTORY_H_
#include "Expression.h"
#include "expressions/Push.h"

namespace JazExpression {

class ExpressionFactory {
public:
	Expression * createPush(std::string);
	Expression * createRvalue(std::string);
	Expression * createLvalue(std::string);
	Expression * createPop(std::string);
	Expression * createAssign(std::string);

	Expression * createLabel(std::string);
	Expression * createGoto(std::string);
	Expression * createGofalse(std::string);
	Expression * createGotrue(std::string);
	Expression * createHalt(std::string);

	Expression * createAddition(std::string);
	Expression * createSubtraction(std::string);
	Expression * createMultiplication(std::string);
	Expression * createDivision(std::string);
	Expression * createModulo(std::string);

	Expression * createAnd(std::string);
	Expression * createNot(std::string);
	Expression * createOr(std::string);

	Expression * createNotEqual(std::string);
	Expression * createLessEqual(std::string);
	Expression * createGreaterEqual(std::string);
	Expression * createLess(std::string);
	Expression * createGreater(std::string);
	Expression * createEqual(std::string);

	Expression * createPrint(std::string);
	Expression * createShow(std::string);

	Expression * createBegin(std::string);
	Expression * createEnd(std::string);
	Expression * createReturn(std::string);
	Expression * createCall(std::string);


	ExpressionFactory();
	virtual ~ExpressionFactory();
};

} /* namespace JazExpression */
#endif /* EXPRESSIONFACTORY_H_ */
