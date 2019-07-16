/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sub.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:54:34 by jhache            #+#    #+#             */
/*   Updated: 2019/07/16 14:27:00 by jhache           ###   ########.fr       */
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

	void	execute(VMStack &stack) override;
};

#endif // SUB_HPP