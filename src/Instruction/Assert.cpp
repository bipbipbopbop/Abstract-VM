/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Assert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:06:39 by jhache            #+#    #+#             */
/*   Updated: 2019/07/16 14:47:41 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Assert.hpp"

Assert::Assert()
	: _value(nullptr)
{}

Assert::Assert(IOperand *value)
	: _value(value)
{}

Assert::Assert(Assert const &src)
	: _value(Operand::StrToOperand(src._value->toString(), src._value->getType()))
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
		;//throw Instruction_WrongOperandPtr();
	else if (stack.size() < 1)
		;//throw Instruction_NoOperandInStack();

	IOperand const	*stackTop = stack.top();
	if (Operand::convertStr(stackTop->toString(), stackTop->getType())
			!= Operand::convertStr(this->_value->toString(), this->_value->getType()))
		;//throw Instruction_AssertFailed();
}
