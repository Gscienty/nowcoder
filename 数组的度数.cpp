#include <iostream>
#include <map>
#include <vector>
#include <limits>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    std::map<int, int> mapper;
    int maxi = -1;
    int maxc = std::numeric_limits<int>::min(); 
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
        mapper[arr[i]]++;
        if (maxc < mapper[arr[i]]) {
            maxc = mapper[arr[i]];
            maxi = arr[i];
        }
    }

    int left = 0;
    while (arr[left] != maxi) { left++; }
    int right = arr.size();
    while (arr[right - 1] != maxi) { right--; }

    std::cout << right - left << std::endl;
    return 0;
}