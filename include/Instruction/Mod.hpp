/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mod.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:24:55 by jhache            #+#    #+#             */
/*   Updated: 2019/07/16 14:26:41 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOD_HPP
# define MOD_HPP

# include "IInstruction.hpp"

class Mod : public IInstruction
{
public:
	Mod();
	~Mod() override;

	void	execute(VMStack &stack) override;
};

#endif // MOD_HPP