/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dump.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:42:46 by jhache            #+#    #+#             */
/*   Updated: 2019/07/19 11:43:29 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dump.hpp"
#include "InstructionException.hpp"

Dump::Dump()
{}

Dump::~Dump()
{}


void	Dump::execute(VMStack &stack)
{
	if (stack.size() < 1)
		throw Instruction_NoOpInStack("Instruction dump failed");

	for (auto operand : stack)
	{
		std::string	str = operand->toString();

		std::reverse(str.begin(), str.end());

		str.erase(0, std::min(str.find_first_not_of('0'), str.size() - 1));
		if (str.front() == '.')
			str = '0' + str;

		std::reverse(str.begin(), str.end());


		std::cout << str << std::endl;
	}
}
