/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Add.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:29:24 by jhache            #+#    #+#             */
/*   Updated: 2019/07/16 14:26:15 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADD_HPP
# define ADD_HPP

# include "IInstruction.hpp"

class Add : public IInstruction
{
public:
	Add();
	~Add() override;

	void	execute(VMStack &stack) override;
};

#endif // ADD_HPP