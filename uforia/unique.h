#ifndef UNIQUE_H
#define UNIQUE_H

#include <vector>

namespace uforia{

	// Makes a vector<string> unique
  std::vector<std::string> unique(std::vector<std::string> vec){
    std::vector<std::string> buffer;
    for(int i = 0; i < vec.size(); ++i){
        bool in_buffer = false;
        const std::string& line = vec[i];
        
	// If the buffer is empty the first string will be pushed
	if(i == 0){
            buffer.push_back(line);
          }
        
	for(int j = 0; j < buffer.size(); ++j){
            const std::string& buffered = buffer[j];
            
		// If the string is allready present in_buffer while be flagged 
	    if(line == buffered){
                in_buffer = true;
                break;
              }
          }

	// If the is not present the string will be added
        if(!in_buffer){
            buffer.push_back(line);
          }
      }
    return buffer;
  }
}

#endif // UNIQUE_H
