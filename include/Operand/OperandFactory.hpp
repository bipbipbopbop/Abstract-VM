/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:59:00 by jhache            #+#    #+#             */
/*   Updated: 2019/07/18 16:24:13 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERANDFACTORY_HPP
# define OPERANDFACTORY_HPP

# include "Operand.hpp"
# include "OperandType.hpp"

namespace OperandFactory
{
	IOperand const	*CreateOperand(OperandType type, std::string const &str);
}

#endif // OPERANDFACTORY_HPP