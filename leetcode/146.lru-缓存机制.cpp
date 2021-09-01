/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start

struct DLinkedNode
{
    int key,value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0),value(0),prev(nullptr),next(nullptr){}
    DLinkedNode(int _key,int _value): key(_key),value(_value),prev(nullptr),next(nullptr){}
};


class LRUCache {
private:
    unordered_map<int,DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;


public:
    LRUCache(int _capacity): capacity(_capacity),size(0) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!cache.count(key)){
            return -1;
        }
        //找到位置
        DLinkedNode* node = cache[key];
        //移动到头
        moveTohead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(!cache.count(key)){
            DLinkedNode* node = new DLinkedNode(key,value);
            cache[key] = node;
            addTohead(node);
            ++size;
            if(size > capacity){    //超出限制
                //删除尾节点
                DLinkedNode* removed = removeTail();
                //删除哈希表中的项
                cache.erase(removed->key);
                delete removed;
                --size;
            }
        }else{      //key存在
            DLinkedNode* node = cache[key];
            node->value = value;
            moveTohead(node);
        }

    }

    void moveTohead(DLinkedNode* node){
        removeNode(node);
        addTohead(node);
    }

    void removeNode(DLinkedNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addTohead(DLinkedNode* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    DLinkedNode* removeTail(){
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

