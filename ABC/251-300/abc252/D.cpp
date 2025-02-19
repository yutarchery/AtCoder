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

int n, a[int(2e5 + 5)], idx;

ll l[int(2e5 + 5)], r[int(2e5 + 5)], ans = 0;
Pll p[int(2e5 + 5)];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);

  int cnt = 1;
  for (int i = 2; i <= n + 1; i++) {
    if (a[i] == a[i - 1]) {
      cnt++;
    } else {
      idx++;
      p[idx] = {a[i - 1], cnt};
      cnt = 1;
    }
  }

  for (int i = 1; i <= idx; i++) {
    l[i] = l[i - 1] + p[i - 1].second;
  }
  for (int i = idx; i >= 1; i--) {
    r[i] = r[i + 1] + p[i + 1].second;
  }

  for (int i = 1; i <= idx; i++) {
    ans += l[i] * r[i] * p[i].second;
  }
  cout << ans << endl;

  return 0;
}
