/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Assert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:06:39 by jhache            #+#    #+#             */
/*   Updated: 2019/07/19 11:03:26 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Assert.hpp"
#include "InstructionException.hpp"
#include "OperandFactory.hpp"

Assert::Assert()
	: _value(nullptr)
{}

Assert::Assert(const IOperand *value)
	: _value(value)
{}

Assert::Assert(Assert const &src)
	: _value(OperandFactory::CreateOperand(src._value->getType(), src._value->toString()))
{}

Assert::Assert(Assert &&src)
{
	std::swap(this->_value, src._value);
}

Assert::~Assert()
{
	delete this->_value;
}


Assert	&Assert::operator=(Assert rhs)
{
	std::swap(this->_value, rhs._value);

	return *this;
}


void	Assert::execute(VMStack &stack)
{
	if (this->_value == nullptr)
		throw Instruction_WrongOpPtr("Instruction assert failed");
	else if (stack.size() < 1)
		throw Instruction_NoOpInStack("Instruction assert failed");

	IOperand const	*stackTop = stack.top();
	if (Operand::convertStr(stackTop->toString(), stackTop->getType())
			!= Operand::convertStr(this->_value->toString(), this->_value->getType()))
		throw Instruction_AssertFailed("Values are different");
}
