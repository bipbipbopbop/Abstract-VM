/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:56:33 by jhache            #+#    #+#             */
/*   Updated: 2019/06/25 19:33:41 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_HPP
# define IOPERAND_HPP

# include <string>
# include "OperandType.hpp"

class IOperand
{
public:
	virtual ~IOperand() {}

	virtual int			getPrecision() const = 0;
	virtual OperandType	getType() const = 0;

	virtual IOperand const	*operator+(IOperand const & rhs) const = 0;
	virtual IOperand const	*operator-(IOperand const & rhs) const = 0;
	virtual IOperand const	*operator*(IOperand const & rhs) const = 0;
	virtual IOperand const	*operator/(IOperand const & rhs) const = 0;
	virtual IOperand const	*operator%(IOperand const & rhs) const = 0;

	virtual std::string const & toString() const = 0;
};


#endif //IOPERAND_HPP