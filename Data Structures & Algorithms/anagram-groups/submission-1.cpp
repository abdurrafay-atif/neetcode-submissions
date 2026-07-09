class Solution 
{
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) 
        {
            // unordered map: frequency map --> vector of strings
            // key: string consisting of frequency mapping
            // value: vector of strings with frequency mapping of key
            // costs O(# of unique strings) + O(m) space
            // m = # of strings 
            unordered_map<string, vector<string>> mapping;
            // loop through all the strings
            // O(m) loop not counting contents, where m = # of strings
            // inside is O(n) 
            // O(m) * O(n) = O(m * n)
            for(auto s : strs) 
            {
                // calculate current string's frequency mapping
                // costs O(n) space, where n = # of characters
                unordered_map<char, int> curr_freqs;
                // loop through all characters to calculate frequencyes
                // worst case O(n) loop, where n = # of characters
                for(char c : s) 
                {
                    if(curr_freqs.find(c) == curr_freqs.end())
                    {
                        curr_freqs.insert({c, 1});
                    }
                    else
                    {
                        curr_freqs[c] = curr_freqs[c] + 1;
                    }
                }
                // convert map to string
                // this is an O(n) loop
                // constant # of characters
                // # of characters appended is the # of characters in original string
                // this # is the same n from before
                string freq_str;
                for(char i = 97; i <= 122; i++)
                {
                    // skip any characters 
                    if(curr_freqs.find(i) != curr_freqs.end())
                    {
                        int freq = curr_freqs[i];
                        for(int j = 0; j < freq; j++)
                        {
                            freq_str.push_back(i);
                        }
                        continue;
                    }
                }
                // check if the current frequency mapping str is in the result
                // if it isn't add it and create a new vector as a value
                // Big-O depends on hash function for strings, most likely O(1)
                if(mapping.find(freq_str) == mapping.end())
                {
                    vector<string> new_vec;
                    mapping[freq_str] = new_vec;
                }
                // add the current string to this mapping
                mapping[freq_str].push_back(s);
            }
            // convert mapping to a list
            // O(m) loop
            vector<vector<string>> result;
            int index = 0;
            for(auto pairing : mapping) 
            {
                result.push_back(pairing.second);
            }
            return result;
        }
};
