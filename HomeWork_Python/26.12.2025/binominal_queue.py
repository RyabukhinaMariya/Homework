import math


class Node:
    def __init__(self, key, priority):
        self.key = key
        self.priority = priority
        self.parent = None
        self.child = None  # левый дочерний узел
        self.sibling = None  # правый дочерний узел
        self.degre = 0

class Bin_heap:  
    def __init__(self):
        self.head = None
    
    def is_empty(self):
        return self.head is None
    
    def insert(self, key, priority):
        new_heap = Bin_heap()
        new_node = Node(key, priority)
        new_heap.head = new_node
        self.union(new_heap)
    
    def get_min(self):
        if self.is_empty():
            return None
        
        min_node = self.find_min_node()
        return (min_node.key, min_node.priority)
    
    def extract_min(self):
        if self.is_empty():
            return None
        
        min_node, prev_node = self.find_min_node()
        
        if prev_node is None:
            self.head = min_node.sibling
        else:
            prev_node.sibling = min_node.sibling
        
        reversed_children = self.reverse_list(min_node.child)
        child_heap = Bin_heap()
        child_heap.head = reversed_children
        
        self.union(child_heap)
        
        return (min_node.key, min_node.priority)
    
    def decrease_key(self, node, new_priority):    
        node.priority = new_priority
        self.up(node)
    
    def delete(self, node):
        self.decrease_key(node, -math.inf)
        self.extract_min()
    
    def merge(self, other):
        self.union(other)
    
    def union(self, other):
        new_head = self.merge_root_lists(self.head, other.head)
        if new_head is None:
            self.head = None
            return
        
        prev = None
        current = new_head
        next_node = current.sibling
        
        while next_node is not None:
            if (current.degree != next_node.degree or 
                (next_node.sibling is not None and 
                 next_node.sibling.degree == current.degree)):
                prev = current
                current = next_node
            elif current.priority <= next_node.priority:
                current.sibling = next_node.sibling
                self.link_trees(next_node, current)
            else:
                if prev is None:
                    new_head = next_node
                else:
                    prev.sibling = next_node
                self.link_trees(current, next_node)
                current = next_node
            
            next_node = current.sibling
        
        self.head = new_head
    
    def merge_root_lists(self, h1, h2):
        dummy = Node(None, -1)
        tail = dummy
        
        while h1 is not None and h2 is not None:
            if h1.degree <= h2.degree:
                tail.sibling = h1
                h1 = h1.sibling
            else:
                tail.sibling = h2
                h2 = h2.sibling
            tail = tail.sibling
        
        tail.sibling = h1 if h1 is not None else h2
        
        return dummy.sibling
    
    def link_trees(self, child, parent):
        child.parent = parent
        child.sibling = parent.child
        parent.child = child
        parent.degree += 1
    
    
    def find_min_node(self):
        if self.is_empty():
            raise ValueError("heap is epty")
        
        min_node = self.head
        prev_node = None
        prev_min = None
        
        current = self.head
        prev = None
        
        while current is not None:
            if current.priority < min_node.priority:
                min_node = current
                prev_min = prev
            prev = current
            current = current.sibling
        
        return min_node, prev_min
    
    def reverse_list(self, head):
        prev = None
        current = head
        
        while current is not None:
            next_node = current.sibling
            current.sibling = prev
            current.parent = None  
            prev = current
            current = next_node
        
        return prev
    
    def up(self, node):
        parent = node.parent
        
        while parent is not None and node.priority < parent.priority:
            node.key, parent.key = parent.key, node.key
            node.priority, parent.priority = parent.priority, node.priority
            
            node = parent
            parent = node.parent
