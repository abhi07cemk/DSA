#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Node {
public:
    int val;
    int row;
    int col;

    Node(int v, int r, int c) {
        val = v;
        row = r;
        col = c;
    }
};

class compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->val > b->val;   // min heap
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        int k = nums.size();
        priority_queue<Node*, vector<Node*>, compare> minHeap;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        // Insert first element of each list
        for(int i = 0; i < k; i++) {
            int element = nums[i][0];
            mini = min(mini, element);
            maxi = max(maxi, element);
            minHeap.push(new Node(element, i, 0));
        }

        int start = mini, end = maxi;

        while(!minHeap.empty()) {

            Node* temp = minHeap.top();
            minHeap.pop();

            mini = temp->val;

            if(maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }

            // Move in same list
            if(temp->col + 1 < nums[temp->row].size()) {

                int nextVal = nums[temp->row][temp->col + 1];
                maxi = max(maxi, nextVal);

                minHeap.push(new Node(nextVal, temp->row, temp->col + 1));
            }
            else {
                break;  // one list exhausted
            }
        }

        return {start, end};
    }
};
