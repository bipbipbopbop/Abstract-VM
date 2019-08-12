/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandValue.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 11:58:19 by jhache            #+#    #+#             */
/*   Updated: 2019/08/12 12:21:31 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERANDVALUE_HPP
# define OPERANDVALUE_HPP

# include "OperandValueException.hpp"
# include "OperandType.hpp"
# include <type_traits>
# include <cinttypes>
# include <cfenv>
# include <cmath>

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
	OperandValue(OperandValue &&src);
	~OperandValue();

	OperandValue	&operator=(OperandValue const &rhs);
	OperandValue	&operator=(OperandValue &&rhs);

	OperandValue	operator+(OperandValue const &rhs) const;
	OperandValue	operator-(OperandValue const &rhs) const;
	OperandValue	operator*(OperandValue const &rhs) const;
	OperandValue	operator/(OperandValue const &rhs) const;
	OperandValue	operator%(OperandValue const &rhs) const;
	bool			operator==(OperandValue const &rhs) const;
	bool			operator!=(OperandValue const &rhs) const;

	union
	{
		int8_t	i8;
		int16_t	i16;
		int32_t	i32;
		float	f;
		double	d;

	}			value;
	OperandType	type;


	template <typename ArithmeticT>
	static OperandValue		safeAdd(ArithmeticT lhs, ArithmeticT rhs)
	{
		ArithmeticT			result;
		static_assert(std::is_arithmetic<ArithmeticT>::value,
				"OperandValue::safeAdd template argument must be an arithmetic type.");

		if constexpr (std::is_integral<ArithmeticT>::value)
		{
			if (__builtin_add_overflow(lhs, rhs, &result))
				throw OperandValue_Overflow("Instruction add Failed");

			return result;
		}
		else
		{
			feclearexcept(FE_OVERFLOW | FE_UNDERFLOW);

			result = lhs + rhs;
			if (fetestexcept(FE_OVERFLOW))
				throw OperandValue_Overflow("Instruction add Failed");
			else if (fetestexcept(FE_UNDERFLOW))
;//				throw OperandValue_Underflow("Instruction add Failed");

			return result;
		}
	}

	template <typename ArithmeticT>
	static OperandValue		safeSub(ArithmeticT lhs, ArithmeticT rhs)
	{
		ArithmeticT			result;
		static_assert(std::is_arithmetic<ArithmeticT>::value,
				"OperandValue::safeSub template argument must be an arithmetic type.");

		if constexpr (std::is_integral<ArithmeticT>::value)
		{
			if (__builtin_sub_overflow(lhs, rhs, &result))
				throw OperandValue_Overflow("Instruction sub Failed");

			return result;
		}
		else
		{
			feclearexcept(FE_OVERFLOW | FE_UNDERFLOW);

			result = lhs - rhs;
			if (fetestexcept(FE_OVERFLOW))
				throw OperandValue_Overflow("Instruction sub Failed");
			else if (fetestexcept(FE_UNDERFLOW))
;//				throw OperandValue_Underflow("Instruction sub Failed");

			return result;
		}
	}

	template <typename ArithmeticT>
	static OperandValue		safeMul(ArithmeticT lhs, ArithmeticT rhs)
	{
		ArithmeticT			result;
		static_assert(std::is_arithmetic<ArithmeticT>::value,
				"OperandValue::safeMul template argument must be an arithmetic type.");

		if constexpr (std::is_integral<ArithmeticT>::value)
		{
			if (__builtin_mul_overflow(lhs, rhs, &result))
				throw OperandValue_Overflow("Instruction mul Failed");

			return result;
		}
		else
		{
			feclearexcept(FE_OVERFLOW | FE_UNDERFLOW);

			result = lhs * rhs;
			if (fetestexcept(FE_OVERFLOW))
				throw OperandValue_Overflow("Instruction mul Failed");
			else if (fetestexcept(FE_UNDERFLOW))
;//				throw OperandValue_Underflow("Instruction mul Failed");

			return result;
		}
	}

	template <typename ArithmeticT>
	static OperandValue		safeDiv(ArithmeticT lhs, ArithmeticT rhs)
	{
		static_assert(std::is_arithmetic<ArithmeticT>::value,
				"OperandValue::safeMul template argument must be an arithmetic type.");

		if constexpr (std::is_integral<ArithmeticT>::value)
		{
			if (rhs == 0)
				throw OperandValue_DivisionByZero("Instruction div Failed");
			if (lhs == std::numeric_limits<ArithmeticT>::min() && rhs == -1)
				throw OperandValue_Overflow("Instruction div Failed");
			return static_cast<ArithmeticT>(lhs / rhs);
		}
		else
		{
			ArithmeticT			result;

			if (rhs == static_cast<ArithmeticT>(0.))
				throw OperandValue_DivisionByZero("Instruction div Failed");

			feclearexcept(FE_OVERFLOW | FE_UNDERFLOW);

			result = lhs / rhs;
			if (fetestexcept(FE_OVERFLOW))
				throw OperandValue_Overflow("Instruction div Failed");
			else if (fetestexcept(FE_UNDERFLOW))
;//				throw OperandValue_Underflow("Instruction div Failed");

			return result;
		}
	}

	template <typename ArithmeticT>
	static OperandValue		safeMod(ArithmeticT lhs, ArithmeticT rhs)
	{
		static_assert(std::is_arithmetic<ArithmeticT>::value,
				"OperandValue::safeMul template argument must be an arithmetic type.");

		if constexpr (std::is_integral<ArithmeticT>::value)
		{
			if (rhs == 0)
				throw OperandValue_ModuloByZero("Instruction mod Failed");

			return static_cast<ArithmeticT>(lhs % rhs);
		}
		else if constexpr (std::is_same<ArithmeticT, float>::value)
		{
			if (rhs == 0.f)
				throw OperandValue_ModuloByZero("Instruction mod Failed");

			return fmodf(lhs, rhs);
		}
		else
		{
			if (rhs == 0.)
				throw OperandValue_ModuloByZero("Instruction mod Failed");

			return fmod(lhs, rhs);
		}
	}
};

#endif // OPERANDVALUE_HPP