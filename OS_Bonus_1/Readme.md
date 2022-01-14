Instruction to Run and Compile-
1) Use the make command to compile all the programs
2) Run ./bonus1 to run the unmodified dining philosopher's problem
3) There is no deadlock in the second case, the explanation for the same is mentioned below.
4) Run ./bonus3 to run the modified dining philosopher's problem

Logic Used - 
1) SCENARIO 1
 In the first version of the problem, we use binary semaphores to synchronize the eating of food. An array of 5 forks is constructed.
These forks are semaphores, whenever a thread holds the semaphore, that means it holds a fork.
The philosophers are modeled as threads or diners ranging from 0 to 4.
Philosopher "i" can only hold the fork numbers i or (i+1)mod 5.
Once a philosopher acquires 2 forks, the philosopher can eat in the bowl for some time. After which he has to return the semaphore.
AVOIDING DEADLOCK - we avoid deadlock by switching the order of picking forks for just one philosopher.
Deadlock only occurs in the case when each philosopher is holding just 1 fork, and nobody is able to eat.
We avoid this case by making philosopher 1 pick up the forks in the reverse order.
 In this way when all philosophers have one fork except philosopher 1, it won't be able to pick up the remaining fork, as it is picking up in reverse order.
 Thus one fork will be left, and deadlock will be avoided.

2)SCENARIO 2
In this case NO deadlock will be present, as philosophers only need one fork to eat and one bowl to eat from.
A deadlock can only arise when all of the philosophers are thinking, and none of them are able to eat.
Since in this case our philosophers have sufficient forks i.e 5, there will always be atleast one philosopher who is eating.

In the worst case scenario atleast 3 philosophers will have the forks according to the distribution - 2+2+1
and the remaining philosophers would have 2 soup bowls
Even in this case the philosophers with the forks would have 2 soup bowls left in the middle which they could eat from.

Thus even in the worst case scenario there would be no deadlock.

3)SCENARIO 3
In this case we model the soup bowls as a counting semaphore, and initialize it with a value of 4.
If the value of this semaphore is >0 then the threads would be able to take a soup bowl, otherwise they would have to wait.
AVOIDING DEADLOCK- We avoid deadlock in this case by making the diners first pickup a soup bowl,
and only then allow them to pick up a fork.
We avoid the scenario where deadlock can occur, where 2 forkless philosophers have soup bowls.
And the other 2 soup bowls are with philosophers with only 1 fork each.
As it is mandatory to hold a soup bowl before holding a fork, we avoid this case, and thus avoid deadlock.
