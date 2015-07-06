void build_fail(string B, int *fail) {
  int len = B.length(), current;
  current = fail[0] = -1;
  for(int i = 1; i < len; ++i) {
    while(current != -1 && B[current + 1] != B[i])
      current = fail[current];
    if(B[current + 1] == B[i]) current++;
    fail[i] = current;
  }
}
void match(string A, string B, int *fail) {
  int lenA = A.length(), lenB = B.length();
  int current = -1;
  for(int i = 0; i < lenA; ++i) {
    while(current != -1 && B[current + 1] != B[i])
      current = fail[current];
    if(B[current + 1] == A[i]) current++;
    if(current == lenB - 1) current = fail[current];
  }
}
