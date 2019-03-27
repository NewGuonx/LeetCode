class Solution
{
  public:
    int mySqrt(int x)
    {
        int lo = 1, hi = x / 2, last_mid; 
        if (x < 2) return x;
        while (lo <= hi)
        {
            const int mid = lo + (hi - lo) / 2;
            if (x / mid > mid)
            {
                lo = mid + 1;
                last_mid = mid;
            }
            else if (x / mid < mid)
                hi = mid - 1;
            else
                return mid;
        }
        return last_mid;
    }
};