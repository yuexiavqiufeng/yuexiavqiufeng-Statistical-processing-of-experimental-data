#include <stdio.h>
#include "array_operation.h"

// ����������
int main()
{

    double result[result_size]; //�����Ž���ĺ���

    printf("������ݵ�ַ:%x\n", read_array_operation(result)); //���ô˼��㺯��

    //��������
    int i = 0;
    printf("ͳ�������Ϊ:\n");
    for (i = 0; i < result_size; i++)
    {
        printf("%f\n", result[i]);
    }

    getchar();
    return 0;
}