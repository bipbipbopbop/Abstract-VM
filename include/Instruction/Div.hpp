/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Div.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:57:34 by jhache            #+#    #+#             */
/*   Updated: 2019/07/16 14:26:28 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIV_HPP
# define DIV_HPP

# include "IInstruction.hpp"

class Div : public IInstruction
{
public:
	Div();
	~Div() override;

	void	execute(VMStack &stack) override;
};

#endif // DIV_HPP