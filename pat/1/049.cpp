#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<std::vector<int>>> res;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    res = decltype(res)(n);
    std::vector data(n, 0);
    for (int t = 0; t < n; ++t)
        std::cin >> data[t];

    if (n == 1) {
        int fd = data.front();
        std::cout << "#1\n";
        int begPos = 1;
        for (int i = 0; i < fd; ++i) {
            for (int j = 0; j < 10; ++j) {
                std::cout << begPos;
                if (j != 9)
                    std::cout << ' ';
                begPos += 2;
            }
            std::cout << '\n';
        }

        return 0;
    }

    int avTeam;
    int begPos = 1;
    while (true) {
        avTeam = 0;
        for (const auto &x: data)
            if (x)
                ++avTeam;

        if (!avTeam)
            break;
        if (avTeam == 1) {
            int index = 0;
            while (!data[index])
                ++index;

            int lastPos = res[index].back().back();
            if (begPos - lastPos == 1)
                ++begPos;

            for (int i = 0; i < data[index]; ++i) {
                std::vector tmp(10, 0);
                for (int j = 0; j < 10; ++j) {
                    tmp[j] = begPos;
                    begPos += 2;
                }
                res[index].emplace_back(std::move(tmp));
            }

            break;
        }

        int xPos = begPos;
        for (int i = 0; i < data.size(); ++i) {
            if (!data[i])
                continue;
            std::vector tmp(10, 0);
            for (int j = 0; j < 10; ++j)
                tmp[j] = xPos + avTeam * j;
            res[i].emplace_back(std::move(tmp));
            ++xPos;
            --data[i];
        }

        begPos += avTeam * 10;
    }

    for (int i = 0; i < res.size(); ++i) {
        std::cout << '#' << i + 1 << '\n';
        for (const auto &v: res[i]) {
            for (int j = 0; j < 10; ++j) {
                std::cout << v[j];
                if (j != 9)
                    std::cout << ' ';
            }
            std::cout << '\n';
        }
    }

    return 0;
}
