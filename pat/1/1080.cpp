#include <cstdio>
#include <cstdint>
#include <string>

int main() {
    std::string data(2, 0);
    uint64_t len;
    std::scanf("%c %c %llu", &data[0], &data[1], &len);

    uint64_t i1 = 0, i2 = 1;
    while (data.size() < len) {
        int i = (data[i1] - '0') * (data[i2] - '0');
        data += std::to_string(i);
        ++i1;
        ++i2;
    }

    for (auto t = 0; t < len; ++t) {
        std::putchar(data[t]);
        if (t != len - 1)
            std::putchar(' ');
    }

    return 0;
}
