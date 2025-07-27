#include <stdio.h>
int count = 2;

void fibonacci(int a, int b) {
    if (count <= 19) {
        int newFibo = a + b;
        printf("%d\n", newFibo);
        b=a;
        a=newFibo;
        count += 1;
        fibonacci(a,b);
    } else {
        return;
    }
}

int main() {
    printf("0\n");
    printf("1\n");
    fibonacci(1, 0);
    return 0;
}
