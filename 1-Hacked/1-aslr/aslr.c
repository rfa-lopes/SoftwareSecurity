
// Não funciona: gcc -fno-stack-protector -D_FORTIFY_SOURCE=0 -Wl,-no_pie,-allow_stack_execute aslr.c -o aslr
// Funciona: 	 gcc -fno-stack-protector -D_FORTIFY_SOURCE=0 -W -no-pie aslr.c -o aslr

#include <stdio.h>
void g()
{ 
	printf("\nfoo\n");
}

void f(int a) {
    long stack1[1];
	
    stack1[0] = 0x666;
   
    //Prin stack
    for(int i = 5; i >= -5; i--){
	printf("%d :   %lx\n", i, stack1[i]);
    }
    
    //Jump 2 instructions
    stack1[3] += 10;
    printf("%d :   %lx\n", 3, stack1[3]);

    /* replace stack1[1]+=0 by stack1[X]+=Y such that */ 
    /* foo! is not printed when program is run  */ 
}

int main(int argc, const char * argv[]) {
    f(0x55555555);
    g();
    printf("\ndone\n");
    return 0;
}

