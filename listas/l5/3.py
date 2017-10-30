# two cards i and j are equivalent if their bank accounts are the same

def test(cards, maj, size_2):
    count = 0
    for card in cards: 
        if maj[1] == card[1]:
            count += 1
        if count > size_2:
            return maj
    return -1


def f(card_set):
    if len(card_set) == 1:
        return card_set[0]
    if len(card_set) == 2:
        if card_set[0][1] == card_set[1][1]:
            return card_set[0]
        else:
            return -1

    size_2 = len(card_set) // 2
    first_half = card_set[:size_2]
    second_half = card_set[size_2:]

    majority_card = -1 
    maj = f(first_half)

    if maj != -1:
        majority_card = test(card_set, maj, size_2)
    else:
        maj = f(second_half)
        if maj != -1:
            majority_card = test(card_set, maj, size_2)

    return majority_card

# pair of <card id, equivalence id>

# set of cards that has a group of n/2 cards that are equivalent
true_cards = [[0,1], [1,7], [2,1], [3,2], [4,1], [5,4], [6,1] ,[7,1], [8,1], [9,2]]

# set of cards that does not have a group of n/2 cards that are equivalent
false_cards = [[0,1], [1,2], [2,3], [3,4], [4,5], [5,6], [6,7] ,[7,8], [8,9], [9,10]]

res = f(true_cards)

print(true_cards)
if res == -1:
    print('There is no set of more than n/2 cards that are equivalent')
else:
    print('Cards with equivalence class {} have a set of more than n/2 cards'.format(res[1]))

print()
print(false_cards)
res = f(true_cards)

if res == -1:
    print('There is no set of more than n/2 cards that are equivalent')
else:
    print('Cards with bank account {} have a set of more than n/2 cards'.format(res[1]))
