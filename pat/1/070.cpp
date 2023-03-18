#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string str;
    int firstPos = 0;
    int cnt = 0;
    int t = 1;
    while (std::getline(std::cin, str) && str != ".") {
        auto pos = str.find("chi1 huo3 guo1");
        if (pos != std::string::npos) {
            if (firstPos == 0)
                firstPos = t;
            ++cnt;
        }

        ++t;
    }

    std::cout << t - 1 << '\n';

    if (cnt)
        std::cout << firstPos << ' ' << cnt;
    else
        std::cout << "-_-#";

    return 0;
}
