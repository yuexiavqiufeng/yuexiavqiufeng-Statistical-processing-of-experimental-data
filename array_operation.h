#ifndef __FSCANF_H__
#define __FSCANF_H__

#define result_size 20 //每次实验数据个数（文本行数）
#define sample_size 20 //试验次数（文本个数）

//存放数据的文件地址
extern char address[sample_size][10];

/*读取文本中数据并且进行要求的计算。
输入为结果数据数组的地址。

结果数组定义:
ex:double result[result_size];

如何更改源数据:
1.需要修改头文件array_operation.h中样本数量与结果个数的宏定义
2.需要修改array_operation.c中的源数据地址*/
double *read_array_operation(double *result);

#endif
