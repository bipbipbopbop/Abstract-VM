/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dump.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:42:46 by jhache            #+#    #+#             */
/*   Updated: 2019/08/08 13:08:18 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
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
