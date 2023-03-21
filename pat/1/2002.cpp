#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string pos;
    int n;
    std::cin >> pos >> n;

    std::unordered_map<std::string, std::pair<std::string, int>> data;
    std::string str;
    for (int t = 0; t < n; ++t) {
        std::pair<std::string, int> p;
        std::cin >> str >> p.second >> p.first;
        data[str] = std::move(p);
    }

    std::vector<std::pair<std::pair<std::string, std::string>, int>> elemUsed, elemDeleted;
    std::unordered_set<int> visited;
    while (true) {
        if (pos == "-1")
            break;

        auto iter = visited.find(std::abs(data[pos].second));
        if (iter != visited.end())
            elemDeleted.emplace_back(std::make_pair(pos, data[pos].first), data[pos].second);
        else {
            elemUsed.emplace_back(std::make_pair(pos, data[pos].first), data[pos].second);
            visited.emplace(std::abs(data[pos].second));
        }

        pos = data[pos].first;
    }

    if (!elemUsed.empty())
        for (int t = 0; t < elemUsed.size() - 1; ++t)
            elemUsed[t].first.second = elemUsed[t + 1].first.first;
    if (!elemDeleted.empty())
        for (int t = 0; t < elemDeleted.size() - 1; ++t)
            elemDeleted[t].first.second = elemDeleted[t + 1].first.first;

    if (!elemUsed.empty())
        elemUsed.back().first.second = "-1";
    if (!elemDeleted.empty())
        elemDeleted.back().first.second = "-1";

    for (const auto &x: elemUsed)
        std::cout << x.first.first << ' ' << x.second << ' ' << x.first.second << '\n';
    for (const auto &x: elemDeleted)
        std::cout << x.first.first << ' ' << x.second << ' ' << x.first.second << '\n';

    return 0;
}
