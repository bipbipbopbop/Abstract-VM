/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandValue.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 11:58:19 by jhache            #+#    #+#             */
/*   Updated: 2019/06/27 14:18:06 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERANDVALUE_HPP
# define OPERANDVALUE_HPP

# include "OperandType.hpp"
#include <type_traits>
# include <cinttypes>

struct	OperandValue
{
	template <typename ArithmeticT>
	OperandValue(ArithmeticT value)
	{
		static_assert(std::is_arithmetic<ArithmeticT>::value,
				"Operand constructor must take one arithmetic value.");

		if constexpr (std::is_same<ArithmeticT, int8_t>::value)
		{
			this->type = OperandType::Int8;
			this->value.i8 = value;
		}
		else if constexpr (std::is_same<ArithmeticT, int16_t>::value)
		{
			this->type = OperandType::Int16;
			this->value.i16 = value;
		}
		else if constexpr (std::is_same<ArithmeticT, int32_t>::value)
		{
			this->type = OperandType::Int32;
			this->value.i32 = value;
		}
		else if constexpr (std::is_same<ArithmeticT, float>::value)
		{
			this->type = OperandType::Float;
			this->value.f = value;
		}
		else if constexpr (std::is_same<ArithmeticT, double>::value)
		{
			this->type = OperandType::Double;
			this->value.d = value;
		}
		else
			this->type = OperandType::Unknown;
	}

	OperandValue();
	OperandValue(OperandValue const &src);
	~OperandValue();

	OperandValue	&operator=(OperandValue const &rhs);

	OperandValue	operator+(OperandValue const &rhs) const;
	OperandValue	operator-(OperandValue const &rhs) const;
	OperandValue	operator*(OperandValue const &rhs) const;
	OperandValue	operator/(OperandValue const &rhs) const;
	OperandValue	operator%(OperandValue const &rhs) const;

	union
	{
		int8_t	i8;
		int16_t	i16;
		int32_t	i32;
		float	f;
		double	d;

	}			value;
	OperandType	type;
};

#endif // OPERANDVALUE_HPP