/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractVM.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:45:54 by jhache            #+#    #+#             */
/*   Updated: 2019/07/17 19:12:00 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractVM.hpp"
#include "InstructionException.hpp"

AbstractVM::AbstractVM()
	: _instructionList(), _stack(), _parser(this->_instructionList)
{}

AbstractVM::AbstractVM(AbstractVM const &src)
	: _instructionList(), _stack(), _parser(this->_instructionList)
{
	*this = src;
}

AbstractVM::~AbstractVM()
{}


AbstractVM  &AbstractVM::operator=(AbstractVM const &rhs)
{//no use
	static_cast<void>(rhs);
	return *this;
}


bool		AbstractVM::parse(std::string const &filename)
{
	int		res = this->_parser.parse(filename.c_str());

	if (res != 0)
	{
		//handle error
		return false;
	}
	//maybe check the list ?
	return true;
}

void		AbstractVM::execute()
{
	for (auto * instruction : this->_instructionList)
	{
		try
		{
			if (this->_stack.has_exited)
				throw Instruction_Exit("Exit must be the last instruction.");
			instruction->execute(this->_stack);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	if (!this->_stack.has_exited)
	{
		std::cout << "Error: No Exit in the instruction list." << std::endl;
		exit(EXIT_FAILURE);
	}
}
