/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Driver.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 12:36:05 by jhache            #+#    #+#             */
/*   Updated: 2019/07/03 13:00:34 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRIVER_HPP
# define DRIVER_HPP

# include "Operand.hpp"
# include "Parser.hpp"

// Give Flex the prototype of yylex we want ...
# define YY_DECL \
	yy::parser::symbol_type yylex (driver& drv)
// ... and declare it for the parser's sake.
YY_DECL;

class Driver
{
public:
	Driver(void *list = nullptr);
	Driver(Driver const &src);
	~Driver();

	Driver	&operator=(Driver const &rhs);

	void	setStr(std::string str);
	void	setOperand(Operand *op);
	void	setOperandType(OperandType type);
	void	setInstruction(void *inst);

	int		parse(std::string const &fileName);

private:
	//intermediate values that is loaded and used during parsing
	std::string		_str;
	Operand			*_op;
	OperandType		_opType;
	void			*_inst;//should be a Instruction class pointer//is it useful ?

	// the list that will load the parsed data
	void			*_instructionList;//should be a reference to a InstructionList class instance

	std::string		_fileName;
	yy::location	location;

	void	_scanBegin();
	void	_scanEnd();

};

#endif //DRIVER_HPP