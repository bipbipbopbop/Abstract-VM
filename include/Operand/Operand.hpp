/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:04:09 by jhache            #+#    #+#             */
/*   Updated: 2019/07/15 12:14:28 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_HPP
# define OPERAND_HPP

# include "IOperand.hpp"
# include "OperandValue.hpp"

class Operand : public IOperand
{
public:
	template <typename ArithmeticT>
	Operand(ArithmeticT value)
	{
		static_assert(std::is_arithmetic<ArithmeticT>::value,
				"Operand constructor must take one arithmetic value.");

		if constexpr (std::is_same<ArithmeticT, int8_t>::value)
			this->_type = OperandType::Int8;
		else if constexpr (std::is_same<ArithmeticT, int16_t>::value)
			this->_type = OperandType::Int16;
		else if constexpr (std::is_same<ArithmeticT, int32_t>::value)
			this->_type = OperandType::Int32;
		else if constexpr (std::is_same<ArithmeticT, float>::value)
			this->_type = OperandType::Float;
		else if constexpr (std::is_same<ArithmeticT, double>::value)
			this->_type = OperandType::Double;
		else
			this->_type = OperandType::Unknown;

		this->_valueStr = std::to_string(value);
	}

	Operand();
	Operand(OperandValue value);
	Operand(Operand const &src);
	Operand(Operand &&src);
	virtual ~Operand();

	Operand						&operator=(Operand rhs);

	virtual int					getPrecision() const;
	virtual OperandType			getType() const;

	virtual IOperand const		*operator+(IOperand const &rhs) const;
	virtual IOperand const		*operator-(IOperand const &rhs) const;
	virtual IOperand const		*operator*(IOperand const &rhs) const;
	virtual IOperand const		*operator/(IOperand const &rhs) const;
	virtual IOperand const		*operator%(IOperand const &rhs) const;

	virtual std::string const	&toString() const;

	static Operand				*StrToOperand(std::string const &str, OperandType type);
	static OperandValue			convertStr(std::string const &str, OperandType type);

private:
	std::string			_valueStr;
	OperandType			_type;
};

#endif //OPERAND_HPP