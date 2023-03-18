#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector data(n, 0);
    for (int t = 0; t < n; ++t)
        std::cin >> data[t];

    std::sort(data.begin(), data.end());

    auto iterA = data.cbegin();
    auto iterB = data.crbegin();
    while (iterA != data.cend() && *iterA == data.front())
        ++iterA;
    while (iterB != data.crend() && *iterB == data.back())
        ++iterB;

    std::cout << data.front() << ' ' << iterA - data.cbegin() << '\n' << data.back() << ' ' << iterB - data.crbegin();

    return 0;
}
