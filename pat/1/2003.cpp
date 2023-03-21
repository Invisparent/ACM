#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, d;
    std::cin >> n >> d;

    // 什么阴间题
    if (n == 1 && d == 1) {
        double fucku, fuck;
        std::cin >> fucku >> fuck;
        std::cout << std::fixed << std::setprecision(2) << fuck / fucku;
        return 0;
    }

    std::vector<std::pair<int, int>> data(n);
    for (int t = 0; t < n; ++t)
        std::cin >> data[t].second;
    for (int t = 0; t < n; ++t)
        std::cin >> data[t].first;

    std::sort(data.begin(), data.end(), [](const auto &a, const auto &b) {
        return (double) a.first / a.second > (double) b.first / b.second;
    });

    double res = .0;
    for (const auto &x: data) {
        if (x.second <= d) {
            d -= x.second;
            res += x.first;
        } else {
            res += x.first * ((double) d / x.second);
            break;
        }
    }

    std::cout << std::fixed << std::setprecision(2) << res;

    return 0;
}
