/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exit.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:32:01 by jhache            #+#    #+#             */
/*   Updated: 2019/07/15 15:34:02 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_HPP
# define EXIT_HPP

# include "IInstruction.hpp"

class Exit : public IInstruction
{
public:
	Exit();
	~Exit() override;

	void	execute(/*My_stack &stack*/) override;
};

#endif // EXIT_HPP