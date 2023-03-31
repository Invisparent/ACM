#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, tt;
    std::cin >> n >> tt;
    std::vector data = std::vector(n, std::make_pair(0, 0));
    int lb = 0, ub = 0;
    for (int t = 0; t < n; ++t) {
        std::cin >> data[t].first >> data[t].second;
        lb += data[t].first;
        ub += data[t].second;
    }

    if (lb == tt) {
        std::cout << "YES\n";
        std::ranges::for_each(data, [](const auto &p) {
            std::cout << p.first << ' ';
        });
    } else if (lb > tt || ub < tt)
        std::cout << "NO\n";
    else {
        std::cout << "YES\n";
        auto iter = data.cbegin();
        while (iter != data.cend() && tt - iter->first <= ub - iter->second) {
            std::cout << iter->first << ' ';
            tt -= iter->first;
            ub -= iter->second;
            ++iter;
        }
        std::cout << iter->second - (ub - tt) << ' ';
        ++iter;
        while (iter != data.cend()) {
            std::cout << iter->second << ' ';
            ++iter;
        }
    }

    return 0;
}
