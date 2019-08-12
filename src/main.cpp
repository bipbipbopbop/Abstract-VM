/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:44:40 by jhache            #+#    #+#             */
/*   Updated: 2019/08/12 10:56:24 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractVM.hpp"

int		main(int ac, char **av)
{
	AbstractVM	vm;

	if (!vm.parse(ac, av))
		return EXIT_FAILURE;
	else
		vm.execute();

	return EXIT_SUCCESS;
}