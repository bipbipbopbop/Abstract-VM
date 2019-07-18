/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractVM.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:42:53 by jhache            #+#    #+#             */
/*   Updated: 2019/07/18 12:29:40 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTVM_HPP
# define ABSTRACTVM_HPP

# include <string>
# include "InstructionContainer.hpp"
# include "Operand.hpp"
# include "VMStack.hpp"
# include "Driver.hpp"

class AbstractVM
{
public:

	AbstractVM();
	AbstractVM(AbstractVM const &src);
	~AbstractVM();

	AbstractVM  &operator=(AbstractVM const &rhs);

	bool		parse(int argc, char **argv);
	void		execute();

private:

	InstructionContainer	_instructionList;
	VMStack					_stack;
	Driver					_parser;

};

#endif //ABSTRACTVM_HPP