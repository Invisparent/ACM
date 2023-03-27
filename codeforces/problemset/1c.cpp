#include <iostream>
#include <iomanip>
#include <array>
#include <cmath>
#include <utility>
#include <algorithm>

#define IVS_EPS ((double)1e-4)

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::pair<double, double> p1, p2, p3;
    std::cin >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >> p3.second;
//    double k1 = (p2.second - p1.second) / (p2.first - p1.first);
//    double k2 = (p3.second - p2.second) / (p3.first - p2.first);
//    k1 = -1 / k1;
//    k2 = -1 / k2;
//    std::pair<double, double> m1((p1.first + p2.first) / 2, (p1.second + p2.second) / 2);
//    std::pair<double, double> m2((p2.first + p3.first) / 2, (p2.second + p3.second) / 2);
//    double b1 = m1.second - k1 * m1.first, b2 = m2.second - k2 * m2.first;
//    std::pair<double, double> o((b2 - b1) / (k1 - k2), .0);
//    o.second = o.first * k1 + b1;
    std::array<double, 3> len{
            std::sqrt(
                    (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second)),
            std::sqrt(
                    (p2.first - p3.first) * (p2.first - p3.first) + (p2.second - p3.second) * (p2.second - p3.second)),
            std::sqrt(
                    (p3.first - p1.first) * (p3.first - p1.first) + (p3.second - p1.second) * (p3.second - p1.second))
    };
    std::ranges::sort(len);
    double cosA = (len[1] * len[1] + len[2] * len[2] - len[0] * len[0]) / (2 * len[1] * len[2]);
//    double cosB = (len[0] * len[0] + len[2] * len[2] - len[1] * len[1]) / (2 * len[0] * len[2]);
    double radius = len[0] / std::sin(std::acos(cosA)) / 2;
    double angA = std::acos((radius * radius + radius * radius - len[0] * len[0]) / (2 * radius * radius));
    double angB = std::acos((radius * radius + radius * radius - len[1] * len[1]) / (2 * radius * radius));
//    int edge = 4;
    int edge = 3;
    double ang;
    while (true) {
        ang = 2 * std::numbers::pi / edge;
        if (std::fmod(angA + (IVS_EPS / 2), ang) < IVS_EPS && std::fmod(angB + (IVS_EPS / 2), ang) < IVS_EPS)
            break;
        else
            ++edge;
    }

    std::cout << std::fixed << std::setprecision(6);
    std::cout << 0.5 * radius * radius * std::sin(ang) * edge;

    return 0;
}
