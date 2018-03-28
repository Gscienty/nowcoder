#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> mou;
    std::vector<int> moou;
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        std::cin >> tmp;
        sum += tmp;
        if (tmp % 2 == 0) {
            moou.push_back(tmp);
        }
        else {
            mou.push_back(tmp);
        }
    }
    
    if (sum % n != 0) { std::cout << -1 << std::endl; }
    else {
        int y = sum / n;
        if ((y % 2 == 0 && mou.empty() == false) || (y % 2 != 0 && moou.empty() == false)) { std::cout << -1 << std::endl; }
        else {
            int result = 0;
            std::for_each(y % 2 == 0 ? moou.begin() : mou.begin(), y % 2 == 0 ? moou.end() : mou.end(), [&](const int elem) -> void {
                if (elem > y) { result += (elem - y) / 2; }
            });
            
            std::cout << result << std::endl;
        }
    }
    
    return 0;
}