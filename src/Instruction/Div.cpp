/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Div.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:57:57 by jhache            #+#    #+#             */
/*   Updated: 2019/07/17 17:10:41 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Div.hpp"
#include "InstructionException.hpp"

Div::Div()
{}

Div::~Div()
{}


void	Div::execute(VMStack &stack)
{
	if (stack.size() < 2)
		throw Instruction_NoOpInStack("Instruction div failed");

	const IOperand	*a = stack.top();
	stack.pop();

	const IOperand	*b = stack.top();
	stack.pop();

	stack.push(a->operator/(*b));

	delete a;
	delete b;
}
