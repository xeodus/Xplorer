#pragma once
#include <vector>

class FirWin {
public:
    std::vector<double> firwin(int N, double cutoff, const std::vector<double>& window);
    double sinc(double x);
};

double FirWin::sinc(double x) {
    if (x == 0.0) {
        return 1.0;
    }
    else {
        return sin(M_PI * x) / (M_PI * x);
    }
}

std::vector<double> FirWin::firwin(int N, double cutoff, const std::vector<double>& window) {
    std::vector<double> b;
    std::vector<double> h;
    h[0] = 0;
    auto center = (N - 1) / 2.0;

    for (int i = 0; i < N; i++) {
        auto offset = i - center;
        double arg = 2 * cutoff * offset;

        if (cutoff > 0.0 && cutoff < 0.5) {
            h[i] += 2 * cutoff * sinc(arg);

            if (arg == 0) {
                h[i] += 2 * cutoff* 1.0;
            }
            else {
                h[i] += 2 * cutoff * (sin(M_PI * arg) / (M_PI * arg));
            }

            b[i] += h[i] * window[i];
        }
    }
    return b;
}