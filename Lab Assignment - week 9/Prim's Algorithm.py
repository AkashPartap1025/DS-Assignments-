import heapq

def prim(graph, start):

    visited = set()
    min_heap = [(0, start)]
    total_cost = 0

    while min_heap:

        weight, node = heapq.heappop(min_heap)

        if node in visited:
            continue

        visited.add(node)
        total_cost += weight

        for neighbor, edge_weight in graph[node]:

            if neighbor not in visited:
                heapq.heappush(
                    min_heap,
                    (edge_weight, neighbor)
                )

    return total_cost


graph = {
    0: [(1, 10), (2, 6), (3, 5)],
    1: [(0, 10), (3, 15)],
    2: [(0, 6), (3, 4)],
    3: [(0, 5), (1, 15), (2, 4)]
}

print(" MST Cost:", prim(graph, 0))