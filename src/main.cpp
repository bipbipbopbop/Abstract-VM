/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:44:40 by jhache            #+#    #+#             */
/*   Updated: 2019/06/25 21:19:11 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Operand.hpp"

int		main(void)
{
	std::cout << "hello World!" << std::endl;

	Operand	a(13, OpenrandType::Int8);

	return 0;
}