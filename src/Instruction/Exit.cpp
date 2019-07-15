/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:32:26 by jhache            #+#    #+#             */
/*   Updated: 2019/07/15 15:34:02 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Exit.hpp"

Exit::Exit()
{}

Exit::~Exit()
{}

/*
void	Exit::execute(My_stack &stack)
{
	if (stack.size() < 2)
		throw Instruction_NoOperandInStack();

	IOperand	*a = stack.pop();
	IOperand	*b = stack.pop();

	stack.push(a->operator+(b));

	delete a;
	delete b;
}
*/