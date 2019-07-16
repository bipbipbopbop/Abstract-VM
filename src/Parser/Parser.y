%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.2" /*current version on 42 Macintosh*/
%defines

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
	# include <iostream>
	# include <string>
	# include "Operand.hpp"
	# include "Add.hpp"
	# include "Assert.hpp"
	# include "Div.hpp"
	# include "Dump.hpp"
	# include "Exit.hpp"
	# include "Mod.hpp"
	# include "Mul.hpp"
	# include "Pop.hpp"
	# include "Print.hpp"
	# include "Push.hpp"
	# include "Sub.hpp"
	class Driver;
}
%param { Driver &drv }
%locations

%define parse.trace
%define parse.error verbose

%code {
	# include "Driver.hpp"
}


%define api.token.prefix {TOK_}
/* miscellaneous parsing tokens */
%token
	END		0	"end of file"
	SEP			"separator"
	COMMENT		"comment"
	MY_EOF		"my_eof"
	LPAREN		"("
	RPAREN		")"

/* instructions */
%token
	PUSH		"push"
	POP			"pop"
	DUMP		"dump"
	ASSERT		"assert"
	ADD			"add"
	SUB			"sub"
	MUL			"mul"
	DIV			"div"
	MOD			"mod"
	PRINT		"print"
	EXIT		"exit"

/* Type specifiers for operands */
%token
	INT8		"int8"
	INT16		"int16"
	INT32		"int32"
	FLOAT		"float"
	DOUBLE		"double"

/* literal values (from the lexer) */
%token <std::string> FLOAT_VALUE	"float_value"
%token <std::string> INT_VALUE		"int_value"

%type <OperandType> type
%type <std::string> literal
%type <Operand*> value
%type <IInstruction*> instruction

%printer { yyo << $$; } <*>;

%%
%start input;

input:
	%empty { }
	| instruction custom_eol input { drv.pushInstruction($1); }
	| custom_eol input { }
	| MY_EOF { }
	;

custom_eol:
	SEP {}
	| COMMENT SEP {}
	;

instruction:
	PUSH value		{ std::cout << "this is a push\n"; $$ = new Push($2); }
	| POP			{ std::cout << "this is a pop\n"; $$ = new Pop(); }
	| DUMP			{ std::cout << "this is a Dump\n"; $$ = new Dump(); }
	| ASSERT value	{ std::cout << "this is a assert\n"; $$ = new Assert($2); }
	| ADD			{ std::cout << "this is a add\n"; $$ = new Add(); }
	| SUB			{ std::cout << "this is a sub\n"; $$ = new Sub(); }
	| MUL			{ std::cout << "this is a mul\n"; $$ = new Mul(); }
	| DIV			{ std::cout << "this is a div\n"; $$ = new Div(); }
	| MOD			{ std::cout << "this is a mod\n"; $$ = new Mod(); }
	| PRINT			{ std::cout << "this is a print\n"; $$ = new Print(); }
	| EXIT			{ std::cout << "this is a exit\n"; $$ = new Exit(); }
	;

value:
	type LPAREN literal RPAREN	{ $$ = Operand::StrToOperand($3, $1); }
	;

literal:
	INT_VALUE		{ $$ = $1; }
	| FLOAT_VALUE	{ $$ = $1; }
	;

type:
	INT8		{ $$ = OperandType::Int8; }
	| INT16		{ $$ = OperandType::Int16; }
	| INT32		{ $$ = OperandType::Int32; }
	| FLOAT		{ $$ = OperandType::Float; }
	| DOUBLE	{ $$ = OperandType::Double; }
	;


%%

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}