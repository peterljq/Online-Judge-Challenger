class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> sCount;
        unordered_map<char,int> pCount;
        int flag = 0;
        vector<int> result;
        if(p.size() > s.size()){
        
        }
        else{
            for(char c: p){
                pCount[c]++;
            }
            for(int j = 0; j < p.size(); j++){
                sCount[s[j]]++;
            }
            if(pCount == sCount){
                result.push_back(0);
            }
            for(int i = 1; i <= s.size() - p.size(); i++){
                sCount[s[i-1]]--;
                //cout << s[i-1] << " poped out: " << sCount[s[i-1]] << endl;
                if(sCount[s[i-1]] == 0){
                    sCount.erase(s[i-1]);
                }
                sCount[s[i+p.size()-1]]++;
                //cout << s[i+p.size()-1] << " push in: " << sCount[s[i+p.size()-1]] << endl;
                if(sCount == pCount){
                    result.push_back(i);
                }
            }
        
        }
        return result;
    }
};
