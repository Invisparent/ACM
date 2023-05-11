#include <iostream>
#include <vector>
#include <ranges>
#include <utility>
#include <algorithm>

struct env_t {
    int w;
    int h;
    int no;
    bool valid;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, w, h;
    std::cin >> n >> w >> h;
    std::vector<env_t> dat(n);
    bool gvalid = false;
    for (int t = 0; t < n; ++t) {
        std::cin >> dat[t].w >> dat[t].h;
        dat[t].no = t + 1;
        if (dat[t].w <= w || dat[t].h <= h)
            dat[t].valid = false;
        else {
            gvalid = true;
            dat[t].valid = true;
        }
    }

    if (n == 1) {
        int i, j;
        std::cin >> i >> j;
        if (i <= w || j <= h)
            std::cout << 0 << std::endl;
        else
            std::cout << 1 << std::endl;

        return 0;
    }

    if (!gvalid) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::ranges::sort(dat, [](const auto &a, const auto &b) {
        if (a.w != b.w)
            return a.w < b.w;
        else
            return a.h < b.h;
    });

    // val, pi
    std::vector dp(n, std::make_pair(0, -1));
    // init
    if (dat.front().valid)
        dp.front().first = 1;

    for (int i = 1; i < n; ++i) {
        if (dat[i].valid)
            dp[i].first = 1;
        else
            continue;
        for (int j = 0; j < i; ++j)
            if (dat[j].valid && dat[j].w < dat[i].w && dat[j].h < dat[i].h && dp[j].first >= dp[i].first) {
                dp[i].first = dp[j].first + 1;
                dp[i].second = j;
            }
    }

    auto iter = std::ranges::max_element(dp, [](const auto &a, const auto &b) {
        return a.first < b.first;
    });
    std::cout << iter->first << std::endl;
    std::vector<int> o;
    int pos = static_cast<int>(iter - dp.begin());
    while (pos != -1) {
        o.push_back(pos);
        pos = dp[pos].second;
    }

    for (const auto &x: o | std::views::reverse) {
        std::cout << dat[x].no << ' ';
    }
    std::cout << std::endl;

    return 0;
}
