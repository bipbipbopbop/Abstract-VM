/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainParser.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 17:32:00 by jhache            #+#    #+#             */
/*   Updated: 2019/07/04 17:32:08 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Driver.hpp"

int		main(int argc, char **argv)
{
	int		res = 0;
	Driver	drv;

	for (int i = 1; i < argc; ++i)
	{
		if (argv[i] == std::string ("-p"))
			drv.trace_parsing = true;
		else if (argv[i] == std::string ("-s"))
			drv.trace_scanning = true;
		else
			std::cout << (res = drv.parse(argv[i])) << '\n';
	}
	return res;
}