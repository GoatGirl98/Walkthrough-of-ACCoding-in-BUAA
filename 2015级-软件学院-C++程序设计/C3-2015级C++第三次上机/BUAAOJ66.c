#include <stdio.h>
int days;
int notRun[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
int Run[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30};
char week[7][10] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
char Month[15][5] = {"", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"};
char Day[40][5] = {"", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10",
                   "11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
                   "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31"};
//因为2000.1.1是星期六

int get_week() { return days % 7; }

int get_year()
{
    int cur = 2000;
    char isRun;
    while (1)
    {
        isRun = (cur % 4 == 0 && cur % 100 != 0 || cur % 400 == 0);
        if (isRun && days >= 366)
        {
            days -= 366;
            ++cur;
            continue;
        }
        else if (!isRun && days >= 365)
        {
            days -= 365;
            ++cur;
            continue;
        }
        else
            break;
    }
    return cur;
}

int get_month(char isRun)
{

    int curMonth = 0;
    while (1)
    {
        if (curMonth >= 11)
            break;
        if (isRun && days >= Run[curMonth])
        {
            days -= Run[curMonth];
            // cout << "debug : curMonth " << curMonth << "remain days" << days << endl;
            curMonth++;
        }
        else if (!isRun && days >= notRun[curMonth])
        {
            days -= notRun[curMonth];
            curMonth++;
        }
        else
            break;
    }
    return ++curMonth;
}
int main()
{
    int year, month, weeklalala;
    char Runlalala;
    while (scanf("%d", &days) != EOF)
    {
        weeklalala = get_week();
        year = get_year();
        Runlalala = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
        month = get_month(Runlalala);
        days++;
        printf("%d-%s-%s %s\n", year, Month[month], Day[days], week[weeklalala]);
    }
    return 0;
}