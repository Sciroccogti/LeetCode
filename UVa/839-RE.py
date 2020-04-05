def myindex(mobile: list) -> int:
    "myindex!"
    if mobile[0] == 0:
        return 0
    elif mobile[2] == 0:
        return 2
    else:
        return -1


n = int(input())

while n > 0:
    input()  # read in \n
    mobiles = []
    zero = 0
    first = True
    is_balance = True

    while zero != 0 or first:
        first = False
        Wl, Dl, Wr, Dr = [int(i) for i in input().split()]

        if Wl == 0 or Wr == 0:  # parent mobile
            zero += 1
            if Wl == 0 and Wr == 0:
                zero += 1
            mobiles.append([Wl, Dl, Wr, Dr])
        else:  # child mobile
            if zero > 0:  # not root
                zero -= 1
                # calculate the parent of this child
                mobiles[-1][mobiles[-1].index(0)] = Wl + Wr
                while True:  # iterate
                    if myindex(mobiles[-1]) == -1:  # current parent is done
                        if mobiles[-1][0] * mobiles[-1][1] != mobiles[-1][2] * mobiles[-1][3]:  # imbalance
                            is_balance = False
                        weight = mobiles[-1][0] + mobiles[-1][2]
                        mobiles.pop(-1)
                        if len(mobiles) == 0:  # no more balance
                            break
                        else:
                            mobiles[-1][mobiles[-1].index(0)] = weight
                            zero -= 1
                    else:
                        break
                else:  # root
                    break

    if is_balance:
        print("YES")
    else:
        print("NO")
    n -= 1
    print("\n")
