/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mul.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:56:48 by jhache            #+#    #+#             */
/*   Updated: 2019/07/15 15:34:02 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mul.hpp"

Mul::Mul()
{}

Mul::~Mul()
{}

/*
void	Mul::execute(My_stack &stack)
{
	if (stack.size() < 2)
		throw Instruction_NoOperandInStack();

	IOperand	*a = stack.pop();
	IOperand	*b = stack.pop();

	stack.push(a->operator*(b));

	delete a;
	delete b;
}
*/