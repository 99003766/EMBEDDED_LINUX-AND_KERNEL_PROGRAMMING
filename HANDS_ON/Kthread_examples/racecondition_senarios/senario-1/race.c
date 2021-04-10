#include <linux/delay.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kthread.h>
// Global
int val=100;
int i=0;
const long int max=1000000;

 

static struct task_struct *task1;
static struct task_struct *task2;
static int thread_one(void *pargs) {

 

   for(i=1;i<=max;i++)
   {
    val++;
   }
    printk("Thread A stopping-- val value is %d\n",val);
   do_exit(0);
  return 0;
}
static int thread_two(void *pargs) {
  

 

   for(i=1;i<=max;i++)
   {
    val--;
   }
    printk("Thread B stopping--val value is %d\n",val);
   do_exit(0);
  return 0;
}
int __init init_module(void) {
  printk("Hello World..Welcome jayasimha\n");
  task1 = kthread_run(thread_one, NULL, "thread_A");
  // kthread_create + wake_up_process
  task2 = kthread_run(thread_two, NULL, "thread_B");
  return 0;
}
void __exit cleanup_module(void) {
  printk("Bye,leaving jayasimha\n");
/*  if (task1)
    kthread_stop(task1);
//  printk("value=%d\n",val1); 
  if (task2)
    kthread_stop(task2); */
  printk("Valvalue is -->%d\n",val);
}

 

MODULE_LICENSE("GPL");
MODULE_AUTHOR("jayasimha");
MODULE_DESCRIPTION("A simple Module");
