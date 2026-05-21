int removeDuplicates(int* nums, int numsSize) {
  int occurred[] = {};
  int k = 0;
  int i = 0;
  while (i < numsSize) {
    int current = nums[i];
    bool _occurred = false;
    int j = 0;
    //while (j < k) {
    //  if (current == occurred[j]) {
    //    _occurred = true;
    //    break;
    //  }
    //  ++j;
    //}
    if (!_occurred) { // Stack smashing: problematic accessing of a memory location
      occurred[k] = current;
      ++k;
    }
    ++i;
  }
}

void main() {
  // Make a set out of the passed list, albeit maintaining the length of the list itself,
  // and return the number of elements in the set.
  // int nums[] = {0,0,0,1,1,2,3,3,3,3,4,5};
  int nums[] = {0,0,0,1,1};
  removeDuplicates(nums, 5);
}
