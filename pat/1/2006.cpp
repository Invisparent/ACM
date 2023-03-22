#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

std::vector<int> mot, pot;

// What the fuuuuuuck??????????

//struct Comp {
//    inline bool operator()(const std::pair<int, int> &a, const std::pair<int, int> &b) const {
//        return a.second < b.second;
//    }
//};
//
//std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Comp> output;

std::vector<std::pair<int, int>> output;

typedef std::vector<int>::const_iterator vci;

int layer;

void build(vci moa, vci mob, vci poa, vci pob) {
    if (moa >= mob)
        return;

    auto pRoot = pob - 1;
    auto mRoot = std::find(moa, mob, *pRoot);

    output.emplace_back(*pRoot, layer);

    ++layer;

    build(moa, mRoot, poa, poa + (mRoot - moa));
    build(mRoot + 1, mob, poa + (mRoot - moa), pRoot);

    --layer;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    mot.resize(n);
    pot.resize(n);
    for (int t = 0; t < n; ++t)
        std::cin >> pot[t];
    for (int t = 0; t < n; ++t)
        std::cin >> mot[t];

    build(mot.cbegin(), mot.cend(), pot.cbegin(), pot.cend());

    std::stable_sort(output.begin(), output.end(), [](const auto &a, const auto &b) {
        return a.second < b.second;
    });

    for (int t = 0; t < output.size(); ++t) {
        std::cout << output[t].first;
        if (t != output.size() - 1)
            std::cout << ' ';
    }

    return 0;
}
