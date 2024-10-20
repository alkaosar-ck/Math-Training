from collections import defaultdict

for _ in range(int(input())):
    x = int(input())
    l = list(map(int, input().split()))
    
    count_map = defaultdict(int)
    
    for i in range(x):
        b_i = l[i] - (i + 1)
        count_map[b_i] += 1  
    
    total_pairs = 0
    
    for count in count_map.values():
        if count > 1:
            total_pairs += count * (count - 1) // 2
    
    print(total_pairs)
