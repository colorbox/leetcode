/*
Time : O(N)
Space : O(1)

LRUを応用してできるとのことだったので実装。
https://www.geeksforgeeks.org/lru-cache-implementation-using-double-linked-lists/
本質的に平衡木による解法と大差ない気がする。
*/
struct Node {
  int index;
  int count;
  Node* prev;
  Node* next;

  explicit Node(int i) {
    index = i;
    count = 1;
    prev = nullptr;
    next = nullptr;
  }
};

class LRUCache {
 public:
  Node* head;
  Node* tail;
  map<char, Node*> character_to_node;

  LRUCache() {
    head = new Node(numeric_limits<int>::max());
    tail = new Node(numeric_limits<int>::max());
    head->next = tail;
    tail->prev = head;
  }

  ~LRUCache() {
    for (auto [_c, node] : character_to_node) {
      delete node;
    }
    delete head;
    delete tail;
  }

  void Put(char character, int index) {
    if (character_to_node.contains(character)) {
      Node *node = character_to_node[character];
      Remove(node);
      node->count++;
      return;
    }

    Node *node = new Node(index);
    character_to_node[character] = node;
    PushBack(node);
  }

  bool Empty() {
    return head->next->index == tail->index;
  }

 private:
  void Remove(Node* node) {
    if (node->prev == nullptr) {
      return;
    }
    Node* prev = node->prev;
    Node* next = node->next;
    prev->next = next;
    next->prev = prev;
    node->prev = nullptr;
    node->next = nullptr;
  }

  void PushBack(Node* node) {
    Node* prev = tail->prev;
    prev->next = node;
    node->prev = prev;
    node->next = tail;
    tail->prev = node;
  }
};

class Solution {
 public:
  int firstUniqChar(string s) {
    LRUCache cache = LRUCache();
    for (int i = 0; i < s.size(); i++) {
      cache.Put(s[i], i);
    }
    if (cache.Empty() || cache.head->next->count > 1) {
      return -1;
    }
    return cache.head->next->index;
  }
};

