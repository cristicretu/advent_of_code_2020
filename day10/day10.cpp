/**
 *    author: etohirse
 *    created: 18.12.2020 09:44:47
 **/
#include <algorithm>
#include <deque>
#include <fstream>
#include <unordered_map>
#include <vector>

typedef long long ll;

std::ifstream fin("input.in");
std::ofstream fout("input.out");

std::deque<ll> av;
std::unordered_map<ll, ll> mp;
ll on, tri;

ll solve2(ll a) {
  if (a >= av.size() - 1) return 1;
  if (mp.find(a) != mp.end()) return mp[a];
  ll ans(0);
  for (ll i = a + 1; i < std::min(a + 4, ll(av.size())); ++i)
    if (av[i] - av[a] < 4) ans += solve2(i);
  mp[a] = ans;
  return ans;
}

int main() {
  ll a;
  while (fin >> a) {
    av.push_back(a);
  }
  std::sort(av.begin(), av.end());
  av.push_front(0);
  av.push_back(av.back() + 3);
  for (ll i = 0; i < av.size() - 1; ++i)
    if (av[i + 1] - av[i] == 1)
      ++on;
    else if (av[i + 1] - av[i] == 3)
      ++tri;
  fout << (on * tri) << '\n';
  fout << solve2(0);
  return 0;
}
