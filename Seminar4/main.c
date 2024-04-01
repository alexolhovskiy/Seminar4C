#include <stdio.h>            
#include <locale.h>
#include <math.h>

#include <stdlib.h>



int getNumCount(int num) {
    int count = 0;
    while (num > 0) {
        num /= 10;
        count++;
    }
    return count;
}

int quadSum(int* arr) {
    int i, sum = 0;
    for (i = arr[0]; i <=arr[1]; i++) {
        sum += i * i;
    }
    return sum;
}

int isThree(int*arr) {
    int count = 0;
    while (arr[0] > 0) {
        arr[0]/=10;
        count++;
    }
    return count;
}

int isEven(int*arr) {
    while (arr[0]> 0) {
        if (arr[0] % 10 % 2 != 0) {
            return 1;
        }
        arr[0] /= 10;
    }
    return 0;
}

int revert(int* arr) {
    int i,num=0,count = getNumCount(arr[0]);
    for (i = count-1; i>=0; i--) {
        num += arr[0] % 10 * pow(10,i);
        arr[0] /= 10;
    }
    return num;
}

int numSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum+=num % 10;
        num /= 10;
    }
    return sum;
}

int numMult(int num) {
    int mult = 1;
    while (num > 0) {
        mult*= num % 10;
        num /= 10;
    }
    return mult;
}

int* sumMult(int* arr,int*count) {
    int i,n=0;
    for (i = 10; i < arr[0]; i++) {
        if (numSum(i) == numMult(i)) {
            (*count)++;
        }
    }
    int* newArr = (int*)malloc(*count);
    for (i = 10; i < arr[0]; i++) {
        if (numSum(i) == numMult(i)) {
            newArr[n]=i;
            n++;
        }
    }
    return newArr;
}

int main(void)
{
    setlocale(LC_ALL, "Rus");

    //1
    printf("Task #1\n");
    int arr[10];
    printf("Enter 2 numbers a>=b\n");
    scanf_s("%d %d",&arr[0],&arr[1]);
    printf("%d\n", quadSum(arr));
    printf("\n\n");

    //2
    printf("Task #2\n");
    printf("Enter number\n");
    scanf_s("%d", &arr[0]);
    isThree(arr)==3?printf("YES\n"):printf("NO\n");
    printf("\n\n");

    //3
    printf("Task #3\n");
    printf("Enter number\n");
    scanf_s("%d", &arr[0]);
    isEven(arr) == 0 ? printf("YES\n") : printf("NO\n");
    printf("\n\n");


    //4
    printf("Task #4\n");
    printf("Enter number\n");
    scanf_s("%d", &arr[0]);
    printf("%d\n", revert(arr));
    printf("\n\n");

    //5
    printf("Task #5\n");
    printf("Enter number a>10\n");
    scanf_s("%d", &arr[0]);
    int i,size = 0;
    int* newArr = sumMult(arr, &size);
    for (i = 0; i < size; i++) {
        printf("%d ", newArr[i]);
    }
    printf("\n\n");
    


    return 0;
}
