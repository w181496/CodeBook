int bit[MAX_N + 1], n;
void init(){
    memset(bit, 0, sizeof(bit));
}
int sum(int i){
    int ret = 0;
    while(i > 0){
        ret += bit[i];
        i -= (i & -i);
    }
    return ret;
}
void add(int i, int x){
    while(i <= n){
        bit[i] += x;
        i += (i & -i);
    }
}
