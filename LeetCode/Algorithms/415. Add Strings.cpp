class Solution {
public:
    string addStrings(string num1, string num2) {
       int resultSize = (num1.size() > num2.size())?num1.size():num2.size();
        string result;
        int resultSizeDup = resultSize;
        int num1Array[resultSize+1] = {0};
        int num2Array[resultSize+1] = {0};
        int resultArray[resultSize+1] = {0};
        for(int i = num1.size()-1; i >= 0; i--){
            int temp1 = num1[i] - '0';
            num1Array[resultSizeDup] = temp1;
            resultSizeDup--;
        }
        resultSizeDup = resultSize;
        for(int i = num2.size()-1; i >= 0; i--){
            int temp2 = num2[i] - '0';
            num2Array[resultSizeDup] = temp2;
            resultSizeDup--;
        }
        
        
        for(int i = resultSize; i > 0; i--){
            int currentAt = num1Array[i] + num2Array[i];
            resultArray[i] += currentAt;
            if(resultArray[i] >= 10){
                resultArray[i-1] += 1;
                resultArray[i] -= 10;
            }
        }
        
        for(int i = 0; i <= resultSize; i++){
            result.push_back((char)(resultArray[i]+'0'));
        }
        
        if(result[0] == '0') result.erase(0,1);
        return result;
    }
};
