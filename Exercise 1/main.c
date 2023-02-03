#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) {
    return a+b;
}
void print_string(char* str) {
     while (*str != 0) {
        printf("%c",*str);
        str++;
    }
    printf("\n");
}
char* reverse(char* str) {
    char* new_str = malloc(sizeof(str));
    while (*str != 0) { //point to end of string
        str++;
    }
    do {
        *new_str = *str;
        new_str++;
        str--;
    } while (*str != 0);
    *new_str = 0;
    do {
        new_str--;
    } while (*new_str != 0);
    new_str++;
    return new_str;
}

void operatorTest(int a) {
    int x = a, y = a;
    x--;
    (y--);
    printf("x = y = %d\n",a);
    printf("x-- = %d\n",x);
    printf("(y--) = %d\n",y);
    printf("2*x+y = %d\n",2*x+y);
    printf("2*(x+y) = %d\n",2*(x+y));
}

int main(void) {
    printf("Hello\n");

    char *str = "Hello";
    str = reverse(str);
    print_string(str);

    printf("Size of int: %d\n",sizeof(int));
    printf("Size of long: %d\n",sizeof(long));
    printf("Size of float: %d\n",sizeof(float));
    printf("Size of double: %d\n",sizeof(double));
    printf("Size of char: %d\n",sizeof(char));

    operatorTest(5);

    int x = 'a'; //Char's are just small integers [0;255],
                 //where number is assigned a charecter
    
    int a = 3;
    double b = 10.0;
    int sum = a + b;
    printf("%d\n",sum); // = 13. yes

    // 9. bitwise operations
    /*
    the >> operator performs a right shift, effectively dividing the number by 2^16. 
    The & operator performs a bitwise AND with the value 0xFFFF, which is a binary number with 16 ones, 
    and this removes the least significant 16 bits, preserving only those bits in the result.
    */
    //a
    int num = 42; //a normal integer in c has 32 bits
    short top = num >> 16; // extract the top 16 bits. right shifting
    short bottom = num & 0xFFFF; // extract the bottom 16 bits. & bitwise and
    //b
    int original = (top << 16) | bottom; // combine the two shorts. << leftshifting. | bitwise or

    if (num == original) {
        printf("Succes1\n"); 
    }
    //c
    char ctop = num >> 8; //char is only 8 bit 
    char cbottom = num & 0xFF;

    int coriginal = (ctop << 8) | cbottom;
    /*
    The largest value that two chars can be combined to is 65535. 
    This is because each char is an 8-bit unsigned integer, 
    and two chars together form a 16-bit unsigned integer.*/
    if (num == coriginal) {
        printf("Succes2\n"); 
    }

    return 0;
}