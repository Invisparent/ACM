// Brute force hah

//#include <iostream>
//#include <vector>
//#include <string>
//#include <unordered_map>
//#include <utility>
//#include <algorithm>
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    std::cout.tie(nullptr);
//
//    int tt;
//    std::cin >> tt;
//    std::unordered_map<std::string, std::pair<int, int>> data;
//    int i;
//    int max = INT_MIN;
//    std::string str;
//    for (int t = 0; t < tt; ++t) {
//        std::cin >> str >> i;
//        if (!i)
//            continue;
//        data[str].first += i;
//        if (data[str].first > max) {
//            max = data[str].first;
//            data[str].second = t;
//        } else if (data[str].first == max && i)
//            data[str].second = t;
//    }
//
//    std::vector<decltype(data)::mapped_type> res;
//    for (const auto &x: data) {
//        if (x.second.first == max)
//            res.push_back(x.second);
//    }
//    std::ranges::sort(res, [](const auto &a, const auto &b) {
//        return a.second < b.second;
//    })
//}

//#include <iostream>
//#include <vector>
//#include <string>
//#include <unordered_map>
//#include <unordered_set>
//#include <utility>
//#include <algorithm>
//#include <ranges>
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    std::cout.tie(nullptr);
//
//    int tt;
//    std::cin >> tt;
//    std::vector<std::pair<std::string, std::pair<int, int>>> o;
//    std::unordered_map<std::string, int> data;
//    int i;
//    for (int t = 0; t < tt; ++t) {
//        std::string str;
//        std::cin >> str >> i;
//        data[str] += i;
//        auto p = std::make_pair(data[str], t);
//        o.emplace_back(std::move(str), std::move(p));
//    }
//
////    std::ranges::sort(o, [](const auto &a, const auto &b) {
////        if (a.second.first != b.second.first)
////            return a.second.first > b.second.first;
////        return a.second.second < b.second.second;
////    });
//
//    // What the fuck?
////    std::cout << o.front().first;
//
//    // What the fuuuuuuck?????
////    int max = std::ranges::max(o, [](const auto &a, const auto &b) {
////        return a.second.first < b.second.first;
////    }).second.first;
//
//    // What the fuuuuuuuuuuuuuuuck????????
//    std::unordered_set<std::string> scanned;
//    int max = INT_MIN;
//    for (const auto &x: o | std::views::reverse) {
//        if (!scanned.contains(x.first)) {
//            max = std::max(x.second.first, max);
//            scanned.emplace(x.first);
//        }
//    }
//
//    scanned.clear();
//    std::string res;
//    for (const auto &x: o | std::views::reverse) {
//        if (!scanned.contains(x.first)) {
//            scanned.emplace(x.first);
//            if (x.second.first == max)
//                res = x.first;
//        }
//    }
//
//    std::cout << res;
//
//    return 0;
//}

#include <iostream>
#include <vector>
#include <string>
#include <ranges>
#include <unordered_map>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int tt;
    std::cin >> tt;
    std::vector<std::pair<std::pair<std::string, int>, int>> data(tt);
    for (int t = 0; t < tt; ++t) {
        std::cin >> data[t].first.first >> data[t].first.second;
        data[t].second = t;
    }

    std::unordered_map<std::string, int> final;
    for (const auto &x: data)
        final[x.first.first] += x.first.second;

    int max = std::ranges::max_element(final, [](const auto &a, const auto &b) {
        return a.second < b.second;
    })->second;

    std::vector<std::pair<std::string, int>> candidate;
    for (const auto &x: final)
        if (x.second == max)
            candidate.emplace_back(x.first, 0);

    for (auto &x: candidate) {
        int tracker = max;
        for (const auto &y: data | std::views::reverse)
            if (y.first.first == x.first) {
                if (tracker >= max) {
                    x.second = y.second;
                }
                tracker -= y.first.second;
            }
    }

    std::ranges::sort(candidate, [](const auto &a, const auto &b) {
        return a.second < b.second;
    });

    std::cout << candidate.front().first;

    return 0;
}
