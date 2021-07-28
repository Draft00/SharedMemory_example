#ifndef SHAREDMEMORY_EXAMPLE_SHR_HEADER_H
#define SHAREDMEMORY_EXAMPLE_SHR_HEADER_H

#include <sys/types.h>
#include <sys/mman.h>

#include <fcntl.h> //oflag
#include <unistd.h>
#include <iostream>
#include <string>
#include <cstring>

#define SHR_MAX_LEN 100
#define SHR_OBJECT_NAME "SharedMemory12345"


#endif //SHAREDMEMORY_EXAMPLE_SHR_HEADER_H
