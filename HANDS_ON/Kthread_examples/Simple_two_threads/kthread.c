#include <linux/delay.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kthread.h>

 

// Global
static struct task_struct *task1;
static struct task_struct *task2;

 


static int thread_one(void *pargs) {
  int k;
  while (!kthread_should_stop()) {
    printk("Thread A--%d\n", k++);
    msleep(1000); // ssleep, usleep
  }
  do_exit(0);
  return 0;
}

 

static int thread_two(void *pargs) {
  int k;
  while (!kthread_should_stop()) {
    printk("Thread B--%d\n", k++);
    msleep(1000); // ssleep, usleep
  }
  do_exit(0);
  return 0;
}

 

 

int __init init_module(void) {
  printk("Hello World..Welcome\n");
  task1 = kthread_run(thread_one, NULL, "thread_A");
  // kthread_create + wake_up_process
  task2 = kthread_run(thread_two, NULL, "thread_B");
  return 0;
}

 

void __exit cleanup_module(void) {
  printk("Bye,leaving\n");

 

  if (task1)
    kthread_stop(task1);
  if (task2)
    kthread_stop(task2);
}

 

 

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your name");
MODULE_DESCRIPTION("A simple Module");
 
