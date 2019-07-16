/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainParser.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 17:32:00 by jhache            #+#    #+#             */
/*   Updated: 2019/07/16 16:22:31 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Driver.hpp"
#include "InstructionContainer.hpp"

int		main(int argc, char **argv)
{
	int		res = 0;
	InstructionContainer list;
	Driver	drv(list);

	for (int i = 1; i < argc; ++i)
	{
		if (argv[i] == std::string ("-p"))
			drv.trace_parsing = true;
		else if (argv[i] == std::string ("-s"))
			drv.trace_scanning = true;
		else
			std::cout << (res = drv.parse(argv[i])) << '\n';
	}

	for (auto * elem : list)
	{
		std::cout << elem << std::endl;
	}
	return res;
}