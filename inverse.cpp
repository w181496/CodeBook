// O(logp) 求反元素
int inverse(int a, int p) {
  return pow(a, p - 2, p);
}
