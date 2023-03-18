//
// Created by Invisparent on 1/22/2023.
//

#ifndef FASTIO_HPP
#define FASTIO_HPP

#include <iostream>

template<typename T>
inline void fread(T &dat) {
    int sgn = 1;
    T retVal = 0;
    char ch = std::getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            sgn = -1;
        ch = std::getchar();
    }
    while (ch >= '0' && ch <= '9') {
        /**
         *  WARNING:
         *  DO NOT USE (ch ^ 48) INSTEAD
         *  It can't pass my test
         */
        retVal = (retVal << 1) + (retVal << 3) + (ch - 48);
        ch = std::getchar();
    }
    dat = sgn * retVal;
}

template<typename T>
inline void fprint(T dat) {
    if (dat < 0) {
        std::putchar('-');
        dat = -dat;
    }
    if (dat > 9)
        fprint(dat / 10);
    std::putchar(dat % 10 + '0');
}


#endif // FASTIO_HPP
