# philosophers (21 school project)

My version of solwing __Dining philosophers problem__. First one with threads and mutex, second with processes and semaphores. 

![An_illustration_of_the_dining_philosophers_problem](https://user-images.githubusercontent.com/90501558/173900008-cd667806-2561-48aa-bbb6-8dc582fc078f.png)


### Index

* [Description](#Description)
* [How to run](#How_to_run)
* [Test examples](#Test_examples)
* [Contacts](#Contacts)
* 

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
### How_to_run

First of all you should download and make project!

``All of makefile rules:``

| Rule | Function |
| - | - |
| ``make`` | Threads and Mutex simulation |
| ``make all`` | Same as just make |
| ``make bonus`` | Processes and Semaphores simulation |
| ``make clean`` | Deletes all object files |
| ``make fclean`` | Deletes the object files and the _philo_ file |
| ``make re`` | makes ``fclean`` and ``make`` again |

And then run the project (time in ms, last argument is optional):
```
./philosophers <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [times_each_philosopher_must_eat]
```
![ezgif com-video-to-gif](https://user-images.githubusercontent.com/90501558/173922097-f6672b84-0fbb-47a7-ae38-c7a0509ce857.gif)
___
### Test_examples

The philosopher should not eat and should die!
```commandline
./philo 1 800 200 200
```
No one should die!
```commandline
./philo 5 800 200 200
```
No one should die and the simulation should stop when all the philosophers has 
eaten at least 7 times each.
```commandline
./philo 5 800 200 200 7
```
No one should die!
```commandline
./philo 4 410 200 200
```
A philosophers should die!
```commandline
./philo 4 310 200 200
```

You can try your own test.
But always mind your hardware characteristics and dont set too strict rules :)
---
### Contacts

Feel free to clone this project, check the code or contact me if you have any question or suggestions:

* 21 Login:   **gajayme**
* Email:    **DonBazilikos@gmail.com**

Good luck and ave a good time! 🤔🤔🤔
