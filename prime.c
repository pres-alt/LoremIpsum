#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_Prime(int x){

    bool is_Prime = true;
    for (int i = 2; i <= x / 2 ; i++){
        if (x % i ==0){
            is_Prime = false;
        }
    }
    return is_Prime;
}

int main(){ 
    int x;
    scanf("%d", &x);

    if(is_Prime(x)){
        printf("The number is prime");
    }
    else{
        printf ("The number is not prime");
    }

    return 1;
}