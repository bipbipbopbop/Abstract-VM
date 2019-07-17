/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstructionException.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:14:49 by jhache            #+#    #+#             */
/*   Updated: 2019/07/17 16:58:33 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONEXCEPTION_HPP
# define INSTRUCTIONEXCEPTION_HPP

# include <exception>
# include <string>

class InstructionException : public std::exception
{
public:
	InstructionException() = default;
	InstructionException(std::string msg, std::string prefix);
	InstructionException(InstructionException const &src);
	~InstructionException() noexcept override = default;

	InstructionException  &operator=(InstructionException const &rhs);

	const char	*what() const noexcept override;

private:
	std::string	_msg;
};

class Instruction_Exit : public InstructionException
{
public:
	Instruction_Exit(std::string msg = "");
};

class Instruction_NoOpInStack : public InstructionException
{
public:
	Instruction_NoOpInStack(std::string msg = "");
};

class Instruction_WrongOpPtr : public InstructionException
{
public:
	Instruction_WrongOpPtr(std::string msg = "");
};

class Instruction_AssertFailed : public InstructionException
{
public:
	Instruction_AssertFailed(std::string msg = "");
};

class Instruction_InvalidTypeForPrint : public InstructionException
{
public:
	Instruction_InvalidTypeForPrint(std::string msg = "");
};


#endif // INSTRUCTIONEXCEPTION_HPP