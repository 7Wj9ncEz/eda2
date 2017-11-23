# considering a simple graph where two adjacent elements in list are connected

def f(n):
    if n == -1:
        return 0
    # if there is only first item, return its weight
    if n == 0:
        return weights[0]

    # get maximum between not choosing weights[i] (thus getting f(i-1) + 0)
    #       and choosing weights[i] (thus adding weights[i] with f(i-2) --> because you have to skip its neighbor)
    return max(f(n-1), weights[n] + f(n-2))

global weights
weights = [4,2,5,2]

print('Maximum weight of {} is {}'.format(weights, f(len(weights) - 1)))
