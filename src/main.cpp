/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:44:40 by jhache            #+#    #+#             */
/*   Updated: 2019/07/17 19:07:31 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractVM.hpp"

int		main(int ac, char **av)
{
	AbstractVM	vm;

	if (ac <= 1)
		return EXIT_SUCCESS;

	if (!vm.parse(av[1]))
		std::cout << "an error occurs during parsing.\n";
	else
		vm.execute();

	return 0;
}