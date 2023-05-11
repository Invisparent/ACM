#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string s;
    int p = 0;
    int res = 0;
    while (std::getline(std::cin, s)) {
        if (s.front() == '+')
            ++p;
        else if (s.front() == '-')
            --p;
        else {
            auto pos = s.find(':');
            res += p * (s.size() - pos - 1);
        }
    }

    std::cout << res << std::endl;

    return 0;
}
