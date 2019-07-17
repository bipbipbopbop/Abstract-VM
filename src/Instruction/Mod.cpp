/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mod.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:25:30 by jhache            #+#    #+#             */
/*   Updated: 2019/07/17 17:10:33 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mod.hpp"
#include "InstructionException.hpp"

Mod::Mod()
{}

Mod::~Mod()
{}


void	Mod::execute(VMStack &stack)
{
	if (stack.size() < 2)
		throw Instruction_NoOpInStack("Instruction mod failed");

	const IOperand	*a = stack.top();
	stack.pop();

	const IOperand	*b = stack.top();
	stack.pop();

	stack.push(a->operator%(*b));

	delete a;
	delete b;
}
