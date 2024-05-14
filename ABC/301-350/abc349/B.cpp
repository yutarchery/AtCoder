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

string s;
int cnt[26];
map<int, int> mp;

int main() {
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    cnt[s[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    if (cnt[i] == 0) {
      continue;
    }

    mp[cnt[i]]++;
  }
  for (int i = 0; i < 26; i++) {
    if (cnt[i] == 0) {
      continue;
    }

    if (mp[cnt[i]] != 2) {
      No();
      return 0;
    }
  }
  Yes();

  return 0;
}
