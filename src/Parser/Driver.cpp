/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Driver.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 12:43:26 by jhache            #+#    #+#             */
/*   Updated: 2019/07/11 10:24:23 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Driver.hpp"

Driver::Driver(void *list)
	: trace_parsing(false), trace_scanning(false), _instructionList(list)
{}

Driver::Driver(Driver const &src)
	: _instructionList(src._instructionList)
{}

Driver::~Driver()
{
	delete this->_op;
}


Driver	&Driver::operator=(Driver const &rhs)
{//no use
	static_cast<void>(rhs);
	return *this;
}


void	Driver::setStr(std::string str)
{
	std::swap(this->_str, str);
}

void	Driver::setOperand(Operand *op)
{
	this->_op = op;
}

void	Driver::setOperandType(OperandType type)
{
	this->_opType = type;
}

int		Driver::parse(std::string const &fileName)
{
	int		result;

	this->_fileName = fileName;
	location.initialize(&this->_fileName);
	this->_scanBegin();

	yy::parser parser(*this);
	parser.set_debug_level(false);

	result = parser();
	this->_scanEnd();

	return result;
}

void	Driver::pushInstruction(void *inst)
{
	this->_instructionList = inst;
}