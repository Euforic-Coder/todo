#ifndef STRINGS_H
#define STRINGS_H

namespace uforia {

// Capitalize a string
    std::string capitalized(std::string s) {
        std::string buffer;
        for (int i = 0; i < s.length(); ++i) {
            if (i == 0) {
                buffer.push_back(toupper(s[i]));
            } else {
                buffer.push_back(tolower(s[i]));
            }
        }
        return buffer;
    }
}

// Makes a string lowercase
std::string lowercase(std::string s) {
    std::string buffer;
    for (int i = 0; i < s.length(); ++i) {
        buffer.push_back(tolower(s[i]));
    }
    return buffer;
}

// Makes a string uppercase
std::string uppercase(std::string s) {
    std::string buffer;
    for (int i = 0; i < s.length(); ++i) {
        buffer.push_back(toupper(s[i]));
    }
    return buffer;
}

// Prints a string within a given number of spaces
std::string spacer(std::string s, int space) {
    std::string buffer;
    buffer = s;
    int total = space - s.length();
    for (int i = 0; i < total; ++i) {
        buffer.push_back(' ');
    }
    return buffer;
}

// Creates a vector<string> from a string with all possible combinations
std::vector <std::string> funnel(const std::string &s) {
    std::vector <std::string> buffer;
    int full = s.length();
    for (int i = 0; i < full; i++) {
        size_t sub = full - i;
        size_t play = full - sub;
        for (int pos = 0; pos <= play; pos++) {
            std::string sub_str = s.substr(pos, sub);
            buffer.push_back(sub_str);
        }
    }
    return buffer;
}

// Checks if a string has a number
bool has_number(std::string s) {
    std::string numbers = "1234567890";
    for (int i = 0; i < s.length(); ++i) {
        char character = s[i];
        for (int j = 0; j < numbers.length(); ++j) {
            char number = numbers[j];
            if (character == number) {
                return true;
            }
        }
    }
    return false;
}

// Checks if a string is numeric
bool is_numeric(const std::string &s) {
    return !s.empty() && s.find_first_not_of("-,.0123456789") == std::string::npos;
}

#endif // STRINGS_H
