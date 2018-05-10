#include<unistd.h>
main()
{
  char *argv[]={"ls","-al","/etc/passwd",(char *)0};
  execv("/bin/ls",argv);
}
