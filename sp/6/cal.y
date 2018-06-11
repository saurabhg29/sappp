%{
/* this is yacc specification */
#include <stdio.h>
%}

%token NAME 
%left '-' '+'
%left '*' '/'
%nonassoc UMINUS

%%
statement: NAME '=' exp
         | exp { printf("= %d\n",$1); }
         ;
exp: exp '+' exp { $$ = $1 + $3; }
   | exp '-' exp { $$ = $1 - $3; }
   | exp '*' exp { $$ = $1 * $3; }
   | exp '/' exp { $$ = $1 / $3; }
   | '-' exp %prec UMINUS { $$ = -$2; }
   | '(' exp ')' { $$ = $2; }
   | NUMBER      { $$ = $1; }
   ;
%%
int main()
{
  yyparse();
}
int yyerror()
{
  
}
int yywrap()
{
  return 1;
}

