#include <linux/kernel.h>           //used for do_exit()
#include <linux/threads.h>          //used for allow_signal
#include <linux/kthread.h>          //used for kthread_create
#include <linux/delay.h>            //used for ssleep()
#include <linux/module.h>
int val=100, k;
const int max=20;
static struct task_struct *task1;
static struct task_struct *task2;
    static int thread_one(void *pargs) {
    int i;
    for(i=1;i<=max;i++)
    {
        printk("Thread A--%d\n",k++);
        if(kthread_should_stop())
          break;
        msleep(100);
    }  
    do_exit(0);
   return 0;
  } 
    static int thread_two(void *pargs) {
    int i;
    for(i=1;i<=max;i++)
    {
        printk("Thread A--%d\n",k++);
        if(kthread_should_stop())
          break;
        msleep(100);
    }  
    do_exit(0);
   return 0;
  } 
int __init init_thread(void)
{
    printk(KERN_INFO "Creating Thread\n");
    //Create the kernel thread with name 'mythread'
    task1 = kthread_run(thread_one, NULL, "threadA");
    if (task1)
    {
        printk(KERN_INFO "Thread Created A successfully\n");
        }
    else
    {
        printk(KERN_ERR "Thread creation failed\n");
        }
        
    task2 = kthread_run(thread_two, NULL, "threadB");
    if (task2)
    {
        printk(KERN_INFO "Thread Created B successfully\n");
        }
    else
    {
        printk(KERN_ERR "Thread creation failed\n");
        }
    return 0;
}
// Module Exit
static void __exit cleanup_thread(void)
{
   printk(KERN_INFO "Cleaning Up\n");
   if (task1)
   {
       kthread_stop(task1);
       printk(KERN_INFO "Thread stopped");
   }
   if (task2)
   {
       kthread_stop(task2);
       printk(KERN_INFO "Thread stopped");
   }
}
MODULE_LICENSE("GPL");
module_init(init_thread);
module_exit(cleanup_thread);
 
