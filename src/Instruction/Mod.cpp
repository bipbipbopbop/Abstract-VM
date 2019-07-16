/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mod.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:25:30 by jhache            #+#    #+#             */
/*   Updated: 2019/07/16 14:41:11 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mod.hpp"

Mod::Mod()
{}

Mod::~Mod()
{}


void	Mod::execute(VMStack &stack)
{
	if (stack.size() < 2)
		;//throw Instruction_NoOperandInStack();

	const IOperand	*a = stack.top();
	stack.pop();

	const IOperand	*b = stack.top();
	stack.pop();

	stack.push(a->operator%(*b));

	delete a;
	delete b;
}
