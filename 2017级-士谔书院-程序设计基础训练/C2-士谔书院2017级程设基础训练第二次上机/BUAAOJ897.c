#include<stdio.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
int length[3], width[3];
int a, b;
int res;
int main()
{
    for(int i = 0; i < 3; ++i)
    {
        scanf("%d%d", &a, &b);
        length[i] = max(a, b), width[i] = min(a, b);
    }
    for(int i = 0; i < 3; ++i)
        for(int j = i + 1; j < 3; ++j)
            if(length[i] * width[i] < length[j] * width[j])
            {
                if(length[i] != length[j])
                    length[i] ^= length[j], length[j] ^= length[i], length[i] ^= length[j];
                if(width[i] != width[j])
                    width[i] ^= width[j], width[j] ^= width[i], width[i] ^= width[j];
            }
    if (length[1] + width[2] <= length[0] && max(width[1], length[2]) <= width[0]) 
        res = 1;

    if (length[1] + width[2] <= width[0] && max(width[1], length[2]) <= length[0]) 
        res = 1; 
    
    if (length[1] + length[2] <= length[0] && max(width[1], width[2]) <= width[0]) 
        res = 1;
    
    if (length[1] + length[2] <= width[0] && max(width[1], width[2]) <= length[0]) 
        res = 1;
    
    if (width[1] + length[2] <= length[0] && max(length[1], width[2]) <= width[0]) 
        res = 1;
    
    if (width[1] + length[2] <= width[0] && max(length[1], width[2]) <= length[0]) 
        res = 1;
    
    if (width[1] + width[2] <= length[0] && max(length[1], length[2]) <= width[0]) 
        res = 1;
    
    if (width[1] + width[2] <= width[0] && max(length[1], length[2]) <= length[0]) 
        res = 1;
    
    puts(res ? "SIXSIXSIX!" : "GG!");
}
