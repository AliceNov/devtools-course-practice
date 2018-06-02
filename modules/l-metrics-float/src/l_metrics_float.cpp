// Copyright 2018 Gribov Pavel

#include <cmath>
#include <algorithm>
#include <numeric>
#include <vector>

#include "include/l_metrics_float.h"

std::vector<float> LMetricsFloat::VecSubstractMod(std::vector<float> vec1,
                                                  std::vector<float> vec2) {
    size_t size = std::max(vec1.size(), vec2.size());
    std::vector<float> vec3(size);

    if (vec1.size() < size)
        vec1.resize(size);
    else if (vec2.size() < size)
        vec2.resize(size);

    for (size_t i = 0; i < size; ++i)
        vec3[i] = fabs(vec1[i] - vec2[i]);

    return vec3;
}

float LMetricsFloat::LinfVecDistance(const std::vector<float>& vec1,
                                     const std::vector<float>& vec2) {
    std::vector<float> vec3 = VecSubstractMod(vec1, vec2);
    return vec3.empty() ? 0.0f :
           *std::max_element(vec3.cbegin(), vec3.cend());
}

float LMetricsFloat::L1VecDistance(const std::vector<float>& vec1,
                                   const std::vector<float>& vec2) {
    std::vector<float> vec3 = VecSubstractMod(vec1, vec2);
    return std::accumulate(vec3.cbegin(), vec3.cend(), 0.0f);
}

float LMetricsFloat::L2VecDistance(const std::vector<float>& vec1,
                                   const std::vector<float>& vec2) {
    std::vector<float> vec3 = VecSubstractMod(vec1, vec2);
    return sqrtf(std::accumulate(vec3.cbegin(), vec3.cend(), 0.0f,
        [](const float& elem1, const float& elem2) {
            return elem1 + elem2 * elem2;
        }));
}

float LMetricsFloat::L3VecDistance(const std::vector<float>& vec1,
                                   const std::vector<float>& vec2) {
    std::vector<float> vec3 = VecSubstractMod(vec1, vec2);
    return powf(std::accumulate(vec3.cbegin(), vec3.cend(), 0.0f,
        [](const float& elem1, const float& elem2) {
            return elem1 + powf(elem2, 3.0f);
        }), 1.0f / 3.0f);
}

float LMetricsFloat::L4VecDistance(const std::vector<float>& vec1,
                                   const std::vector<float>& vec2) {
    std::vector<float> vec3 = VecSubstractMod(vec1, vec2);
    return powf(std::accumulate(vec3.cbegin(), vec3.cend(), 0.0f,
        [](const float& elem1, const float& elem2) {
            return elem1 + powf(elem2, 4.0f);
        }), 1.0f / 4.0f);
}
