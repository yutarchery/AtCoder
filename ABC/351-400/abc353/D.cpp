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
ll a[int(2e5 + 5)];

ll ans, digit;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (ll i = n; i >= 1; i--) {
    ans += a[i] * (i - 1) % MOD2;
    ans += a[i] * digit % MOD2;
    ans %= MOD2;

    ll num = 1;
    while (a[i] > 0) {
      num *= 10;
      num %= MOD2;
      a[i] /= 10;
    }
    digit += num;
    digit %= MOD2;
  }
  cout << ans << endl;

  return 0;
}
