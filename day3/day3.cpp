/**
 *    author: etohirse
 *    created: 15.12.2020 12:12:37
 **/
#include <fstream>
#include <queue>

std::ifstream fin("input.in");
std::ofstream fout("input.out");

std::string a[323];

bool ok(int i, int j) {
  return a[i][j] == '.' ||
         a[i][j] == '#' and i >= 0 and j >= 0 and i <= 323 and j <= 31;
}

int solve(int slopeX, int slopeY) {
  std::queue<std::pair<int, int> > cords;
  int ans(0);
  cords.push({0, 0});
  while (!cords.empty()) {
    int i = cords.front().first, j = cords.front().second;
    cords.pop();
    if (a[i][j] == '#') ans++;
    int ni = i + slopeX, nj = j + slopeY;
    if (ok(ni, nj)) {
      cords.push({ni, nj});
    } else {
      cords.push({ni, nj % 31});
    }
    if (ni > 324) break;
  }
  return ans;
}

int main() {
  for (int i = 0; i < 324; ++i) fin >> a[i];
  int p1 = solve(1, 3);
  return 0;
}
