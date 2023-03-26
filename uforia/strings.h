#ifndef STRINGS_H
#define STRINGS_H

std::string capitalized(std::string s){
    std::string buffer;
    for(int i = 0; i < s.length(); ++i){
        if(i == 0){
            buffer.push_back(toupper(s[i]));
        }else{
            buffer.push_back(tolower(s[i]));
        }
    }
    return buffer;
}

std::string lowercase(std::string s){
    std::string buffer;
    for(int i = 0; i < s.length(); ++i){
        buffer.push_back(tolower(s[i]));
    }
    return buffer;
}

std::string uppercase(std::string s){
    std::string buffer;
    for(int i = 0; i < s.length(); ++i){
        buffer.push_back(toupper(s[i]));
    }
    return buffer;
}

std::string spacer(std::string s, int space){
    std::string buffer;
    buffer = s;
    int total = space - s.length();
    for(int i = 0; i < total; ++i){
        buffer.push_back(' ');
    }
    return buffer;
}

bool has_number(std::string s){
    std::string numbers = "1234567890";
    for(int i = 0; i < s.length(); ++i){
        char character = s[i];
        for(int j = 0; j < numbers.length(); ++j){
            char number = numbers[j];
            if(character == number){
                return true;
            }
        }
    }
    return false;
}

#endif // STRINGS_H
