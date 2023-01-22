/*

> WHAT IS OPERATING SYSTEM ?
-  An operating system is a piece of software that manages all the resources of a computer system,
-  both hardware and software, and provides an environment in which the user can execute his/her
-  programs in a convenient and efficient manner.


> Services provided by OS –
- Manages the computer hardware
- Facilitates execution of application programs
- Acts as an intermediary between the user and the computer hardware
- Designed to be convenient and efficient.



> Types of Operating Systems: Some widely used operating systems are as follows-

> 1. Batch Operating System –
- This type of operating system does not interact with the computer directly.
- There is an operator which takes similar jobs having the same requirement
- and group them into batches. It is the responsibility of the operator to
- sort jobs with similar needs.



> Advantages of Batch Operating System:
- It is very difficult to guess or know the time required for any job to complete.
- Processors of the batch systems know how long the job would be when it is in queue
- Multiple users can share the batch systems
- The idle time for the batch system is very less
- It is easy to manage large work repeatedly in batch systems

> Disadvantages of Batch Operating System:
- The computer operators should be well known with batch systems.
- Batch systems are hard to debug
- It is sometimes costly
- The other jobs will have to wait for an unknown time if any job fails
- Examples of Batch based Operating System: Payroll System, Bank Statements, etc.

2. Time-Sharing Operating Systems –
Each task is given some time to execute so that all the tasks work smoothly.
Each user gets the time of CPU as they use a single system. These systems are
 also known as Multitasking Systems. The task can be from a single user or
 different users also. The time that each task gets to execute is called quantum.
 After this time interval is over OS switches over to the next task.


Advantages of Time-Sharing OS:

Each task gets an equal opportunity
Fewer chances of duplication of software
CPU idle time can be reduced
Disadvantages of Time-Sharing OS:

Reliability problem
One must have to take care of the security and integrity of user programs and data.
Data communication problem.
Examples of Time-Sharing OSs are: Multics, Unix, etc.

3. Distributed Operating System –
These types of the operating system is a recent advancement in the world of
computer technology and are being widely accepted all over the world and,
that too, with a great pace. Various autonomous interconnected computers
communicate with each other using a shared communication network.
Independent systems possess their own memory unit and CPU. These are referred
to as loosely coupled systems or distributed systems. These systems processors
differ in size and function. The major benefit of working with these types of the
operating system is that it is always possible that one user can access the files
or software which are not actually present on his system but some other system
connected within this network i.e., remote access is enabled within the devices
connected in that network.




Advantages of Distributed Operating System:
Failure of one will not affect the other network communication, as all systems are independent of each other.
Electronic mail increases the data exchange speed.
Since resources are being shared, computation is highly fast and durable.
Load on host computer reduces.
These systems are easily scalable as many systems can be easily added to the network.
Delay in data processing reduces.


Disadvantages of Distributed Operating System:
Failure of the main network will stop the entire communication
To establish distributed systems the language which is used are not well-defined yet
These types of systems are not readily available as they are very expensive.
Not only that the underlying software is highly complex and not understood well yet

Examples of Distributed Operating System are- LOCUS, etc.


4. Network Operating System –
These systems run on a server and provide the capability to manage data, users,
groups, security, applications, and other networking functions. These types of
operating systems allow shared access of files, printers, security, applications,
and other networking functions over a small private network. One more important
aspect of Network Operating Systems is that all the users are well aware of the
underlying configuration, of all other users within the network, their individual
connections, etc. and that’s why these computers are popularly known as tightly coupled systems.



Advantages of Network Operating System:

Highly stable centralized servers
Security concerns are handled through servers
New technologies and hardware up-gradation are easily integrated into the system
Server access is possible remotely from different locations and types of systems
Disadvantages of Network Operating System:

Servers are costly
User has to depend on a central location for most operations
Maintenance and updates are required regularly
Examples of Network Operating System are: Microsoft Windows Server 2003, Microsoft
Windows Server 2008, UNIX, Linux, Mac OS X, Novell NetWare, and BSD, etc.

5. Real-Time Operating System –
These types of OSs serve real-time systems. The time interval required to process
and respond to input is very small. This time interval is called response time.

Real-time systems are used when there are time requirements that are very strict like
missile systems, air traffic control systems, robots, etc.

Two types of Real-Time Operating System which are as follows:

Hard Real-Time Systems:
These OSs are meant for applications where time constraints are very strict and even the
shortest possible delay is not acceptable. These systems are built for saving life like
automatic parachutes or airbags which are required to be readily available in case
of any accident. Virtual memory is rarely found in these systems.

Soft Real-Time Systems:
These OSs are for applications where for time-constraint is less strict.



Advantages of RTOS:

Maximum Consumption: Maximum utilization of devices and system, thus more output from all the resources
Task Shifting: The time assigned for shifting tasks in these systems are very less.
For example, in older systems, it takes about 10 microseconds in shifting one task to
another, and in the latest systems, it takes 3 microseconds.
Focus on Application: Focus on running applications and less importance to applications which are in the queue.
Real-time operating system in the embedded system: Since the size of programs are small,
RTOS can also be used in embedded systems like in transport and others.
Error Free: These types of systems are error-free.
Memory Allocation: Memory allocation is best managed in these types of systems.
Disadvantages of RTOS:

Limited Tasks: Very few tasks run at the same time and their concentration is very less on few applications to avoid errors.
Use heavy system resources: Sometimes the system resources are not so good and they are expensive as well.
Complex Algorithms: The algorithms are very complex and difficult for the designer to write on.
Device driver and interrupt signals: It needs specific device drivers and interrupts signals to respond earliest to interrupts.
Thread Priority: It is not good to set thread priority as these systems are very less prone to switching tasks.
Examples of Real-Time Operating Systems are: Scientific experiments, medical imaging systems,
industrial control systems, weapon systems, robots, air traffic control systems, etc.


What is RAM?
The full form of RAM is Random Access Memory. The information stored in this type of
memory is lost when the power supply to the PC or laptop is switched off.
The information stored in RAM can be checked with the help of BIOS. It is generally
known as the main memory, or temporary memory or cache memory or volatile memory
of the computer system.


What is ROM?
The full form of ROM is a Read-Only Memory. It is a permanent type of memory.
Its content are not lost when the power supply is switched off. The computer
manufacturer decides the information of ROM, and it is permanently stored at
the time of manufacturing, which cannot be overwritten by the user.


Parameters	                      RAM	                                                       ROM
Usage	        RAM allows the computer to read data quickly        ROM stores all the application which is needed to boot the
                to run applications.	                            computer initially. It only allows for reading.


Volatility	 RAM is volatile. So, its contents are lost 	         It is non-volatile, i.e., its contents are retained
                when the device is powered off                       even if the device is powered off.

Accessibility	Information stored in the RAM is 	               The processor can’t directly access the information that
                easily accessed.                                     is stored in the ROM. In order to access ROM information
                                                                     first, the information is transferred into the RAM, and
                                                                     then it can be executed by the processor.

Read/Write	    Both R (read) and W (write) operations can      	 The ROM memory allows the user to read the information.
                be performed over the information                    But, the user can’t alter the information.
                which is stored in the RAM.

Storage	        RAM is used to store temporary information.	         ROM memory is used to store
                                                                     permanent information, which is non-erasable.


Speed	       The access speed of RAM is faster.	                 Its speed is slower in comparison with RAM. Therefore,
               ROM can’t boost up the processor speed.


Cost	       The price of RAM is quite high.	                     The price of ROM is comparatively low.


Chip size	   Physical size of RAM chip is bigger than ROM chip.	 Physical size of ROM chip is smaller than the RAM
                                                                     chip of same storage capacity.

Preservation   Electricity is needed in RAM to flow and 	         Electricity is not required to flow and preserving information
of Data        to preserve information.

Structure	   The RAM chip is in rectangle form and is              Read-only memory (ROM) is a type of storage medium
               inserted over the motherboard of the computer.        that permanently stores data on personal computers
                                                                     (PCs) and other electronic devices.




VIRTUALIZATION:
Virtualization is the technology which can simulate your physical hardware (such as CPU cores, memory, disk)
and represent it as separate machine. It has its own Guest OS, Kernel, process, drivers etc.
Therefore, it is hardware level virtualization. Most common technology is VMware and VirtualBox


CONTAINERIZATION:
Containerization is os-level virtualization. It doesn't simulate the entire physical machine.
It just simulates the OS of your machine. Therefore, multiple applications can share the same OS kernel.
Container play similar roles to virtual machine but without hardware virtualization.
Most common container technology is Docker




BIOS :
The BIOS is abbreviated as ‘Basic Input-Output System‘. It refers to the computer’s embedded software and is located on
the motherboard’s controller chip. The BIOS connects the hardware components of the computer with the operating system.
It loads the bootloader, which is what boots the OS and initializes the system.

UEFI :
It stands for 'Unified Extensible Firmware Interface'. This is the newer and more advanced firmware interface that
aims to correct the technical shortcomings. Similar to BIOS, it also serves as a bridge, connecting a computer’s
operating system to its firmware. UEFI comes with a number of features and advantages that cannot be obtained
through the legacy BIOS. This technology will eventually replace the BIOS entirely.




Difference between UEFI and BIOS :

BIOS and UEFI are interfaces used by computers that act as translators between their operating
systems and their firmware. These two interfaces are used when the computer starts to initialize
its components and to launch the operating system from the hard drive.

BIOS reads the first sector of the hard drive, which contains the address or code needed to
initialize the next device. In addition, BIOS also determines the boot device that must be
initialized for the operating system to run. Because BIOS has been around since the dawn of time,
it continues to operate in 16-bit mode, which results in restricting the amount of code that can be accessed.
On the other hand, UEFI performs similar functions to BIOS but in a slightly different way.
It stores all startup and initialization information in a .efi file rather than a firmware file.
The file is located on a special partition of the hard drive called EFI System Partition.
On a computer, the EFI System Partition consists of the bootloader for the Operating System installed.

BIOS only works in 16 bits therefore it cannot address more than 1 MB of space. As a consequence,
it can only initialize one device at a time and the booting might take longer.



In contrast, UEFI operates in 64-bit mode, meaning it has higher addressable memory  thus it
makes the booting process faster. Furthermore, UEFI supports networking, so you can troubleshoot
remotely even without installing an operating system. As a result, most motherboard manufacturers
find it to be a much better choice in most cases. For this reason, it has gained popularity recently.

The next difference between the two programs is that BIOS stores bootloader data in the Master Boot Record (MBR).
The MBR is located in the '''first sector of the disk''', so it can be easily corrupted, making the
operating system unresponsive.

UEFI, on the other hand, makes use of the GUID Partition Table (GPT), which performs cyclic redundancy checks
to identify any corruption issue. Thus, it creates a more robust boot environment that can be
easily recovered. With a GPT, it is capable of supporting more than four primary partitions.

In essence, UEFI brings in a lot of new features and enhancements that are not possible through BIOS.


 WHAT IS MBR and GPT :
 MBR (Master Boot Record) and GPT (GUID Partition Table) are two different ways of storing the partitioning
 information on a drive. This information includes where partitions begin and end on the physical disk, so
 your operating system knows which sectors belong to each partition and which partition is bootable.
 This is why you have to choose MBR or GPT before creating partitions on a drive.

MBR:
MBR was first introduced with IBM PC DOS 2.0 in 1983. It’s called Master Boot Record because the MBR is a special
boot sector located at the beginning of a drive.It is associated with BIOS. This sector contains a boot-loader for
the installed operating system and information about the drive’s logical partitions. The boot-loader is a small bit
of code that generally loads the larger boot-loader from another partition on a drive.

MBR does have its limitations. For starters, MBR only works with disks up to 2 TB in size.
MBR also only supports up to four primary partitions




GPT :
GPT stands for GUID Partition Table. It’s a new standard that’s gradually replacing MBR. It’s associated with UEFI, which
replaces the clunky old BIOS with something more modern. GPT, in turn, replaces the clunky old MBR partitioning system
with something more modern. It’s called GUID Partition Table because every partition on your drive has a “globally
unique identifier,” or GUID—a random string so long that every GPT partition on earth likely has its own unique
identifier.


GPT doesn't suffer from MBR’s limits. GPT-based drives can be much larger, with size limits dependent on the operating
system and its file systems. GPT also allows for a nearly unlimited number of partitions. Again, the limit here will be
your operating system—Windows allows up to 128 partitions on a GPT drive, and you don’t have to create an extended
partition to make them work.


MAJOR DIFFERENCES :

On an MBR disk, the partitioning and boot data is stored in one place. If this data is overwritten or corrupted, you’re
in trouble. In contrast, GPT stores multiple copies of this data across the disk, so it’s much more robust and can recover
if the data is corrupted.

GPT also stores cyclic redundancy check (CRC) values to check that its data is intact. If the data is corrupted, GPT can
notice the problem and attempt to recover the damaged data from another location on the disk. MBR had no way of knowing
if its data was corrupted—you’d only see there was a problem when the boot process failed or your drive’s partitions
vanished.







What is Program in OS?
A Program is an executable file which contains a certain set of instructions written to complete the specific job or
operation on your computer. For example, Google browser chrome.exe is an executable file which stores a set of
instructions written in it which allow you to open the browser and explore web pages.

Programs are never stored on the primary memory in your computer. Instead, they are stored on a disk or secondary
memory on your PC or laptop. They are read from the primary memory and executed by the kernel.

The program is stored on disk in some file and does not require any other resources.



What is Process?
A Process is an execution of a specific program. It is an active entity that actions the purpose of the application.
Multiple processes may be related to the same program. For example, if you double-click on Google Chrome browser,
you start a process that runs Google Chrome and when you open another instance of Chrome, you essentially create a
second process.

Process holds resources like CPU, memory address, disk, I/O, etc.


Process States :
The process, from its creation to completion, passes through various states. The minimum number of states is five.
The names of the states are not standardized although the process may be in one of the following
states during execution.

1. New
A program which is going to be picked up by the OS into the main memory is called a new process.

2. Ready
Whenever a process is created, it directly enters the ready state, in which, it waits for the CPU to be assigned.
The OS picks the new processes from the secondary memory and put all of them in the main memory.

The processes which are ready for the execution and reside in the main memory are called ready state processes.
There can be many processes present in the ready state.

3. Running
One of the processes from the ready state will be chosen by the OS depending upon the scheduling algorithm. Hence,
if we have only one CPU in our system, the number of running processes for a particular time will always be one.
If we have n processors in the system then we can have n processes running simultaneously.

4. Block or wait
From the Running state, a process can make the transition to the block or wait state depending upon the scheduling
algorithm or the intrinsic behavior of the process.

When a process waits for a certain resource to be assigned or for the input from the user then the OS move this process
to the block or wait state and assigns the CPU to the other processes.

5. Completion or termination
When a process finishes its execution, it comes in the termination state. All the context of the process
(Process Control Block) will also be deleted the process will be terminated by the Operating system.

WHAT IS A THREAD ?
Thread is the segment of a process means a process can have multiple threads and these multiple threads
are contained within a process. A thread has three states: Running, Ready, and Blocked.

Thread takes less time to terminate as compared to process but unlike process threads do not isolate.




Difference between Process and Thread:

S.NO	            Process	                                                Thread
---------------------------------------------------------------|-------------------------------------------------------------------------------------------
1.	    Process means any program is in execution.	           |     Thread means segment of a process.
                                                               |
2.	    Process takes more time to terminate.	               |     Thread takes less time to terminate.
                                                               |
3.	    It takes more time for creation.	                   |     It takes less time for creation.
                                                               |
4.	    It also takes more time for context switching.	       |     It takes less time for context switching.
                                                               |
5.	    Process is less efficient in terms of communication.   |	 Thread is more efficient in terms of communication.
                                                               |
6. 	    Multi -programming holds the concepts of               |	 We don’t need multi programs in action for multiple threads because
        multi- process                                         |     a single process consists of multiple threads.
                                                               |
7.	    Process is isolated.	                               |     Threads share memory.
                                                               |
8.	    Process is called heavy- weight process.	           |     A Thread is lightweight as each thread in a process shares code, data and resources.
                                                               |
9.	    Process switching uses interface in operating system.  |	 Thread switching does not require to call a operating system and
                                                               |     cause an interrupt to the kernel.
                                                               |
10.	    If one process is blocked then it will not affect      |     an interrupt to the kernel.
        the execution of other process 	Second thread in the   |
        same task could not run, while one server thread       |
        is blocked.                                            |
                                                               |
11.	    Process has its own Process Control Block, 	           |     Thread has Parents’ PCB, its own Thread Control Block and
        Stack and Address Space.                               |     Stack and common Address space.
                                                               |
12.	    If one process is blocked, then no other process can   |	 While one thread is blocked and waiting, a second thread
        execute until the first process is unblocked.          |     in the same task can run.
                                                               |
13.	    Changes to the parent process does not affect          |      Since all threads of the same process share address space and other
        child processes.                                       |      resources so any changes to the main thread may affect the behavior
                                                               |      of the other threads of the process.
                                                               |
                                                               |




Process Table and Process Control Block (PCB):
While creating a process the operating system performs several operations. To identify the processes,
it assigns a process identification number (PID) to each process. As the operating system supports
multi-programming, it needs to keep track of all the processes. For this task, the process control block (PCB)
is used to track the process’s execution status. Each block of memory contains information about the process state,
program counter, stack pointer, status of opened files, scheduling algorithms, etc. All this information is required
and must be saved when the process is switched from one state to another. When the process makes a transition from one
state to another, the operating system must update information in the process’s PCB.

A process control block (PCB) contains information about the process, i.e. registers, quantum, priority, etc.
The process table is an array of PCB’s, that means logically contains a PCB for all the current
processes in the system.



Pointer – It is a stack pointer which is required to be saved when the process is switched
from one state to another to retain the current position of the process.

Process state – It stores the respective state of the process.

Process number – Every process is assigned with a unique id known as process ID or PID
which stores the process identifier.

Program counter – It stores the counter which contains the address of the next instruction
that is to be executed for the process.

Register – These are the CPU registers which includes: accumulator, base, registers and
general purpose registers.

Memory limits – This field contains the information about memory management system used by
operating system. This may include the page tables, segment tables etc.

Open files list – This information includes the list of files opened for a process.

PROCESS SCHEDULING :
The process scheduling is the activity of the process manager that handles the removal of the running process from the
CPU and the selection of another process on the basis of a particular strategy.

Process scheduling is an essential part of a Multiprogramming operating systems. Such operating systems allow more than
one process to be loaded into the executable memory at a time and the loaded process shares the CPU
using time multiplexing.





Process Scheduling Queues:
JOB QUEUE:
As process enters the system ,they are put into a job queue , which consists of all the processes in th system.

READY QUEUE:
The process that are residing in the main memory are ready and waiting
to ex execute are kept on a list called the ready queue.


The OS can use different policies to manage each queue (FIFO, Round Robin, Priority, etc.).
The OS scheduler determines how to move processes between the ready and run queues which can only
have one entry per processor core on the system.



SCHEDULERS :
Schedulers are special system software which handle process scheduling in various ways.
Their main task is to select the jobs to be submitted into the system and to decide which
process to run.

Schedulers are of three types :-
1. Long-Term Scheduler
2. Short-Term Scheduler
3. Medium-Term Scheduler


Long Term Scheduler or JOB Sc.
-------------------------------
It is also called a job scheduler. A long-term scheduler determines which programs are admitted to the system for
processing. It selects processes from the queue and loads them into memory for execution. Process loads into the
memory for CPU scheduling.

The primary objective of the job scheduler is to provide a balanced mix of jobs, such as I/O bound and processor bound.
It also controls the degree of multiprogramming. If the degree of multiprogramming is stable, then the average rate of
process creation must be equal to the average departure rate of processes leaving the system.

On some systems, the long-term scheduler may not be available or minimal. Time-sharing operating systems have no long
term scheduler. When a process changes the state from new to ready, then there is use of long-term scheduler.

Short Term Scheduler or CPU Sc.
-------------------------------
It is also called as CPU scheduler. Its main objective is to increase system performance in accordance with the chosen
set of criteria. It is the change of ready state to running state of the process. CPU scheduler selects a process among
the processes that are ready to execute and allocates CPU to one of them.

Short-term schedulers, also known as dispatchers, make the decision of which process to execute next. Short-term
schedulers are faster than long-term schedulers.

Medium Term Scheduler
-------------------------------
Medium-term scheduling is a part of swapping. It removes the processes from the memory. It reduces the degree of
multiprogramming. The medium-term scheduler is in-charge of handling the swapped out-processes.

A running process may become suspended if it makes an I/O request. A suspended processes cannot make any progress
towards completion. In this condition, to remove the process from memory and make space for other processes, the
suspended process is moved to the secondary storage. This process is called swapping, and the process is said to be
swapped out or rolled out. Swapping may be necessary to improve the process mix.

__________________________________________________________________________________________________________
“CPU-bound” and “I/O bound” :

1. Introduction
In this tutorial, we’ll examine two terms commonly used in program development, CPU bound and I/O bound.
First, we’ll define them and describe their properties. Then we’ll discuss how to identify them.
Finally, we’ll explore the benefits and problems associated with each of them.

2. What Does CPU-Bound Mean?
The term CPU-bound describes a scenario where the execution of a task or program is highly dependent
on the CPU. Before we go any further, let’s define what a CPU is. The CPU usually refers to the central
processing unit of a computing device, such as a desktop computer. It’s responsible for controlling the
execution of tasks and programs in a computer system. As such, a computing device can’t really function without it.

In a CPU-bound environment, most times, the processor is the only component being used for execution.
This means that other components in the computer system are rarely used during execution. Due to this
dependence, everything concerned with program execution is dependent on the CPU. Consequently, if we
want a program to run faster, then we have to increase the speed of the CPU.

Furthermore, CPU-bound operations tend to have few and long CPU bursts. CPU burst refers to the amount
of time taken to execute a task, usually with the CPU. As a result, it’s always advisable to assign a
lower priority to such tasks to prevent wasting resources:

cpu-bound-timeline
2.1. Examples of Applications:
Applications that usually require tons of calculations are a classic example. For instance, High-Performance
Computing (HPC) systems can be thought of as CPU-bound. Such systems combine the processing power of several
powerful processors in the CPU to deliver higher computing performance.

Due to the speed and efficiency of such systems, they’re capable of computing billions of calculations per
second. If we want to increase the performance of the HPC system, in addition to other components, we can
increase the processor’s speed. HPC systems have been employed in a number of areas, such as weather prediction,
artificial intelligence, and research in general.

In addition to HPC systems, graphics operations are also CPU-bound in the sense that calculations have to be
made to render graphics.

2.2. Advantages and Disadvantages
The main advantage is:

The use of the CPU results in faster processing of tasks or programs.
The disadvantages are:

The use of the processing unit alone results in other system components being idle, hence a waste of resources.
Increasing CPU power is an expensive exercise because they’re generally expensive to purchase.

3. What do I/O Bound Mean?
In contrast, a task or program is I/O bound if its execution is dependent on the input-output system and
its resources, such as disk drives and peripheral devices. In I/O bound environments, we wait for resources
to be retrieved through the input-output systems. Hence, it’s safe to say that a program or task would execute
faster if the input-output system worked faster.

In addition, in executing an I/O bound task, the computing device spends its time performing input-output
operations, and other resources, such as the central processing unit, are used less frequently or not at all.
The input-output system refers to the input-output component of an operating system. This is usually responsible
for the communication or transfer of information between the computing device and the outside.

It should also be noted that I/O bound operations are characterized by many and fewer CPU bursts during execution:

3.1. Examples of Applications
Any application that involves reading and writing data from an input-output system, as well as waiting for information,
is considered I/O bound. These include applications like word processing systems, web applications, copying files,
and downloading files.

3.2. Advantages and Disadvantages
The main advantage is:

Due to the short CPU bursts, they’re usually assigned higher priority during scheduling to ensure that system
resources are better used.
The disadvantages are:

Programs that are I/O bound are often slower than CPU-bound programs.
Due to the use of the input-output system, the time spent waiting for data to be read or written can be substantial.
This is considerably slower than the time it takes a processor to complete operations.



4. How to Distinguish the Two?
So how do we decide which category a program or task belongs to? In identifying the category, there are a couple of
questions to ask. First, we need to identify which resources make the program or task execute faster. Second, does
the program require long CPU bursts or short CPU bursts?

It’s also important to note that some programs or tasks are both CPU and I/O bound. Therefore, we can’t strictly
place them into one group.

5. Conclusion
In this article, we defined CPU and I/O bound operations. We discussed some example applications and then listed
the pros and cons. Lastly, we outlined how to identify which group an operation or task belongs to.

If you have a few years of experience in Computer Science or research, and you’re interested in sharing that
experience with the community, have a look at our Contribution Guidelines.




CONTEXT SWITCHING :
Context Switching involves storing the context or state of a process so that it can be reloaded when required and
execution can be resumed from the same point as earlier. This is a feature of a multitasking operating system
and allows a single CPU to be shared by multiple processes.



MULTITHREADING:
The concept of multi-threading needs proper understanding of these two terms – a process and a thread.
A process is a program being executed. A process can be further divided into independent units known as threads.

A thread is like a small light-weight process within a process. Or we can say a collection of threads is what
is known as a process.


Threading is used widely in almost every field. Most widely it is seen over the internet nowadays where we are
using transaction processing of every type like recharges, online transfer, banking etc. Threading is a segment
which divide the code into small parts that are of very light weight and has less burden on CPU memory so that
it can be easily worked out and can achieve goal in desired field. The concept of threading is designed due to
the problem of fast and regular changes in technology and less the work in different areas due to less application.
Then as says “need is the generation of creation or innovation” hence by following this approach human mind develop
the concept of thread to enhance the capability of programming.







________________________________________________________________________________________________________________________

PROCESS SYNCHRONIZATION:
Process Synchronization was introduced to handle problems that arose while multiple process executions.

Process is categorized into two types on the basis of synchronization and these are given below:
1. Independent Process
2. Cooperative Process

Independent Processes
Two processes are said to be independent if the execution of one process does not affect the execution of
another process.

Cooperative Processes
Two processes are said to be cooperative if the execution of one process affects the execution of another process.
These processes need to be synchronized so that the order of execution can be guaranteed.

Process Synchronization
It is the task phenomenon of coordinating the execution of processes in such a way that no two processes can have
access to the same shared data and resources.

It is a procedure that is involved in order to preserve the appropriate order of execution of cooperative processes.

In order to synchronize the processes, there are various synchronization mechanisms.

Process Synchronization is mainly needed in a multi-process system when multiple processes are running together, and
more than one processes try to gain access to the same shared resource or any data at the same time.

Race Condition :
At the time when more than one process is either executing the same code or accessing the same memory or any shared
variable; In that condition, there is a possibility that the output or the value of the shared variable is wrong so
for that purpose all the processes are doing the race to say that my output is correct. This condition is commonly
known as a race condition. As several processes access and process the manipulations on the same data in a concurrent
manner and due to which the outcome depends on the particular order in which the access of data takes place.

Mainly this condition is a situation that may occur inside the critical section. Race condition in the critical
section happens when the result of multiple thread execution differs according to the order in which the threads
execute. But this condition is critical sections can be avoided if the critical section is treated as an atomic
instruction. Proper thread synchronization using locks or atomic variables can also prevent race conditions.

Critical Section Problem :
A Critical Section is a code segment that accesses shared variables and has to be executed as an atomic action.
(In programming, an atomic action is one that effectively happens all at once. An atomic action cannot stop in
the middle: it either happens completely, or it doesn't happen at all. No side effects of an atomic action are
visible until the action is complete) It means that in a group of cooperating processes, at a given point of time,
only one process must be executing its critical section. If any other process also wants to execute its critical
section, it must wait until the first one finishes. The entry to the critical section is mainly handled by wait()
function while the exit from the critical section is controlled by the signal() function.


Critical Section Problem

Entry Section
In this section mainly the process requests for its entry in the critical section.

Exit Section
This section is followed by the critical section.

The solution to the Critical Section Problem
A solution to the critical section problem must satisfy the following three conditions:

1. Mutual Exclusion
Out of a group of cooperating processes, only one process can be in its critical section at a given point of time.

2. Progress
If no process is in its critical section, and if one or more threads want to execute their critical section then
any one of these threads must be allowed to get into its critical section.

3. Bounded Waiting
After a process makes a request for getting into its critical section, there is a limit for how many other processes
can get into their critical section, before this process's request is granted. So after the limit is reached, the
system must grant the process permission to get into its critical section.

Solutions for the Critical Section
The critical section plays an important role in Process Synchronization so that the problem must be solved.

Some widely used method to solve the critical section problem are as follows:

1.Peterson's Solution
This is widely used and software-based solution to critical section problems. Peterson's solution was developed
by a computer scientist Peterson that's why it is named so.

With the help of this solution whenever a process is executing in any critical state, then the other process only
executes the rest of the code, and vice-versa can happen. This method also helps to make sure of the thing that only
a single process can run in the critical section at a specific time.

This solution preserves all three conditions:

Mutual Exclusion is comforted as at any time only one process can access the critical section.

Progress is also comforted, as a process that is outside the critical section is unable to block other processes
from entering into the critical section.

Bounded Waiting is assured as every process gets a fair chance to enter the Critical section.

The above shows the structure of process Pi in Peterson's solution.

Suppose there are N processes (P1, P2, ... PN) and as at some point of time every process requires to enter the
Critical Section

A FLAG[] array of size N is maintained here which is by default false. Whenever a process requires to enter the
critical section, it has to set its flag as true. Example: If Pi wants to enter it will set FLAG[i]=TRUE.

Another variable is called TURN and is used to indicate the process number that is currently waiting to enter into
the critical section.

The process that enters into the critical section while exiting would change the TURN to another number from the
list of processes that are ready.

Example: If the turn is 3 then P3 enters the Critical section and while exiting turn=4 and therefore P4 breaks
out of the wait loop.

Synchronization Hardware
Many systems provide hardware support for critical section code. The critical section problem could be solved
easily in a single-processor environment if we could disallow interrupts to occur while a shared variable or
resource is being modified.

In this manner, we could be sure that the current sequence of instructions would be allowed to execute in order
without pre-emption. Unfortunately, this solution is not feasible in a multiprocessor environment.

Disabling interrupt on a multiprocessor environment can be time-consuming as the message is passed to all
the processors.

This message transmission lag delays the entry of threads into the critical section, and the system efficiency
decreases.

Mutex Locks
As the synchronization hardware solution is not easy to implement for everyone, a strict software approach called
Mutex Locks was introduced. In this approach, in the entry section of code, a LOCK is acquired over the critical
resources modified and used inside the critical section, and in the exit section that LOCK is released.

As the resource is locked while a process executes its critical section hence no other process can access it.


*/