#include<stdio.h>

int main(){
    printf("The size of different data types are: ");
   printf("int: %zu bytes\n", sizeof(int));
    printf("float: %zu bytes\n", sizeof(float));
    printf("double: %zu bytes\n", sizeof(double));
    printf("char: %zu byte\n", sizeof(char));
    printf("long: %zu bytes\n", sizeof(long));
    printf("short: %zu bytes\n", sizeof(short));
    return 0;
}
