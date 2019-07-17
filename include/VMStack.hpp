/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VMStack.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 14:02:48 by jhache            #+#    #+#             */
/*   Updated: 2019/07/17 17:22:56 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VMSTACK_HPP
# define VMSTACK_HPP

# include <stack>
# include "IOperand.hpp"

template <typename T>
class MyStack : public std::stack<T>
{
public:
	typedef	typename std::stack<T>::container_type			container_type;
	typedef	typename container_type::reverse_iterator		iterator;
	typedef	typename container_type::const_reverse_iterator	const_iterator;


	MyStack(const container_type &cont = container_type())
		: std::stack<T>(cont)
	{}

	MyStack(MyStack const &src)
		: std::stack<T>(src)
	{}

	~MyStack()
	{}

	MyStack  &operator=(MyStack const &rhs)
	{
		this->std::stack<T>::operator=(rhs);

		return *this;
	}

	iterator		begin()
	{
		return this->c.rbegin();
	}

	const_iterator	cbegin()
	{
		return this->c.crbegin();
	}

	iterator		end()
	{
		return this->c.rend();
	}

	const_iterator	cend()
	{
		return this->c.crend();
	}

	// For VMStack: check if exit have been executed
	bool		has_exited = false;
private:
};

typedef	MyStack<IOperand const *>	VMStack;

#endif // VMSTACK_HPP