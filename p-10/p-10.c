#include<stdio.h>

bool isValid(char* s) {
  // What's new:
  // - Unlike python, cannot simply iterate over object when the size of array is not available
  char* open_arr[] = {"(", "[", "{"};
  char* closed_arr[] = {")", "]", "}"};
  
  char* curr_arr[] = {};
  int curr_count = 0;
  int index;
  int i = 0;
  while (s[i] != 0) {
    for (int j = 0; j < 3; ++j) {
      if (s[i] == open_arr[j]) {
        index = j;
        curr_arr[curr_count] = s[i];
        curr_count += 1;
      } else {
      }
    }
  }
}

int main() {
  isValid("asfddsf");
  return 0;
}
