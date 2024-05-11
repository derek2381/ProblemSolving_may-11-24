// problem link
// https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/?envType=daily-question&envId=2024-05-11

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double, int>> prop;
        int n = quality.size();

        for(int i = 0; i < n;i++){
            prop.emplace_back(static_cast<double>(wage[i])/quality[i], i);
        }

        sort(begin(prop), end(prop));
        priority_queue<int> pq;
        int cost = 0;
        double ppt = 0.0;

        for(int i = 0;i < k;i++){
            cost += quality[prop[i].second];
            ppt = max(ppt, prop[i].first);
            pq.push(quality[prop[i].second]);
        }

        double min_cost = cost*ppt;

        for(int i = k;i < n;i++){
            ppt = max(ppt, prop[i].first);
            cost -= pq.top();
            pq.pop();

            cost += quality[prop[i].second];
            pq.push(quality[prop[i].second]);
            if(cost*ppt < min_cost){
                min_cost = cost*ppt;
            }
        }

        return min_cost;

    }
};
