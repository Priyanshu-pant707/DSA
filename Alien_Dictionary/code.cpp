#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
  public:
    string findOrder(vector<string> &words) {
        vector<vector<int>> graph(26);     
        vector<int> inDegree(26, 0);       
        vector<bool> exists(26, false);    

       
        for (const string& word : words) {
            for (char ch : word) {
                exists[ch - 'a'] = true;
            }
        }

        for (int i = 0; i + 1 < words.size(); ++i) {
            const string& w1 = words[i];
            const string& w2 = words[i + 1];
            int len = min(w1.length(), w2.length());
            int j = 0;

            while (j < len && w1[j] == w2[j]) ++j;

            if (j < len) {
                int u = w1[j] - 'a';
                int v = w2[j] - 'a';
                graph[u].push_back(v);
                inDegree[v]++;
            } else if (w1.size() > w2.size()) {
               
                return "";
            }
        }

        
        queue<int> q;
        for (int i = 0; i < 26; ++i) {
            if (exists[i] && inDegree[i] == 0) {
                q.push(i);
            }
        }

        string result;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            result += (char)(u + 'a');

            for (int v : graph[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        for (int i = 0; i < 26; ++i) {
            if (exists[i] && inDegree[i] != 0) {
                return "";
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

   
    vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};

    string order = sol.findOrder(words);

    if (order.empty()) {
        cout << "Invalid input or cycle detected in character ordering." << endl;
    } else {
        cout << "Alien Dictionary Order: " << order << endl;
    }

    return 0;
}
