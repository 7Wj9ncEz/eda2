INF = 2**25
text = ['Call','me','Ishmael.',
        'Some','years','ago',
        'never', 'mind', 'how', 'long', 'precisely,',
        'having', 'little', 'or', 'no', 'money', 'in', 'my', 'purse,',
        'and', 'nothing', 'particular', 'to', 'interest', 'me', 'on', 'shore,',
        'I' 'thought', 'I', 'would', 'sail', 'about', 'a', 'little',
        'and', 'see', 'the', 'watery', 'part', 'of', 'the', 'world.'
        ]
n = len(text)
L = 40

def pretty_print():
    s = [[INF for i in range(n)] for j in range(n)]

    for i in range(n):
        for j in range(i+1, n):
            line_length = 0
            for k in range(i,j+1):
                line_length += len(text[k])
            s[i][j] = line_length if line_length <= L else INF

    opt = [INF for i in range(n)]
    opt[0] = 0

    for k in range(n):
        for j in range(k+1):
            opt[k] = min(opt[k], s[j][k] ** 2 + opt[j-1])

    return opt[n-1]

print(pretty_print())
