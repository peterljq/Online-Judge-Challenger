class Solution {
public:
    string reverseString(string s) {
        string ROS;
        for(int i = s.size()-1; i >= 0; i--){
            ROS.push_back(s[i]);
        }
        return ROS;
    }
};
