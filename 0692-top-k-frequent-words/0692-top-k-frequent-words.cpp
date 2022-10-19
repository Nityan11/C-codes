class word{
  public:
    string st;
    int freq;
    
};

bool operator<(const word& p1, const word& p2)
{
    if(p1.freq == p2.freq)
            return p1.st > p2.st;
    return p1.freq < p2.freq;
}
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        priority_queue<word> pq;
        for(int i =0; i<words.size(); i++){
            mp[words[i]]++;
        }
        for(auto i:mp){
            word obj;
            obj.st = i.first;
            obj.freq = i.second;
            pq.push(obj);
        }
        vector<string> ans;
        for(int i = 0; i<k;i++){
            ans.emplace_back(pq.top().st);
            pq.pop();
        }
        return ans;
    }
};