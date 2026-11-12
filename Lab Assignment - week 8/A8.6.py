import heapq

pq = []

heapq.heappush(pq, 30)  # Insert Elements
heapq.heappush(pq, 10)
heapq.heappush(pq, 50)
heapq.heappush(pq, 20)

print("Priority Queue:")
print(pq)

print("Top Element:", pq[0])  # Peek Minimum Element

print("Removed:", heapq.heappop(pq))  # Delete Highest Priority (Smallest)

print("After Deletion:")
print(pq)