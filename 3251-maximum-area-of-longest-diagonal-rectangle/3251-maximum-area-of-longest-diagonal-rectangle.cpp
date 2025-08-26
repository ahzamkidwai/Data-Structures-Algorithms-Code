class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        // int numberOfRectangles = dimensions.size();
        // int maxArea = INT_MIN, maxDiagonal = INT_MIN;
        // for(int i=0; i<numberOfRectangles; i++){
        //     int length = dimensions[i][0];
        //     int breadth = dimensions[i][1];
        //     int diagonalLength = sqrt((length * length) + (breadth * breadth));
        //     if(diagonalLength > maxDiagonal){
        //         maxDiagonal = diagonalLength;
        //         int tempArea = length * breadth;
        //         if(tempArea > maxArea)
        //             maxArea = tempArea;
        //     } else if(diagonalLength == maxDiagonal){
        //         int tempArea = length * breadth;
        //         if(tempArea > maxArea)
        //             maxArea = tempArea;
        //     }
        // }
        // return maxArea;
        int maxDiaSq = 0, maxArea = 0;
        for (const auto& dim : dimensions) {
            int l = dim[0], w = dim[1];
            int diaSq = l * l + w * w, area = l * w;
            if (diaSq > maxDiaSq) {
                maxDiaSq = diaSq;
                maxArea = area;
            } else if (diaSq == maxDiaSq) {
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};