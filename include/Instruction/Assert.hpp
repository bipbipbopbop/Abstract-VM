/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Assert.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:03:38 by jhache            #+#    #+#             */
/*   Updated: 2019/07/16 14:26:11 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSERT_HPP
# define ASSERT_HPP

# include "IInstruction.hpp"
# include "Operand.hpp"

class Assert : public IInstruction
{
public:
	Assert();
	Assert(IOperand *value);
	Assert(Assert const &src);
	Assert(Assert &&src);
	~Assert() override;

	Assert 	&operator=(Assert rhs);

	void	execute(VMStack &stack) override;

private:
	IOperand	*_value;
};

#endif // ASSERT_HPP