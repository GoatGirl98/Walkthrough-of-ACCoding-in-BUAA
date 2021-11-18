#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********** Formula ***********
 * <EXPR> ::= <TERM> {"+"|"-" <TERM>}
 * <TERM> ::= <FACTOR> {"*"|"/" <FACTOR>}
 * <FACTOR> ::= (<NAME> [<FUNC> | <METHOD> {<METHOD>}]) | ("(" <EXPR> ")" {<METHOD>})
 * <FUNC> ::= "(" <EXPR> {"," <EXPR>} ")"
 * <METHOD> ::= "." <NAME> <FUNC>
 * <NAME> ::= [IDENTIFIER]
 *******************************/ 

#define WF printf("panic at line %d:^^^^^^WRONG FORMAT^^^^^^^^^\n", __LINE__);

#define MAX_EXPR_LENGTH 125
char buf[MAX_EXPR_LENGTH];
char *p_str = buf;

static int count = 0;
#define SAVE (++count)

typedef struct Val {
    unsigned char type; // 0: variable, 1: temporary result
    union {
        char var;
        int res;
    } val;
} Val;
void disp(const Val *v) {
    if (v->type == 0) {
        putchar(v->val.var);
    } else {
        printf("%d", v->val.res);
    }
}
Val ValVar(char var) {
    Val r;
    r.type = 0;
    r.val.var = var;
    return r;
}
Val ValRes(int res) {
    Val r;
    r.type = 1;
    r.val.res = res;
    return r;
}


Val Expr();
Val Term();
Val Factor();
Val Func(char name, const Val* self);
Val Method(const Val *self);
Val Name();

int main()
{
    gets(buf);
    Expr();
    return 0;
}


Val Expr(){
    if (!(*p_str)) WF;

    Val term = Term();
    Val res = term;
    while ((*p_str) && ((*p_str) == '+' || (*p_str) == '-')) {
        char op = *(p_str++);
        term = Term();
        printf("%c ", op);
        disp(&res); putchar(' ');
        disp(&term);
        res = ValRes(SAVE);
        putchar('\n');
    }
    
    return res;
}

Val Term(){
    if (!(*p_str)) WF;

    Val factor = Factor();
    Val res = factor;
    while ((*p_str) && ((*p_str) == '*' || (*p_str) == '/')) {
        char op = *(p_str++);
        factor = Factor();
        printf("%c ", op);
        disp(&res); putchar(' ');
        disp(&factor);
        res = ValRes(SAVE);
        putchar('\n');
    }
    
    return res;
}

Val Factor(){
    if (!(*p_str)) WF;
    Val ret;
    if ((*p_str) == '(') {
        p_str++;
        Val expr = Expr();
        if (!(*p_str) || (*p_str) != ')') WF;
        p_str++; // ')'
        ret = expr;
    } else {
        Val name = Name();
        if (*p_str && (*p_str) == '(') {ret = Func(name.val.var, NULL);}
        else ret = name;
    }

    while ((*p_str) && (*p_str) == '.') {
        ret = Method(&ret);
    }
    return ret;
}

Val Func(char name, const Val* self){
    // self has already calculated
    Val *args = malloc(121 * sizeof(Val)); 
    int argc = 0;
    if (!(*p_str) || (*p_str) != '(') WF;
    p_str++; // '('
    
    if (self != NULL) {
        args[argc++] = *self;
    }
    Val expr = Expr();
    args[argc++] = expr;
    while (*p_str && (*p_str) == ',') {
        p_str++;
        expr = Expr();
        args[argc++] = expr;
    }
    if (!(*p_str) || (*p_str) != ')') WF;
    p_str++;
    printf("%c", name);
    for (int i = 0; i < argc; i++) {
        putchar(' ');
        disp(&args[i]);
    }
    putchar('\n');
    free(args);
    return ValRes(SAVE);
}

Val Method(const Val *self){
    if (!(*p_str) || (*p_str) != '.') WF;
    p_str++;
    Val name = Name();
    return Func(name.val.var, self);
}
Val Name(){
    if (!(*p_str) || (*p_str) < 'a' || (*p_str) > 'z') WF;
    char name = *(p_str++);
    return ValVar(name);
}