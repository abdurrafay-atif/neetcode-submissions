class Solution 
{
    public:
        // swapping bits algorithm
        uint32_t reverseBits(uint32_t n) 
        {
            int left = 0;
            int right = 31;
            while(left <= right)
            {
                int bit_left = 1 & (n >> left);
                int bit_right = 1 & (n >> right);
                if(bit_left == 0 && bit_right == 1)
                {
                    n |= (1 << left);
                    n &= ~(1 << right);
                }
                if(bit_left == 1 && bit_right == 0)
                {
                    n &= ~(1 << left);
                    n |= (1 << right);
                }
                left++;
                right--;
            }
            return n;
        }
};
