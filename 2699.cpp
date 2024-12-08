#include <compare>
#include <cstring>
#include <functional>
#include <iostream>
#include <iterator>
#include <optional>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <limits.h>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<pair<int,int>>> edge_pairs(n, vector<pair<int,int>>());
        for (auto edge : edges) {
            edge_pairs[edge[0]].push_back(make_pair(edge[1], edge[2]));
            edge_pairs[edge[1]].push_back(make_pair(edge[0], edge[2]));
        }

        vector<int> min_values(n, INT_MAX);
        min_values[source] = 0;
        queue<int> q;
        queue<int> q2;
        q.push(source);

        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            for (auto edge : edge_pairs[node]) {
                if (edge.second == -1) {
                    continue;
                } else {
                    if (edge.second + min_values[node] < min_values[edge.first]) {
                        min_values[edge.first] = edge.second + min_values[node];
                        q2.push(edge.first);
                    }
                }
            }

            if (q.empty()) {
                swap(q, q2);
            }
        }
        if (min_values[destination] < target) {
            return vector<vector<int>>();
        }


        min_values = vector<int>(n, INT_MAX);
        auto preds = vector<int>(n, INT_MAX);
        min_values[source] = 0;
        q = queue<int>();
        q2 = queue<int>();
        q.push(source);

        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            for (auto edge : edge_pairs[node]) {
                if (edge.second == -1) {
                    if (1 + min_values[node] < min_values[edge.first]) {
                        min_values[edge.first] = edge.second + min_values[node];
                        q2.push(edge.first);
                        preds[edge.first] = node;
                    }
                } else {
                    if (edge.second + min_values[node] < min_values[edge.first]) {
                        min_values[edge.first] = edge.second + min_values[node];
                        q2.push(edge.first);
                        preds[edge.first] = node;
                    }
                }
            }
            if (q.empty()) {
                swap(q, q2);
            }
        }
        if (min_values[destination] > target) {
            return vector<vector<int>>();;
        }
        auto temp = destination;

        while (temp != source) {
            temp = preds[temp];
        }

        
    }
};