/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pop.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 11:48:32 by jhache            #+#    #+#             */
/*   Updated: 2019/07/17 17:10:26 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pop.hpp"
#include "InstructionException.hpp"

Pop::Pop()
{}

Pop::~Pop()
{}


void	Pop::execute(VMStack &stack)
{
	if (stack.size() < 1)
		throw Instruction_NoOpInStack("Instruction pop failed");

	delete stack.top();
	stack.pop();
}
