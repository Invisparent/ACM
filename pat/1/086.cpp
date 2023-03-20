#include <iostream>
#include <string>

std::string f(const std::string &str) {
    std::string retVal;
    for (int t = 1; t < str.size(); ++t)
        if (str[t] % 2 == str[t - 1] % 2)
            retVal.push_back(std::max(str[t], str[t - 1]));

    return retVal;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string a, b;
    std::cin >> a >> b;
    a = f(a);
    b = f(b);
    if (a == b)
        std::cout << a;
    else
        std::cout << a << '\n' << b;

    return 0;
}
