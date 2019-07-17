/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 11:14:39 by jhache            #+#    #+#             */
/*   Updated: 2019/07/17 19:08:05 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operand.hpp"
#include <type_traits>
#include <sstream>

Operand::Operand()
	: _type(OperandType::Unknown)
{}

Operand::Operand(OperandValue value)
{
	if (value.type == OperandType::Unknown)
		throw OperandValue_BadType();

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
	: _valueStr(src._valueStr), _type(src._type)
{}

Operand::Operand(Operand &&src)
{
	std::swap(this->_valueStr, src._valueStr);
	this->_type = src._type;
}

Operand::~Operand()
{}


Operand	&Operand::operator=(Operand rhs)
{
	std::swap(this->_valueStr, rhs._valueStr);
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
			throw OperandValue_BadType();
	}
}

template <typename FloatT>
static bool			_testUnderflow(FloatT value, std::string strValue)
{
	static_assert(std::is_floating_point<FloatT>::value,
			"Template argument must be a floating point value.");

	//delete unwanted 0
	strValue.erase(0, std::min(strValue.find_first_not_of('0'), strValue.size() - 1));
	std::reverse(strValue.begin(), strValue.end());

	strValue.erase(0, std::min(strValue.find_first_not_of('0'), strValue.size() - 1));
	std::reverse(strValue.begin(), strValue.end());

	return (strValue.find(std::to_string(value)) == std::string::npos);
}

Operand				*Operand::StrToOperand(std::string const &str, OperandType type)
{
	union {
		int8_t	i8;
		int16_t	i16;
		int32_t	i32;
		float	f;
		double	d;
	}					testValue;
	std::istringstream	iss(str);

	switch (type)
	{
		case OperandType::Int8:
			//streams interpret int8_t as char, and thus only read one byte
//			iss >> testValue.i8;
//			break;
		case OperandType::Int16:
			iss >> testValue.i16;
			break;
		case OperandType::Int32:
			iss >> testValue.i32;
			break;
		case OperandType::Float:
			iss >> testValue.f;
			break;
		case OperandType::Double:
			iss >> testValue.d;
			break;
		default:
			throw OperandValue_BadType();
	}
	if (iss.fail() || (type == OperandType::Int8 && static_cast<int16_t>(testValue.i8) != testValue.i16))
		throw OperandValue_Overflow("Invalid type for value '" + str + "'");
	else if (type == OperandType::Float || type == OperandType::Double)
	{
		if (_testUnderflow(type == OperandType::Float ? testValue.f : testValue.d, str))
			;//throw OperandValue_Underflow();//Seriously, i'm not going to stop my program for that
	}

	return new Operand(Operand::convertStr(str, type));
}