/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstructionException.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:16:32 by jhache            #+#    #+#             */
/*   Updated: 2019/07/17 17:05:59 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InstructionException.hpp"


InstructionException::InstructionException(std::string msg, std::string prefix = "")
	: exception::exception(), _msg(prefix + msg)
{}

InstructionException::InstructionException(InstructionException const &src)
	: exception::exception(src)
{
	*this = src;
}

InstructionException  &InstructionException::operator=(InstructionException const &rhs)
{
	this->_msg = rhs._msg;

	return *this;
}

const char	*InstructionException::what() const noexcept
{
	return this->_msg.c_str();
}


Instruction_Exit::Instruction_Exit(std::string msg)
	: InstructionException::InstructionException(msg, "Instruction after Exit: ")
{}

Instruction_NoOpInStack::Instruction_NoOpInStack(std::string msg)
	: InstructionException::InstructionException(msg, "No Operator in stack: ")
{}

Instruction_WrongOpPtr::Instruction_WrongOpPtr(std::string msg)
	: InstructionException::InstructionException(msg, "Ill-formed Operand: ")
{}

Instruction_AssertFailed::Instruction_AssertFailed(std::string msg)
	: InstructionException::InstructionException(msg, "Assert failed: ")
{}

Instruction_InvalidTypeForPrint::Instruction_InvalidTypeForPrint(std::string msg)
	: InstructionException::InstructionException(msg, "Invalid type for print: ")
{}
