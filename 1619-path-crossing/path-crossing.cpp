class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int,int>,int> um;
        int x=0, y=0;
        um[make_pair(x,y)]++;
        for(int i=0; i<path.length(); i++) {
            if(path[i]=='N')
                y += 1;
            else if(path[i]=='S')
                y -= 1;
            else if(path[i]=='E')
                x += 1;
            else
                x -= 1;

            pair<int,int> temp = make_pair(x,y);
            if(um.find(temp)!=um.end())
                return 1;
            um[temp]++;
        }
        return 0;
    }
};