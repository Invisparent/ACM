#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::pair<int, std::string>> data(n);
    int sigma = 0;
    for (int t = 0; t < n; ++t) {
        std::cin >> data[t].second >> data[t].first;
        sigma += data[t].first;
    }

    std::sort(data.begin(), data.end());

    int avg = sigma / n / 2;
    if (data.front().first > avg) {
        std::cout << avg << ' ' << data.front().second;
        return 0;
    }

    auto iter = data.cbegin();
    while (iter + 1 != data.end())
        if (iter->first <= avg && (iter + 1)->first >= avg)
            break;
        else
            ++iter;

    std::cout << avg << ' ';

    if (std::abs(avg - iter->first) < std::abs(avg - (iter + 1)->first))
        std::cout << iter->second;
    else
        std::cout << (++iter)->second;

    return 0;
}
