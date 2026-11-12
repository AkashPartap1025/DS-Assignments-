import heapq

def dijkstra(graph, start):

    distances = {
        node: float('inf')
        for node in graph
    }

    distances[start] = 0
    pq = [(0, start)]

    while pq:
        current_distance, current_node = heapq.heappop(pq)

        if current_distance > distances[current_node]:
            continue

        for neighbor, weight in graph[current_node]:
            distance = current_distance + weight

            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(
                    pq,
                    (distance, neighbor)
                )

    return distances


graph = {
    'A': [('B', 4), ('C', 1)],
    'B': [('D', 2)],
    'C': [('B', 2), ('D', 5)],
    'D': []
}

result = dijkstra(graph, 'A')
for node, dist in result.items():
    print(f"{node} : {dist}")