#include <stdio.h>

void change(int* x){
    *x *= 30;
}

int main(){
    int a = 30;
    printf("Before change: %d\n", a);
    change(&a);
    printf("After change: %d\n", a);
    
    return 0;
}