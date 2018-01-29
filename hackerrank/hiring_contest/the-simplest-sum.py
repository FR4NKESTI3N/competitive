from math import *

def calc(n, k):
    return(int((log(n*(k-1) + 1))/log(k)))

def calc_inv(N, k):
    return(int((k**N - 1)/(k-1)))

def func(k, n):
    return((((k*((k**n) - 1))/(k-1)) - n)/(k-1))

def main():
    q = input()
    for a0 in range(q):
        sum = 0
        k, a, b = map(int,(raw_input().strip()).split(' '))
        A = calc(a, k)
        B = calc(b, k)
        while (A < B):
            pnt = calc_inv(A+1, k);
            sum += func(k, A)*(pnt - a)
            if (sum >= 1000000007):
                sum%=1000000007
            A+= 1
            a = pnt
        sum+=func(k, B)*(b-a+1)
        if (sum >= 1000000007):
            sum%=1000000007
        print sum
    return(0)

if __name__ == "__main__":
    main()
