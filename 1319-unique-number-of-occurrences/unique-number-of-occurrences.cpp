class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       unordered_map<int , int> count;
       for(int n : arr)  count[n]++;
       unordered_set<int> s;
       for(auto& p : count)
       {
        if(!s.insert(p.second).second) return false;
       }
       return true;
    }
};