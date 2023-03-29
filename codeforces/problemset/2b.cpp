#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <optional>

#define i32inf 0x3f3f3f3f

typedef std::pair<int, int> Tp;
typedef std::vector<Tp> Tvp;

int i32in;

std::vector<Tvp> data;
std::vector<Tvp> dp;

std::pair<int, int> calc() {
    if (i32in == 0)
        return {i32inf, i32inf};

    // What are you dooooing???
//    std::pair<int, int> retVal{};
//    for (const auto &ch: i32in)
//        if (ch == '2')
//            ++retVal.first;
//        else if (ch == '4')
//            retVal.first += 2;
//        else if (ch == '8')
//            retVal.first += 3;
//        else if (ch == '5')
//            ++retVal.second;
//        else if (ch == '0') {
//            ++retVal.first;
//            ++retVal.second;
//        }
//
//    return retVal;

    Tp retVal{};
    while (!(i32in % 2)) {
        ++retVal.first;
        i32in /= 2;
    }
    while (!(i32in % 5)) {
        ++retVal.second;
        i32in /= 5;
    }

    // For line 91 judgement
    i32in = -1;

    return retVal;
}

void rec(int x, int y, bool is5) {
    if (x == 1 && y == 1)
        return;

    if (!is5) {
        if (dp[x - 1][y].first < dp[x][y - 1].first) {
            rec(x - 1, y, is5);
            std::cout << 'D';
        } else {
            rec(x, y - 1, is5);
            std::cout << 'R';
        }
    } else {
        if (dp[x - 1][y].second < dp[x][y - 1].second) {
            rec(x - 1, y, is5);
            std::cout << 'D';
        } else {
            rec(x, y - 1, is5);
            std::cout << 'R';
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::optional<std::pair<int, int>> zero;
    data = std::vector<Tvp>(n + 2, Tvp(n + 2));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            std::cin >> i32in;
            data[i][j] = calc();
            if (i32in == 0 && !zero.has_value())
                zero = std::make_pair(i, j);
        }

    dp = std::vector<Tvp>(n + 2, Tvp(n + 2));
    for (int t = 0; t <= n + 1; ++t) {
        dp[0][t].first = dp[0][t].second = i32inf;
        dp[t][0].first = dp[t][0].second = i32inf;
    }

    dp[1][1] = data[1][1];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            if (i == 1 && j == 1)
                continue;
            dp[i][j].first = std::min(dp[i - 1][j].first, dp[i][j - 1].first) + data[i][j].first;
            dp[i][j].second = std::min(dp[i - 1][j].second, dp[i][j - 1].second) + data[i][j].second;
        }

    int resVal = std::min(dp[n][n].first, dp[n][n].second);
    if (zero.has_value() && resVal > 0)
        std::cout << "1\n" << std::string(zero.value().first - 1, 'D') + std::string(n - 1, 'R') +
                              std::string(n - zero.value().first, 'D') << std::endl;
    else if (dp[n][n].first < dp[n][n].second) {
        std::cout << dp[n][n].first << '\n';
        rec(n, n, false);
    } else {
        std::cout << dp[n][n].second << '\n';
        rec(n, n, true);
    }

    return 0;
}
