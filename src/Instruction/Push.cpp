/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 11:53:43 by jhache            #+#    #+#             */
/*   Updated: 2019/07/19 11:03:30 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push.hpp"
#include "InstructionException.hpp"
#include "OperandFactory.hpp"

Push::Push()
	: _value(nullptr)
{}

Push::Push(const IOperand *value)
	: _value(value)
{}

Push::Push(Push const &src)
	: _value(OperandFactory::CreateOperand(src._value->getType(), src._value->toString()))
{}

Push::Push(Push &&src)
{
	std::swap(this->_value, src._value);
}

Push::~Push()
{
	delete this->_value;
}


Push	&Push::operator=(Push rhs)
{
	std::swap(this->_value, rhs._value);

	return *this;
}


void	Push::execute(VMStack &stack)
{
	if (this->_value == nullptr)
		throw Instruction_WrongOpPtr("Instruction push failed");

	stack.push(this->_value);
}
