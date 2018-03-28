#include <iostream>
#include <vector>
#include <algorithm>

int dfs(int surplus, int target, std::vector<bool> &member, std::vector<int> &zero_index, std::vector<int> &a) {
    if (surplus == 0) {
        int sum = 0;
        for (int i = 0; i < a.size(); i++) {
            for (int j = i + 1; j < a.size(); j++) {
                if (a[i] < a[j]) { sum++; }
            }
        }
        return sum == target ? 1 : 0;
    }
    else {
        int zero_ptr = *(zero_index.rbegin() + (surplus - 1));
        int sum = 0;
        for (int i = 1; i < member.size(); i++) {
            if (member[i] == false) {
                member[i] = true;
                a[zero_ptr] = i;
                sum += dfs(surplus - 1, target, member, zero_index, a);
                a[zero_ptr] = 0;
                member[i] = false;
            }
        }
        return sum;
    }
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    std::vector<bool> member(n + 1, false);
    std::vector<int> zero_index;
    
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i] == 0) { zero_index.push_back(i); }
        else { member[a[i]] = true; }
    }
    
    std::cout << dfs(zero_index.size(), k, member, zero_index, a) << std::endl;
    
    return 0;
}