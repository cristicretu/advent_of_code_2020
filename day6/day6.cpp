
/**
 *    author: etohirse
 *    created: 16.12.2020 13:47:57
 **/
#include <fstream>
#include <unordered_set>
#include <vector>

std::ifstream fin("input.in");
std::ofstream fout("input.out");

int solve1(std::string s) {
  std::unordered_set<char> as;
  for (char d : s) as.insert(d);
  return as.size() - 1;
}

int solve2(std::string s, int cnt) {
  int fv[200] = {0};
  for (char d : s) fv[int(d)] += 1;

  int ans(0), cc(0);
  for (char d : s) {
    if (d != '/') {
      if (fv[int(d)] == cnt) ans++;
    } else {
      cc++;
      if (cc == 2) return ans;
    }
  }
}

int main() {
  std::string s, curr = "";
  int ans(0), ans1(0), count(0);
  while (getline(fin, s)) {
    if (s.size() != 0) {
      curr = curr + '/' + s;
      count++;
    } else {
      ans += solve1(curr);
      curr += '/';
      ans1 += solve2(curr, count);
      count = 0;
      curr = "";
    }
  }
  if (curr != "") {
    ans += solve1(curr);
    ans1 += solve2(curr, count);
  }
  fout << ans1;
  return 0;
}
