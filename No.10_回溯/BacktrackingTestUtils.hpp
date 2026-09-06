#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

inline std::string boolToString(bool value) {
    return value ? "true" : "false";
}

inline std::string vectorToString(const std::vector<int>& nums) {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < nums.size(); ++i) {
        if (i) oss << ", ";
        oss << nums[i];
    }
    oss << "]";
    return oss.str();
}

inline std::string stringVectorToString(const std::vector<std::string>& strs) {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < strs.size(); ++i) {
        if (i) oss << ", ";
        oss << "\"" << strs[i] << "\"";
    }
    oss << "]";
    return oss.str();
}

inline std::string matrixToString(const std::vector<std::vector<int>>& matrix) {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < matrix.size(); ++i) {
        if (i) oss << ", ";
        oss << vectorToString(matrix[i]);
    }
    oss << "]";
    return oss.str();
}

inline std::string stringMatrixToString(const std::vector<std::vector<std::string>>& matrix) {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < matrix.size(); ++i) {
        if (i) oss << ", ";
        oss << stringVectorToString(matrix[i]);
    }
    oss << "]";
    return oss.str();
}

inline std::string charMatrixToString(const std::vector<std::vector<char>>& matrix) {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < matrix.size(); ++i) {
        if (i) oss << ", ";
        oss << "[";
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            if (j) oss << ", ";
            oss << "'" << matrix[i][j] << "'";
        }
        oss << "]";
    }
    oss << "]";
    return oss.str();
}
