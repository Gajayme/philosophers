# philosophers (21 school project)

My version of solwing __Dining philosophers problem__. First one with threads and mutex, second with processes and semaphores. 

![An_illustration_of_the_dining_philosophers_problem](https://user-images.githubusercontent.com/90501558/173900008-cd667806-2561-48aa-bbb6-8dc582fc078f.png)

---
### Description

``21 school's slightly modified version of the problem says:``

One or more philosophers sit at a round table. There is a large bowl of spaghetti in the middle of the table.
The philosophers alternatively eat, think, or sleep. While they are eating, they are not thinking nor sleeping;
while thinking, they are not eating nor sleeping; and, of course, while sleeping, they are not eating nor thinking.
There are also forks on the table. There are as many forks as philosophers. 
Because serving and eating spaghetti with only one fork is very inconvenient, a philosopher takes their right and their
left forks to eat, one in each hand. When a philosopher has finished eating, they put their forks back on the table and start sleeping.
Once awake, they start thinking again. The simulation stops when a philosopher dies of starvation. Every philosopher needs
to eat and should never starve. Philosophers don’t speak with each other. Philosophers don’t know if another philosopher
is about to die. No need to say that philosophers should avoid dying!

And our mission is to write such an algorithm that avoid deadlock and effectivly synchronize philosopherse's activities
(eating, sleeping, thinking).

``You can read the original description of the problem down here:``
https://en.wikipedia.org/wiki/Dining_philosophers_problem


---
### How to run

First of all you should download and make project!

All of makefile rules:

| Rule | Function |
| - | - |
| ``make`` | Threads and mutes simulation |
| ``make all`` | Same as just make |
| ``make bonus`` | Processes and semaphores simulation |
| ``make clean`` | Deletes all object files |
| ``make fclean`` | Deletes the object files and the _philo_ file |
| ``make re`` | makes ``fclean`` and ``make`` again |
