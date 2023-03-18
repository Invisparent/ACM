#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>

inline bool judge(const std::string &str) {
    if (str.size() < 4)
        return false;
    return str.substr(str.size() - 4, 3) == "ong";
}

void solve() {
    std::string str;
    std::getline(std::cin, str);
    std::stringstream ss(str);
    std::istream_iterator<std::string> isIter(ss), eof;
    std::vector<std::string> data(isIter, eof);

    auto iter = data.cbegin();
    while (true)
        if (iter->back() == ',')
            break;
        else
            ++iter;

    if (!judge(*iter) || !judge(data.back())) {
        std::cout << "Skipped\n";
        return;
    }

    for (auto t = 0; t < data.size() - 3; ++t)
        std::cout << data[t] << ' ';
    std::cout << "qiao ben zhong.\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string str;
    std::getline(std::cin, str);
    int tt = std::stoi(str);
    while (tt--)
        solve();

    return 0;
}
