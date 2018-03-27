#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int main() {
    std::vector<std::vector<int> > mapper(1001, std::vector<int>(1001, 0));
    int n;
    std::cin >> n;
    std::vector<int> xs(n);
    for (int i = 0; i < n; i++) { std::cin >> xs[i]; }
    for (int i = 0; i < n; i++) {
        int y;
        std::cin >> y;
        mapper[xs[i]][y] = -1;
    }

    int result = std::numeric_limits<int>::max();
    for (int x = 1; x <= 1000; x++) {
        for (int y = 1; y <= 1000; y++) {
            int sec = 0;
            if (x == 1 && y == 1) { sec = 0; }
            else if (x == 1) {
                sec = mapper[x][y - 1] == -1 ? (std::numeric_limits<int>::max() - 2000) : (mapper[x][y - 1] + 1);
            }
            else if (y == 1) {
                sec = mapper[x - 1][y] == -1 ? (std::numeric_limits<int>::max() - 2000) : (mapper[x - 1][y] + 1);
            }
            else if (mapper[x - 1][y] == -1 && mapper[x][y - 1] == -1) {
                sec = mapper[x][y] = std::numeric_limits<int>::max() - 2000;
            }
            else if (mapper[x - 1][y] == -1) {
                sec = mapper[x][y - 1] + 1;
            }
            else if (mapper[x][y - 1] == -1) {
                sec = mapper[x - y][y] + 1;
            }
            else {
                sec = std::min<int>(mapper[x][y - 1], mapper[x - 1][y]) + 1;
            }

            if (mapper[x][y] == -1) {
                result = std::min<int>(result, sec);
            }
            else {
                mapper[x][y] = sec;
            }
        }
    }

    std::cout << result << std::endl;

    return 0;
}