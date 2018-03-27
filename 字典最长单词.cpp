#include <stack>
#include <iostream>
#include <string>
#include <vector>


class alpha_tree {
public:
    alpha_tree* children[26] = { NULL };
    bool has_children;
    bool light;

    alpha_tree() : light(false), has_children(false) { }
};

bool dp(alpha_tree *root, std::stack<char>& s) {
    if (root->has_children == false) {
        return true;
    }

    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL && root->children[i]->light == true) {
            s.push(i + 97);
            if (dp(root->children[i], s)) {
                return true;
            }
            s.pop();
        }
    }
}

int main() {
    alpha_tree *root = new alpha_tree();
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) { 
        std::string word;
        std::cin >> word;

        alpha_tree *ptr = root;
        for (char c : word) {
            if (ptr->children[c - 97] == NULL) {
                ptr->children[c - 97] = new alpha_tree();
                ptr->has_children = true;
            }
            ptr = ptr->children[c - 97];
        }
        ptr->light = true;
    }

    std::stack<char> s;
    dp(root, s);
    
    std::stack<char> rs;
    while (s.empty() == false) {
        rs.push(s.top());
        s.pop();
    }

    while (rs.empty() == false) {
        std::cout << rs.top();
        rs.pop();
    }

    std::cout << std::endl;

    return 0;
}