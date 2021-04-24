class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n, 0));
        
        int top = 0, bottom = n-1;
        int left = 0, right = n-1;
        int count = 1;
        while(true){
            for(int i = left; i <= right; ++i){
                v[top][i] = count++;
            }
            if(++top > bottom){
                break;
            }
                
            for(int i = top; i <= bottom; ++i){
                v[i][right] = count++;
            }
            if(--right < left){
                break;
            }

            for(int i = right; i >= left; --i){
                v[bottom][i] = count++;
            } 
            if(--bottom < top){
                break;
            }

            for(int i = bottom; i >=top; --i){
                v[i][left] = count++;
            }
            if(++left > right){
                break;
            }
        }
        return v;
    }
};