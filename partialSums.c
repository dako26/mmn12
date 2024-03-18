#include <stdio.h>
#include <stdlib.h>

#define MAX_INT_SIZE 1000

int *partialSums(int length, int array[]);

int main() {
    int array[MAX_INT_SIZE], length, i;
    int *result;
    printf("Hello!\n");
    printf("please enter a length of the array you want me to check \n");
    scanf("%d", &length);
    printf("The length of the array you want me to check is %d \n",length);
    for (i = 0; i < length; i++) {
        printf("enter value number %d :", i);
        scanf("%d", &array[i]);
        printf("you enter The number %d  \n", array[i]);
    }
    printf("\n");
    result = partialSums(length, array);
    for (i = 0; i < length; i++) {
        printf("%d ", result[i]);
    }
    free(result);
    return 0;
}

int *partialSums(int length, int array[]) {
    int *result = (int *) malloc(length * sizeof(int));
    if (result == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    int index, new_number = 0;
    result[0] = array[0];
    for (index = 1; index < length; index++) {
        result[index] = result[index - 1] + array[index];
    }
    return result;
}