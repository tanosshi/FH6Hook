#pragma once

#include <algorithm>
#include <cctype>
#include <string>

namespace FH6String {

inline std::string BaseName(const std::string& path)
{
    size_t p = path.find_last_of("\\/");
    return (p == std::string::npos) ? path : path.substr(p + 1);
}

inline std::string ToLower(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
        return static_cast<char>(std::tolower(c));
    });
    return s;
}

} // namespace FH6String
