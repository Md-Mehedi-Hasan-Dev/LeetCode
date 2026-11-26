class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for(int task : tasks) freq[task]++;
        priority_queue<int> pq;
        for(auto i : freq) pq.push(i.second);
        int time = 0;
        while(!pq.empty())
        {
            list<int> l;
            for(int i = 0; i < n + 1; i++)
            {
                if (!pq.empty()) {l.push_back(pq.top()); pq.pop();}
            }
            for(int freq : l)
            {
                if(--freq > 0) pq.push(freq);
            }
            time += (pq.empty()) ? l.size() : n + 1;
        }
        return time;
    }
};