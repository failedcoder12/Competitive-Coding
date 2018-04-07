 # https://www.codechef.com/APRIL18B/problems/WGHTNUM

    def power(x, y, p) :
        res = 1 
        x = x % p 
        while (y > 0) :
             
            if ((y & 1) == 1) :
                res = (res * x) % p
            y = y >> 1  
            x = (x * x) % p
        return res
        
    t = input()
    for l in range(t):
        number,weight = map(int, raw_input().split())
        count = 0
        for i in range(1,10):
            for j in range(0,10):
                if(weight == j-i):
                    count = count+1
        
        count = count*power(10,number-2,1000000007)
        print(count%1000000007) 