/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:44:40 by jhache            #+#    #+#             */
/*   Updated: 2019/07/02 13:31:28 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Operand.hpp"
#include <cfenv>

void	float_flags_test(void)
{
//#pragma STDC FENV_ACCESS ON
	std::cout << "Testing float flags from cfenv header..." << std::endl;

	//float	a = 0.f;
	//float	b = 0.f;
	//double	da = 0.;
	//double	db = 0.;
	//float	result;
	double	dresult;

	feclearexcept(FE_ALL_EXCEPT);

	dresult = std::numeric_limits<double>::min() / 3.;
	if (fetestexcept(FE_OVERFLOW))
		std::cout << "overflow  ";
	if (fetestexcept(FE_UNDERFLOW))
		std::cout << "underflow  ";
	std::cout << "result = " << dresult << std::endl;


//#pragma STDC FENV_ACCESS OFF
}

void	builtin_intoverflow_test(void)
{
	std::cout << "Testing builtin overflow operation from the compiler..." << std::endl;

	int	a = 10;
	int b = std::numeric_limits<int>::max();
	int result;

	std::cout << "MAX_INT + 10 = ";
	if (__builtin_add_overflow(a, b, &result))
		std::cout << result << "(Overflow !!)" << std::endl;
	else
		std::cout << result << std::endl;

	a = -10;
	b = std::numeric_limits<int>::min();
	std::cout << "MIN_INT - 10 = ";
	if (__builtin_add_overflow(b, a, &result))
		std::cout << result << "(Overflow !!)" << std::endl;
	else
		std::cout << result << std::endl;

	char ca = 10;
	char cb = 100;
	char cresult;
	std::cout << "CHAR: 100 * 10 = ";
	if (__builtin_mul_overflow(ca, cb, &cresult))
		std::cout << (int)cresult << "(Overflow !!)" << std::endl;
	else
		std::cout << (int)cresult << std::endl;
}

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

//	----------

	OperandValue kek(32.27f);
	OperandValue heh(4);


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
	//builtin_intoverflow_test();
	//float_flags_test();

	return 0;
}