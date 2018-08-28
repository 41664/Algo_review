#include<iostream>
#include<cstring> //Fir the memset function
using namespace std;
/* https://www.geeksforgeeks.org/sieve-of-eratosthenes/
An alorithm to find all prime numbers smaller than n
The steps taken in the algorithm are as follows
 1. Take all numbers below from 2 to n
 2. Don't mark 2 but mark every number divisible by 2 like 2,4,6,8, etc. Some numbers might already have been marked
 3. Find the first number greater than p in the list that is not marked. If there was no such number, stop.
 The prime numbers are the numbers that are not marked
*/
void Seive(int n)
{
  bool prime[n+1]; //an array to mark all numbers from 2 to n
  memset(prime,true,sizeof(prime)); //sets all elements as true prime
  for(int i=2;i*i<=n;i++) //we will mark only elements upto sqrt(n)
  {
    if(prime[i]==true) //If the number is marked as prime
    {
      for(int j=i*2;j<=n;j+=i) //starts from second multiple upto max multiple possible in the set
      {
        prime[j]=false; //set them as not prime
      }
    }
  }
  for(int i=2;i<=n;i++) {
      if(prime[i]==true)
      {
        cout<<i<<endl; //outputs only those numbers which are marked as true in the above mentioned array
      }
  }
}
int main()
{
      int n=1000;
      Seive(n);
}
