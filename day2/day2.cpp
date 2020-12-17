/**
 *    author: etohirse
 *    created: 15.12.2020 11:44:14
 **/
#include <fstream>

std::ifstream fin("input.in");
std::ofstream fout("input.out");

bool solve1(int a, int b, std::string lett, std::string passwd) {
  int count(0);
  for (unsigned i = 0; i < passwd.size(); ++i) {
    if (passwd[i] == lett[0]) count++;
    if (count > b) return false;
  }
  if (count < a) return false;
  return true;
}

bool solve2(int a, int b, std::string lett, std::string passwd) {
  return ((passwd[a - 1] == lett[0]) ^ (passwd[b - 1] == lett[0]));
}
int main() {
  int ans1(0), ans2(0);
  std::string numb, lett, passwd;
  while (fin >> numb >> lett >> passwd) {
    int i(0), a(0), b(0);
    while (isdigit(numb[i])) {
      a = a * 10 + numb[i] - '0';
      i++;
    }
    i++;
    while (isdigit(numb[i])) {
      b = b * 10 + numb[i] - '0';
      i++;
    }
    if (solve1(a, b, lett, passwd)) ans1++;
    if (solve2(a, b, lett, passwd)) ans2++;
  }
  fout << ans1;
  fout << '\n';
  fout << ans2;
  return 0;
}