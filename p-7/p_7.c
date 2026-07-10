#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int reverse(int x){
    if (x <= -1 * pow(2, 31)) {
        return 0;
    }
    
    int negative = 0;
    if (x < 0) {
        negative = 1;
        x *= -1;
    }

    int length = 0;
    int counter = x;
    while (counter > 0) {
        length += 1;
        counter /= 10;
    }

    int* answerToTheGods = malloc(sizeof(int) * length);
    int constructor = x;
    for (int i = 0; i < length; ++i) {
        answerToTheGods[i] = constructor % 10;
        constructor /= 10;
    }

    // How to handle the size of the integer exceeding its limit? How to even detect it?
    int answerToThePeople = 0;
    for (int i = 0; i < length; ++i) {
        answerToThePeople += pow(10, length - 1 - i) * answerToTheGods[i];
    }

    if (answerToThePeople < 0) {
        return 0;
    }

    if (negative) {return -1 * answerToThePeople;}
    else {return answerToThePeople;}
}
