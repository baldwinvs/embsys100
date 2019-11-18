#include<stdio.h>

void function_1(int value1);
void function_3(int value1, int value2, int value3);
void function_5(int value1, int value2, int value3, int value4, int value5);
void function_7(int value1, int value2, int value3, int value4, int value5, int value6, int value7);

int main()
{
    int a = 0;

    function_1(a);

    return 0;
}

void function_1(int value1)
{
    value1 = 5;
    int b = 10;
    int c = 15;
    function_3(value1, b, c);
}

void function_3(int value1, int value2, int value3)
{
    value1 = 10;
    value2 = 15;
    value3 = 20;
    int d = 25;
    int e = 30;
    function_5(value1, value2, value3, d, e);
}

void function_5(int value1, int value2, int value3, int value4, int value5)
{
    value1 = 5;
    value2 = 10;
    value3 = 15;
    value4 = 20;
    value5 = 25;
    int f = 30;
    int g = 35;
    function_7(value1, value2, value3, value4, value5, f, g);
}

void function_7(int value1, int value2, int value3, int value4, int value5, int value6, int value7)
{
    value1 = 0;
    value2 = 5;
    value3 = 10;
    value4 = 15;
    value5 = 20;
    value6 = 25;
    value7 = 30;
}