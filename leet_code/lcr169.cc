#include "common_def.h"
using std::string;

class Solution {
public:
    char dismantlingAction(string arr) {
        std::unordered_map<char, int> hash;
        for(const auto& ch: arr){
            auto it = hash.find(ch);
            if(it != hash.end()) {
                it->second++;
            } else {
                hash.insert(std::make_pair(ch, 1));
            }
        }
        for(const auto& ch:arr){
            if(hash[ch] == 1) {
                return ch;
            }
        }
        return 0;
    }
};