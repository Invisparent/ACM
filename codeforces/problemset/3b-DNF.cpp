#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using Tp = std::pair<int, int>;
using Tvp = std::vector<Tp>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, v;
    std::cin >> n >> v;
    Tvp one, two;
    int a, b;
    int cnt = 0;
    for (int t = 0; t < n; ++t) {
        std::cin >> a >> b;
        ++cnt;
        if (a == 1)
            one.emplace_back(b, cnt);
        else
            two.emplace_back(b, cnt);
    }

    auto Comp=[](const Tp&a,const Tp&b){
        return a.first>b.first;
    };
    std::ranges::sort(one,Comp);
    std::ranges::sort(two,Comp);
}
