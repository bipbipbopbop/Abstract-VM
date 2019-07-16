/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dump.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:42:46 by jhache            #+#    #+#             */
/*   Updated: 2019/07/16 14:39:34 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dump.hpp"

Dump::Dump()
{}

Dump::~Dump()
{}


void	Dump::execute(VMStack &stack)
{
	if (stack.size() < 1)
		;//throw Instruction_NoOperandInStack();

	for (auto operand : stack)
		std::cout << operand->toString() << std::endl;
}
