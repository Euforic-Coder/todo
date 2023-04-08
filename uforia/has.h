#ifndef HAS_H
#define HAS_H

namespace uforia {

    // Checks if a string is part another string
    bool has(std::string s, const std::string &other) {
        if (s.length() <= other.length()) {
            for (unsigned int i = 0; i <= (other.length() - s.length()); ++i) {
                const std::string &substr = other.substr(i, s.length());
                if (substr == s) {
                    return true;
                }
            }
        } else if (s == other) {
            return true;
        }
        return false;
    }

    // Checks is a char is part of a string
    bool has(char c, const std::string &s) {
        for (unsigned int i = 0; i < s.length(); ++i) {
            const char &character = s[i];
            if (character == c) {
                return true;
            }
        }
        return false;
    }

    // Checks if a string is in a vector
    bool has(std::string s, const std::vector <std::string> &vec) {
        for (unsigned int i = 0; i < vec.size(); ++i) {
            const std::string &line = vec[i];
            if (s == line) {
                return true;
            }
        }
        return false;
    }
}
#endif // HAS_H
