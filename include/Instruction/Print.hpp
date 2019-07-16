/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Print.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:27:07 by jhache            #+#    #+#             */
/*   Updated: 2019/07/16 14:26:53 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_HPP
# define PRINT_HPP

# include "IInstruction.hpp"

class Print : public IInstruction
{
public:
	Print();
	~Print() override;

	void	execute(VMStack &stack) override;
};

#endif // PRINT_HPP