/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:44:40 by jhache            #+#    #+#             */
/*   Updated: 2019/07/18 12:46:27 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractVM.hpp"

int		main(int ac, char **av)
{
	AbstractVM	vm;

	if (!vm.parse(ac, av))
		return EXIT_SUCCESS;
	else
		vm.execute();

	return EXIT_SUCCESS;
}