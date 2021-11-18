#include<cstdio>
#include<cstring>
#define Short_Set 1
#define Long_Set 2
#define Normal_Game 1
#define Long_Game 2
#define Decide_Game 3
#define AD -1
char s[114514];
int scores[] = { 0, 15, 30, 40 };
int main() {
    while (scanf("%s",s) !=EOF)
    {
        int A_Set_Score = 0;
        int B_Set_Score = 0;
        int A_Game_Score = 0;
        int B_Game_Score = 0;
        int A_Ball = 0;
        int B_Ball = 0;
        int Set_Type = Short_Set;
        int Game_Type = Normal_Game;
        for (int i = 0; i < strlen(s); i++)
        {
            if (Game_Type == Normal_Game) {
                if (s[i] == 'A')
                {
                    if (A_Ball == AD) {
                        A_Game_Score++;
                        if (A_Game_Score == 6) {
                            A_Set_Score++;
                            A_Game_Score = 0;
                            B_Game_Score = 0;
                        }
                        A_Ball = 0;
                        B_Ball = 0;
                    }
                    else if (B_Ball == AD)
                    {
                        A_Ball = 3;
                        B_Ball = 3;
                    }
                    else{
                        A_Ball++;
                        if (A_Ball >= 4) {
                            if (B_Ball < 3) {
                                A_Game_Score++;
                                if (A_Game_Score == 6) {
                                    A_Set_Score++;
                                    A_Game_Score = 0;
                                    B_Game_Score = 0;
                                }
                                A_Ball = 0;
                                B_Ball = 0;
                            }
                            else{
                                A_Ball = AD;
                            }
                        }
                    }
                }
                else
                {
                    if (B_Ball == AD) {
                        B_Game_Score++;
                        if (B_Game_Score == 6) {
                            B_Set_Score++;
                            A_Game_Score = 0;
                            B_Game_Score = 0;
                        }
                        A_Ball = 0;
                        B_Ball = 0;
                    }
                    else if (A_Ball == AD)
                    {
                        A_Ball = 3;
                        B_Ball = 3;
                    }
                    else {
                        B_Ball++;
                        if (B_Ball >= 4) {
                            if (A_Ball < 3) {
                                B_Game_Score++;
                                if (B_Game_Score == 6) {
                                    B_Set_Score++;
                                    A_Game_Score = 0;
                                    B_Game_Score = 0;
                                }
                                A_Ball = 0;
                                B_Ball = 0;
                            }
                            else {
                                B_Ball = AD;
                            }
                        }
                    }
                }
                printf("  Set:%3d :%3d\n", A_Set_Score, B_Set_Score);
                printf(" Game:%3d :%3d\n", A_Game_Score, B_Game_Score);
                if(A_Ball == AD)
                    printf("Point: AD :   \n");
                else if(B_Ball == AD)
                    printf("Point:    : AD\n");
                else
                    printf("Point:%3d :%3d\n", scores[A_Ball], scores[B_Ball]);
            }
            else if (Game_Type == Long_Game) {
                if (s[i] == 'A')
                {
                    if (A_Ball == AD) {
                        A_Game_Score++;
                        if (A_Game_Score == 7) {
                            A_Set_Score++;
                            A_Game_Score = 0;
                            B_Game_Score = 0;
                            Game_Type = Normal_Game;
                        }
                        A_Ball = 0;
                        B_Ball = 0;
                    }
                    else if (B_Ball == AD)
                    {
                        A_Ball = 3;
                        B_Ball = 3;
                    }
                    else {
                        A_Ball++;
                        if (A_Ball >= 4) {
                            if (B_Ball < 3) {
                                A_Game_Score++;
                                if (A_Game_Score == 7) {
                                    A_Set_Score++;
                                    A_Game_Score = 0;
                                    B_Game_Score = 0;
                                    Game_Type = Normal_Game;
                                }
                                A_Ball = 0;
                                B_Ball = 0;
                            }
                            else {
                                A_Ball = AD;
                            }
                        }
                    }
                }
                else
                {
                    if (B_Ball == AD) {
                        B_Game_Score++;
                        if (B_Game_Score == 7) {
                            B_Set_Score++;
                            A_Game_Score = 0;
                            B_Game_Score = 0;
                            Game_Type = Normal_Game;
                        }
                        A_Ball = 0;
                        B_Ball = 0;
                    }
                    else if (A_Ball == AD)
                    {
                        A_Ball = 3;
                        B_Ball = 3;
                    }
                    else {
                        B_Ball++;
                        if (B_Ball >= 4) {
                            if (A_Ball < 3) {
                                B_Game_Score++;
                                if (B_Game_Score == 7) {
                                    B_Set_Score++;
                                    A_Game_Score = 0;
                                    B_Game_Score = 0;
                                    Game_Type = Normal_Game;
                                }
                                A_Ball = 0;
                                B_Ball = 0;
                            }
                            else {
                                B_Ball = AD;
                            }
                        }
                    }
                }
                printf("  Set:%3d :%3d\n", A_Set_Score, B_Set_Score);
                printf(" Game:%3d :%3d\n", A_Game_Score, B_Game_Score);
                if (A_Ball == AD)
                    printf("Point: AD :   \n");
                else if (B_Ball == AD)
                    printf("Point:    : AD\n");
                else
                    printf("Point:%3d :%3d\n", scores[A_Ball], scores[B_Ball]);
            }
            else{ //Decide_Game
                if (Set_Type == Short_Set) {
                    if (s[i] == 'A') {
                        A_Ball++;
                        if (A_Ball >= 7 && A_Ball - B_Ball >= 2) {
                            A_Set_Score++;
                            A_Game_Score = 0;
                            B_Game_Score = 0;
                            A_Ball = 0;
                            B_Ball = 0;
                            Game_Type = Normal_Game;
                        }
                    }
                    else {
                        B_Ball++;
                        if (B_Ball >= 7 && B_Ball - A_Ball >= 2) {
                            B_Set_Score++;
                            A_Game_Score = 0;
                            B_Game_Score = 0;
                            A_Ball = 0;
                            B_Ball = 0;
                            Game_Type = Normal_Game;
                        }
                    }
                    printf("  Set:%3d :%3d\n", A_Set_Score, B_Set_Score);
                    printf(" Game:%3d :%3d\n", A_Game_Score, B_Game_Score);
                    printf("Point:%3d :%3d\n", A_Ball, B_Ball);
                }
                else {
                    if (s[i] == 'A')
                    {
                        if (A_Ball == AD) {
                            A_Game_Score++;
                            if (A_Game_Score >= 8 && A_Game_Score - B_Game_Score >= 2) {
                                A_Set_Score++;
                                A_Game_Score = 0;
                                B_Game_Score = 0;
                            }
                            A_Ball = 0;
                            B_Ball = 0;
                        }
                        else if (B_Ball == AD)
                        {
                            A_Ball = 3;
                            B_Ball = 3;
                        }
                        else {
                            A_Ball++;
                            if (A_Ball >= 4) {
                                if (B_Ball < 3) {
                                    A_Game_Score++;
                                    if (A_Game_Score >= 8 && A_Game_Score - B_Game_Score >= 2) {
                                        A_Set_Score++;
                                        A_Game_Score = 0;
                                        B_Game_Score = 0;
                                    }
                                    A_Ball = 0;
                                    B_Ball = 0;
                                }
                                else {
                                    A_Ball = AD;
                                }
                            }
                        }
                    }
                    else
                    {
                        if (B_Ball == AD) {
                            B_Game_Score++;
                            if (B_Game_Score >= 8 && B_Game_Score - A_Game_Score >= 2) {
                                B_Set_Score++;
                                A_Game_Score = 0;
                                B_Game_Score = 0;
                            }
                            A_Ball = 0;
                            B_Ball = 0;
                        }
                        else if (A_Ball == AD)
                        {
                            A_Ball = 3;
                            B_Ball = 3;
                        }
                        else {
                            B_Ball++;
                            if (B_Ball >= 4) {
                                if (A_Ball < 3) {
                                    B_Game_Score++;
                                    if (B_Game_Score >= 8 && B_Game_Score - A_Game_Score >= 2) {
                                        B_Set_Score++;
                                        A_Game_Score = 0;
                                        B_Game_Score = 0;
                                    }
                                    A_Ball = 0;
                                    B_Ball = 0;
                                }
                                else {
                                    B_Ball = AD;
                                }
                            }
                        }
                    }
                    printf("  Set:%3d :%3d\n", A_Set_Score, B_Set_Score);
                    printf(" Game:%3d :%3d\n", A_Game_Score, B_Game_Score);
                    if (A_Ball == AD)
                        printf("Point: AD :   \n");
                    else if (B_Ball == AD)
                        printf("Point:    : AD\n");
                    else
                        printf("Point:%3d :%3d\n", scores[A_Ball], scores[B_Ball]);
                }
            }
            if (A_Game_Score == 5 && B_Game_Score == 5)
                Game_Type = Long_Game;
            if (A_Game_Score == 6 && B_Game_Score == 6)
                Game_Type = Decide_Game;
            if (A_Set_Score == 2 && B_Set_Score == 2)
                Set_Type = Long_Set;
            if (A_Set_Score == 3)
                printf("A wins!");
            if (B_Set_Score == 3)
                printf("B wins!");
        }
    }
}
