class LFUCache {
public:

    class Node{
    public:
        int key, val, freq;
        Node* prev;
        Node* next;
        Node(int k, int v){
            key = k;
            val = v;
            freq = 1;
            prev = next = nullptr;
        }
    };

    int capacity;
    int size;
    int minFreq;

    unordered_map<int, Node*>mp;
    unordered_map<int, pair<Node*, Node*>> freqmap;

    LFUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        minFreq = 0;
    }

    void addNode(Node* node){
        int freq = node->freq;
        if(freqmap.find(freq) == freqmap.end()){
            Node* head = new Node(-1,-1);
            Node* tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            freqmap[freq] = {head, tail};
        }
        Node* head = freqmap[freq].first;
        Node* nextNode = head->next;
        head->next = node;
        node->next = nextNode;
        node->prev = head;
        nextNode->prev = node;
    }

    void delNode(Node* node){
        Node* next = node->next;
        Node* prev = node->prev;
        prev->next = next;
        next->prev = prev;
    }

    void increaseFreq(Node* node){
        int old = node->freq;
        delNode(node);
        Node* head = freqmap[old].first;
        Node* tail = freqmap[old].second;
        if(head->next == tail){
            freqmap.erase(old);
            if(minFreq == old){
                minFreq++;
            }
        }
        node->freq++;
        addNode(node);
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        Node* node = mp[key];
        increaseFreq(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(capacity == 0){
            return;
        }
        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];
            node->val = value;
            increaseFreq(node);
            return;
        }
        if(size == capacity){
            Node* head = freqmap[minFreq].first;
            Node* tail = freqmap[minFreq].second;
            Node* lru = tail->prev;
            delNode(lru);
            mp.erase(lru->key);
            size--;
            if(head->next == tail){
                freqmap.erase(minFreq);
            }
        }
        Node* node = new Node(key, value);
        mp[key] = node;
        minFreq = 1;
        addNode(node);
        size++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */