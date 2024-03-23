// example.c
#include <stdio.h>
#include <unistd.h>

int test(int a) {
    printf("print: %d\n", a);
    printf("print: %d\n", a);
    return -a;
}

int main(){
    while(1) {
        for (int i = 1; i <= 5; i++) {
            test(i);
        }
        sleep(1);
    }
}