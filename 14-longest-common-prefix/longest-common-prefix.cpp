// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         string ans = "";
//         int n = strs.size();
//         //for traversing all charcters of first string
//         for(int i = 0; i<strs[0].length(); i++)
//         {
//             char ch = strs[0][i];

//             bool match = true;

//             //For remaining strings(compairing character)
//             for(int j = 1; j<n; j++)
//             {
//                 if(strs[j].size() < i || ch != strs[j][i])
//                 {
//                     match = false;
//                     break;
//                 }
//             }
//             if(match == false)
//             {
//                 break;
//             }
//             else
//             {
//                 ans.push_back(ch);
//             }
//         }
//         return ans;
//     }
// };

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;

    TrieNode(char ch) {
        data = ch;
        for(int i = 0; i < 26; i++)
            children[i] = NULL;
        isTerminal = false;
        childCount = 0;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insert(string word) {
        TrieNode* temp = root;

        for(int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';

            if(temp->children[index] == NULL) {
                temp->childCount++;
                temp->children[index] = new TrieNode(word[i]);
            }

            temp = temp->children[index];
        }
        temp->isTerminal = true;
    }

    string longestCommonPrefix(string first) {
        string ans = "";
        TrieNode* temp = root;

        for(int i = 0; i < first.length(); i++) {
            int index = first[i] - 'a';

            if(temp->childCount == 1 && temp->isTerminal == false) {
                ans.push_back(first[i]);
                temp = temp->children[index];
            }
            else {
                break;
            }
        }
        return ans;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if(strs.size() == 0)
            return "";

        Trie* t = new Trie();

        for(int i = 0; i < strs.size(); i++) {
            t->insert(strs[i]);
        }

        
        return t->longestCommonPrefix(strs[0]);
    }
};
