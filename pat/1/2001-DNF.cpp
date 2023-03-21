#include <iostream>
#include <vector>
#include <queue>

int n, m, s, d;

std::vector<int> pwr;

// std::vector<std::vector<std::pair<dest, len>>>
std::vector<std::vector<std::pair<int, int>>> data;

std::vector<bool> visited;

struct bfsData {
    template<typename T>
    bfsData(int pNode, int pLen, int pNum, T &&pPath):node(pNode), len(pLen), num(pNum), path(std::forward<T>(pPath)) {}

    int node;
    int len;
    int num;
    std::vector<int> path;
};

struct Comp {
    inline bool operator()(const bfsData &a, const bfsData &b) const {
        return a.len < b.len;
    }
};

std::priority_queue<bfsData, std::vector<bfsData>, Comp> bfsQueue;

void bfs() {
    while (!bfsQueue.empty()) {

    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n >> m >> s >> d;
    pwr = decltype(pwr)(n);
    data = decltype(data)(n);
    visited = decltype(visited)(n);
    for (int t = 0; t < n; ++t)
        std::cin >> pwr[t];
    int i1, i2, i3;
    for (int t = 0; t < m; ++t) {
        std::cin >> i1 >> i2 >> i3;
        data[i1].emplace_back(i2, i3);
        data[i2].emplace_back(i1, i3);
    }

    bfsQueue.emplace(s, 0, 0, std::vector<int>{s});
    bfs();
}
