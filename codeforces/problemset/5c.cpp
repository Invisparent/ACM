#include <iostream>
#include <vector>
#include <string>
#include <stack>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string s;
    std::getline(std::cin, s);
    const int n = static_cast<int>(s.size());
    std::vector vb(n, false);
    std::stack<int> st;
    for (int t = 0; t < n; ++t)
        if (s[t] == '(')
            st.push(t);
        else if (!st.empty()) {
            vb[st.top()] = true;
            vb[t] = true;
            st.pop();
        }

    int mx = 0;
    int cnt = 1;
    int prev = 0;
    for (const auto &x: vb)
        if (x) {
            ++prev;
        } else {
            if (prev > mx) {
                mx = prev;
                cnt = 1;
            } else if (prev == mx && prev)
                ++cnt;
            prev = 0;
        }
    if (prev > mx) {
        mx = prev;
        cnt = 1;
    } else if (prev == mx && prev)
        ++cnt;

    std::cout << mx << ' ' << cnt << std::endl;

    return 0;
}
