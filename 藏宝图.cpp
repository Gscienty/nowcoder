#include <iostream>
#include <string>
#include <map>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;
    std::string t;
    std::cin >> t;
    for (int i = 0, si = 0; i < t.length(); i++, si++) {
        while (si < s.length() && s[si] != t[i]) { si++; }
        if (si >= s.length()) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    std::cout << "Yes" << std::endl;
    return 0;
}