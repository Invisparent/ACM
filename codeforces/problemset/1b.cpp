#include <iostream>
#include <string>

inline int alpha2digit(std::string::const_iterator iterA, std::string::const_iterator iterB) {
    int retVal = 0;
    while (iterA != iterB) {
        retVal = 26 * retVal + *iterA - 'A' + 1;
        ++iterA;
    }

    return retVal;
}

inline std::string digit2alpha(int i) {
    std::string retVal;
    int r = 1;
    while (r < i) {
        retVal.push_back('A');
        i -= r;
        r *= 26;
    }

    r /= 26;
    int index = 0;
    while (r) {
        retVal[index] += i / r;
        i %= r;
        if (r == 1)
            r = 0;
        else
            r /= 26;

        ++index;
    }

    return retVal;
}

void solve() {
    std::string str;
    std::cin >> str;

    auto iter = str.cbegin();
    while (iter != str.cend() && std::isalpha(*iter))
        ++iter;
    while (iter != str.cend() && std::isdigit(*iter))
        ++iter;
    if (iter == str.cend()) {
        iter = str.cbegin();
        while (iter != str.cend() && std::isalpha(*iter))
            ++iter;
        std::cout << 'R' + std::string(iter, str.cend()) + 'C' << alpha2digit(str.cbegin(), iter);
    } else {
        iter = str.cbegin() + 1;
        while (std::isdigit(*iter))
            ++iter;
        std::cout << digit2alpha(std::stoi(std::string(iter + 1, str.cend()))) << std::string(str.cbegin() + 1, iter);
    }

    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int tt;
    std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}

//#include <iostream>
//#include <string>
//
//// false: RXCX to RC
//// true: RC to RXCX
//inline bool judge(const std::string &str) {
//    auto iter = str.cbegin();
//    while (iter != str.cend() && std::isalpha(*iter))
//        ++iter;
//    while (iter != str.cend() && std::isdigit(*iter))
//        ++iter;
//
//    if (iter == str.cend())
//        return true;
//    else
//        return false;
//}
//
//std::string i2s(int i) {
//    std::string retVal;
//    int r = 1;
//    while (r * 26 < i)
//        r *= 26;
//
//    while (i){
//
//    }
//}
//
//void solve() {
//    std::string str;
//    std::cin >> str;
//
//    if (judge(str)) {
//
//    }
//}
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    std::cout.tie(nullptr);
//
//    int tt;
//    std::cin >> tt;
//    while (tt--)
//        solve();
//
//    return 0;
//}
