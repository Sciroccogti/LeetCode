# 寒假每日一题（入门组）0118

def flip(coins: str, pos: int) -> str:
    if pos > len(coins) - 2:
        print("Error!")
    ret = coins[:pos]
    if coins[pos] == '*':
        ret += 'o'
    else:
        ret += '*'
    if coins[pos+1] == '*':
        ret += 'o'
    else:
        ret += '*'
    if pos < len(coins) - 1:
        ret += coins[pos+2:]
    return ret


init = input()
goal = input()

coins = init
length = len(coins)

count = 0
while coins != goal:
    i = 0
    while coins[i] == goal[i]:
        i += 1
    coins = flip(coins, i)
    count += 1
print(count)
