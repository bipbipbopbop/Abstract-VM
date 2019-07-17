/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mul.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:56:48 by jhache            #+#    #+#             */
/*   Updated: 2019/07/17 17:10:29 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mul.hpp"
#include "InstructionException.hpp"

Mul::Mul()
{}

Mul::~Mul()
{}


void	Mul::execute(VMStack &stack)
{
	if (stack.size() < 2)
		throw Instruction_NoOpInStack("Instruction mul failed");

	const IOperand	*a = stack.top();
	stack.pop();

	const IOperand	*b = stack.top();
	stack.pop();

	stack.push(a->operator*(*b));

	delete a;
	delete b;
}
