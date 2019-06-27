/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:44:40 by jhache            #+#    #+#             */
/*   Updated: 2019/06/27 14:22:18 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Operand.hpp"

void	operand_test(void)
{
	std::cout << "Welcome to the Operand class test!" << std::endl;

	Operand	a(13.7f);
	Operand b(static_cast<int8_t>(2));
	//Operand wrongOperand(nullptr);//trigger static_assert

	std::cout << "a = " << a.toString() << std::endl;
	std::cout << "b = " << b.toString() << std::endl;
	std::cout << "(a + b)->getType() = " << (a + b)->getType() << std::endl;
	std::cout << "a % b = " << (a % b)->toString() << std::endl;

	std::cout << std::endl;

	OperandValue kek(32.27f);
	OperandValue heh(4);

//	----------

	std::cout << "heh = " << heh.value.i32 << ", type: " << heh.type << std::endl;
	std::cout << "kek = " << kek.value.f << ", type: " << kek.type << std::endl;
	// The following test do not work because OperandValue do not handle
	// the cast toward the higher accurate type. Its only use is inside the Operand class
//	OperandValue res = heh - kek;

	//The following test works, but it does not use the operator- overload.
	OperandValue res = heh.value.i32 - kek.value.f;

	if (res.type == OperandType::Int32)
		std::cout << "res (heh - kek) = " << res.value.i32 << " (type = " << res.type << ")\n";
	else if (res.type == OperandType::Float)
		std::cout << "res (heh - kek) = " << res.value.f << " (type = " << res.type << ")\n";
	else
		std::cout << "??? type == " << res.type << std::endl;
}

int		main(void)
{
	std::cout << "hello World!" << std::endl;

	operand_test();

	return 0;
}