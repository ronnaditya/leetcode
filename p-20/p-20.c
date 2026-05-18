#include<stdio.h>
// Not including the following line broke the program. Current was printing "{", even though that character was not
// there in the input.
// Never mind this wasn't the problem. The problem was incorrect indexing.
#include<string.h>

bool isValid(char* s) {
  char open_arr[3] = {'(', '{', '['};
  char closed_arr[3] = {')', '}', ']'};

  char current[strlen(s)] = {};

  if (strlen(s) == 1) {
    return false;
  }
  
  int curr_count = 0;
  int i = 0;
  while (s[i] != 0) {
    for (int j = 0; j < 3; ++j) {
      if (s[i] == open_arr[j]) {
        current[curr_count] = s[i];
        ++curr_count;
        continue;
      } else if (s[i] == closed_arr[j]) {
        if (curr_count == 0) {
            return false;
        }
        if (open_arr[j] == current[curr_count - 1]) {
          --curr_count;
          continue;
        } else {
          return false;
        }
      }
    }
    ++i;
  }

  if (curr_count) {
    return false;
  } else {
    return true;
  }
}

void main() {
  printf("%d", isValid("){"));
}
