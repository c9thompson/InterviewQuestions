/*
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.
*/

class Solution {
public:
    double getRatio(vector<int> origin, vector<int> c1){
        return double(c1[1] - origin[1])/double(c1[0] - origin[0]);
    }
    
    bool equal(double d1, double d2, double e){
        return abs(d1 - d2) < e;
    }
    
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size() < 3) return true;
        
        double e = 0.0000001;
        double ratio = getRatio(coordinates[0], coordinates[1]);
        for(int i = 2; i < coordinates.size(); ++i){
            if(!equal(ratio, getRatio(coordinates[0], coordinates[i]), e)) return false;
        }
               
        return true;
    }
};