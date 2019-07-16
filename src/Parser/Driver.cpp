/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Driver.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 12:43:26 by jhache            #+#    #+#             */
/*   Updated: 2019/07/16 16:19:41 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Driver.hpp"

Driver::Driver(InstructionContainer &list)
	: trace_parsing(false), trace_scanning(false), _instructionList(list)
{}

Driver::Driver(Driver const &src)
	: _instructionList(src._instructionList)
{}

Driver::~Driver()
{}


Driver	&Driver::operator=(Driver const &rhs)
{//no use
	static_cast<void>(rhs);
	return *this;
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

void	Driver::pushInstruction(IInstruction *inst)
{
	this->_instructionList.push_back(inst);
}