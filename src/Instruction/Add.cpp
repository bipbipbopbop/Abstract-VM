/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:34:52 by jhache            #+#    #+#             */
/*   Updated: 2019/07/16 14:37:50 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Add.hpp"

Add::Add()
{}

Add::~Add()
{}


void	Add::execute(VMStack &stack)
{
	if (stack.size() < 2)
		;//throw Instruction_NoOperandInStack();

	const IOperand	*a = stack.top();
	stack.pop();

	const IOperand	*b = stack.top();
	stack.pop();

	stack.push(a->operator+(*b));

	delete a;
	delete b;
}
