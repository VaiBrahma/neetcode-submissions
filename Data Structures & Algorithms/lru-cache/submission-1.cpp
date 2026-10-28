
class ListNode {
public:
    int key;
    int val;
    ListNode* next;
    ListNode* prev;

    ListNode(int key, int val) {
        this->key = key;
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class LRUCache {
private:
    int cap;
    unordered_map<int, ListNode*> mp;
    ListNode* head;
    ListNode* tail;

    void moveToHead(ListNode* node) {
        if (node == head) return;

        ListNode* n1 = node->prev;
        ListNode* n2 = node->next;

        if (!n2) {
            tail = n1;
        } else {
            n2->prev = n1;
        }

        n1->next = n2;

        node->prev = nullptr;
        node->next = head;
        head->prev = node;
        head = node;
    }

    void insert(int key, int val) {
        ListNode* newNode = new ListNode(key, val);
        newNode->next = head;

        if (head) head->prev = newNode;
        head = newNode;

        if (!tail) tail = head;

        mp[key] = newNode;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = nullptr;
        tail = nullptr;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            moveToHead(mp[key]);
            return mp[key]->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            moveToHead(mp[key]);
            mp[key]->val = value;
            return;
        }

        if (cap == 0) return;

        if (mp.size() < cap) {
            insert(key, value);
            return;
        }

        ListNode* temp = tail;
        tail = tail->prev;

        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }

        mp.erase(temp->key);
        delete temp;

        insert(key, value);
    }
};
