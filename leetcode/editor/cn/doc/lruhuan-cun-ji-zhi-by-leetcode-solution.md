### ðº è§é¢é¢è§£  

![146. LRUç¼å­æºå¶.mp4](42b5ca6a-4d69-4f7d-bf63-5c196aa23b44)

### ð æå­é¢è§£

#### åè¨

å®ç°æ¬é¢çä¸¤ç§æä½ï¼éè¦ç¨å°ä¸ä¸ªåå¸è¡¨åä¸ä¸ªååé¾è¡¨ãå¨é¢è¯ä¸­ï¼é¢è¯å®ä¸è¬ä¼ææè¯»èè½å¤èªå·±å®ç°ä¸ä¸ªç®åçååé¾è¡¨ï¼èä¸æ¯ä½¿ç¨è¯­è¨èªå¸¦çãå°è£å¥½çæ°æ®ç»æãå¨ `Python` è¯­è¨ä¸­ï¼æä¸ç§ç»åäºåå¸è¡¨ä¸ååé¾è¡¨çæ°æ®ç»æ `OrderedDict`ï¼åªéè¦ç­ç­çå è¡ä»£ç å°±å¯ä»¥å®ææ¬é¢ãå¨ `Java` è¯­è¨ä¸­ï¼åæ ·æç±»ä¼¼çæ°æ®ç»æ `LinkedHashMap`ãè¿äºåæ³é½ä¸ä¼ç¬¦åé¢è¯å®çè¦æ±ï¼å æ­¤ä¸é¢åªç»åºä½¿ç¨å°è£å¥½çæ°æ®ç»æå®ç°çä»£ç ï¼èä¸å¤åä»»ä½éè¿°ã

```Python [sol0-Python3]
class LRUCache(collections.OrderedDict):

    def __init__(self, capacity: int):
        super().__init__()
        self.capacity = capacity


    def get(self, key: int) -> int:
        if key not in self:
            return -1
        self.move_to_end(key)
        return self[key]

    def put(self, key: int, value: int) -> None:
        if key in self:
            self.move_to_end(key)
        self[key] = value
        if len(self) > self.capacity:
            self.popitem(last=False)
```

```Java [sol0-Java]
class LRUCache extends LinkedHashMap<Integer, Integer>{
    private int capacity;
    
    public LRUCache(int capacity) {
        super(capacity, 0.75F, true);
        this.capacity = capacity;
    }

    public int get(int key) {
        return super.getOrDefault(key, -1);
    }

    public void put(int key, int value) {
        super.put(key, value);
    }

    @Override
    protected boolean removeEldestEntry(Map.Entry<Integer, Integer> eldest) {
        return size() > capacity; 
    }
}
```

#### æ¹æ³ä¸ï¼åå¸è¡¨ + ååé¾è¡¨

**ç®æ³**

LRU ç¼å­æºå¶å¯ä»¥éè¿åå¸è¡¨è¾ä»¥ååé¾è¡¨å®ç°ï¼æä»¬ç¨ä¸ä¸ªåå¸è¡¨åä¸ä¸ªååé¾è¡¨ç»´æ¤ææå¨ç¼å­ä¸­çé®å¼å¯¹ã

- ååé¾è¡¨æç§è¢«ä½¿ç¨çé¡ºåºå­å¨äºè¿äºé®å¼å¯¹ï¼é è¿å¤´é¨çé®å¼å¯¹æ¯æè¿ä½¿ç¨çï¼èé è¿å°¾é¨çé®å¼å¯¹æ¯æä¹æªä½¿ç¨çã

- åå¸è¡¨å³ä¸ºæ®éçåå¸æ å°ï¼HashMapï¼ï¼éè¿ç¼å­æ°æ®çé®æ å°å°å¶å¨ååé¾è¡¨ä¸­çä½ç½®ã

è¿æ ·ä»¥æ¥ï¼æä»¬é¦åä½¿ç¨åå¸è¡¨è¿è¡å®ä½ï¼æ¾åºç¼å­é¡¹å¨ååé¾è¡¨ä¸­çä½ç½®ï¼éåå°å¶ç§»å¨å°ååé¾è¡¨çå¤´é¨ï¼å³å¯å¨ *O(1)* çæ¶é´åå®æ `get` æè `put` æä½ãå·ä½çæ¹æ³å¦ä¸ï¼

- å¯¹äº `get` æä½ï¼é¦åå¤æ­ `key` æ¯å¦å­å¨ï¼

   - å¦æ `key` ä¸å­å¨ï¼åè¿å *-1*ï¼

   - å¦æ `key` å­å¨ï¼å `key` å¯¹åºçèç¹æ¯æè¿è¢«ä½¿ç¨çèç¹ãéè¿åå¸è¡¨å®ä½å°è¯¥èç¹å¨ååé¾è¡¨ä¸­çä½ç½®ï¼å¹¶å°å¶ç§»å¨å°ååé¾è¡¨çå¤´é¨ï¼æåè¿åè¯¥èç¹çå¼ã

- å¯¹äº `put` æä½ï¼é¦åå¤æ­ `key` æ¯å¦å­å¨ï¼

   - å¦æ `key` ä¸å­å¨ï¼ä½¿ç¨ `key` å `value` åå»ºä¸ä¸ªæ°çèç¹ï¼å¨ååé¾è¡¨çå¤´é¨æ·»å è¯¥èç¹ï¼å¹¶å° `key` åè¯¥èç¹æ·»å è¿åå¸è¡¨ä¸­ãç¶åå¤æ­ååé¾è¡¨çèç¹æ°æ¯å¦è¶åºå®¹éï¼å¦æè¶åºå®¹éï¼åå é¤ååé¾è¡¨çå°¾é¨èç¹ï¼å¹¶å é¤åå¸è¡¨ä¸­å¯¹åºçé¡¹ï¼

   - å¦æ `key` å­å¨ï¼åä¸ `get` æä½ç±»ä¼¼ï¼åéè¿åå¸è¡¨å®ä½ï¼åå°å¯¹åºçèç¹çå¼æ´æ°ä¸º `value`ï¼å¹¶å°è¯¥èç¹ç§»å°ååé¾è¡¨çå¤´é¨ã

ä¸è¿°åé¡¹æä½ä¸­ï¼è®¿é®åå¸è¡¨çæ¶é´å¤æåº¦ä¸º *O(1)*ï¼å¨ååé¾è¡¨çå¤´é¨æ·»å èç¹ãå¨ååé¾è¡¨çå°¾é¨å é¤èç¹çå¤æåº¦ä¹ä¸º *O(1)*ãèå°ä¸ä¸ªèç¹ç§»å°ååé¾è¡¨çå¤´é¨ï¼å¯ä»¥åæãå é¤è¯¥èç¹ãåãå¨ååé¾è¡¨çå¤´é¨æ·»å èç¹ãä¸¤æ­¥æä½ï¼é½å¯ä»¥å¨ *O(1)* æ¶é´åå®æã

**å°è´´å£«**

å¨ååé¾è¡¨çå®ç°ä¸­ï¼ä½¿ç¨ä¸ä¸ª**ä¼ªå¤´é¨**ï¼dummy headï¼å**ä¼ªå°¾é¨**ï¼dummy tailï¼æ è®°çéï¼è¿æ ·å¨æ·»å èç¹åå é¤èç¹çæ¶åå°±ä¸éè¦æ£æ¥ç¸é»çèç¹æ¯å¦å­å¨ã

 ![fig1](https://assets.leetcode-cn.com/solution-static/146/1.PNG) ![fig2](https://assets.leetcode-cn.com/solution-static/146/2.PNG) ![fig3](https://assets.leetcode-cn.com/solution-static/146/3.PNG) ![fig4](https://assets.leetcode-cn.com/solution-static/146/4.PNG) ![fig5](https://assets.leetcode-cn.com/solution-static/146/5.PNG) ![fig6](https://assets.leetcode-cn.com/solution-static/146/6.PNG) ![fig7](https://assets.leetcode-cn.com/solution-static/146/7.PNG) ![fig8](https://assets.leetcode-cn.com/solution-static/146/8.PNG) ![fig9](https://assets.leetcode-cn.com/solution-static/146/9.PNG) ![fig10](https://assets.leetcode-cn.com/solution-static/146/10.PNG) 

```Python [sol1-Python3]
class DLinkedNode:
    def __init__(self, key=0, value=0):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None


class LRUCache:

    def __init__(self, capacity: int):
        self.cache = dict()
        # ä½¿ç¨ä¼ªå¤´é¨åä¼ªå°¾é¨èç¹    
        self.head = DLinkedNode()
        self.tail = DLinkedNode()
        self.head.next = self.tail
        self.tail.prev = self.head
        self.capacity = capacity
        self.size = 0

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        # å¦æ key å­å¨ï¼åéè¿åå¸è¡¨å®ä½ï¼åç§»å°å¤´é¨
        node = self.cache[key]
        self.moveToHead(node)
        return node.value

    def put(self, key: int, value: int) -> None:
        if key not in self.cache:
            # å¦æ key ä¸å­å¨ï¼åå»ºä¸ä¸ªæ°çèç¹
            node = DLinkedNode(key, value)
            # æ·»å è¿åå¸è¡¨
            self.cache[key] = node
            # æ·»å è³ååé¾è¡¨çå¤´é¨
            self.addToHead(node)
            self.size += 1
            if self.size > self.capacity:
                # å¦æè¶åºå®¹éï¼å é¤ååé¾è¡¨çå°¾é¨èç¹
                removed = self.removeTail()
                # å é¤åå¸è¡¨ä¸­å¯¹åºçé¡¹
                self.cache.pop(removed.key)
                self.size -= 1
        else:
            # å¦æ key å­å¨ï¼åéè¿åå¸è¡¨å®ä½ï¼åä¿®æ¹ valueï¼å¹¶ç§»å°å¤´é¨
            node = self.cache[key]
            node.value = value
            self.moveToHead(node)
    
    def addToHead(self, node):
        node.prev = self.head
        node.next = self.head.next
        self.head.next.prev = node
        self.head.next = node
    
    def removeNode(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev

    def moveToHead(self, node):
        self.removeNode(node)
        self.addToHead(node)

    def removeTail(self):
        node = self.tail.prev
        self.removeNode(node)
        return node
```

```Java [sol1-Java]
public class LRUCache {
    class DLinkedNode {
        int key;
        int value;
        DLinkedNode prev;
        DLinkedNode next;
        public DLinkedNode() {}
        public DLinkedNode(int _key, int _value) {key = _key; value = _value;}
    }

    private Map<Integer, DLinkedNode> cache = new HashMap<Integer, DLinkedNode>();
    private int size;
    private int capacity;
    private DLinkedNode head, tail;

    public LRUCache(int capacity) {
        this.size = 0;
        this.capacity = capacity;
        // ä½¿ç¨ä¼ªå¤´é¨åä¼ªå°¾é¨èç¹
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head.next = tail;
        tail.prev = head;
    }

    public int get(int key) {
        DLinkedNode node = cache.get(key);
        if (node == null) {
            return -1;
        }
        // å¦æ key å­å¨ï¼åéè¿åå¸è¡¨å®ä½ï¼åç§»å°å¤´é¨
        moveToHead(node);
        return node.value;
    }

    public void put(int key, int value) {
        DLinkedNode node = cache.get(key);
        if (node == null) {
            // å¦æ key ä¸å­å¨ï¼åå»ºä¸ä¸ªæ°çèç¹
            DLinkedNode newNode = new DLinkedNode(key, value);
            // æ·»å è¿åå¸è¡¨
            cache.put(key, newNode);
            // æ·»å è³ååé¾è¡¨çå¤´é¨
            addToHead(newNode);
            ++size;
            if (size > capacity) {
                // å¦æè¶åºå®¹éï¼å é¤ååé¾è¡¨çå°¾é¨èç¹
                DLinkedNode tail = removeTail();
                // å é¤åå¸è¡¨ä¸­å¯¹åºçé¡¹
                cache.remove(tail.key);
                --size;
            }
        }
        else {
            // å¦æ key å­å¨ï¼åéè¿åå¸è¡¨å®ä½ï¼åä¿®æ¹ valueï¼å¹¶ç§»å°å¤´é¨
            node.value = value;
            moveToHead(node);
        }
    }

    private void addToHead(DLinkedNode node) {
        node.prev = head;
        node.next = head.next;
        head.next.prev = node;
        head.next = node;
    }

    private void removeNode(DLinkedNode node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    private void moveToHead(DLinkedNode node) {
        removeNode(node);
        addToHead(node);
    }

    private DLinkedNode removeTail() {
        DLinkedNode res = tail.prev;
        removeNode(res);
        return res;
    }
}
```

```C++ [sol1-C++]
struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;

public:
    LRUCache(int _capacity): capacity(_capacity), size(0) {
        // ä½¿ç¨ä¼ªå¤´é¨åä¼ªå°¾é¨èç¹
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        // å¦æ key å­å¨ï¼åéè¿åå¸è¡¨å®ä½ï¼åç§»å°å¤´é¨
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (!cache.count(key)) {
            // å¦æ key ä¸å­å¨ï¼åå»ºä¸ä¸ªæ°çèç¹
            DLinkedNode* node = new DLinkedNode(key, value);
            // æ·»å è¿åå¸è¡¨
            cache[key] = node;
            // æ·»å è³ååé¾è¡¨çå¤´é¨
            addToHead(node);
            ++size;
            if (size > capacity) {
                // å¦æè¶åºå®¹éï¼å é¤ååé¾è¡¨çå°¾é¨èç¹
                DLinkedNode* removed = removeTail();
                // å é¤åå¸è¡¨ä¸­å¯¹åºçé¡¹
                cache.erase(removed->key);
                // é²æ­¢åå­æ³æ¼
                delete removed;
                --size;
            }
        }
        else {
            // å¦æ key å­å¨ï¼åéè¿åå¸è¡¨å®ä½ï¼åä¿®æ¹ valueï¼å¹¶ç§»å°å¤´é¨
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    
    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};
```

```golang [sol1-Golang]
type LRUCache struct {
    size int
    capacity int
    cache map[int]*DLinkedNode
    head, tail *DLinkedNode
}

type DLinkedNode struct {
    key, value int
    prev, next *DLinkedNode
}

func initDLinkedNode(key, value int) *DLinkedNode {
    return &DLinkedNode{
        key: key,
        value: value,
    }
}

func Constructor(capacity int) LRUCache {
    l := LRUCache{
        cache: map[int]*DLinkedNode{},
        head: initDLinkedNode(0, 0),
        tail: initDLinkedNode(0, 0),
        capacity: capacity,
    }
    l.head.next = l.tail
    l.tail.prev = l.head
    return l
}

func (this *LRUCache) Get(key int) int {
    if _, ok := this.cache[key]; !ok {
        return -1
    }
    node := this.cache[key]
    this.moveToHead(node)
    return node.value
}


func (this *LRUCache) Put(key int, value int)  {
    if _, ok := this.cache[key]; !ok {
        node := initDLinkedNode(key, value)
        this.cache[key] = node
        this.addToHead(node)
        this.size++
        if this.size > this.capacity {
            removed := this.removeTail()
            delete(this.cache, removed.key)
            this.size--
        }
    } else {
        node := this.cache[key]
        node.value = value
        this.moveToHead(node)
    }
}

func (this *LRUCache) addToHead(node *DLinkedNode) {
    node.prev = this.head
    node.next = this.head.next
    this.head.next.prev = node
    this.head.next = node
}

func (this *LRUCache) removeNode(node *DLinkedNode) {
    node.prev.next = node.next
    node.next.prev = node.prev
}

func (this *LRUCache) moveToHead(node *DLinkedNode) {
    this.removeNode(node)
    this.addToHead(node)
}

func (this *LRUCache) removeTail() *DLinkedNode {
    node := this.tail.prev
    this.removeNode(node)
    return node
}
```

**å¤æåº¦åæ**

* æ¶é´å¤æåº¦ï¼å¯¹äº `put` å `get` é½æ¯ *O(1)*ã

* ç©ºé´å¤æåº¦ï¼![O(\text{capacity}) ](./p__O_text{capacity}__.png) ï¼å ä¸ºåå¸è¡¨åååé¾è¡¨æå¤å­å¨ ![\text{capacity}+1 ](./p__text{capacity}_+_1_.png)  ä¸ªåç´ ã