/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dump.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:41:31 by jhache            #+#    #+#             */
/*   Updated: 2019/07/15 15:42:32 by jhache           ###   ########.fr       */
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

	void	execute(/*My_stack &stack*/) override;
};

#endif // DUMP_HPP