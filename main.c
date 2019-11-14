#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
int main(){
  struct stat buff;
  int fd = stat("main.c", &buff);
  long long size = buff.st_size;
  if(size >= 1073741824){
    printf("File size: %lld GB\n", size / 1073741824);
  }
  else if(size >= 1048576){
    printf("File size: %lld MB\n", size / 1048576);
  }
  else if(size >= 1024){
    printf("File size: %lld KB\n", size / 1024);
  }
  else{
    printf("File size: %lld B \n", size);
  }
  int perms = buff.st_mode;
  perms = perms % 01000;
  int sep[3];
  sep[0] = perms / 0100;
  sep[1] = (perms % 0100) / 010;
  sep[2] = (perms % 010);
  char lsl[9];
  lsl[0] = '-';
  for (int i = 0; i<3; i ++){
    if(sep[i] - 4 >= 0){
      sep[i] -= 4;
      lsl[(3*i)+1] = 'r';
    }
    else{
      lsl[(3*i)+1] = '-';
    }

    if(sep[i] - 2 >= 0){
      sep[i] -= 2;
      lsl[(3*i)+2] = 'w';
    }
    else{
      lsl[(3*i)+2] = '-';
    }

    if(sep[i] - 1 >= 0){
      sep[i] -= 1;
      lsl[(3*i)+3] = 'x';
    }
    else{
      lsl[(3*i)+3] = '-';
    }
  }
  printf("Permissions: %s\n", lsl);
  printf("Time of last access: %s\n", ctime(&buff.st_atime));
  return 0;
}
