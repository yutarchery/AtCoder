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

ll n, ans;
int a[int(2e5 + 5)];
vector<ll> v[int(2e5 + 5)];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    v[a[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    v[i].push_back(0);
    v[i].push_back(n + 1);
    sort(v[i].begin(), v[i].end());
  }

  for (int i = 1; i <= n; i++) {
    ll rest = n * (n + 1) / 2;
    for (int j = 0; j < v[i].size() - 1; j++) {
      ll now = v[i][j + 1] - v[i][j];
      rest -= now * (now - 1) / 2;
    }
    ans += rest;
  }
  cout << ans << endl;

  return 0;
}
