class PrefixTree 
{
    private:
        class PrefixNode
        {
            public:
                char prefix;
                unordered_map<char, PrefixNode*> suffixes;

                PrefixNode(char prefix)
                {
                    this->prefix = prefix;
                }
        };

        PrefixNode *root;
        unordered_set<string> words_inserted;

    public:
        PrefixTree() 
        {
            root = new PrefixNode(' ');
        }
        
        void insert(string word) 
        {
            int ptr = 0;
            PrefixNode *curr = root;
            while(ptr != word.size())
            {
                if(curr->suffixes.find(word[ptr]) == curr->suffixes.end())
                {
                    curr->suffixes[word[ptr]] = new PrefixNode(word[ptr]);
                }
                curr = curr->suffixes[word[ptr++]];
            }
            words_inserted.insert(word);
        }
        
        bool search(string word) 
        {
            return words_inserted.find(word) != words_inserted.end();
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
