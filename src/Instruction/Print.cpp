/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:28:15 by jhache            #+#    #+#             */
/*   Updated: 2019/07/17 17:10:23 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Print.hpp"
#include "InstructionException.hpp"

Print::Print()
{}

Print::~Print()
{}


void	Print::execute(VMStack &stack)
{
	if (stack.size() < 1)
		throw Instruction_NoOpInStack("Instruction print failed");

	IOperand const	*stackTop = stack.top();

	if (stackTop->getType() != OperandType::Int8)
	{
		std::ostringstream	ss;

		ss << "Top operand type is: " << stackTop->getType();
		throw Instruction_InvalidTypeForPrint(ss.str());
	}
	
	std::cout << static_cast<char>(std::atoi(stackTop->toString().c_str())) << std::endl;
}
