#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

inline std::string vectorToString(const std::vector<int>& values) {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < values.size(); ++i) {
        if (i > 0) {
            oss << ", ";
        }
        oss << values[i];
    }
    oss << "]";
    return oss.str();
}

inline std::string matrixToString(const std::vector<std::vector<int>>& matrix) {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < matrix.size(); ++i) {
        if (i > 0) {
            oss << ", ";
        }
        oss << vectorToString(matrix[i]);
    }
    oss << "]";
    return oss.str();
}

