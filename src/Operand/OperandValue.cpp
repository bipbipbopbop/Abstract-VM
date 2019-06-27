/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandValue.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 12:05:26 by jhache            #+#    #+#             */
/*   Updated: 2019/06/27 13:56:18 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OperandValue.hpp"
#include <type_traits>
#include <cmath>


OperandValue::OperandValue()
	: type(OperandType::Unknown)
{}

OperandValue::OperandValue(OperandValue const &rhs)
{
	*this = rhs;
}

OperandValue::~OperandValue()
{}

OperandValue	&OperandValue::operator=(OperandValue const &rhs)
{
	this->value = rhs.value;
	this->type = rhs.type;

	return *this;
}

OperandValue	OperandValue::operator+(OperandValue const &rhs) const
{
	switch (this->type)
	{
		case OperandType::Int8:
			return (this->value.i8 + rhs.value.i8);
		case OperandType::Int16:
			return (this->value.i16 + rhs.value.i16);
		case OperandType::Int32:
			return (this->value.i32 + rhs.value.i32);
		case OperandType::Float:
			return (this->value.f + rhs.value.f);
		case OperandType::Double:
			return (this->value.d + rhs.value.d);
		default:
			//throw OperandValue_BadType();
			return OperandValue();
	}
}

OperandValue	OperandValue::operator-(OperandValue const &rhs) const
{
	switch (this->type)
	{
		case OperandType::Int8:
			return (this->value.i8 - rhs.value.i8);
		case OperandType::Int16:
			return (this->value.i16 - rhs.value.i16);
		case OperandType::Int32:
			return (this->value.i32 - rhs.value.i32);
		case OperandType::Float:
			return (this->value.f - rhs.value.f);
		case OperandType::Double:
			return (this->value.d - rhs.value.d);
		default:
			//throw OperandValue_BadType();
			return OperandValue();
	}
}

OperandValue	OperandValue::operator*(OperandValue const &rhs) const
{
	switch (this->type)
	{
		case OperandType::Int8:
			return (this->value.i8 * rhs.value.i8);
		case OperandType::Int16:
			return (this->value.i16 * rhs.value.i16);
		case OperandType::Int32:
			return (this->value.i32 * rhs.value.i32);
		case OperandType::Float:
			return (this->value.f * rhs.value.f);
		case OperandType::Double:
			return (this->value.d * rhs.value.d);
		default:
			//throw OperandValue_BadType();
			return OperandValue();
	}
}

OperandValue	OperandValue::operator/(OperandValue const &rhs) const
{
	switch (this->type)
	{
		case OperandType::Int8:
			return (this->value.i8 / rhs.value.i8);
		case OperandType::Int16:
			return (this->value.i16 / rhs.value.i16);
		case OperandType::Int32:
			return (this->value.i32 / rhs.value.i32);
		case OperandType::Float:
			return (this->value.f / rhs.value.f);
		case OperandType::Double:
			return (this->value.d / rhs.value.d);
		default:
			//throw OperandValue_BadType();
			return OperandValue();
	}
}

OperandValue	OperandValue::operator%(OperandValue const &rhs) const
{
	switch (this->type)
	{
		case OperandType::Int8:
			return (this->value.i8 % rhs.value.i8);
		case OperandType::Int16:
			return (this->value.i16 % rhs.value.i16);
		case OperandType::Int32:
			return (this->value.i32 % rhs.value.i32);
		case OperandType::Float:
			return (fmodf(this->value.f, rhs.value.f));
		case OperandType::Double:
			return (fmod(this->value.d, rhs.value.d));
		default:
			//throw OperandValue_BadType();
			return OperandValue();
	}
}
