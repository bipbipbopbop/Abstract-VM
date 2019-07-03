/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Driver.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 12:43:26 by jhache            #+#    #+#             */
/*   Updated: 2019/07/03 13:03:46 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Driver.hpp"

Driver::Driver(void *list)
	_instructionList(list);
{}

Driver::Driver(Driver const &src)
	: _instructionList(src._instructionList)
{}

Driver::~Driver()
{
	delete this->_op;
	//delete this->_inst;
}


Driver	&Driver::operator=(Driver const &rhs)
{//no use
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

void	Driver::setInstruction(void *inst)
{
	this->_inst = inst;
}

int		Driver::parse(std::string const &fileName)
{
	int		result;

	this->_fileName = fileName;
	location.initialize(&fileName);
	scan_begin();

	yy::parser parser(*this);
	parse.set_debug_level(false);

	result = parser();
	scan_end();

	return result;
}

void	Driver::_scanBegin()
{}

void	Driver::_scanEnd()
{}
