/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandValueException.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:10:15 by jhache            #+#    #+#             */
/*   Updated: 2019/07/17 16:59:41 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OperandValueException.hpp"

OperandValueException::OperandValueException(std::string msg, std::string prefix = "")
	: exception::exception(), _msg(prefix + msg)
{}

OperandValueException::OperandValueException(OperandValueException const &src)
	: exception::exception(src)
{
	*this = src;
}

OperandValueException  &OperandValueException::operator=(OperandValueException const &rhs)
{
	this->_msg = rhs._msg;

	return *this;
}

const char	*OperandValueException::what() const noexcept
{
	return this->_msg.c_str();
}


OperandValue_Overflow::OperandValue_Overflow(std::string msg)
	: OperandValueException::OperandValueException(msg, "Overflow: ")
{}

OperandValue_Underflow::OperandValue_Underflow(std::string msg)
	: OperandValueException::OperandValueException(msg, "Underflow: ")
{}

OperandValue_DivisionByZero::OperandValue_DivisionByZero(std::string msg)
	: OperandValueException::OperandValueException(msg, "Division by zero: ")
{}

OperandValue_ModuloByZero::OperandValue_ModuloByZero(std::string msg)
	: OperandValueException::OperandValueException(msg, "Modulo by zero: ")
{}

OperandValue_BadType::OperandValue_BadType(std::string msg)
	: OperandValueException::OperandValueException(msg, "Unknown Operand Type: ")
{}
