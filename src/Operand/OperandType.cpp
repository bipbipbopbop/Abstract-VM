/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandType.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:48:58 by jhache            #+#    #+#             */
/*   Updated: 2019/06/27 13:51:30 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OperandType.hpp"

std::ostream	&operator<<(std::ostream &out, OperandType type)
{
	if (type == OperandType::Int8)
		out << "Int8";
	else if (type == OperandType::Int16)
		out << "Int16";
	else if (type == OperandType::Int32)
		out << "Int32";
	else if (type == OperandType::Float)
		out << "Float";
	else if (type == OperandType::Double)
		out << "Double";
	else if (type == OperandType::Unknown)
		out << "Unknown";

	return out;
}