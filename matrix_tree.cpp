// 矩陣樹定理
// 求Spanning tree數量
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 35;
const double EPS = 1e-8;
double mat[MAX][MAX];
int deg[MAX];
void Gauss(int n) {
    for(int i = 0; i < n; ++i) {
        bool ok = 0;
        for(int j = i; j < n; ++j) {
            if(fabs(mat[j][i]) > EPS) {
                swap(mat[j], mat[i]);
                ok = 1;
                break;
            }
        }
        if(!ok) continue;
        double fs = mat[i][i];
        for(int j = i + 1; j < n; ++j) {
            double r = mat[j][i] / fs;
            for(int k = i; k < n; ++k)
                mat[j][k] -= mat[i][k] * r;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    long long n, m, a, b;
    while(cin >> n && n != 0) {
        memset(deg, 0, sizeof(deg));
        memset(mat, 0, sizeof(mat));
        cin >> m;
        for(int i = 0; i < m; ++i) {
            cin >> a >> b; // 0 ~ n - 1
            mat[a][b] = mat[b][a] = -1;
            deg[a]++;
            deg[b]++;
        }
        for(int i = 0; i < n; ++i) mat[i][i] = deg[i];
        Gauss(n - 1);
        double ans = 1;
        for(int i = 0; i < n - 1; ++i) ans *= mat[i][i];
        ans = floor(ans + 0.5);
        cout << (long long)ans << endl;
    }
    return 0;
}
