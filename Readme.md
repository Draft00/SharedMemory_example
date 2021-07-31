## Simple example how to use shared memory to communicate between two separate processes

### Build: 
> `cmake . && make`
 
### Run:
First start a writer:
> `./writer`

Second start a reader:
> `./reader`

### About implementation: 
writer - Create a new memory object (or Open if object already exist), Set memory object size and Write string with memcpy().

reader - (Open a memory object and Read a data by mmap) or Close a memory object. 
