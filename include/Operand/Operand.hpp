/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:04:09 by jhache            #+#    #+#             */
/*   Updated: 2019/06/25 21:22:05 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_HPP
# define OPERAND_HPP

# include "IOperand.hpp"
# include <type_traits>
# include <variant>

class Operand : public IOperand
{
public:

	typedef std::variant<int8_t, int16_t, int32_t, float, double>	OperandValueType;

	Operand()
		: _type(OperandType::Unknown)
	{}

	Operand(std::string const &value, OperandType type)
		: _value(value), _type(type)
	{}

	Operand(Operand const &src)
	{
		*this = src;
	}

	virtual ~Operand()
	{}

	Operand  &operator=(Operand const &rhs)
	{
		this->_value = rhs._value;

		return *this;
	}

	virtual int			getPrecision() const//Really it is a silly function
	{
		return this->getOperandType();
	}

	virtual OperandType	getType() const
	{
		return this->getOperandType();
	}


	virtual IOperand const	*operator+(IOperand const &rhs) const
	{
		OperandValueType	result;
		OperandType			typeToCast;

		typeToCast = (this->getPrecision() >= rhs.getPrecision() ? this->getType() : rhs.getType());
		result = std::get<typeToCast>(convertStr(this->_value, typeToCast)) + std::get<typeToCast>(convertStr(rhs._value, typeToCast));
		return new Operand(std::to_string(std::get<typeToCast>(result), typeToCast));
	}

	virtual IOperand const	*operator-(IOperand const &rhs) const
	{
		OperandValueType	result;
		OperandType			typeToCast;

		typeToCast = (this->getPrecision() >= rhs.getPrecision() ? this->getType() : rhs.getType());
		result = std::get<typeToCast>(convertStr(this->_value, typeToCast)) - std::get<typeToCast>(convertStr(rhs._value, typeToCast));
		return new Operand(std::to_string(std::get<typeToCast>(result), typeToCast));
	}

	virtual IOperand const	*operator*(IOperand const &rhs) const
	{
		OperandValueType	result;
		OperandType			typeToCast;

		typeToCast = (this->getPrecision() >= rhs.getPrecision() ? this->getType() : rhs.getType());
		result = std::get<typeToCast>(convertStr(this->_value, typeToCast)) * std::get<typeToCast>(convertStr(rhs._value, typeToCast));
		return new Operand(std::to_string(std::get<typeToCast>(result), typeToCast));
	}

	virtual IOperand const	*operator/(IOperand const &rhs) const
	{
		OperandValueType	result;
		OperandType			typeToCast;

		typeToCast = (this->getPrecision() >= rhs.getPrecision() ? this->getType() : rhs.getType());
		result = std::get<typeToCast>(convertStr(this->_value, typeToCast)) / std::get<typeToCast>(convertStr(rhs._value, typeToCast));
		return new Operand(std::to_string(std::get<typeToCast>(result), typeToCast));
	}

	virtual IOperand const	*operator%(IOperand const &rhs) const
	{
		OperandValueType	result;
		OperandType			typeToCast;

		typeToCast = (this->getPrecision() >= rhs.getPrecision() ? this->getType() : rhs.getType());
		result = std::get<typeToCast>(convertStr(this->_value, typeToCast)) % std::get<typeToCast>(convertStr(rhs._value, typeToCast));
		return new Operand(std::to_string(std::get<typeToCast>(result), typeToCast));
	}

	virtual std::string const	&toString() const
	{//It should return a rvalue reference ...
		return this->_value;
	}

	OperandType	getOperandType() const
	{
		return this->_type;
	}

	static OperandValueType		convertStr(std::string const &str, OperandType type)
	{
		OperandValueType		result;

		if (type == OperandType::Int8)
			result = static_cast<int8_t>(stol(str));
		else if (type == OperandType::Int16)
			result = static_cast<int16_t>(stol(str));
		else if (type == OperandType::Int32)
			result = static_cast<int32_t>(stol(str));
		else if (type == OperandType::Float)
			result = stof(str);
		else if (type == OperandType::Double)
			result = stod(str);
	//	else
	//		throw my_badType();

		return result;
	}

private:
	std::string			_value;
	OperandType			_type;
};


#endif //OPERAND_HPP