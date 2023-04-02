#ifndef COUNT_H
#define COUNT_H

#include <vector>
#include <utility>
#include <algorithm>

namespace uforia{

	// Sorts a vector<string> by count
  std::vector<std::string> count(std::vector<std::string> vec){
    std::vector<std::string> buffer;
    std::vector<std::pair<std::string, int>> counting;

    for(int i = 0; i < vec.size(); ++i){
        const std::string& line = vec[i];
        std::pair<std::string, int> p;
        p.first = line;
        p.second = 1;
        bool is_present = false;

        // Check is counting is empty
        if(i == 0){
            counting.push_back(p);
          }

        // Find existing lines
        for(int j = 0; j < counting.size(); ++j){
            auto found = counting[j];
            if(line == found.first){
                found.second++;
                is_present = true;
		counting.push_back(found);
		counting.erase(counting.begin() + j);
                break;
              }
          }

        // If no match was found the line will be added
        if(!is_present){
            counting.push_back(p);
          }
      }

    // Sort counting by frequence
    sort(counting.begin(), counting.end(), [](std::pair<std::string, int> a, std::pair<std::string, int> b){
      return a.second > b.second;
    });

    // Convert counting to buffer
    for(int i = 0; i < counting.size(); ++i){
        std::pair<std::string, int> found = counting[i];
	
	// Put counted lines back in buffer
	for(int j = 0; j < found.second; ++j){
		buffer.push_back(found.first);
	}
      }
    return buffer;
  }
}

#endif // COUNT_H
