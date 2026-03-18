def main():
    try:
        N, K = map(int, input("N, K: ").split())
    except:
        print("Zov too oruulna uu!")
        return

    # N, K шалгах
    if N < 1 or N > 100000:
        print("N n 1-ees 100000 baih ystoi!")
        return

    if K < 0 or K > N:
        print("K n 0-ees N hurtel baih ystoi!")
        return

    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    # 1. D массив үүсгэх
    D = [B[i] - A[i] for i in range(N)]

    # 2. D-г эрэмбэлээд X (median) олох
    D.sort()
    X = D[N // 2]

    # 3. |D[i] - X| ялгааг олох
    diff = [abs(D[i] - X) for i in range(N)]

    # 4. diff-г буурахаар эрэмбэлээд K-г хасах
    diff.sort(reverse=True)

    result = sum(diff[K:])

    print("Ylgaatai baidal:", result)


if __name__ == "__main__":
    main()
