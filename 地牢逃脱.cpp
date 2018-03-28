#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct tuple {
    int dx;
    int dy;
};

void dfs(int m, int n, std::vector<std::string> &mapper, std::vector<std::vector<int> > &mark, std::vector<tuple> &step, int x, int y, int times) {
    mark[x][y] = times;
    std::for_each(step.begin(), step.end(), [&](const tuple& t) -> void {
        if (x + t.dx >= 0 && x + t.dx < m && y + t.dy >= 0 && y + t.dy < n && mapper[x + t.dx][y + t.dy] != 'X') {
            if (mark[x + t.dx][y + t.dy] == 0) {
                dfs(m, n, mapper, mark, step, x + t.dx, y + t.dy, times + 1);
            }
            else if (mark[x + t.dx][y + t.dy] > times + 1) {
                dfs(m, n, mapper, mark, step, x + t.dx, y + t.dy, times + 1);
            }
        }
    });
}

int main() {
    int m, n;
    std::cin >> m >> n;
    std::vector<std::vector<int> > mark(m, std::vector<int>(n, 0));
    std::vector<std::string> mapper(m);
    
    for (int i = 0; i < m; i++) { std::cin >> mapper[i]; }
    
    int x, y;
    std::cin >> x >> y;
    
    int k;
    std::cin >> k;
    std::vector<tuple> step(k);
    for (int i = 0; i < k; i++) {
        int dx, dy;
        std::cin >> dx >> dy;
        step[i] = { dx, dy };
    }
    
    dfs(m, n, mapper, mark, step, x, y, 1);
    
    int result = 0;
    std::for_each(mark.begin(), mark.end(), [&](const std::vector<int>& col) -> void {
        std::for_each(col.begin(), col.end(), [&](const int elem) -> void {
            result = std::max<int>(result, elem);
        });
    });
    
    std::cout << result - 1 << std::endl;
    return 0;
}