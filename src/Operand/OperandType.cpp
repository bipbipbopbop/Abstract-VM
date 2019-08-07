/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandType.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:48:58 by jhache            #+#    #+#             */
/*   Updated: 2019/07/19 12:02:16 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OperandType.hpp"
#include <cfloat>

std::ostream	&operator<<(std::ostream &out, OperandType type)
{
	switch (type)
	{
		case OperandType::Int8:
			out << "Int8";
			break ;
		case OperandType::Int16:
			out << "Int16";
			break ;
		case OperandType::Int32:
			out << "Int32";
			break ;
		case OperandType::Float:
			out << "Float";
			break ;
		case OperandType::Double:
			out << "Double";
			break ;
		case OperandType::Unknown:
			out << "Unknown";
	}

	return out;
}