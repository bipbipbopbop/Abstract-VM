/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dump.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:41:31 by jhache            #+#    #+#             */
/*   Updated: 2019/07/16 14:26:31 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMP_HPP
# define DUMP_HPP

# include "IInstruction.hpp"

class Dump : public IInstruction
{
public:
	Dump();
	~Dump() override;

	void	execute(VMStack &stack) override;
};

#endif // DUMP_HPP