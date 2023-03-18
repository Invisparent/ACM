#include <iostream>
#include <vector>
#include <algorithm>

int n;
int bound;
int k = 2;
int lim;
int x, y;

std::vector<std::vector<int>> data;

inline void fill() {
    if (x == 0 && y != bound) {
        x = bound;
        ++y;
        data[x][y] = k;
    } else if (y == bound && x) {
        y = 0;
        --x;
        data[x][y] = k;
    } else if (x == 0 && y == bound) {
        ++x;
        data[x][y] = k;
    } else {
        if (!data[x - 1][y + 1]) {
            --x;
            ++y;
            data[x][y] = k;
        } else {
            ++x;
            data[x][y] = k;
        }
    }

    ++k;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n;
    lim = n * n;
    bound = n - 1;
    data = decltype(data)(n, std::vector(n, 0));
    y = n / 2;
    data[x][y] = 1;

    while (k <= lim)
        fill();

    std::ranges::for_each(data, [](const auto &v) {
        std::ranges::for_each(v, [](const auto &x) {
            std::cout << x << ' ';
        });
        std::cout << '\n';
    });

    return 0;
}
