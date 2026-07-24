// least recently used cache
// probably has something to do with tracking
// obtain least recently used key... we can use a deque... maybe
// we can store keys in a HashMap
// deques are doubly linked lists where adding / removing is O(1) from both ends
// front of deque --> most recently used keys
// back of deque --> least recently used keys
// if new key is same as back of deque, remove from back of deque and add key
// if cache is full, remove from back of deque and add new key
// do checks in this order
// 1. back == front, remove from back
// 2. size == capacity, remove from back
// 3. add to front the new key
// every time we use an element is when get() or put() is called
// so element should be pushed to front of deque when those funcs() are called
// solution to deleting elements when re-adding: keep track of nodes
// we still use a deque, but we create a custom LL where we can remove based on node
// in the hashmap, we store int-node pairs, with the node consisting of the value
// we hold front and back nodes of list
// we add to the front on every put
// we remove from back when we reach cache capacity
// when we re-add an element we extract node...
// remove it from that area
// and add it to the front
// nodes consist of prev & next pointers so deletion is O(1)
class LRUCache 
{
    private:
        // private class for a node in a list
        // consists of prev & next pointers so deletion is O(1)
        class Node
        {
            public: 
                int key;
                int val;
                Node *prev;
                Node *next;

                Node(int key, int val)
                {
                    this->key = key;
                    this->val = val;
                    prev = nullptr;
                    next = nullptr;
                }
        };

        int capacity;                           // the limit to our cache
        unordered_map<int, Node*> cache;        // key-value pairs in cache
        Node *front;                            // front of the deque
        Node *back;                             // back of the deque

        // function for adding to the front of the deque
        // called addMostRecentlyUsed as this is essentially its functionality
        // consists of 2 cases:
        // 1. empty deque: set front & back to the given node
        // 2. non-empty deque: set current front's next to new node...
        // then move front to the new node, also set current's prev to front
        // O(1) as doing simple checks & pointer manipulation
        void addMostRecentlyUsed(Node *node)
        {
            // case 1: empty deque
            if(front == nullptr)
            {
                front = node;
                back = node;
            }
            // case 2: non-empty deque
            else
            {
                front->next = node;
                node->prev = front;
                front = node;
            }
        }

        // function for removing from the back of the deque
        // called removeLeastRecentlyUsed(); only called when cache is full
        // cases:
        // 1. empty deque, set all pointers to nullptr
        // 2. non-empty deque, move back pointer and set prev to nullptr
        // O(1) as doing simple value checks and pointer manipulation
        // returns the LRU node so it can be removed from the map 
        Node *removeLeastRecentlyUsed()
        {
            Node *lru = back;
            if(lru == front)
            {
                front = nullptr;
                back = nullptr;
            }
            else
            {
                back = back->next;
                back->prev = nullptr;
            }
            return lru;
        }

        // function for removing arbitrary node from a deque
        // called removePrevUsage(); called when key value is replaced
        // cases: 
        // 1. both prev & next of node are null, set front & back to null
        // 2. only prev is null, move back and set back prev to null
        // 3. only next is null, move front backward and set front next to null
        // 4. both prev & next are non-null, set next of prev to next of curr, 
        // and prev of next to prev of curr
        // O(1) function as simply setting pointers & checking for null pointer
        void removePrevUsage(Node *node)
        {
            // case 1: only one node
            if(node == front && node == back)
            {
                front = nullptr;
                back = nullptr;
            }
            // case 2: node is back pointer
            else if(node == back)
            {
                back = back->next;
                back->prev = nullptr;
            }
            // case 3: node is front pointer
            else if(node == front)
            {
                front = front->prev;
                front->next = nullptr;
            }
            // case 4: default case, simply connect prev & next
            else
            {   
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }
        }

    public:
        // initialization
        // we obtain a capacity, so we set the capacity field
        LRUCache(int capacity) 
        {
            cache.clear();
            front = nullptr;
            back = nullptr;
            this->capacity = capacity;
        }

        // takes in an integer key and returns corresponding value
        // if key not in cache return -1
        // also get() is considered a usage, so we need to update used list
        int get(int key) 
        {
            // if the key is not in the map, return -1... O(1) check
            if(cache.find(key) == cache.end())
            {
                return -1;
            }
            // key is in the map
            // remove previous usage & add next usage
            Node *node = cache[key];
            removePrevUsage(node);
            addMostRecentlyUsed(node);
            // O(1) extraction of value
            return node->val;
        }
        
        // if a key is updated, do we need to remove until key is found?
        // if a key is updated, isn't it the least recently used item?
        // every time we update a key, we need to ensure that...
        // the usage of the rest of the keys is not affected
        // if the key is in map, simply replace it & update deque
        // if key is not in map, remove least recently used if needed and add it
        void put(int key, int value) 
        {
            // case 1: not in map, remove LRU if needed and add new key-value pair
            if(cache.find(key) == cache.end()) 
            {
                // if capacity has been reached, remove LRU (from back)
                if(cache.size() == capacity)
                {
                    Node *lru = removeLeastRecentlyUsed();
                    cache.erase(lru->key);
                }
                Node *new_node = new Node(key, value);
                addMostRecentlyUsed(new_node);
                cache.insert({key, new_node});
            }
            // case 2: in map, remove last usage and update value
            else
            {
                Node *prev = cache[key];
                removePrevUsage(prev);
                prev->val = value;
                addMostRecentlyUsed(prev);
            }
        }
};
