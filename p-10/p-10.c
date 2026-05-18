#include<stdio.h>

bool isValid(char* s) {
  char* open_arr[] = {"(", "{", "["};
  char* closed_arr[] = {")", "}", "]"};

  char* curr_arr[] = {};
  int curr_count = 0;
  
  int i = 0;
  while (s[i] != 0) {
    for (int j = 0; j < 3; ++j) {
      if (s[i] == *open_arr[j]) {
        *curr_arr[curr_count] = s[i];
        ++curr_count;
      } else if (s[i] == *closed_arr[j]) {
          if (curr_arr[curr_count] == open_arr[j]) {
            --curr_count;
            continue;
          } else {
            return false;
        }
      }
    }
    ++i;
  }
  return true;
}

int main() {

  char* string = "()";
  printf("%d", isValid(string));


  return 0;
}
