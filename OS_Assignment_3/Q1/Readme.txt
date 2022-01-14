Instructions to test and run - 
1) The diff and the test files have been attached along with this folder.
2) After patching the diff file, run the 'make' instruction to obtain test and measure object files
3) run ./test and ./measure in seperate terminals and use htop command to view the time taken by each process to finish

Logic- 
Both test and measure perform the task of finding the first n prime numbers. 
You can use the work1 file to add extra work to the system while testing, to make the effect of the syscall more evident.
Test calls the system call increase_delay, while measure does not.
Both test and measure have been shifted to a priority level of 39 to make their execution seperate from other programmes, in a fresh kernel only measure and test will have the priority level of 39.

The syscall increase_delay takes in 2 arguments, 1) the delay you want to introduce and 2) the PID of the process you want to delay

We make sure that the user can never increase the priority of the process as the delay is of the form unsigned long long integer, thus it can never have a negative value.

To reflect this delay in process selection we make use of the basic principle of the CFS scheduler i.e the vruntime variable.
All processes are stored in the red black tree according to the vruntime, and the process with the minimum vruntime is chosen. 
So to introduce delay in selection by the scheduler we increase the vruntime by the given amount. This causes the scheduler to believe that the current process has run for longer than it actually has.
And thus according to the algorithm is chosen less often, as it goes back in the red black tree.

We increase the vruntime in 2 ways - 
1) we access the task_struct structure through the pid_task system call, we then use this task_struct to gain access to the sched_entity structure which holds the vruntime of the current process
We then simply add the delay to the vruntime process. You can see the before and after vruntime in the kernel logs, by using the 'sudo dmesg | tail' command.

2) We modify the sched_entity structure to hold an additional variable called the user_delay, in normal cases this user_delay is set to 0, but whenever this system call is called, 
the user_delay value is set to the delay passed by the user.
In fair.c, we add another line in the update_curr function, we keep adding the user_delay to the vruntime before it is added to the red black tree, in normal cases as this user_delay is 0,
it has no effect on the scheduler. But whenever our system call is used, the user_delay creates a delay in the process by increasing the vruntime in the update_curr function.

Other source files modified were - 
1) sched.h - to add the user_delay variable to the sched_entity structure
2) core.c - to set the user_delay to 0, in the __sched_fork function
3) syscalls64.tbl - to add the syscall to the table, at number 448
4) sys.c - this is where the main syscall was written

Note - Due to high processing speed, very little noticeable gap can be seen in the measure and test files, to make this gap more evident, 
load up the system with excess work from the work1 file, as mentioned in class by arani sir.



