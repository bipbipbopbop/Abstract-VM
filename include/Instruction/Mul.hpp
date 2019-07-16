/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mul.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:56:10 by jhache            #+#    #+#             */
/*   Updated: 2019/07/16 14:26:47 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUL_HPP
# define MUL_HPP

# include "IInstruction.hpp"

class Mul : public IInstruction
{
public:
	Mul();
	~Mul() override;

	void	execute(VMStack &stack) override;
};

#endif // MUL_HPP