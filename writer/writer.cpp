//
// Created by julia on 28.07.2021.
//
#include "../Shr_Header.h"

//usage: create|write ['text']

void Usage() {
    std::cout << "Usage: <write ['text'] (max len 100)" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        Usage();
        return -1;
    }

    uint16_t len = 0;

    int fd = 0, shm = 0;
    char *addr = nullptr;

    if (!strcmp(argv[1], "write")){
        len = strlen(argv[2]);
        len = (len <= SHR_MAX_LEN)?len:SHR_MAX_LEN;
    }
    else {
        Usage();
        return -1;
    }

    /* Create a new memory object */
    if ((shm = shm_open(SHR_OBJECT_NAME, O_CREAT|O_RDWR, 0777)) == -1){
        perror("shm_open"); //how can I use errno in C++?
        return -1;
    }

    /* Set memory object size */
    if (ftruncate(shm, SHR_MAX_LEN + 1) == -1){
        perror("ftruncate");
        return -1;
    }

    /*Map memory object */
    addr = static_cast<char *>(mmap(0, SHR_MAX_LEN + 1, PROT_WRITE | PROT_READ, MAP_SHARED, shm, 0));
    if ( addr == (char*)-1 ) {
        perror("mmap");
        return -1;
    }

    std::cout << "Trying to write: " << argv[2] << std::endl;
    memcpy(addr, argv[2], len);
    addr[len] = '\0';

    munmap(addr, SHR_MAX_LEN);
    close(shm);

    std::cout << "End program. You can try read from shared memory and close shared memory in reader" << std::endl;

}

