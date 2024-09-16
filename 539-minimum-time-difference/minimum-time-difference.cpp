class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> mins;
        int len = timePoints.size();

        sort(timePoints.begin(), timePoints.end());
    
        // for(int i=0; i<len; i++) {
        //     string time = timePoints[i];
        //     int hours = stoi(time.substr(0,2));
        //     int minutes = stoi(time.substr(3,2));

        //     int total_minutes = hours * 60 + minutes;
        //     //cout << total_minutes << " ";
        //     if(hours == 0) {
        //         mins.push_back(total_minutes);
        //         total_minutes = 1440 + minutes;
        //         mins.push_back(total_minutes);
        //     }
        //     else
        //         mins.push_back(total_minutes);
        // }

        // sort(mins.begin(), mins.end());
        int mini = INT_MAX;
        //len = mins.size();
        for(int i=1; i<len; i++) {
            int hours1 = stoi(timePoints[i].substr(0,2));
            int hours2 = stoi(timePoints[i-1].substr(0,2));
            int mins1 = stoi(timePoints[i].substr(3,2));
            int mins2 = stoi(timePoints[i-1].substr(3,2));
            
            int diff = (hours1 - hours2) * 60 + (mins1 - mins2);

            mini = min(mini, diff);
        }

        // last case
        int hours1 = stoi(timePoints[0].substr(0,2)) + 24;
        int hours2 = stoi(timePoints[len-1].substr(0,2));
        int mins1 = stoi(timePoints[0].substr(3,2));
        int mins2 = stoi(timePoints[len-1].substr(3,2));

        int diff = (hours1 - hours2) * 60 + (mins1 - mins2);

        mini = min(mini, diff);

        return mini;
    }
};