/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Driver.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 12:36:05 by jhache            #+#    #+#             */
/*   Updated: 2019/07/11 10:24:28 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRIVER_HPP
# define DRIVER_HPP

# include "Operand.hpp"
# include "Parser.tab.h"

class Driver
{
public:
	Driver(void *list = nullptr);
	Driver(Driver const &src);
	~Driver();

	Driver	&operator=(Driver const &rhs);

	void	setStr(std::string str);
	void	setOperand(Operand *op);
	void	setOperandType(OperandType type);

	int		parse(std::string const &fileName);
	void	pushInstruction(void *inst);//should be a Instruction class pointer

	// set as public because it is used by the parser/lexer, not by me
	yy::location	location;
	// those 2 booleans are used for debugging options
	bool			trace_parsing;
	bool			trace_scanning;

private:
	//intermediate values that is loaded and used during parsing
	std::string		_str;
	Operand			*_op;
	OperandType		_opType;

	// the list that will load the parsed data
	void			*_instructionList;//should be a reference to a InstructionList class instance

	std::string		_fileName;

	// those 2 functions are implemented in the corresponding .l files
	void	_scanBegin();
	void	_scanEnd();

};

// Give Flex the prototype of yylex we want ...
# define YY_DECL \
	yy::parser::symbol_type yylex (Driver& drv)
// ... and declare it for the parser's sake.
YY_DECL;

#endif //DRIVER_HPP