#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
// std::string str;
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        std::unordered_map<string, vector<string>> hash_res;
        for(auto iter = strs.begin(); iter != strs.end(); ++iter) {
            string tmp = *iter;
            std::sort(tmp.begin(), tmp.end());
            // tmp is sorted.
            auto it = hash_res.find(tmp);
            if ( it == hash_res.end()) {
                hash_res.insert({tmp, vector<string>()});
            }
            hash_res[tmp].push_back(*iter);
        }
        
        for(auto it = hash_res.begin(); it != hash_res.end(); ++it){
            res.push_back(it->second);
        }
        return res;
    }
};
