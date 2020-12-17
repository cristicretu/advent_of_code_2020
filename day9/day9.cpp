/**
 *    author: etohirse
 *    created: 17.12.2020 13:12:18
 **/
#include <climits>
#include <fstream>
#include <unordered_set>
#include <vector>

typedef long long ll;

std::ifstream fin("input.in");
std::ofstream fout("input.out");

std::vector<ll> av;

bool verify(std::vector<ll> av, ll a) {
  std::unordered_set<ll> as;
  for (int i = av.size() - 25; i < av.size(); ++i) {
    int tg = a - av[i];
    if (as.find(tg) != as.end()) {
      return true;
    }
    as.insert(av[i]);
  }
  return false;
}

void solve2(std::vector<ll> av, ll a) {
  int curr = av[0], start = 0, finish;
  for (int i = 1; i <= av.size(); i++) {
    while (curr > a && start < i - 1) {
      curr = curr - av[start];
      start++;
    }
    if (curr == a) {
      finish = i - 1;
      break;
    }
    if (i < av.size()) curr = curr + av[i];
  }

  ll mn(LLONG_MAX), mx(LLONG_MIN);
  for (int i = start; i <= finish; ++i) {
    mn = std::min(mn, av[i]), mx = std::max(mx, av[i]);
  }

  fout << mn + mx;
}

int main() {
  ll a;
  int count(0);
  while (fin >> a) {
    if (av.size() < 25)
      av.push_back(a);
    else {
      if (verify(av, a))
        av.push_back(a);
      else {
        fout << a << '\n';  /// part 1
        solve2(av, a);      /// part 2
        break;
      }
    }
  }
  return 0;
}
