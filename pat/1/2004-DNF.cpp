#include <iostream>
#include <vector>

int n;
int index;
std::vector<int> data;

bool reverse;
std::vector<int> bst;

int pRangeL, pRangeR;
std::vector<int> output;

inline int left(int i) {
    return 2 * i;
}

inline int right(int i) {
    return 2 * i + 1;
}

inline int parent(int i) {
    return i / 2;
}

void build(int pos) {
    bst[pos] = data[index];
    ++index;

    if (left(pos) <= n)
        build(left(pos));
    if (right(pos) <= n)
        build(right(pos));
}

bool check(int pos) {
    if (!reverse) {
        if (left(pos) <= n)
            if (bst[left(pos)] >= bst[pos])
                return false;
        if (right(pos) <= n)
            if (bst[right(pos)] < bst[pos])
                return false;
    } else {
        if (left(pos) <= n)
            if (bst[left(pos)] < bst[pos])
                return false;
        if (right(pos) <= n)
            if (bst[right(pos)] >= bst[pos])
                return false;
    }

    if (left(pos) <= n)
        if (!check(left(pos)))
            return false;
    if (right(pos) <= n)
        if (!check(right(pos)))
            return false;

    return true;
}

void pot(int pos) {
    if (pos > n)
        return;

    pot(left(pos));
    pot(right(pos));
    output.push_back(bst[pos]);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n;
    if (n == 1) {
        std::cin >> n;
        std::cout << "YES\n" << n;
        return 0;
    }
    data.resize(n + 1);
    bst.resize(n + 1);
    for (int t = 1; t <= n; ++t)
        std::cin >> data[t];

    index = 1;
    build(1);

    if (bst[2] < bst[1])
        reverse = false;
    else
        reverse = true;

    bool res = check(1);
    if (res){
        int i=1;
        while (i<n)
            i*=2;

    }
    if (!res)
        std::cout << "NO";
    else {
        std::cout << "YES\n";
        pot(1);
        for (int t = 0; t < output.size(); ++t) {
            std::cout << output[t];
            if (t != output.size() - 1)
                std::cout << ' ';
        }
    }

    return 0;
}
