var Node = function(value) {
    this.value = value;
    this.prev = null;
    this.next = null;
};

/**
 * @constructor
 */
var LRUCache = function(capacity) {
    this.map = new Map();
    this.capacity = capacity;
    this.cacheHead = new Node();
    this.cacheTail = new Node();
    this.cacheHead.next = this.cacheTail;
    this.count = 0;
};

/**
 * @param  {Node} node
 */
LRUCache.prototype.updateNode = function(node) {
    if (node.prev) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }
    let prevHead = this.cacheHead.next;
    node.next = prevHead;
    prevHead.prev = node;
    prevHead = node;
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
    if (this.capacity == 0) return;

    let map = this.map;
    if (!map.has(key)) {
        if (this.count >= this.capacity) {
            let tailPP = this.cacheTail.prev.prev; 
            tailPP.next = this.cacheTail;
            this.cacheTail.prev = tailPP;
            this.count--; 
        }
        let node = new Node(value); 
        map.set(key, node);
        this.updateNode(node);
        this.count++;
    } else {
        this.updateNode(map.get(key));
    }
};


var l = console.log.bind(console);

var lru = new LRUCache(3);
lru.set(1, 1);
l(lru.get(1));
lru.set(2, 2);
lru.set(3, 3);
lru.set(4, 4);
l(lru.get(3));
l(lru.get(2));