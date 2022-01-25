#include<stdio.h>
double GPA(int score) {
	if (score >= 60) return 4.0 - 3.0 * (100.0 - 1.0 * score) * (100.0 - 1.0 * score) / 1600.0;
	else return 0.0;
}
double sum_grade, sum_point;
int score[510];
double credit;
int n;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &score[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%lf", &credit), sum_grade += GPA(score[i]) * credit, sum_point += credit;
	printf("%.3f\n", sum_grade / sum_point);
}