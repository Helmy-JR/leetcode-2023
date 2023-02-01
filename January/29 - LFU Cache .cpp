// Author: Ahmed Gamal

class LFUCache {
public:
    struct Item {
        int freq, key, time;

        Item(){
            freq = key = time = -1;
        }

        Item(int freq, int key, int time){
            this -> freq = freq;
            this -> key = key;
            this -> time = time;
        }
    };

    class Compare {
        public:
            bool operator()(Item& a, Item& b){
                if(a.freq == b.freq){
                    return a.time > b.time;
                }
                return a.freq > b.freq;
            }
    };
    
    vector<int> cache, freq, time;
    priority_queue<Item, vector<Item>, Compare> pq;
    int timer, size, capacity;

    LFUCache(int capacity) {
        cache = freq = time = vector<int>(1e5 + 5, 0);
        timer = 1;
        size = 0;
        this -> capacity = capacity;
    }
    
    void add(int freq, int value, int key){

        this -> freq[key] = freq;
        cache[key] = value;
        time[key] = timer++;

        pq.emplace(1, key, time[key]);
    }

    void update(int key, int value){
        freq[key]++;
        cache[key] = value;
        time[key] = timer++;

        pq.emplace(freq[key], key, time[key]);
    }

    int get(int key) {
        if(not freq[key]){
            return -1;
        }

        update(key, cache[key]);
        return cache[key];
    }
    
    void put(int key, int value) {
        if(freq[key]){
            update(key, value);
        }else{
           
            if(size == capacity){

                if(not capacity) return;
                
                Item curr;
                do {
                    curr = pq.top();
                    pq.pop();
                }while(curr.freq != freq[curr.key]);

                freq[curr.key] = 0;
                cache[curr.key] = -1;

                add(1, value, key);
            }else{
                size++;
                add(1, value, key);
            }
        }
        
    }
}; //CREDIT >> AHMED GAMAL

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
