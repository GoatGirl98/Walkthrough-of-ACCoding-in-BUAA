//\dhy/\dhy/\dhy/

/*
Recursive descend
BNF:
<equation> ::= <expr> "=" <expr> // 2H2+O2=2H2O
<expr> ::= <coef> <formula> | <coef> <formula> "+" <expr> // 2H2+O2, 2H2O
<coef> ::= <digits> | ""    //
<digits> ::= <digit> | <digits> <digit>
<digit> ::= "0" | "1" | ... | "9"
<formula> ::= <term> <coef> | <term> <coef> <formula>   // H2O CO2 Ca(OH)2 Ba3(PO4)2
<term> ::= <element> | "(" <formula> ")" // H, Ca, (OH), (PO4)
<element> ::= <uppercase> | <uppercase> <lowercase> // H, Ca, O, P, C
<uppercase> ::= "A" | "B" | ... | "Z"
<lowercase> ::= "a" | "b" | ... | "z"

11
H2+O2=H2O
2H2+O2=2H2O
H2+Cl2=2NaCl
H2+Cl2=2HCl
CH4+2O2=CO2+2H2O
CaCl2+2AgNO3=Ca(NO3)2+2AgCl
3Ba(OH)2+2H3PO4=6H2O+Ba3(PO4)2
3Ba(OH)2+2H3PO4=Ba3(PO4)2+6H2O
4Zn+10HNO3=4Zn(NO3)2+NH4NO3+3H2O
4Au+8NaCN+2H2O+O2=4Na(Au(CN)2)+4NaOH
Cu+As=Cs+Au
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <cassert>
using namespace std;
typedef long long ll;

#define MAXN 1000
char input[MAXN + 5];
int offset;

#define RST (offset = 0)
#define CHR (input[offset])
#define NXT (offset++)

struct ElementSet {
    map<string, int> content;
    ElementSet() {}
    ElementSet(string element, int coef) {content[element] = coef;}
    void merge(const ElementSet &s) {
        map<string, int>::const_iterator it1 = s.content.begin(), ie1 = s.content.end();
        while (it1 != ie1) {
            if (this->content.count(it1->first)) {
                this->content[it1->first] += it1->second;
            }
            else {
                this->content[it1->first] = it1->second;
            }
            it1++;
        }
    }
    void times(const int coef) {
        map<string, int>::iterator it1 = this->content.begin(), ie1 = this->content.end();
        while (it1 != ie1) {
            this->content[it1->first] *= coef;
            it1++;
        }
    }
    bool equals(const ElementSet &b) {
        map<string, int>::const_iterator it1 = this->content.begin(), ie1 = this->content.end();
        map<string, int>::const_iterator it2 = b.content.begin(), ie2 = b.content.end();
        while (it1 != ie1 && it2 != ie2) {
            if (it1->first != it2->first) return false;
            if (it1->second != it2->second) return false;
            it1++; it2++;
        }
        return (it1 == ie1) && (it2 == ie2);
    }
};



bool Equation();
void Expr(ElementSet &es);
int Coef();
// Digits
// Digit
void Formula(ElementSet &es);
void Term(ElementSet &es);
string Element();
// uppercase
// lowercase

bool Equation() {
    ElementSet left, right;
    Expr(left);
    assert(CHR == '=');
    NXT;
    Expr(right);
    return left.equals(right);
}

void Expr(ElementSet &es) {
    int coef = Coef();
    ElementSet formula;
    Formula(formula);
    formula.times(coef);
    es.merge(formula);
    while (CHR == '+') {
        NXT;
        formula.content.clear();
        coef = Coef();
        Formula(formula);
        formula.times(coef);
        es.merge(formula);
    }
}

int Coef() {
    if (CHR >= '0' && CHR <= '9') {
        int ret = 0;
        while (CHR >= '0' && CHR <= '9') {
            ret = (ret << 3) + (ret << 1) + (CHR - '0');
            NXT;
        }
        return ret;
    }
    else return 1;
}

void Formula(ElementSet &es) {
    ElementSet term;
    Term(term);
    int coef = Coef();
    term.times(coef);
    es.merge(term);
    while (CHR && CHR != '+' && CHR != ')' && CHR != '=') { // !!!
        term.content.clear();
        Term(term);
        coef = Coef();
        term.times(coef);
        es.merge(term);
    }
}

void Term(ElementSet &es) {
    if (CHR >= 'A' && CHR <= 'Z') {
        string ele = Element();
        es.merge(ElementSet(ele, 1));
    }
    else if (CHR == '(') {
        NXT; // '('
        ElementSet formula;
        Formula(formula);
        NXT; // ')'
        es.merge(formula);
    }
    else assert(0);
}

string Element() {
    assert(CHR >= 'A' && CHR <= 'Z');
    char ele[3] = {CHR, 0, 0};
    NXT;
    if (CHR >= 'a' && CHR <= 'z') {ele[1] = CHR; NXT;}
    return string(ele);
}


int main() {
    // freopen("test.in", "r", stdin);
    while (scanf("%s", input) != EOF) {
        RST;
        puts(Equation() ? "YES" : "NO");
    }
    return 0;
}
