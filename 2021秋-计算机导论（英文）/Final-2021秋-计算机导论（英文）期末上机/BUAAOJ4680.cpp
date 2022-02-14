#include <iostream>
#include <string>
#include <sstream>
#include <ctype.h>
using namespace std;
int T;
string a;
double sc, credit;
double GPA(double score)
{
    if (score >= 60.0)
        return 4.0 - 3.0 * (100.0 - 1.0 * score) * (100.0 - 1.0 * score) / 1600.0;
    else
        return 0.0;
}
double GPA(char c)
{
    return (c == 'A') ? 4.0 : (c == 'B') ? 3.5 : (c == 'C') ? 2.8 : (c == 'D') ? 1.7 : 0;
}
double sum_grade, sum_point;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> a >> credit;
        if (isdigit(a[0]))
        {
            stringstream s(a);
            s >> sc;
            sum_grade += GPA(sc) * credit;
		    sum_point += credit;
        }
        else
            sum_grade += GPA(a[0]) * credit, sum_point += credit;
    }
    printf("%.3f", sum_grade / sum_point);
}