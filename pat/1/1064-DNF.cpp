// 写nm

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>

void solve() {
    std::string str;
    std::getline(std::cin, str);
    std::cout << str << '\n';

    std::stringstream ss(str);
    std::istream_iterator<std::string> isIter(ss), eof;
    std::vector<std::string> data(isIter, eof);

    std::for_each(data.begin(), data.end(), [](auto &x) {
        std::for_each(x.begin(), x.end(), [](auto &ch) {
            if (ch != 'I' && std::isupper(ch))
                ch = std::tolower(ch);
        });
    });


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
