/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:32:26 by jhache            #+#    #+#             */
/*   Updated: 2019/07/17 17:07:17 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Exit.hpp"
#include "InstructionException.hpp"

Exit::Exit()
{}

Exit::~Exit()
{}


void	Exit::execute(VMStack &stack)
{
	stack.has_exited = true;
}
