var BiNode = function(key, value, prev=null, next=null) {
    this.key = key;
    this.value = value;
    this.prev = prev;
    this.next = next;
};

/**
 * @constructor
 */
var LRUCache = function(capacity) {
    this.map = new Map();
    this.capacity = capacity;
    this.cacheHead = new BiNode();
    this.cacheTail = new BiNode();
    this.cacheHead.next = this.cacheTail;
    this.cacheTail.prev = this.cacheHead;
    this.count = 0;
};

/**
 * @param  {BiNode} node
 */
LRUCache.prototype.updateNode = function(node) {
    if (node.prev) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }
    node.next = this.cacheHead.next;
    node.prev = this.cacheHead;
    this.cacheHead.next.prev = node;
    this.cacheHead.next = node;
    return node;
};

/**
 * @param {number} key
 * @returns {number}
 */
LRUCache.prototype.get = function(key) {
    let node = this.map.get(key);
    if (!node) return -1;
    return this.updateNode(node).value;
};

/**
 * @param {number} key
 * @param {number} value
 * @returns {void}
 */
LRUCache.prototype.set = function(key, value) {
    if (this.capacity <= 0) return;

    let map = this.map;
    let node = map.get(key);
    if (!node) {
        if (this.count >= this.capacity) {
            let tailPP = this.cacheTail.prev.prev;
            map.delete(tailPP.next.key); 
            tailPP.next = this.cacheTail;
            this.cacheTail.prev = tailPP;
            this.count--; 
        }
        node = new BiNode(key, value); 
        map.set(key, node);
        this.updateNode(node);
        this.count++;
    } else {
        node.value = value;
        this.updateNode(node);
    }
};


var l = console.log.bind(console);


var lru = new LRUCache(2);

lru.set(2, 1);
lru.set(2, 2);

l(lru.get(2));

lru.set(1, 1);
lru.set(4, 1);
l(lru.get(2));

