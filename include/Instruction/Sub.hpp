/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sub.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:54:34 by jhache            #+#    #+#             */
/*   Updated: 2019/07/15 15:34:02 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUB_HPP
# define SUB_HPP

# include "IInstruction.hpp"

class Sub : public IInstruction
{
public:
	Sub();
	~Sub() override;

	void	execute(/*My_stack &stack*/) override;
};

#endif // SUB_HPP