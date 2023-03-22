#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_set>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cout << std::fixed << std::setprecision(2);

    int n;
    std::cin >> n;
    std::vector<std::unordered_set<int>> data(1);
    int i;
    int r;
    for (int t = 1; t <= n; ++t) {
        std::unordered_set<int> us;
        std::cin >> r;
        for (int x = 0; x < r; ++x) {
            std::cin >> i;
            us.insert(i);
        }

        data.emplace_back(std::move(us));
    }

    std::cin >> n;
    int a, b;
    for (int t = 0; t < n; ++t) {
        std::cin >> a >> b;
        int setA = 0, setB = (int) data[a].size() + (int) data[b].size();
        for (const auto &x: data[a]) {
            auto iter = data[b].find(x);
            if (iter != data[b].end()) {
                ++setA;
                --setB;
            }
        }

        std::cout << 100.0 * setA / setB << "%\n";
    }

    return 0;
}
