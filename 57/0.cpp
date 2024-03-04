class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // intervalsが空の場合
        if(intervals.size()==0){
            return {newInterval};
        }

        if(newInterval[0] <= intervals[0][0] && intervals.back()[1] <= newInterval[1]){
            return {newInterval};
        }

        // newIntervalがintervalsと被らない位置にある
        if(newInterval[1] < intervals[0][0]){
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        if(intervals.back()[1] < newInterval[0]){
            intervals.push_back(newInterval);
            return intervals;
        }

        // newIntervalがいずれかのintervalの中にある時、intervalsをそのまま帰す
        for(int i = 0; i < intervals.size(); i++){
            vector<int> currentInterval = intervals[i];
            if(currentInterval[0] <= newInterval[0] && newInterval[1] <= currentInterval[1]){
                return intervals;
            }
        }

        vector<vector<int>> ret = {};
        vector<int> growingInterval;
        bool growing = false;
        for(int i = 0; i < intervals.size(); i++){
            vector<int> currentInterval = intervals[i];
            if(!growing){
                // 重なっていないならそのまま
                if(currentInterval[1] < newInterval[0] || newInterval[1] < currentInterval[0]){
                    ret.push_back(currentInterval);
                    continue;
                }
                // newのstartがcurrentの中に入っていて、newのendがcurrentの外
                if(currentInterval[0] <= newInterval[0] && newInterval[0] <= currentInterval[1] && currentInterval[1] < newInterval[1]){
                    // intervalを拡張する
                    growingInterval = {0, 0};
                    growingInterval[0] = currentInterval[0];
                    growingInterval[1] = newInterval[1];
                    growing = true;
                    continue;
                }

                // newIntervalのendのみがcurrentIntervalの中にある時
                if(currentInterval[0] <= newInterval[1] && newInterval[1] <= currentInterval[1]){
                    ret.push_back({newInterval[0], currentInterval[1]});
                }

            }else{
                // growingIntervalと重なりがないならそのまま追加
                if(growingInterval[1] < currentInterval[0]){
                    ret.push_back(growingInterval);
                    ret.push_back(currentInterval);
                    growing = false;
                    continue;
                }

                // growingIntervalと重なりがあるなら統合
                if(currentInterval[0] <= growingInterval[1] && growingInterval[1] <= currentInterval[1]){
                    growingInterval[1] = currentInterval[1];
                    continue;
                }

                // currentIntervalのendよりもgrowingIntervalのendの方が大きいときは何もしない
            }
        }
        if(growing){
            ret.push_back(growingInterval);
        }

        return ret;
    }
};
