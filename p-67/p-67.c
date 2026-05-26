char* addBinary(char* a, char* b) {
  int lena;
  int lenb;

  int i = 0;
  while (a[i] != 0) {
      ++i;
  }
  lena = i;

  int j = 0;
  while (b[j] != 0) {
      ++j;
  }
  lenb = j;
 
  char* binaries[] = {a, b};
  char* response = malloc(sizeof(char) * 100000);

  int indexSwitch;
  int difference;
  if (lena > lenb) {indexSwitch = 1; difference = lena - lenb;}
  else {indexSwitch = 0; int difference = lenb - lena;}

  int carry = 0;
  for (int i = binaries[indexSwitch] - 1; i >= 0; --i) {
    if (a[i] == "0" && b[i] 
  }
}
  }
void main() {
  char* a = "11001";
  char* b = "100";
  char* answer = addBinary(a, b);
}
