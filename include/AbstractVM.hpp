/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractVM.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:42:53 by jhache            #+#    #+#             */
/*   Updated: 2019/07/16 14:23:33 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTVM_HPP
# define ABSTRACTVM_HPP

# include <list>
# include <string>
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

	bool		parse(std::string const &filename);
	void		execute();

private:

//	std::list<Instruction *>	_instructionList;
	VMStack						_stack;
	Driver						_parser;

};

#endif //ABSTRACTVM_HPP