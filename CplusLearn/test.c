#include<stdio.h>
#include<string.h>

void test() {

    char sentence[20];

    printf("Enter a sentence: \n");

    scanf("%s", sentence);
    // gets(sentence);

    printf("sentence is : %s", sentence);
}


int main() {

    printf("main ...");
    test();
    return 0;
}