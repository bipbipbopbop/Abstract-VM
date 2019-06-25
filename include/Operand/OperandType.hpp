/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandType.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:41:52 by jhache            #+#    #+#             */
/*   Updated: 2019/06/25 20:50:48 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERANDTYPE_HPP
# define OPERANDTYPE_HPP

enum	OperandType
{
	Int8 = 0,
	Int16 = 1,
	Int32 = 2,
	Float = 3,
	Double = 4,
	Unknown = -1
};

#endif // OPERANDTYPE_HPP