class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size() != B.size()){
            return false;
        }
        else if(A.size() == 0 && B.size() == 0){
            return true;
        }
        else{
            for(int i = 0; i < B.size();i++){
                char temp = A[0];
                A.erase(0,1);
                A.push_back(temp);
                if(A.compare(B) == 0){
                    return true;
                }
            }
            return false;
        }
    }
};
