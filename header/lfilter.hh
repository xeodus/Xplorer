#pragma once
#include <vector>

class LFilter {
public:
    LFilter(const std::vector<double>& b) : b_{b} {}
    std::vector<double> apply(const std::vector<double>& x) const;

private:
    std::vector<double> b_;
};

std::vector<double> LFilter::apply(const std::vector<double>& x) const {
    std::vector<double> y;
    y[0] = 0;

    for (int i = 0; i < x.size(); i++) {
        for (int k = 0; k < b_.size(); k++) {
            if ((i - k) > 0) {
                y[i] += b_[k] * x[i - k];
            }
        }
    }
    return y;
}