def solve():
    n = int(input())
    k = int(input())
    a = list(map(int, input().split()))

    mini = {}
    maxi = {}

    for i in range(n):
        if a[i] not in mini or mini[a[i]] == 0:
            mini[a[i]] = i + 1
        else:
            mini[a[i]] = min(mini[a[i]], i + 1)

        if a[i] not in maxi or maxi[a[i]] == 0:
            maxi[a[i]] = i + 1
        else:
            maxi[a[i]] = max(maxi[a[i]], i + 1)

    v = []

    for i in range(k, 0, -1):
        if i not in mini or mini[i] == 0:
            pass
        elif i == k:
            pass
        else:
            if i + 1 in mini and mini[i + 1] != 0:
                maxi[i] = max(maxi[i], maxi[i + 1])
            if i + 1 in mini and mini[i + 1] != 0:
                mini[i] = min(mini[i], mini[i + 1])

        if i in mini and mini[i] != 0:
            v.append(2 * (maxi[i] - mini[i] + 1))
        else:
            if i != k:
                maxi[i] = maxi[i + 1]
            v.append(0)
            if i != k:
                mini[i] = mini[i + 1]

    v.reverse()

    for val in v:
        print(val, end=" ")
    print()


def main():
    t = int(input())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
