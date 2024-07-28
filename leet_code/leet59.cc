
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    enum {
        dir_right = 0,
        dir_bottom = 1,
        dir_left = 2,
        dir_top = 3,
        dir_count
    };
    vector<vector<int>> generateMatrix(int n) {
        int r = n, l = 0, t = 0, b = n;
        int dir = dir_right;
        std::vector<std::vector<int>> res(n, std::vector<int>(n, 0));
        int cr = 0, cl = 0;
        int cnt = 1;
        while (l <= r && t <= b) {
            if(dir == dir_right) {
                for(int idx = l; idx < r; ++idx) {
                    res[cr][cl++] = cnt++;
                }
                cl = r - 1;
                ++t;
                dir = dir_bottom;
            }
            if(dir == dir_bottom) {
                cr = t;
                for(int idx = t; idx < b; ++t) {
                    res[cr++][cl] = cnt++;
                }
                cr = b -1;
                dir = dir_left;
                --r;
            }
            if(dir == dir_left) {
                cl = r - 1;
                for(int idx = r-1; idx >=l; --idx) {
                    res[cr][cl--] = cnt++;
                }
                cl = l;
                --b;
                dir = dir_top;
            }
            if( dir == dir_top) {
                cr = b - 1;
                for(int idx = b - 1; idx >=t; --idx) {
                    res[cr--][cl] = cnt++;
                }
                ++l;
                cr = t;
                dir = dir_right;
            }
        }
        return res;
    }
};

int main(){
    Solution().generateMatrix(3);
    return 0;
}