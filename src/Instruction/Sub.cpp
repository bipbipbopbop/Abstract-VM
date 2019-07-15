/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sub.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:54:57 by jhache            #+#    #+#             */
/*   Updated: 2019/07/15 15:34:02 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sub.hpp"

Sub::Sub()
{}

Sub::~Sub()
{}

/*
void	Sub::execute(My_stack &stack)
{
	if (stack.size() < 2)
		throw Instruction_NoOperandInStack();

	IOperand	*a = stack.pop();
	IOperand	*b = stack.pop();

	stack.push(a->operator-(b));

	delete a;
	delete b;
}
*/