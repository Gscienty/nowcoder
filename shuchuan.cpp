#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n ;
    cin >> n;
    vector<string> strs;
    while(n--) {
        int num;
        cin >> num;
        strs.push_back(to_string(num));                                        
    }

    sort(strs.begin(), strs.end(), [] (const string &a, const string &b) -> bool {
        int a_len = a.length();
        int b_len = b.length();
        int max_len = max(a_len, b_len);

        for (int i = 0; i < max_len; i++) {
            if (a[i % a_len] < b[i % b_len]) {
                 return true;
            }
            if (a[i % a_len] > b[i % b_len]) {
                return false;
            }
        }
        if (a_len != b_len) {
            return *a.rbegin() < *b.rbegin();
        }
        return false;
    });

    for_each(strs.rbegin(), strs.rend(), [] (const string &str) -> void {
        cout << str;
    });
    cout << endl;
                        
    return 0;
}
