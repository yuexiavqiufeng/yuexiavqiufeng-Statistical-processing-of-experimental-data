#include <stdio.h>
#include "array_operation.h"

//存放源数据的文件地址
char address[sample_size][10] = {
    "1.txt",
    "2.txt",
    "3.txt",
    "4.txt",
    "5.txt",
    "6.txt",
    "7.txt",
    "8.txt",
    "9.txt",
    "10.txt",
    "11.txt",
    "12.txt",
    "13.txt",
    "14.txt",
    "15.txt",
    "16.txt",
    "17.txt",
    "18.txt",
    "19.txt",
    "20.txt"};

/*读取文本中数据并且进行要求的计算。
输入为结果数据数组的地址，返回值是结果数据数组指针。

结果数组定义:
ex:double result[result_size];

如何更改源数据:
1.需要修改头文件array_operation.h中result_size与sample_size的宏定义
2.需要修改array_operation.c中的源数据地址*/
double *read_array_operation(double *result)
{

    double u[result_size][sample_size]; //用于存放u的二维数组
    double v[result_size][sample_size]; //用于存放v的二维数组
    char temchar;

    int i = 0; //i：每次实验第i个数据。
    int j = 0; //j：第j次实验。
    int k = 0; //k：用于控制循环次数。

    FILE *fp = NULL; //定义源文件指针

    //依次读取每次实验的数据
    for (j = 0; j < sample_size; j++)
    {

        fp = fopen(address[j], "r+"); //打开文件

        //读取掉最开始的字母（数据开头有三个描述字符）
        for (k = 0; k < 3; k++)
        {
            fscanf(fp, "%c", &temchar);
        }

        //读取实验数据
        for (i = 0; i < result_size; i++)
        {
            fscanf(fp, "%lf", &u[i][j]);
            fscanf(fp, "%c", &temchar);
            fscanf(fp, "%lf", &v[i][j]);
        }
        fclose(fp);
    }

    /**************************读取结束********************************/
    /**************************开始计算********************************/

    double A = 0;
    double ave_u = 0;
    double ave_v = 0;
    i = 0;
    j = 0;

    //依次计算每项实验数据的统计值
    for (i = 0; i < result_size; i++)
    {

        //初始化
        A = 0;
        ave_u = 0;
        ave_v = 0;

        //求和
        for (j = 0; j < sample_size; j++)
        {
            ave_u += u[i][j];
            ave_v += v[i][j];
            A += u[i][j] * v[i][j];
        }

        //取平均
        A = A / sample_size;
        ave_u = ave_u / sample_size;
        ave_v = ave_v / sample_size;

        //计算最后的结果存入结果数组
        result[i] = A - ave_u * ave_v;
    }

    return result; //返回结果数据数组指针
}
