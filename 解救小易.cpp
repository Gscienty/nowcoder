#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> xs(n);
    std::vector<int> ys(n);
    for (int i = 0; i < n; i++) { std::cin >> xs[i]; }
    int result = std::numeric_limits<int>::max();

    for (int i = 0; i < n; i++) {
        int y;
        std::cin >> y;

        result = std::min<int>(result, xs[i] + y);
    }


    std::cout << result - 2 << std::endl;

    return 0;
}