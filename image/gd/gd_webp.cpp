#include<webp/decode.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
int main(int argc, char* argv[]){
    if(argc != 2){
        printf("%s,infile quality outfile", argv[0]);
        return -1;
    }

    FILE *in;
    struct stat stat_buf;
    in = fopen(argv[1], "rb");
    if(0 != fstat(fileno(in), &stat_buf)){
        fclose(in);
        printf("stat file failed");
        return  1;
    }
    char *buffer = (char*)malloc(stat_buf.st_size);
    if (fread(buffer, 1, stat_buf.st_size, in) != stat_buf.st_size){
                /* Error */
        printf("read not equal size");
        return 1;
    }

    int width = 0, height = 0;
    WebPGetInfo((const uint8_t*)buffer, stat_buf.st_size, &width, &height);
    uint8_t* buf = (uint8_t*)buffer;
    if(buf[20] == 0x2f){
        uint32_t intBit = 0L;
        intBit |= (uint32_t)buf[21];
        printf("%x\n", intBit);
        intBit |= buf[22]<<8;
        printf("%x\n", intBit);
        intBit |= buf[23]<<16;
        intBit |= buf[24]<<24;
        printf("%u\n", intBit&0x3fff);
        printf("%u\n", (intBit>>14)&0x3fff);
    }
    return 0;
}
