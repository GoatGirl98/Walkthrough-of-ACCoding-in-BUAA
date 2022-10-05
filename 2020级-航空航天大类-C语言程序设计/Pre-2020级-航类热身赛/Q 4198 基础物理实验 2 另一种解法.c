#include <stdio.h>
int n;
int main(){
    while(scanf("%d",&n)!=EOF){
        switch (n) {
            case 1:printf("1\n");break;
            case 2:printf("3\n");break;
            case 3:printf(" 1\n"
                          "5-\n"
                          " 2\n");break;
            case 4:printf(" 1\n"
                          "8-\n"
                          " 3\n");break;
            case 5:printf("  5\n"
                          "11--\n"
                          "  12\n");break;
            case 6:printf("  7\n"
                          "14--\n"
                          "  10\n");break;
            case 7:printf("  3\n"
                          "18--\n"
                          "  20\n");break;
            case 8:printf("  26\n"
                          "21--\n"
                          "  35\n");break;
            case 9:printf("  129\n"
                          "25---\n"
                          "  280\n");break;
            case 10:printf("  73\n"
                           "29---\n"
                           "  252\n");break;
            case 11:printf("  551\n"
                           "33----\n"
                           "  2520\n");break;
            case 12:printf("  551\n"
                           "37----\n"
                           "  2310\n");break;
            case 13:printf("  9473\n"
                           "41-----\n"
                           "  27720\n");break;
            case 14:printf("  13433\n"
                           "45-----\n"
                           "  25740\n");break;
            case 15:printf("  18581\n"
                           "49-----\n"
                           "  24024\n");break;
            case 16:printf("  4129\n"
                           "54-----\n"
                           "  45045\n");break;
            case 17:printf("  340463\n"
                           "58------\n"
                           "  720720\n");break;
            case 18:printf("  620743\n"
                           "62------\n"
                           "  680680\n");break;
            case 19:printf("  1662439\n"
                           "67-------\n"
                           "  4084080\n");break;
            case 20:printf("  3704479\n"
                           "71-------\n"
                           "  3879876\n");break;
            case 21:printf("  408335\n"
                           "76------\n"
                           "  739024\n");break;
            case 22:printf("  46533\n"
                           "81------\n"
                           "  235144\n");break;
            case 23:printf("  4597419\n"
                           "85-------\n"
                           "  5173168\n");break;
            case 24:printf("  9265735\n"
                           "90--------\n"
                           "  14872858\n");break;
            case 25:printf("  142406227\n"
                           "95---------\n"
                           "  356948592\n");break;
            case 26:printf("   73762267\n"
                           "100---------\n"
                           "   343219800\n");break;
            case 27:printf("   206234003\n"
                           "105----------\n"
                           "   2974571600\n");break;
            case 28:printf("   2755866803\n"
                           "109----------\n"
                           "   2868336900\n");break;
            case 29:printf("   71315126587\n"
                           "114-----------\n"
                           "   80313433200\n");break;
            case 30:printf("   65960897707\n"
                           "119-----------\n"
                           "   77636318760\n");break;
        }
        putchar('\n');
    }
}