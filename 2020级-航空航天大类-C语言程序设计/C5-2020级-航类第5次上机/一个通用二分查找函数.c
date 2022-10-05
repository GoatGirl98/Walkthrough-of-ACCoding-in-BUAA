/*******
 * 使用说明：
 * a是被查找的数组，如果需要查找其他数据类型的数组，可自行修改变量类型
 * len为数组长度
 * num为被查找的变量
 * isLeft为1表示查找num在数组中第一次出现的位置，为0表示最后一次出现的位置
 * 返回值就是该值在数组中的索引，数组在该处的值不等于num，说明没找到。
 *******/

int FindCntofNum(int a[],int len, int num, int isLeft)
{
    int left = 0, right = len -1;

    int pos,mid;

    while(left <= right)//二分查找
    {
        mid = (left + right)/2;

        if( a[mid] < num )
        {
            left = mid +1;
        }
        else if(a[mid] > num)
        {
            right = mid -1;
        }
        else
        {
            pos = mid;

            if(isLeft)//查找最左值
            {
                right = mid -1;
            }
            else//查找最右值
            {
                left = mid +1;
            }
        }
    }
    return pos;//返回最终查找到的位置
}