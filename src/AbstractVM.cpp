/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractVM.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:45:54 by jhache            #+#    #+#             */
/*   Updated: 2019/07/10 18:01:43 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractVM.hpp"


AbstractVM::AbstractVM()
	: /*_instructionList(), _stack(), */_parser(/*this->_instructionList*/)
{}

AbstractVM::AbstractVM(AbstractVM const &src)
	: /*_instructionList(), _stack(), */_parser(/*this->_instructionList*/)
{
	*this = src;
}

AbstractVM::~AbstractVM()
{}


AbstractVM  &AbstractVM::operator=(AbstractVM const &rhs)
{//no use
	static_cast<void>(rhs);
	return *this;
}


bool		AbstractVM::parse(std::string const &filename)
{
	int		res = this->_parser.parse(filename.c_str());

	if (res != 0)
	{
		//handle error
		return false;
	}
	//maybe check the list ?
	return true;
}

void		AbstractVM::execute()
{
/*
	for (auto it = this->_instructionList.begin(); it != this->_instructionList.end(); ++it)
	{
		try
		{
			it->execute();
		}
		catch (std::exception &e)
		{
			std::cout << "kek: " << e.what() << std::endl;
			exit();
		}
	}
*/
}
