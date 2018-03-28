#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> s(n);
    
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    int k, d;
    std::cin >> k >> d;
    
    std::vector<std::vector<long long> > dp(n, std::vector<long long>(k, 0));
    std::vector<std::vector<long long> > fdp(n, std::vector<long long>(k, 0));
    
    for (int i = 0; i < n; i++) { dp[i][0] = fdp[i][0] = s[i]; }
    
    for (int t = 1; t < k; t++) {
        for (int i = t; i < n; i++) {
            for (int j = std::max<int>(0, i - d); j < i; j++) {
                dp[i][t] = std::max<long long>(dp[i][t], std::max<long long>(dp[j][t - 1] * s[i], fdp[j][t - 1] * s[i]));
                fdp[i][t] = std::min<long long>(fdp[i][t], std::min<long long>(dp[j][t - 1] * s[i], fdp[j][t - 1] * s[i]));
            }
        }
    }
    
    long long result = *dp[0].rbegin();
    
    for (int i = 1; i < n; i++) {
        result = std::max<long long>(result, *dp[i].rbegin());
    }
    
    std::cout << result << std::endl;
    
    return 0;
}