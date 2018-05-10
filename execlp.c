#include<unistd.h>
main()
{
  execlp("ls","ls","-al","/etc/passwd",(char *)0);
}
