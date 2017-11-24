x = [10, 1, 7, 7]
s = [8, 4, 2, 1]
n = len(x)

def solve():
    # opt = [ min(x[n-1], s[j]) for j in range(n) ]
    opt = [[0 for i in range(n)] for j in range(n)]

    for j in range(n):
        opt[n-1][j] = min(x[n-1], s[j])

    for i in reversed(range(n-1)):
        for j in range(i+1):
            opt[i][j] = max(
                            opt[i+1][0], # nothing is processed on day i
                            min(x[i], s[j]) + opt[i+1][j+1] # process min(x[i], s[j])
                        )

    return opt[0][0]

print('Maximun number of terabytes processed is {}'.format(solve()))
