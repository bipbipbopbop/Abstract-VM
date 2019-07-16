/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pop.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 11:48:32 by jhache            #+#    #+#             */
/*   Updated: 2019/07/16 14:42:15 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pop.hpp"

Pop::Pop()
{}

Pop::~Pop()
{}


void	Pop::execute(VMStack &stack)
{
	if (stack.size() < 1)
		;//throw Instruction_NoOperandInStack();

	delete stack.top();
	stack.pop();
}
