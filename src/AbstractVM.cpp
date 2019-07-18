/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractVM.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:45:54 by jhache            #+#    #+#             */
/*   Updated: 2019/07/18 13:01:32 by jhache           ###   ########.fr       */
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


bool		AbstractVM::parse(int argc, char **argv)
{
	int		res;

	if (argc == 1)
	{
		std::cout << "usage:\n./abstract_vm [-p] [-s] filename" << std::endl << std::endl;
		std::cout << "global options:\n  -p\tactivate trace on parsing\n  -s\tactivate trace on scanning" << std::endl;
		return false;
	}

	for (int i = 1; i < argc; ++i)
	{
		if (argv[i] == std::string("-p"))
			this->_parser.trace_parsing = true;
		else if (argv[i] == std::string("-s"))
			this->_parser.trace_scanning = true;
		else
		{
			res = this->_parser.parse(argv[i]);

			if (res != 0)
				std::cout << "An error occurs during parsing '" << argv[i] << "' file." << std::endl;
			return res == 0;
		}
	}
	std::cout << "Error: no filename provided." << std::endl;
	return false;
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
