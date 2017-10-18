# coll2-lab
More Collective Communications lab


### Textbook Exercise 3.11
```
A: The alogrithm would be a for loop looping through the array of size n, adding each number to a prefixSum number and then printing it out.
prefixSum = 0;
for(i = 0; i < n; i++)
{
  prefixSum += array[i]
  print(prefixSum)
}

B: For parallelizing the algorithm instead of their being a for loop every process would just send its curent prefix sum forward while waiting for one.
i = 0;
print(array[0])
while(i < n-1)
if(i == rank)
  MPI_send x to i+1
else if(i+1 == rank)
  MPI_recieve(newX)
  x += newX
  print(x)
  MPI barrier //Wait to make sure every process is kept together
  
C: In this algorithm we would devide the number of numbers (n) by the number of processors (even number) and each time we enter a k communication phase it passes the current prefix sum and adds together the preivious numbers.
ex:
n = 8, 4 processors, n = 2^3 so three comm phases max
1 2    3 4    5 6    7 8
add the cur prefix from yourself
1 3    3 7    5 11   7 15
first comm phase
send proc 0 prefix sum to proc 1 and proc 2 prefix sum to proc 3
1 3    6 10 || 5 11  18 26
So now the first half of the array has its correct prefix sums and the second half will get it next
Second comm phase send proc 1 prefix sum to proc 2 and 3 which have been condensed into one. So you just add proc 1's prefix sum to the remaining numbers 
1 3    6 10     15 21    28 36
There we have the total prefix sum implementation and it only took 2 communication phases! 

D:




