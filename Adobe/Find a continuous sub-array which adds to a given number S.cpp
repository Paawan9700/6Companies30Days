vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        vector<int > ans;
        // initially my two indexes are -1
        int leftIndex = -1, rightIndex = -1;
        int left = 0, right = 0, occured = 0;
        long long sum = 0;
        
        while(right < n){
            sum += arr[right];
            
            // not allowed - its time to move the left pointer
            if(sum > s){
                while(left < right and sum > s){
                    sum -= arr[left];
                    ++left;
                }
            }
            
            if(sum == s and !occured){
                leftIndex = left + 1;
                rightIndex = right + 1;
                occured = 1;
            }
            
            ++right;
        }
        
        if(!occured){
            ans.push_back(-1);
            return ans;
        }
            
        ans.push_back(leftIndex);
        ans.push_back(rightIndex);
        
        return ans;
    }