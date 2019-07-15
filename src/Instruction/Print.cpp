/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:28:15 by jhache            #+#    #+#             */
/*   Updated: 2019/07/15 15:52:10 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Print.hpp"

Print::Print()
{}

Print::~Print()
{}

/*
void	Print::execute(My_stack &stack)
{
	if (stack.size() < 1)
		throw Instruction_NoOperandInStack();

	IOperand const	*stackTop = *stack.begin();

	if (stackTop.getType() != OperandType::Int8)
		throw Instruction_InvalidTypeForPrint();
	
	std::cout << static_cast<char>(std::atoi(stackTop->toString())) << std::endl;
}
*/