#include <stdio.h>






int encode(int h, int m){
    h = h * 100 + m;


}
int read(){

    printf("hours: ");
    scanf("%02d");
    printf("minutes: ");
    scanf("%02d");
   return printf("%04d");

}
int hours(int t){

t = t/100;


}

int minutes(int t){

    t = t % 100;


}

void print(int t){


printf("%d", t);

}

int add(int t1, int t2){

    if (t1+t2 > 59)
        t1 + 100;

    if (t1+t2 > 2300)
        t1 - 2400;

}

int total_minutes(int t){
t = t /100 * 60;

}






/* D O N T   T O U C H   T H I S */
void Test_1() {
    int h, m;
    printf("h: ");
    scanf("%d", &h);
    printf("m: ");
    scanf("%d", &m);
    printf("encoded: %04d", encode(h, m));
}

void Test_2() {
    printf("read: %04d", read());
}

void Test_3() {
    int t;
    printf("hours: %02d\n", hours(t = read()));
    printf("minutes: %02d\n", minutes(t));
}

void Test_4() {
    print(read());
}

void Test_5() {
    int t1 = read();
    int t2 = read();
    printf("add: ");
    print(t1);
    printf(" + ");
    print(t2);
    printf(" = ");
    print(add(t1, t2));
}

void Test_6() {
    int t = read();
    printf("read: %d\n", total_minutes(t));
}

int main() {
    /* Input */
    int num;
    /* List of all available tests */
    void (*tests[])() = { Test_1, Test_2, Test_3, Test_4, Test_5, Test_6 };
    int num_of_tests = (int)(sizeof(tests) / sizeof(void (*)()));

    /* Read test number */
    printf("Test #: ");
    scanf("%d", &num);

    /* Check valid range */
    if (num >= 1 && num <= num_of_tests) {
        /* Call the selected test */
        printf("Executing Test_%d.\n", num);
        tests[num - 1]();
    } else {
        /* Print error */
        printf("Invalid test number!");
    }

    return 0;
}


