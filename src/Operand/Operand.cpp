/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 11:14:39 by jhache            #+#    #+#             */
/*   Updated: 2019/06/27 14:17:04 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operand.hpp"
#include <type_traits>

Operand::Operand()
	: _type(OperandType::Unknown)
{}

Operand::Operand(OperandValue value)
{
//	if (value.type == OperandType::Unknown)
//		throw OperandValue_BadType();

	if (value.type == OperandType::Int8)
		this->_valueStr = std::to_string(value.value.i8);
	else if (value.type == OperandType::Int16)
		this->_valueStr = std::to_string(value.value.i16);
	else if (value.type == OperandType::Int32)
		this->_valueStr = std::to_string(value.value.i32);
	else if (value.type == OperandType::Float)
		this->_valueStr = std::to_string(value.value.f);
	else if (value.type == OperandType::Double)
		this->_valueStr = std::to_string(value.value.d);
	
	this->_type = value.type;
}

Operand::Operand(Operand const &src)
{
	*this = src;
}

Operand::~Operand()
{}


Operand  &Operand::operator=(Operand const &rhs)
{
	this->_valueStr = rhs._valueStr;
	this->_type = rhs._type;

	return *this;
}


int					Operand::getPrecision() const
{
	return static_cast<int>(this->_type);
}

OperandType			Operand::getType() const
{
	return this->_type;
}

IOperand const		*Operand::operator+(IOperand const &rhs) const
{
	const OperandType	typeToCast =
		this->getPrecision() >= rhs.getPrecision() ? this->getType() : rhs.getType();
	
	return new Operand(Operand::convertStr(this->toString(), typeToCast)
		+ Operand::convertStr(rhs.toString(), typeToCast));
}

IOperand const		*Operand::operator-(IOperand const &rhs) const
{
	const OperandType	typeToCast =
		this->getPrecision() >= rhs.getPrecision() ? this->getType() : rhs.getType();
	
	return new Operand(Operand::convertStr(this->toString(), typeToCast)
		- Operand::convertStr(rhs.toString(), typeToCast));
}

IOperand const		*Operand::operator*(IOperand const &rhs) const
{
	const OperandType	typeToCast =
		this->getPrecision() >= rhs.getPrecision() ? this->getType() : rhs.getType();
	
	return new Operand(Operand::convertStr(this->toString(), typeToCast)
		* Operand::convertStr(rhs.toString(), typeToCast));
}

IOperand const		*Operand::operator/(IOperand const &rhs) const
{
	const OperandType	typeToCast =
		this->getPrecision() >= rhs.getPrecision() ? this->getType() : rhs.getType();
	
	return new Operand(Operand::convertStr(this->toString(), typeToCast)
		/ Operand::convertStr(rhs.toString(), typeToCast));
}

IOperand const		*Operand::operator%(IOperand const &rhs) const
{
	const OperandType	typeToCast =
		this->getPrecision() >= rhs.getPrecision() ? this->getType() : rhs.getType();
	
	return new Operand(Operand::convertStr(this->toString(), typeToCast)
		% Operand::convertStr(rhs.toString(), typeToCast));
}

std::string const	&Operand::toString() const
{
	return this->_valueStr;
}

OperandValue		Operand::convertStr(std::string const &str, OperandType type)
{
	switch (type)
	{
		case OperandType::Int8:
			return OperandValue(static_cast<int8_t>(stol(str)));
		case OperandType::Int16:
			return OperandValue(static_cast<int16_t>(stol(str)));
		case OperandType::Int32:
			return OperandValue(static_cast<int32_t>(stol(str)));
		case OperandType::Float:
			return OperandValue(stof(str));
		case OperandType::Double:
			return OperandValue(stod(str));
		default:
			//throw OperandValue_BadType();
			return OperandValue();
	}
}