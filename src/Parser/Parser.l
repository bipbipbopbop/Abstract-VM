%{
	#include <cstring>
	#include <cstring>
	#include <string>
	#include "Driver.hpp"
	#include "Parser.tab.h"
%}

%option debug nounput noinput

DIGITS		[0-9]+
INT			-?{DIGITS}
FLOAT		-?{DIGITS}\.{DIGITS}

SEP			\n

COMMENT		;.*$
MY_EOF		^;;$
WHITESPACES	[ \t\r]+

%{
	// Code run each time a pattern is matched.
	# define YY_USER_ACTION  loc.columns (yyleng);
%}

%%

%{
	// A handy shortcut to the location held by the driver.
	yy::location	&loc = drv.location;
	// Code run each time yylex is called.
	loc.step();
%}

push		{ return yy::parser::make_PUSH(loc); }
pop			{ return yy::parser::make_POP(loc); }
dump		{ return yy::parser::make_DUMP(loc); }
assert		{ return yy::parser::make_ASSERT(loc); }
add			{ return yy::parser::make_ADD(loc); }
sub			{ return yy::parser::make_SUB(loc); }
mul			{ return yy::parser::make_MUL(loc); }
div			{ return yy::parser::make_DIV(loc); }
mod			{ return yy::parser::make_MOD(loc); }
print		{ return yy::parser::make_PRINT(loc); }
exit		{ return yy::parser::make_EXIT(loc); }

int8		{ return yy::parser::make_INT8(loc); }
int16		{ return yy::parser::make_INT16(loc); }
int32		{ return yy::parser::make_INT32(loc); }
float		{ return yy::parser::make_FLOAT(loc); }
double		{ return yy::parser::make_DOUBLE(loc); }
{FLOAT}		{ return yy::parser::make_FLOAT_VALUE(yytext, loc); }
{INT}		{ return yy::parser::make_INT_VALUE(yytext, loc); }

\(			{ return yy::parser::make_LPAREN(loc); }
\)			{ return yy::parser::make_RPAREN(loc); }

{SEP}		{ loc.lines(yyleng); loc.step(); return yy::parser::make_SEP(loc); }
{MY_EOF}	{ return yy::parser::make_END(loc); }
{COMMENT}	{ return yy::parser::make_COMMENT(loc); }
<<EOF>>		{ return yy::parser::make_EOF(loc); }

{WHITESPACES}	{ return yy::parser::make_WHITESPACES(loc); }
.				{ return yy::parser::make_CHAR(loc); }

%%

bool	Driver::_scanBegin()
{
	yy_flex_debug = this->trace_scanning;
	if (this->_fileName == "stdin")
		yyin = stdin;
	else if (!(yyin = fopen(this->_fileName.c_str(), "r")))
	{
		std::cout << "can't open " << this->_fileName << ": " << strerror(errno) << std::endl;
		return false;
	}
	return true;
}

bool	Driver::_scanEnd()
{
	return fclose(yyin) == 0;
}