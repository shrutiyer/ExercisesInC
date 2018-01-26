#include <stdio.h>

void print_c(int c) {
  int b = (c%2 == 0);
  switch (b) {
    case 0:
        printf("c is odd\n");
        break;
    case 1:
        printf("c is even\n");
        break;
    }
}

int main() {
    printf("Hello, World!\n");
    int a = 3;
    int b = 4;
    int c = a + b;
    printf("c is %d\n", c);
    print_c(c);
    return 0;
}
