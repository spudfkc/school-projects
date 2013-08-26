/*
 * Parser.h
 *
 *  Created on: Jan 28, 2013
 *      Author: ncc
 */

#ifndef PARSER_H_
#define PARSER_H_
#include <string>
#include <vector>
#include <map>
#include "Expression.h"
#include "ExpressionFactory.h"

class Parser {
private:
	void trim(std::string&);
	typedef Expression * (JazExpression::ExpressionFactory::*exp_method_t)(std::string);
	typedef std::map<std::string, exp_method_t> exp_func_map_t;
	exp_func_map_t createMap;
	JazExpression::ExpressionFactory factory;
	std::map<std::string, int> labelMap;       // maps label name to index (1 indexed)
	std::vector<Expression> expressionList;    // list of parsed expressions
public:
	std::map<std::string, int> getLabelMap(void);
	std::vector<Expression*> parse(std::string);
	Parser();
	virtual ~Parser();
};

#endif /* PARSER_H_ */
