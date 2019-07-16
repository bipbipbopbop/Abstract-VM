/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pop.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 11:47:10 by jhache            #+#    #+#             */
/*   Updated: 2019/07/16 14:26:51 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POP_HPP
# define POP_HPP

# include "IInstruction.hpp"

class Pop : public IInstruction
{
public:
	Pop();
	~Pop() override;

	void	execute(VMStack &stack) override;
};

#endif // POP_HPP