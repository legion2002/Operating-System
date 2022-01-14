#include <stdio.h>

int main(int argc, char *argv[]){

    FILE *source, *destination;
    
    source = fopen(argv[1], "rb");
    destination = fopen(argv[2], "wb");
    
    char transporter[1];
    
    

    while(fread(&transporter,sizeof(transporter),1,source) != 0){

        fwrite(&transporter,sizeof(transporter),1,destination);
    }
    fclose(source);
    fclose(destination);
   
    return 0;
}
