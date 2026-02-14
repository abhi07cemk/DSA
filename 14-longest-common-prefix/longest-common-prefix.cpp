class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n = strs.size();
        //for traversing all charcters of first string
        for(int i = 0; i<strs[0].length(); i++)
        {
            char ch = strs[0][i];

            bool match = true;

            //For remaining strings(compairing character)
            for(int j = 1; j<n; j++)
            {
                if(strs[j].size() < i || ch != strs[j][i])
                {
                    match = false;
                    break;
                }
            }
            if(match == false)
            {
                break;
            }
            else
            {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};