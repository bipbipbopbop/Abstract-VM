/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:03:18 by jhache            #+#    #+#             */
/*   Updated: 2019/08/08 13:08:56 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OperandFactory.hpp"
#include "OperandValue.hpp"
#include <sstream>
#include <string>
#include <functional>

namespace OperandFactory
{
	namespace
	{
		IOperand const *createInt8(std::string const &value)
		{
			int16_t				val;
			std::stringstream	ss(value);

			ss >> val;
			if (ss.fail() || static_cast<int8_t>(val) != val)//TODO: test it
				throw OperandValue_Overflow("Invalid type 'int8' for value '" + value + "'");

			return new Operand(OperandValue(static_cast<int8_t>(val)));
		}

		IOperand const *createInt16(std::string const &value)
		{
			int16_t				val;
			std::stringstream	ss(value);

			ss >> val;
			if (ss.fail())
				throw OperandValue_Overflow("Invalid type 'int16' for value '" + value + "'");

			return new Operand(OperandValue(val));
		}

		IOperand const *createInt32(std::string const &value)
		{
			int32_t				val;
			std::stringstream	ss(value);

			ss >> val;
			if (ss.fail())
				throw OperandValue_Overflow("Invalid type 'int32' for value '" + value + "'");

			return new Operand(OperandValue(val));
		}
		
		IOperand const *createFloat(std::string const &value)
		{
			float				val;
			std::stringstream	ss(value);

			ss >> val;
			if (ss.fail() || std::to_string(val).find("inf") != std::string::npos)
				throw OperandValue_Overflow("Invalid type 'float' for value '" + value + "'");

			return new Operand(OperandValue(val));
		}
		
		IOperand const *createDouble(std::string const &value)
		{
			double				val;
			std::stringstream	ss(value);

			ss >> val;
			if (ss.fail() || std::to_string(val).find("inf") != std::string::npos)
				throw OperandValue_Overflow("Invalid type 'double' for value '" + value + "'");

			return new Operand(OperandValue(val));
		}
	}// namespace

	IOperand const	*CreateOperand(OperandType type, std::string const &str)
	{
		static const std::function<IOperand const *(std::string const &)>	array[]
		{createInt8, createInt16, createInt32, createFloat, createDouble};

		if (type == OperandType::Unknown)
			throw OperandValue_BadType();

		return array[static_cast<int>(type)](str);
	}
}// namespace OperandFactory
