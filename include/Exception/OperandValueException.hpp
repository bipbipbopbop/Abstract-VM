/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandValueException.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:01:35 by jhache            #+#    #+#             */
/*   Updated: 2019/07/17 16:58:50 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERANDVALUEEXCEPTION_HPP
# define OPERANDVALUEEXCEPTION_HPP

# include <exception>
# include <string>

class OperandValueException : public std::exception
{
public:
	OperandValueException() = default;
	OperandValueException(std::string msg, std::string prefix);
	OperandValueException(OperandValueException const &src);
	~OperandValueException() noexcept override = default;

	OperandValueException  &operator=(OperandValueException const &rhs);

	const char	*what() const noexcept override;

private:
	std::string	_msg;
};

class OperandValue_Overflow : public OperandValueException
{
public:
	OperandValue_Overflow(std::string msg = "");
};

class OperandValue_Underflow : public OperandValueException
{
public:
	OperandValue_Underflow(std::string msg = "");
};

class OperandValue_DivisionByZero : public OperandValueException
{
public:
	OperandValue_DivisionByZero(std::string msg = "");
};

class OperandValue_ModuloByZero : public OperandValueException
{
public:
	OperandValue_ModuloByZero(std::string msg = "");
};

class OperandValue_BadType : public OperandValueException
{
public:
	OperandValue_BadType(std::string msg = "");
};

#endif // OPERANDVALUEEXCEPTION_HPP