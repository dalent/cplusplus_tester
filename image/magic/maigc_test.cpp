#include <Magick++.h> 
#include<iostream>
using std::cout;
using namespace Magick;

int main(int argc, char* argv[]){
    if(argc != 4){
        printf("%s,infile outfile", argv[0]);
        return -1;
    }
    InitializeMagick(*argv);
    int quality = atoi(argv[1]);
    if(quality < 0 || quality > 100) quality = 1000;

     Image image;
     try{
         image.read(argv[2]);
         image.quality(quality);
         //image.strip();
         image.write(argv[3]);
     }catch(Exception & err){
         cout << err.what();
         return 1;
     }
    return 0;
}
