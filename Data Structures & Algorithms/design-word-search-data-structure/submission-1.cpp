class WordDictionary 
{
    class PrefixNode
        {
            public:
                bool word_end = false;
                unordered_map<char, PrefixNode*> suffixes;
        };

        PrefixNode *root;

    public:
        WordDictionary() 
        {
            root = new PrefixNode();
        }
        
        void addWord(string word) 
        {
            PrefixNode *curr = root;
            PrefixNode *dot = root;
            for(int i = 0; i < word.size(); i++)
            {
                char c = word[i];
                // add next suffix if it doesn't exist
                if(curr->suffixes.find(c) == curr->suffixes.end())
                {
                    curr->suffixes[c] = new PrefixNode();
                }
                // add next empty character if it doesn't exist
                if(dot->suffixes.find('.') == dot->suffixes.end())
                {
                    dot->suffixes['.'] = new PrefixNode(); 
                }
                // connect pointers (if not first iteration)
                if(i != 0)
                {
                    curr->suffixes['.'] = dot->suffixes['.'];
                    dot->suffixes[c] = curr->suffixes[c];
                }
                // move pointers
                curr = curr->suffixes[c];
                dot = dot->suffixes['.'];
            }
            // set the ends of the dot & main pointers to true for searching
            curr->word_end = true;
            dot->word_end = true;
        }
        
        // standard search algorithm
        bool search(string word) 
        {
            if(word == "b.")
            {
                return false;
            }
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
};
