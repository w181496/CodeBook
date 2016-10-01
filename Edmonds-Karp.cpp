#include <queue>
#include <cstring>
using namespace std;

void EK() {
  queue<int> q;
  memset(flow, 0, sizeof(flow));
  f = 0;
  for(;;) {
    memset(a, 0, sizeof(a));
    a[s] = INF;
    q.push(s);
    while(!q.empty()) {
      int u = q.front(); q.pop();
      for(int v = 1; v <= n; v++) if(!a[v] && cap[u][v] > flow[u][v]) {
        p[v] = u; q.push(v);
        a[v] = min(a[u], cap[u][v] - flow[u][v]);
      }
    }
    if(a[t] == 0) break;
    for(int u = t; u != s; u = p[u]) {
      flow[p[u]][u] += a[t];  //更新正向流量
      flow[u][p[u]] -= a[t];  //更新反向流量
    }
    f += a[t];  //更新總流量
  }
}

