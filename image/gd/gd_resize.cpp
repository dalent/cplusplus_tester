#include<gd.h>
#include <stdio.h>
#include<sys/stat.h>

void fromMemWebpResize(const char* inFile, const char* outFile, int quality){
    gdImagePtr im;
    FILE * in, *out;
    struct stat stat_buf;
    in = fopen(inFile, "rb");
    out = fopen(outFile, "wb");
    if(0 != fstat(fileno(in), &stat_buf)){
        fclose(in);
        fclose(out);
        printf("stat file failed");
        return ;
    }
    char *buffer = (char*)malloc(stat_buf.st_size);
    if (fread(buffer, 1, stat_buf.st_size, in) != stat_buf.st_size){
                /* Error */
        printf("read not equal size");
        return;
    }

    im = gdImageCreateFromJpegPtr(stat_buf.st_size, buffer);
    int size = 0;
    char * data = (char *) gdImageWebpPtrEx(im, &size, 100);
    if(fwrite(data, 1, size, out) != size){
        printf("write not equal size");
        return;
    }

    fclose(out);
    fclose(in);
    gdImageDestroy(im);
}

void fromFile(const char* inFile, const char* outFile, int quality){
    gdImagePtr im, om;
    FILE * in, *out;
    in = fopen(inFile, "rb");
    im = gdImageCreateFromPng(in);
    out = fopen(outFile, "wb");
    //gdImageWebpEx(im, out, quality);
    //gdImageSetInterpolationMethod(im, gdImageGetInterpolationMethod();
    //om = gdImageScale(im, 100, 66);
    int sx = gdImageSX(im);
    int sy = gdImageSY(im);
    om = gdImageCreateTrueColor(100,100);
    gdImageCopyResampled(om, im, 0, 0, 0, 0, 100, 100,sx,sy); 
    gdImagePng(om, out);
    fclose(out);
    fclose(in);
    gdImageDestroy(im);
    gdImageDestroy(om);
}

int main(int argc, char* argv[]){
    if(argc != 4){
        printf("%s,infile quality outfile", argv[0]);
        return -1;
    }
    int quality = atoi(argv[1]);
    if(quality < 0 || quality > 100) quality = 100;

    fromFile(argv[2], argv[3], quality);
    return 0;
}
