
#include "../Shr_Header.h"

void Usage() {
    std::cout << "Usage: <read | close" << std::endl;
}

int main(int argc, char* argv[]){
    if (argc < 2) {
        Usage();
        return -1;
    }

    int shm = 0;
    char *addr = nullptr;

    if (!strcmp(argv[1], "read")){
        if ((shm = shm_open(SHR_OBJECT_NAME, O_RDWR, 0777)) == -1){
            perror("shm_open"); //how can I use errno in C++?
            return -1;
        }
        addr = static_cast<char *>(mmap(0, SHR_MAX_LEN + 1, PROT_WRITE | PROT_READ, MAP_SHARED, shm, 0));
        if (addr == (char*)-1 ) {
            perror("mmap");
            return -1;
        }
        std::cout << "Trying to read." << std::endl;
        std::cout << "Got from shared memory: " << addr << std::endl;
    }
    else if (!strcmp(argv[1], "close")){
        shm_unlink(SHR_OBJECT_NAME);
        std::cout << "Shared Memory closed!" << std::endl;
    }
    else {
        Usage();
        return -1;
    }
}
