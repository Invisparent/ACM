#include <iostream>
#include <vector>
#include <string>

// Max length
int ml;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::vector<std::string> vs;
    while (true) {
        std::string s;
        if (!std::getline(std::cin, s))
            break;
        if (ml < s.size())
            ml = static_cast<int>(s.size());
        vs.emplace_back(std::move(s));
    }

    std::cout << std::string(ml + 2, '*') << std::endl;
    bool reverse = false;
    for (const auto &s: vs) {
        int l = ml - static_cast<int>(s.size());
        if (!l)
            std::cout << '*' + s + '*' << std::endl;
        else if (l % 2) {
            std::cout << '*' + std::string(l / 2 + reverse, ' ') + s + std::string(l / 2 + 1 - reverse, ' ') + '*'
                      << std::endl;
            reverse = !reverse;
        } else
            std::cout << '*' + std::string(l / 2, ' ') + s + std::string(l / 2, ' ') + '*' << std::endl;
    }

    std::cout << std::string(ml + 2, '*') << std::endl;

    return 0;
}
