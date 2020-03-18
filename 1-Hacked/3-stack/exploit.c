#include <stdio.h>

int main(int argc, char **argv)
{
  char st[8];

  //printf("%lx\n", (long)&printf); 
    
    st[0]='H';
    st[1]='A';
    st[2]='C';
    st[3]='K';
    st[4]='E';
    st[5]='D';
    st[6]='\n';
    st[7]=0;
	
    while(1)
    	((int (*)(const char *, ...))(0x7ffff7e4ea20))(st);
}
