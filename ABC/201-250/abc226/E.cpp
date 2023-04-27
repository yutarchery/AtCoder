#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector<vector<ll>> Mat;
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int n, m;
vector<int> graph[int(2e5 + 5)];
int group[int(2e5 + 5)];

int node_count[int(2e5 + 5)], edge_count[int(2e5 + 5)];

int parent(int node) {
  if (node == group[node]) {
    return node;
  } else {
    int tmp = group[node];
    return group[node] = parent(tmp);
  }
}

void unite(int u, int v) {
  int pu = parent(u), pv = parent(v);
  group[max(pu, pv)] = min(pu, pv);
  return;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    group[i] = i;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
    unite(u, v);
  }

  if (n != m) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    int p = parent(i);
    node_count[p]++;
    edge_count[p] += int(graph[i].size());
  }

  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (node_count[i] == 0) {
      continue;
    }

    if (node_count[i] * 2 == edge_count[i]) {
      cnt++;
    } else {
      cout << 0 << endl;
      return 0;
    }
  }

  ll ans = 1;
  for (int i = 0; i < cnt; i++) {
    ans *= 2;
    ans %= MOD2;
  }
  cout << ans << endl;

  return 0;
}