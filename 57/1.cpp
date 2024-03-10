class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret = {};
        bool added = false;

        for(int i = 0; i < intervals.size(); i++){
            vector<int> currentInterval = intervals[i];
            if(overlapping(currentInterval, newInterval)){
                newInterval = merge(currentInterval, newInterval);
            }else{
                if(!added && newInterval[1] < currentInterval[0]){
                    ret.push_back(newInterval);
                    added = true;
                }
                ret.push_back(currentInterval);
            }
        }
        if(!added){
            ret.push_back(newInterval);
        }

        return ret;
    }

    bool overlapping(vector<int>& currentInterval, vector<int>& newInterval){
        return (min(currentInterval[1], newInterval[1]) - max(currentInterval[0], newInterval[0]) >= 0);
    }

    vector<int> merge(vector<int>& currentInterval, vector<int>& newInterval){
        return {min(currentInterval[0], newInterval[0]), max(currentInterval[1], newInterval[1])};
    }
};
