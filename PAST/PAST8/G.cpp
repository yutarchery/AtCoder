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

int n;
ll k, a[int(1e5 + 5)], b[int(1e5 + 5)], c[int(1e5 + 5)];

ll count_element(ll num) {
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (num < b[i]) {
      continue;
    }

    ll cnt = (num - b[i]) / c[i] + 1;
    cnt = min(cnt, a[i]);
    ans += cnt;
  }
  return ans;
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }

  ll l = 0, r = 1e18;
  while (r - l > 1) {
    ll mid = (l + r) / 2;
    if (count_element(mid) < k) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << r << endl;

  return 0;
}