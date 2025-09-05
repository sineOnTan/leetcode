class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int N = points.size();
        int edge_weight[1005][1005]; // edge_weight[i][j] is the length of the edge from i to j.
        
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j <= i; j++) {
                edge_weight[i][j] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
              	edge_weight[j][i] = edge_weight[i][j];
            }
        }
        
        priority_queue<pair<int, int>> pq; //edge_weight, index
            
        bool inserted[1005];
        for (int i = 0; i < N + 5; i++) {
            inserted[i] = false;
        }
        
        inserted[0] = true;
        for (int i = 0; i < points.size(); i++) {
            if (inserted[i] == false) pq.emplace(edge_weight[0][i] * (-1), i);
        }
        
        int res = 0;
        int inserted_count = 1;

        while (inserted_count != points.size()) {
            auto cur = pq.top();
            pq.pop();
            if (inserted[cur.second] == true) continue;
            
            inserted[cur.second] = true;
            res += cur.first;
            inserted_count++;
            for (int i = 0; i < points.size(); i++) {
                if (inserted[i] == false) pq.emplace(-1 *(edge_weight[cur.second][i]), i);
            }
        }
        
        return -res;
    }
};