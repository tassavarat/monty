# 0x18. C - Stacks, Queues - LIFO, FIFO

 ## Description
 What you should learn from this project:
 
 * What do LIFO and FIFO mean
 * What is a stack, and when to use it
 * What is a queue, and when to use it
 * What are the common implementations of stacks and queues
* What are the most common use cases of stacks and queues
* What is the proper way to use global variables
* How to work with git submodules

---

### [push, pall]
* Implement the push and pall opcodes.
The push opcode

The opcode push pushes an element to the stack.

* Usage: push <int>
* where <int> is an integer
* if <int> is not an integer or if there is no argument given to push, print the error message L<line_number>: usage: push integer, followed by a new line, and exit with the status EXIT_FAILURE
*where is the line number in the file
The pall opcode

* The opcode pall prints all the values on the stack, starting from the top of the stack.
```
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ ./monty bytecodes/00.m
3
2
1
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$
```
### [pint]
Implement the pint opcode.

The pint opcode

The opcode pint prints the value at the top of the stack, followed by a new line.

Usage: pint
If the stack is empty, print the error message L<line_number>: can't pint, stack empty, followed by a new line, and exit with the status EXIT_FAILURE.
```
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ cat bytecodes/06.m 
push 1
pint
push 2
pint
push 3
pint
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ ./monty bytecodes/06.m 
1
2
3
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ 
```
### [pop]
* Implement the pop opcode.
* The pop opcode

The opcode pop removes the top element of the stack.

Usage: pop
If the stack is empty, print the error message L<line_number>: can't pop an empty stack, followed by a new line, and exit with the status EXIT_FAILURE.
```
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ cat bytecodes/07.m 
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ ./monty bytecodes/07.m 
3
2
1
2
1
1
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ 
```
### [swap]
Implement the swap opcode.

The swap opcode

The opcode swap swaps the top two elements of the stack.

Usage: swap
If the stack contains less than two elements, print the error message L<line_number>: can't swap, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
```
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ cat bytecodes/09.m 
push 1
push 2
push 3
pall
swap
pall
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ ./monty bytecodes/09.m 
3
2
1
2
3
1
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ 
```
### [add]
Implement the add opcode.

The add opcode

The opcode add adds the top two elements of the stack.

Usage: add
If the stack contains less than two elements, print the error message L<line_number>: can't add, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
The top element of the stack contains the result
The stack is one element shorter
```
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ cat bytecodes/12.m 
push 1
push 2
push 3
pall
add
pall

julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ ./monty bytecodes/12.m 
3
2
1
5
1
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$
```
### [nop]
Implement the nop opcode.

The nop opcode

The opcode nop doesnt do anything.
### [sub]
Implement the sub opcode.

The sub opcode

The opcode sub subtracts the top element of the stack from the second top element of the stack.

Usage: sub
If the stack contains less than two elements, print the error message L<line_number>: can't sub, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
The top element of the stack contains the result
The stack is one element shorter
```julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ cat bytecodes/19.m 
push 1
push 2
push 10
push 3
sub
pall
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ ./monty bytecodes/19.m 
7
2
1
```
### [div]
Implement the div opcode.

The div opcode

The opcode div divides the second top element of the stack by the top element of the stack.

Usage: div
If the stack contains less than two elements, print the error message L<line_number>: can't div, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
The top element of the stack contains the result
The stack is one element shorter
If the top element of the stack is 0, print the error message L<line_number>: division by zero, followed by a new line, and exit with the status EXIT_FAILURE.
### [mul]
Implement the mul opcode.

The mul opcode

The opcode mul multiplies the second top element of the stack with the top element of the stack.

Usage: mul
If the stack contains less than two elements, print the error message L<line_number>: can't mul, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
The top element of the stack contains the result
The stack is one element shorter.
### [mod]
Implement the mod opcode.

The mod opcode

The opcode mod computes the rest of the division of the second top element of the stack by the top element of the stack.

Usage: mod
If the stack contains less than two elements, print the error message L<line_number>: can't mod, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
The top element of the stack contains the result
The stack is one element shorter
If the top element of the stack is 0, print the error message L<line_number>: division by zero, followed by a new line, and exit with the status EXIT_FAILURE.
### [comment]
Every good language comes with the capability of commenting. When the first non-space character of a line is #, treat this line as a comment (dont do anything).
### [pchar]
Implement the pchar opcode.

The pchar opcode

The opcode pchar prints the char at the top of the stack, followed by a new line.

Usage: pchar
The integer stored at the top of the stack is treated as the ascii value of the character to be printed
If the value is not in the ascii table (man ascii) print the error message L<line_number>: can't pchar, value out of range, followed by a new line, and exit with the status EXIT_FAILURE
If the stack is empty, print the error message L<line_number>: can't pchar, stack empty, followed by a new line, and exit with the status EXIT_FAILURE
```julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ cat bytecodes/28.m 
push 72
pchar
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ ./monty bytecodes/28.m 
H
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$
```
### [pstr]
Implement the pstr opcode.

The pstr opcode

The opcode pstr prints the string starting at the top of the stack, followed by a new line.

Usage: pstr
The integer stored in each element of the stack is treated as the ascii value of the character to be printed
The string stops when either:
the stack is over
the value of the element is 0
the value of the element is not in the ascii table
If the stack is empty, print only a new line
```julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ cat bytecodes/31.m 
push 1
push 2
push 3
push 4
push 0
push 110
push 0
push 110
push 111
push 116
push 114
push 101
push 98
push 108
push 111
push 72
pstr
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ ./monty bytecodes/31.m 
Holberton
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$
```
### [rotl]
Implement the rotl opcode.

The rotl opcode

The opcode rotl rotates the stack to the top.

Usage: rotl
The top element of the stack becomes the last one, and the second top element of the stack becomes the first one
rotl never fails
```julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ cat bytecodes/35.m 
push 1
push 2
push 3
push 4
push 5
push 6
push 7
push 8
push 9
push 0
pall
rotl
pall
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ ./monty bytecodes/35.m 
0
9
8
7
6
5
4
3
2
1
9
8
7
6
5
4
3
2
1
0
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ 
```
### [rotr]
Implement the rotr opcode.

The rotr opcode

The opcode rotr rotates the stack to the bottom.

Usage: rotr
The last element of the stack becomes the top element of the stack
rotr never fails
### [Stack, Queue]
Implement the stack and queue opcodes.

##### The stack opcode

The opcode stack sets the format of the data to a stack (LIFO). This is the default behavior of the program.

Usage: stack
##### The queue opcode

The opcode queue sets the format of the data to a queue (FIFO).

Usage: queue
When switching mode:

The top of the stack becomes the front of the queue
The front of the queue becomes the top of the stack
### [Brainf*ck]
Write a Brainf*ck script that prints Holberton, followed by a new line.
```julien@ubuntu:~/bf$ bf 1000-holberton.bf 
Holberton
julien@ubuntu:~/bf$
```
##### [add 2 digit]
Add two digits given by the user.

Read the two digits from stdin, add them, and print the result
The total of the two digits with be one digit-long (<10)
```julien@ubuntu:~/bf$ bf ./1001-add.bf
81
9julien@ubuntu:~/bf$
```
##### [Multiplication]
Multiply two digits given by the user.

* Read the two digits from stdin, multiply them, and print the result
* The result of the multiplication will be one digit-long (<10)
```julien@ubuntu:~/bf$ bf 1002-mul.bf
24
8julien@ubuntu:~/bf$
```
##### [multiplication with newline]
Multiply two digits given by the user.
Read the two digits from stdin, multiply them, and print the result, followed by a new line
```julien@ubuntu:~/bf$ bf 1003-mul.bf 
77
49
julien@ubuntu:~/bf$ 
```
---

## Author
* **Van Phan** - [vdphan](https://github.com/vdphan)
* **Tim Assavarat** - [tassavarat](https://github.com/tassavarat)