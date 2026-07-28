class PrefixTree 
{
    private:
        class PrefixNode
        {
            public:
                bool word_end = false;
                unordered_map<char, PrefixNode*> suffixes;
        };

        PrefixNode *root;

    public:
        PrefixTree() 
        {
            root = new PrefixNode();
        }
        
        void insert(string word) 
        {
            int ptr = 0;
            PrefixNode *curr = root;
            while(ptr != word.size())
            {
                if(curr->suffixes.find(word[ptr]) == curr->suffixes.end())
                {
                    curr->suffixes[word[ptr]] = new PrefixNode();
                }
                curr = curr->suffixes[word[ptr++]];
            }
            curr->word_end = true;
        }
        
        bool search(string word) 
        {
            int ptr = 0; 
            PrefixNode *curr = root;
            while(ptr < word.size())
            {   
                if(curr->suffixes.find(word[ptr]) == curr->suffixes.end())
                {
                    return false;
                }
                curr = curr->suffixes[word[ptr++]];
            }
            return curr->word_end;
        }
        
        bool startsWith(string prefix) 
        {
            int ptr = 0; 
            PrefixNode *curr = root;
            while(ptr < prefix.size())
            {   
                if(curr->suffixes.find(prefix[ptr]) == curr->suffixes.end())
                {
                    return false;
                }
                curr = curr->suffixes[prefix[ptr++]];
            }
            return true;
        }
};
