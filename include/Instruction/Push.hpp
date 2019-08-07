/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 11:49:32 by jhache            #+#    #+#             */
/*   Updated: 2019/07/19 11:03:15 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_HPP
# define PUSH_HPP

# include "IInstruction.hpp"
# include "Operand.hpp"

class Push : public IInstruction
{
public:
	Push();
	Push(const IOperand *value);
	Push(Push const &src);
	Push(Push &&src);
	~Push() override;

	Push 	&operator=(Push rhs);

	void	execute(VMStack &stack) override;

private:
	const IOperand	*_value;
};

#endif // PUSH_HPP