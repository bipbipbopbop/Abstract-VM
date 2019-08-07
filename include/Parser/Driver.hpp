/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Driver.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 12:36:05 by jhache            #+#    #+#             */
/*   Updated: 2019/07/19 11:30:26 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRIVER_HPP
# define DRIVER_HPP

# include "Operand.hpp"
# include "Parser.tab.h"
# include "InstructionContainer.hpp"
# include "IInstruction.hpp"

class Driver
{
public:
	Driver(InstructionContainer &list);
	Driver(Driver const &src);
	~Driver();

	Driver	&operator=(Driver const &rhs);

	bool	parse(std::string const &fileName);
	void	pushInstruction(IInstruction *inst);

	// set as public because it is used by the parser/lexer, not by me
	yy::location	location;
	// those 2 booleans are used for debugging options
	bool			trace_parsing;
	bool			trace_scanning;

private:
	// the container that will load the parsed data
	InstructionContainer	&_instructionList;

	std::string				_fileName;

	// those 2 functions are implemented in the corresponding .l files
	bool	_scanBegin();
	bool	_scanEnd();

};

// Give Flex the prototype of yylex we want ...
# define YY_DECL \
	yy::parser::symbol_type yylex (Driver& drv)
// ... and declare it for the parser's sake.
YY_DECL;

#endif //DRIVER_HPP