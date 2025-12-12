class BinomialNode:
    def __init__(self, key, value=None):
        self.key = key
        self.value = value
        self.degree = 0
        self.parent = None
        self.child = None
        self.sibling = None
    
    def get_children_list(self):
        children = []
        child = self.child
        while child:
            children.append(child)
            child = child.sibling
        return children


class BinomialHeap:
    
    def _link(self, node1, node2):
        if node1.key < node2.key:
            node1, node2 = node2, node1
        
        node2.parent = node1
        node2.sibling = node1.child
        node1.child = node2
        node1.degree += 1
        return node1
    
    def _union(self, head1, head2):
        dummy = BinomialNode(-float('inf'))
        current = dummy
        
        while head1 and head2:
            if head1.degree <= head2.degree:
                current.sibling = head1
                head1 = head1.sibling
            else:
                current.sibling = head2
                head2 = head2.sibling
            current = current.sibling
        
        current.sibling = head1 if head1 else head2
        
        return self._consolidate(dummy.sibling)
    
    def insert(self, key, value=None):
        node = BinomialNode(key, value)
        self.head = self._union(self.head, node)
      
