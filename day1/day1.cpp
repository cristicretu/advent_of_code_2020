/**
 *    author: etohirse
 *    created: 14.12.2020 20:45:36
 **/
#include <fstream>
#include <unordered_set>
#include <vector>

std::ifstream fin("input.in");
std::ofstream fout("input.out");

void solve1(int a[], int len, int &on, int &de) {
  std::unordered_set<int> s;
  for (int i = 0; i < len; ++i) {
    int tg = 2020 - a[i];
    if (s.find(tg) != s.end()) {
      on = tg, de = a[i];
      break;
    }
    s.insert(a[i]);
  }
}

void solve2(int a[], int len, int &on, int &de, int &tri) {
  for (int i = 0; i < len - 2; i++) {
    std::unordered_set<int> s;
    int curr_sum = 2020 - a[i];
    for (int j = i + 1; j < len; j++) {
      if (s.find(curr_sum - a[j]) != s.end()) {
        on = a[i], de = a[j], tri = curr_sum - a[j];
        break;
      }
      s.insert(a[j]);
    }
  }
}
const int mxn = 1e6 + 5;
int a[mxn], on, de, tri;

int main() {
  int in, len(0);
  while (fin >> in) {
    a[len] = in;
    len++;
  }
  solve1(a, len, on, de);
  fout << on * de << '\n';
  solve2(a, len, on, de, tri);
  fout << on * de * tri << '\n';
}
