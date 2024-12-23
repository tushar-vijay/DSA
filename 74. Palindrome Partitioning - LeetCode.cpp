class Solution {
public:
    bool isPalindrome(string s){
        string s_new = s;
        reverse(s_new.begin(), s_new.end());
        return (s == s_new);
    }

    void getAllPartitions(string s, vector<string> &partitions, vector<vector<string>> &ans){
        // base case
        if(s.size() == 0){
            ans.push_back(partitions);
            return;
        }

        for(int i = 0; i < s.size(); i++){
            string part = s.substr(0, i+1);

            if(isPalindrome(part)){
                partitions.push_back(part);
                getAllPartitions(s.substr(i+1), partitions, ans);
                partitions.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> partitions;
        vector<vector<string>> ans;

        getAllPartitions(s, partitions, ans);

        return ans;
    }
};
