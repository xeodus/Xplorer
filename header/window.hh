#pragma once
#include <vector>

class Window {
public:
    std::vector<double> Hamming(int N) const;
    std::vector<double> Hann(int N) const;
    std::vector<double> Blackmann(int N) const;
};

std::vector<double> Window::Hamming(int N) const {
    std::vector<double> w;
    w[0] = 0;

    for (int i = 0; i < N; i++) {
        if (N < 1)   {
            throw std::length_error("Hamming window's length can't be lesser than 1");
        }

        w[i] += 0.54 + 0.46 * cos((2 * M_PI * i) / (N - 1));
    }
    return w;
}

std::vector<double> Window::Hann(int N) const {
    std::vector<double> w;
    w[0] = 0;

    for (int i = 0; i < N; i++) {
        if (N < 1) {
            throw std::length_error("Hann window's length can't be lesser than 1");
        }

        w[i] += 0.5 * (1 - cos((2 * M_PI * i) / (N - 1)));
    }
    return w;
}

std::vector<double> Window::Blackmann(int N) const {
    std::vector<double> w;
    w[0] = 0;

    for (int i = 0; i < N; i++) {
        if (N < 1) {
            throw std::length_error("Blackmann window's length can't be lesser than 1");
        }

        w[i] += 0.42 - 0.5 * cos((2 * M_PI * i) / (N - 1)) + 0.08* cos((4 * M_PI * i) / (N - 1));
    }
    return w;
}