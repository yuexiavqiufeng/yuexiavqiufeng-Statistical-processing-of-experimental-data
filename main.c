#include <stdio.h>
#include "array_operation.h"

// 主函数举例
int main()
{

    double result[result_size]; //定义存放结果的函数

    printf("结果数据地址:%x\n", read_array_operation(result)); //调用此计算函数

    //输出最后结果
    int i = 0;
    printf("统计量结果为:\n");
    for (i = 0; i < result_size; i++)
    {
        printf("%f\n", result[i]);
    }

    getchar();
    return 0;
}