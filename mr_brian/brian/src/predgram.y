%{
#include "engine_objects.h"

#ifdef DMALLOC
#include <dmalloc.h>
#endif

extern int predlex();
int prederror(const char *);

aggr_tree_multimap *pt=NULL;

%}

%union {
  char * dataname;
  operation * op;
}

%type <dataname> name
%type <op> operator andexprlist orexprlist
%token <dataname> NAME
%token LEFTPAR
%token RIGHTPAR
%token NEWLINE
%token DEF
%token AND
%token OR
%token NOT
%token P
%token D

%start predicates

%%

predicates: pred NEWLINE predicates
          | pred
          | pred NEWLINE
          | NEWLINE predicates
          | NEWLINE
          ;

pred: name DEF operator      {pt->insert(pair < char *, aggregation_tree *> ($1, new aggregation_tree($1,$3)));}
    ;

operator: LEFTPAR AND andexprlist RIGHTPAR  {$$=$3;}
        | LEFTPAR OR orexprlist RIGHTPAR   {$$=$3;}
        | LEFTPAR NOT operator RIGHTPAR           {$$=new op_not($3);}
        | LEFTPAR D name name RIGHTPAR              {$$=new data_node($3,$4); free($3); free($4);}
        | LEFTPAR P name RIGHTPAR                   {$$=new predicate_node($3); free($3);}
        ;
        
andexprlist: operator andexprlist {$$= new op_and($1, $2);}
           | operator operator {$$= new op_and($1, $2);}
           ;
           
orexprlist: operator orexprlist {$$= new op_or($1, $2);}
          | operator operator {$$= new op_or($1, $2);}
          ;

name: NAME  {$$=(char *) malloc(strlen($1)+1);
             strcpy($$,$1);}
      ;

%%
  
int prederror(const char *s)
{
  printf("\n# Predicate file error: %s\n",s);
  return 0;
}
 
aggr_tree_multimap * parsefile(aggr_tree_multimap *anaggrmmap)
{
  pt = anaggrmmap;
  predparse();
  return pt;
}
