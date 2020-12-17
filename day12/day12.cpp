/**
 *    author: etohirse
 *    created: 17.12.2020 19:59:49
 **/
#include <fstream>

std::ifstream fin("input.in");
std::ofstream fout("input.out");

int main() {
  long long dirx(1), diry(0), x(0), y(0);
  char letter;
  long long num;

  long long sx = 0, sy = 0, wx = 10, wy = 1;

  while (fin >> letter >> num) {
    switch (letter) {
      case 'F':
        x += num * dirx;
        y += num * diry;

        sx += num * wx;
        sy += num * wy;
        break;
      case 'N':
        y -= num;
        wy += num;
        break;
      case 'E':
        x += num;
        wx += num;
        break;
      case 'W':
        x -= num;
        wx -= num;
        break;
      case 'S':
        y += num;
        wy -= num;
        break;
      case 'L':
        for (int i = 0; i < num; i += 90) {
          int diry2 = -dirx;
          int dirx2 = diry;
          dirx = dirx2;
          diry = diry2;
        }

        while (num > 0) {  // part 2
          std::swap(wx, wy);
          wx = -wx;
          num -= 90;
        }
        break;
      case 'R':
        for (int i = 0; i < num; i += 90) {
          int diry2 = dirx;
          int dirx2 = -diry;
          dirx = dirx2;
          diry = diry2;

          while (num > 0) {  // part 2
            std::swap(wx, wy);
            wy = -wy;
            num -= 90;
          }
        }
    }
  }
  fout << abs(x) + abs(y) << '\n';  // part 1
  fout << abs(sx) + abs(sy);        // part 2
  return 0;
}
