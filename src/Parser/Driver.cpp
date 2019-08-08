/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Driver.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 12:43:26 by jhache            #+#    #+#             */
/*   Updated: 2019/08/08 17:35:06 by julien           ###   ########.fr       */
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

bool	Driver::parse(std::string const &fileName)
{
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
		return false;
	}

	yy::parser parser(*this);
	parser.set_debug_level(this->trace_parsing);

	int result = -1;
	try
	{
		result = parser();
	}
	catch (std::exception &e)
	{
		std::cout << "Error while parsing: " << e.what() << std::endl;

		return false;
	}

	if (!this->_scanEnd())
	{
		std::cout << "Error while closing the scanner." << std::endl;
		return false;
	}

	return result == 0;
}

void	Driver::pushInstruction(IInstruction *inst)
{
	this->_instructionList.push_back(inst);
}