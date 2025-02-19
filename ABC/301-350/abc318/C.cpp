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

int n, d;
ll p, f[int(2e5 + 5)];

priority_queue<ll> que;
ll now = 0, cnt = 0, ans = 0;

int main() {
  cin >> n >> d >> p;
  for (int i = 1; i <= n; i++) {
    cin >> f[i];
    que.push(f[i]);
  }

  while (!que.empty()) {
    ll q = que.top();
    que.pop();

    now += q;
    cnt++;

    if (cnt == d) {
      ans += min(now, p);
      now = 0;
      cnt = 0;
    }
  }
  ans += min(now, p);
  cout << ans << endl;

  return 0;
}
