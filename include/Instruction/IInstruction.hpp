/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IInstruction.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:25:33 by jhache            #+#    #+#             */
/*   Updated: 2019/07/16 14:26:20 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IINSTRUCTION_HPP
# define IINSTRUCTION_HPP

# include "VMStack.hpp"

class IInstruction
{
public:
	virtual ~IInstruction() {}

	virtual void	execute(VMStack &stack) = 0;
};

#endif // IINSTRUCTION_HPP