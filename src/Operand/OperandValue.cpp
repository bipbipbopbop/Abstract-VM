/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandValue.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 12:05:26 by jhache            #+#    #+#             */
/*   Updated: 2019/07/17 14:29:54 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OperandValue.hpp"
#include <type_traits>
#include <cmath>


OperandValue::OperandValue()
	: type(OperandType::Unknown)
{}

OperandValue::OperandValue(OperandValue const &src)
	: value(src.value), type(src.type)
{}

OperandValue::OperandValue(OperandValue &&src)
	: value(src.value), type(src.type)
{}

OperandValue::~OperandValue()
{}

OperandValue	&OperandValue::operator=(OperandValue const &rhs)
{
	this->value = rhs.value;
	this->type = rhs.type;

	return *this;
}

OperandValue	&OperandValue::operator=(OperandValue &&rhs)
{
	std::swap(this->value, rhs.value);
	this->type = rhs.type;

	return *this;
}


OperandValue	OperandValue::operator+(OperandValue const &rhs) const
{
	switch (this->type)
	{
		case OperandType::Int8:
			return safeAdd(this->value.i8, rhs.value.i8);
		case OperandType::Int16:
			return safeAdd(this->value.i16, rhs.value.i16);
		case OperandType::Int32:
			return safeAdd(this->value.i32, rhs.value.i32);
		case OperandType::Float:
			return safeAdd(this->value.f, rhs.value.f);
		case OperandType::Double:
			return safeAdd(this->value.d, rhs.value.d);
		default:
			throw OperandValue_BadType();
	}
}

OperandValue	OperandValue::operator-(OperandValue const &rhs) const
{
	switch (this->type)
	{
		case OperandType::Int8:
			return safeSub(this->value.i8, rhs.value.i8);
		case OperandType::Int16:
			return safeSub(this->value.i16, rhs.value.i16);
		case OperandType::Int32:
			return safeSub(this->value.i32, rhs.value.i32);
		case OperandType::Float:
			return safeSub(this->value.f, rhs.value.f);
		case OperandType::Double:
			return safeSub(this->value.d, rhs.value.d);
		default:
			throw OperandValue_BadType();
	}
}

OperandValue	OperandValue::operator*(OperandValue const &rhs) const
{
	switch (this->type)
	{
		case OperandType::Int8:
			return safeMul(this->value.i8, rhs.value.i8);
		case OperandType::Int16:
			return safeMul(this->value.i16, rhs.value.i16);
		case OperandType::Int32:
			return safeMul(this->value.i32, rhs.value.i32);
		case OperandType::Float:
			return safeMul(this->value.f, rhs.value.f);
		case OperandType::Double:
			return safeMul(this->value.d, rhs.value.d);
		default:
			throw OperandValue_BadType();
	}
}

OperandValue	OperandValue::operator/(OperandValue const &rhs) const
{
	switch (this->type)
	{
		case OperandType::Int8:
			return safeDiv(this->value.i8, rhs.value.i8);
		case OperandType::Int16:
			return safeDiv(this->value.i16, rhs.value.i16);
		case OperandType::Int32:
			return safeDiv(this->value.i32, rhs.value.i32);
		case OperandType::Float:
			return safeDiv(this->value.f, rhs.value.f);
		case OperandType::Double:
			return safeDiv(this->value.d, rhs.value.d);
		default:
			throw OperandValue_BadType();
	}
}

OperandValue	OperandValue::operator%(OperandValue const &rhs) const
{
	switch (this->type)
	{
		case OperandType::Int8:
			return safeMod(this->value.i8, rhs.value.i8);
		case OperandType::Int16:
			return safeMod(this->value.i16, rhs.value.i16);
		case OperandType::Int32:
			return safeMod(this->value.i32, rhs.value.i32);
		case OperandType::Float:
			return safeMod(this->value.f, rhs.value.f);
		case OperandType::Double:
			return safeMod(this->value.d, rhs.value.d);
		default:
			throw OperandValue_BadType();
	}
}


bool	OperandValue::operator==(OperandValue const &rhs) const
{
	OperandType	typeToCast = rhs.type > this->type ? rhs.type : this->type;

	switch (typeToCast)
	{
		case OperandType::Int8:
			return this->value.i8 == rhs.value.i8;
		case OperandType::Int16:
			return this->value.i16 == rhs.value.i16;
		case OperandType::Int32:
			return this->value.i32 == rhs.value.i32;
		case OperandType::Float:
			return this->value.f == rhs.value.f;
		case OperandType::Double:
			return this->value.d == rhs.value.d;
		default:
			throw OperandValue_BadType();
	}
}

bool	OperandValue::operator!=(OperandValue const &rhs) const
{
	return !(this->operator==(rhs));
}