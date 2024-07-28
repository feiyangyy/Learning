class Solution {
public:
    std::vector<bool> used;

    void dfs(string& goods, string& path, std::vector<string>& res) {
        if(path.size() == goods.size()) {
            res.push_back(path);
            return;
        }
        std::set<char> plc_rec;
        for(int idx = 0; idx<goods.size(); ++idx) {
            if(used[idx]) {
                continue;
            }

            if(plc_rec.find(goods[idx]) != plc_rec.end()) {
                continue;
            }
            // path此位置已记录
            plc_rec.insert(goods[idx]);

            path.push_back(goods[idx]);
            used[idx] = true;
            dfs(goods, path, res);
            used[idx] = false;
            path.pop_back();
        }
    }

    vector<string> goodsOrder(string goods) {
       // std::swap(used, std::vector<bool>(goods.size(), false));
        used = std::vector<bool>(goods.size(), false);
        std::string path;
        std::vector<std::string> res;
        dfs(goods, path, res);
        return res;
    }
};