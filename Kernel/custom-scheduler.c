//Create own task struct, to build on top of Linux task struct & scheduler to implement our own rules.
//aka we are augmenting the process control block without actually modifying the linux PCB.
struct mp3_task_struct {
   struct list_head list;
   struct task_struct *linux_task; //linux Process control block
   unsigned int pid;
   //other variables to associate
};

//The structure above follows the interesting design pattern used with kernel linked list as well.

//Fixed priority (real time priority) a little confusing naming convention
//Dynamic priority

//Priority Inversion
//
