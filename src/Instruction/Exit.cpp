/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:32:26 by jhache            #+#    #+#             */
/*   Updated: 2019/07/16 14:40:50 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Exit.hpp"

Exit::Exit()
{}

Exit::~Exit()
{}


void	Exit::execute(VMStack &stack)
{
	static_cast<void>(stack);
	//How should we handle this ? maybe a specific throw ? hmmm
}
