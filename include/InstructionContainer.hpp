/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstructionContainer.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:24:28 by jhache            #+#    #+#             */
/*   Updated: 2019/07/16 15:26:24 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONCONTAINER_HPP
# define INSTRUCTIONCONTAINER_HPP

# include <list>
# include "IInstruction.hpp"

typedef std::list<IInstruction *>	InstructionContainer;

#endif // INSTRUCTIONCONTAINER_HPP
