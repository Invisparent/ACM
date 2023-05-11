#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::unordered_map<std::string, int> dat;
    std::string s;
    for (int t = 0; t < n; ++t) {
        std::cin >> s;
        ++dat[s];
        if (dat[s] == 1)
            std::cout << "OK" << std::endl;
        else
            std::cout << s << dat[s] - 1 << std::endl;
    }

    return 0;
}
