/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sub.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:54:57 by jhache            #+#    #+#             */
/*   Updated: 2019/07/17 17:09:51 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sub.hpp"
#include "InstructionException.hpp"

Sub::Sub()
{}

Sub::~Sub()
{}


void	Sub::execute(VMStack &stack)
{
	if (stack.size() < 2)
		throw Instruction_NoOpInStack("Instruction sub failed");

	const IOperand	*a = stack.top();
	stack.pop();

	const IOperand	*b = stack.top();
	stack.pop();

	stack.push(a->operator-(*b));

	delete a;
	delete b;
}
