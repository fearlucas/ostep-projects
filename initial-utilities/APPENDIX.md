# Unix

## wgrep
- Why use char** in **getline** ?
1. Dynamic Memory Allocation:
getline needs to allocate enough memory to hold the entire line it reads from the input stream, regardless of its length. Since the length of the line is not known beforehand, it uses dynamic memory allocation (usually with new or malloc) to create a buffer of the appropriate size.
A double pointer allows getline to **modify the address** stored in the pointer passed to it(**C copy value**). This means that after getline has allocated memory for the line, it updates the original pointer to point to this newly allocated memory. This way, the caller of getline receives the address of the buffer containing the read line.

2. Modifying the Original Pointer:
getline needs to update the pointer passed to it so that the caller of the function can access the newly allocated memory where the line is stored. If a single pointer were used, any changes made to it inside the function would be lost when the function returns, and the caller would not have access to the allocated memory.

Further: read this [stackoverflow](https://stackoverflow.com/questions/5744393/why-is-the-first-argument-of-getline-a-pointer-to-pointer-char-instead-of-c);
