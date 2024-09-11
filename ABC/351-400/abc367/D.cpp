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
ll m;
ll a[int(4e5 + 5)], sum[int(4e5 + 5)], cnt[int(1e6 + 5)];

ll ans = 0;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i + n] = a[i];
  }
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i];
    cnt[sum[i] % m]++;
  }

  for (int i = n + 1; i <= n * 2; i++) {
    cnt[sum[i - n] % m]--;
    sum[i] = sum[i - 1] + a[i];
    ans += cnt[sum[i] % m];
    cnt[sum[i] % m]++;
  }
  cout << ans << endl;

  return 0;
}
