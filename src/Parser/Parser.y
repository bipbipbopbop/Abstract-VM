%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.2" /*current version on 42 Macintosh*/
%defines

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
	# include <string>
	# include "OperandFactory.hpp"
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
	WHITESPACES	"whitespaces"
	COMMENT		"comment"
	LPAREN		"("
	RPAREN		")"
	CHAR		"character"

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

%type <OperandType> int_type
%type <OperandType> float_type
%type <const IOperand*> value
%type <IInstruction*> instruction

%printer { yyo << $$; } <*>;

%%
%start input;

input:
	line_content SEP input {}
	| line_content END { return 0; }
	| SEP input {}
	| END { return 0; }
	;

line_content:
	WHITESPACES line_content {}
	| COMMENT {}
	| instruction 						{ drv.pushInstruction($1); }
	| instruction COMMENT 				{ drv.pushInstruction($1); }
	;

instruction:
	instruction WHITESPACES		{ $$ = $1; }
	| PUSH WHITESPACES value	{ $$ = new Push($3); }
	| POP						{ $$ = new Pop(); }
	| DUMP						{ $$ = new Dump(); }
	| ASSERT WHITESPACES value	{ $$ = new Assert($3); }
	| ADD						{ $$ = new Add(); }
	| SUB						{ $$ = new Sub(); }
	| MUL						{ $$ = new Mul(); }
	| DIV						{ $$ = new Div(); }
	| MOD						{ $$ = new Mod(); }
	| PRINT						{ $$ = new Print(); }
	| EXIT						{ $$ = new Exit(); }
	;

value:
	float_type LPAREN FLOAT_VALUE RPAREN	{ $$ = OperandFactory::CreateOperand($1, $3); }
	| int_type LPAREN INT_VALUE RPAREN		{ $$ = OperandFactory::CreateOperand($1, $3); }
	;

int_type:
	INT8		{ $$ = OperandType::Int8; }
	| INT16		{ $$ = OperandType::Int16; }
	| INT32		{ $$ = OperandType::Int32; }
	;

float_type:
	FLOAT		{ $$ = OperandType::Float; }
	| DOUBLE	{ $$ = OperandType::Double; }
	;


%%

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cout << l << ": " << m << '\n';
}