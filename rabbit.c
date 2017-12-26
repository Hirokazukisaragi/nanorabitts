#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc,char* argv[]){
  FILE *rfp,*wfp;
  if(argc != 4){
    printf("invalid arg!%d\n",argc);
    exit(1);
  }
  if(!(rfp = fopen(argv[1],"r"))){
    printf("read error!\n");
    exit(1);
  }
  char buf[512];
  char key[512];
  strcpy(key,argv[2]);
  char wname[1024];
  strcpy(wname,argv[1]);
  strcat(wname,"_c.crpt");
  if(!(wfp = fopen(wname,"w+"))){
    printf("write error!\n");
  }
  int i=0;
  int j=0;
  int len = strlen(key);
  if(!strcmp(argv[3],"e")){
    while(!feof(rfp)){
      printf("cryption!!\n");
      fread(buf,sizeof(char),1,rfp);
      if(key[i])i=0;
      buf[j] = buf[j]+key[i];
      if(feof(rfp))break;
      fwrite(buf,sizeof(char),1,wfp);
    }
  }
  if(!strcmp(argv[3],"d")){
    while(!feof(rfp)){
      printf("decryption!!\n");
      fread(buf,sizeof(char),1,rfp);
      if(key[i])i=0;
      if(feof(rfp))break;
      buf[j] = buf[j]-key[i];
      fwrite(buf,sizeof(char),1,wfp);
    }
  }
  
  fclose(rfp);
  fclose(wfp);
  return 0;
}
