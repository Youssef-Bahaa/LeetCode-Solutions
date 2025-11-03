class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int minTime = 0;
        int i = 0 ,j = i + 1;
        while(j < neededTime.size()){
            if(colors[i] == colors[j]){
                if(neededTime[i] >= neededTime[j]){
                    minTime += neededTime[j];
                }
                else minTime += neededTime[i],i=j;
            }
            else i = j;
            j++;
        }
        return minTime;
    }
};