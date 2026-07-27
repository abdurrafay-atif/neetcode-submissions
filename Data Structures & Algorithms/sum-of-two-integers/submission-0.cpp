class Solution 
{
    public:
        int getSum(int a, int b) 
        {
            int tot_sum = 0;
            int carry = 0;
            for(int i = 0; i < 32; i++)
            {
                int a_i = 1 & (a >> i);
                int b_i = 1 & (b >> i);
                int sum_i = a_i ^ b_i ^ carry;
                carry = (a_i & b_i) | (carry & (a_i ^ b_i));
                tot_sum |= ((sum_i) << i);
            }
            return tot_sum;
        }
};
