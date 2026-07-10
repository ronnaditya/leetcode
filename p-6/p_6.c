#include<stdlib.h>
#include<string.h>
#include<stdio.h>

char* convert(char* s, int numRows) {
    // The entire algorithm must be a function of numRows, the Row Index, and the length of `s`.
    if (strlen(s) == 1 || numRows == 1) {
        return s;
    }
    int length = strlen(s);
    char* response = malloc(sizeof(char) * (length + 1));

    int currentIndex = 0;
    int principleOfIndexing = 2 * numRows - 2;
    for (int rowIndex = 0; rowIndex < numRows; ++rowIndex) {
        int s_index = rowIndex;
        if (rowIndex == 0 || rowIndex == numRows - 1) {
            while (s_index < length) {
                response[currentIndex] = s[s_index];
                currentIndex += 1;
                s_index += principleOfIndexing;
            }
        } else {
            int firstPartition = principleOfIndexing - rowIndex * 2;
            int secondPartition = rowIndex * 2;
            int switch_ = 1;
            while (s_index < length) {
                response[currentIndex] = s[s_index];
                printf("%c", response[currentIndex]);
                currentIndex += 1;
                if (switch_) {
                    s_index += firstPartition;
                    switch_ = 0;
                } else {
                    s_index += secondPartition;
                    switch_ = 1;
                }
            }
        }
    }
    response[currentIndex] = '\0';
    return response;
}
