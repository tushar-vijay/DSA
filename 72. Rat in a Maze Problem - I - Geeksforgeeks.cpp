class Solution {
  public:
    void helper(vector<vector<int>> &mat, int r, int c, string path, vector<string> &ans){
        int n = mat.size();
        
        if(r < 0 || c < 0 || r >= n || c >= n || mat[r][c] == 0 || mat[r][c] == -1){
            return;
        }
        
        if(r == n-1 && c == n-1){
            ans.push_back(path);
            return;
        }
        
        mat[r][c] = -1;
        
        helper(mat, r+1, c, path + "D", ans); // down
        helper(mat, r-1, c, path + "U", ans); // up
        helper(mat, r, c-1, path + "L", ans); // left
        helper(mat, r, c+1, path + "R", ans); // right
        
        mat[r][c] = 1;
    }
    
    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        string path = "";
        vector<string> ans;
        // vector<vector<bool>> visited (n, vector<bool>(n, false));
        
        helper(mat, 0, 0, path, ans);
        
        return ans;
    }
};
