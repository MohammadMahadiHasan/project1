import heapq
from collections import defaultdict

class HuffmanNode:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq

def huffman_coding(data, frequencies):
    heap = []
    for char, freq in zip(data, frequencies):
        heap.append(HuffmanNode(char, freq))
    
    heapq.heapify(heap)
    
    while len(heap) > 1:
        node1 = heapq.heappop(heap)
        node2 = heapq.heappop(heap)
        
        merged = HuffmanNode(None, node1.freq + node2.freq)
        merged.left = node1
        merged.right = node2
        
        heapq.heappush(heap, merged)
    
    root = heap[0]
    
    codes = {}
    def generate_codes(node, code):
        if node is None:
            return
        
        if node.char is not None:
            codes[node.char] = code
            return
        
        generate_codes(node.left, code + "0")
        generate_codes(node.right, code + "1")
    
    generate_codes(root, "")
    return codes

def main():
    data = input("Enter the characters: ").strip().split()
    frequencies = list(map(int, input("Enter the frequencies: ").strip().split()))
    
    codes = huffman_coding(data, frequencies)
    for char, code in codes.items():
        print(f"{char}: {code}")

if __name__ == "__main__":
    main()
