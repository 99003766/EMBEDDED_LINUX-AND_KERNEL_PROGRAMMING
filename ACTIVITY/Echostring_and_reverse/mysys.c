#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/uaccess.h>
SYSCALL_DEFINE2(mytestthree, const char __user *,ch,char __user *,gett)
{
   char buf[50],rev[50];
   int k,x,y;
   int length=0;
   n=copy_from_user(buf,ch,50);
   if(n)
   {
      printk("copy");
      return -EFAULT;
   }
   while(buf[length] != '\0')
   	length++;
   y=length-1;
   
   for(x=0;x<length;x++)
   {
     rev[x] = buf[y];
    j--;
   }
   rev[length]='\0';
   k=copy_to_user(gett,rev,50);
   if(k)
   {
    return -EFAULT;
   }
   printk("%s",rev);
   return 0;
}
