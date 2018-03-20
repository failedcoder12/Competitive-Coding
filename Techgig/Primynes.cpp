// https://www.techgig.com/challenge/question/coding-challenge-easy/a1BRUlNTWEM3Y3UydXJzN1QvQzZCZndheDlhQ1kvdklPSkdkb1Bld1hHTFkxNzVRUmNHdm5Da0tZdzdKQVR0ZA==/1#

// Primyness Of Strings (100 Marks)
// Ritik has been closely associated with the String Organization.It keeps producing strings at a very fast rate.But they are facing a problem regarding Primyness of strings so they have appointed him as the Coordinator.
// Primyness of the String S is given as the number of subsequences of length <=6 of the String whose concatenation of digits forms a prime number.Since you are a close friend of Ritik. Help him in solving this mammoth task. 

// Input Format
// First line of input contains a String S consisting of digits (1-9).



// Constraints
// 1<= |S| <=19

// Output Format
// You must print an Integer denoting the answer to the problem.
// Sample TestCase 1
// Input

// 123

// Output

// 4

// Explanation

// The possible subsequences of 123 are 1,2,3,12,13,23,123.
// Out of these 2,3,13,23 are prime numbers.
// Hence, the answer is 4.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool prime[10000000];
void SieveOfEratosthenes(ll number)
{
    for (ll p=2; p*p<=number; p++)
    {
        if (prime[p])
        {
            for (ll i=p*2; i<=number; i += p)
                prime[i] = false;
        }
    }
}
int main() {
    memset(prime, true, sizeof(prime));
    SieveOfEratosthenes(10000000);
    string s;
    cin>>s;
    ll a[s.length()];
    for(ll i=0;i<s.length();i++){
        a[i] = s[i] - '0';
    }
    ll n = sizeof(a) / sizeof(a[0]);
    ll ans = 0;
    for (ll i = 1; i < 1 << n; i++) {
        ll m = 0;
        ll p=0;
        ll temp = i;
        ll j = 0;
        while (temp) {
            if (temp & 1)
            {
                p++;
                if(p>6){
                    goto cc;
                }
                m = m*10 + a[j];
            }
            temp >>= 1;
            j++;
        }
        if(prime[m] && m!=1){
            ans++;
        }
        cc:
        ll o = 0;
    }
    cout<<ans<<endl;
}