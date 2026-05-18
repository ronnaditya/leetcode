#include<stdio.h>
// Not including the following line broke the program. Current was printing "{", even though that character was not
// there in the input.
#include<string.h>

bool isValid(char* s) {
  char open_arr[3] = {'(', '{', '['};
  char closed_arr[3] = {')', '}', ']'};

  char current[strlen(s)] = {};
  char curr_count = 0;
  
  int i = 0;
  while (s[i] != 0) {
    for (int j = 0; j < 3; ++j) {
      if (s[i] == open_arr[j]) {
        current[curr_count] = s[i];
        ++curr_count;
        continue;
      } else if (s[i] == closed_arr[j]) {
        if (open_arr[j] == current[curr_count - 1]) {
          --curr_count;
          continue;
        } else {
          printf("I'm here");
          return false;
        }
      }
    }
    ++i;
  }
  
  // This does not work here because of the way data structures work in C.
  if (current) {
    return false;
  } else {
    return true;
  }
}

void main() {
  printf("%d", isValid("[({{}})]"));
}
