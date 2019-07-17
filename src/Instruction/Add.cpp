/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:34:52 by jhache            #+#    #+#             */
/*   Updated: 2019/07/17 17:11:07 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Add.hpp"
#include "InstructionException.hpp"

Add::Add()
{}

Add::~Add()
{}


void	Add::execute(VMStack &stack)
{
	if (stack.size() < 2)
		throw Instruction_NoOpInStack("Instruction add failed");

	const IOperand	*a = stack.top();
	stack.pop();

	const IOperand	*b = stack.top();
	stack.pop();

	stack.push(a->operator+(*b));

	delete a;
	delete b;
}
