class LRUCache:

    class Node:
        def __init__(self, k, v):
            self.key = k
            self.val = v
            self.next = None
            self.prev = None

    def __init__(self, capacity: int):
        self.limit = capacity
        self.mp = {}
        self.head = self.Node(-1,-1)
        self.tail = self.Node(-1,-1)
        self.head.next = self.tail
        self.tail.prev = self.head

    def addNode(self, node) -> None:
        nextNode = self.head.next
        self.head.next = node
        node.prev = self.head
        node.next = nextNode
        nextNode.prev = node
    
    def deleteNode(self, node) -> None:
        prevNode = node.prev
        nextNode = node.next
        prevNode.next = nextNode
        nextNode.prev = prevNode

    def get(self, key: int) -> int:
        if key not in self.mp:
            return -1
        node = self.mp[key]
        self.deleteNode(node)
        self.addNode(node)
        return node.val

    def put(self, key: int, value: int) -> None:
        if key in self.mp:
            node = self.mp[key]
            self.deleteNode(node)
            del self.mp[key]
        if len(self.mp) == self.limit:
            node = self.tail.prev
            del self.mp[node.key]
            self.deleteNode(node)
        newNode = self.Node(key, value)
        self.addNode(newNode)
        self.mp[key] = newNode


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)