int nx[N][26], spt, ans;
int newnode() {
	for(int i = 0; i < 26; i++)
		nx[spt][i] = 0;
	return spt++;
}
void add(char*s, int p){
	int flag = 1;
	for(int i = 0; s[i]; i++){
		int a = s[i] - 'a';
		ans += flag;
		if(nx[p][a] == 0) {
			nx[p][a] = newnode();
			flag = 0;
		}
		p = nx[p][a];
	}
}
char s[N];
int n;
void sol(int num){
	scanf("%d", &n);
	spt = 1;
	ans = 0;
	int root = newnode();
	for(int i = 0; i < n; i++){
		scanf("%s", s);
		add(s, root);
	}
	printf("Case #%d: %d\n", num, ans);
}
