/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Driver.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 12:43:26 by jhache            #+#    #+#             */
/*   Updated: 2019/07/18 15:29:52 by jhache           ###   ########.fr       */
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

	if (!this->_instructionList.empty())
		this->_instructionList.clear();

	if (fileName == "-")
		this->_fileName = "stdin";
	else
		this->_fileName = fileName;
	location.initialize(&this->_fileName);
	if (!this->_scanBegin())
	{
		std::cout << "Error while starting the scanner." << std::endl;
		return !0;
	}

	yy::parser parser(*this);
	parser.set_debug_level(this->trace_parsing);

	result = parser();

	if (!this->_scanEnd())
	{
		std::cout << "Error while closing the scanner." << std::endl;
		return !0;
	}

	return result;
}

void	Driver::pushInstruction(IInstruction *inst)
{
	// push_front because the parser work recursively,
	// so it start by the last instruction
	this->_instructionList.push_front(inst);
}