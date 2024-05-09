# philosophers
### Philosophers is a project about the Philosopher's issue where it teaches about threads, multithreading and mutex.

**The philosopher's issue:** </br>
- Five philosophers are sitting around a circular table, and each philosopher spends their time thinking, sleeping and eating. There is a bowl of spaghetti in the center of the table, and to eat, a philosopher must use two forks, one for each hand. However, there are only five forks available, one placed between each pair of adjacent philosophers.</br>
- The challenge is to devise a protocol that allows each philosopher to alternate between thinking, sleeping and eating in such a way that no philosopher starves (i.e., each philosopher can eat eventually) and deadlocks are prevented (i.e., no philosopher holds one fork indefinitely, preventing others from eating).</br>
- The Dining Philosophers problem is interesting because it highlights issues related to resource contention, deadlock avoidance, and mutual exclusion in concurrent systems. Solutions to this problem typically involve using semaphores, mutexes, or other synchronization primitives to coordinate access to the forks in a mutually exclusive manner, ensuring that philosophers can eat without getting into a deadlock state.</br>
- The simulation ends when any philosopher dies or all philosophers have finish eating.</br>
