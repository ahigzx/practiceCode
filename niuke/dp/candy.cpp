class Solution {
    public:
        int candy(vector<int>& ratings) {
            if(ratings.empty())
            {
                return 0;
            }
            int n = ratings.size();
            int candies = 0;
            vector<int> childCandies(n, 1);
            if(n > 1)
            {
                for(int i = 1; i < n; i++)
                {
                    if(ratings[i] > ratings[i-1])
                    {
                        childCandies[i] = childCandies[i-1] + 1;
                    }
                }
                for(int i = n - 2; i >= 0; i--)
                {
                    if(ratings[i] > ratings[i+1] && childCandies[i] <= childCandies[i+1])
                    {
                        childCandies[i] = childCandies[i+1] + 1;
                    }
                }
            }
            for(auto &x : childCandies)
            {
                candies += x;
            }
            return candies;
            
        }
}
