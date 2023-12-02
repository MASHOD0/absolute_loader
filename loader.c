#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct object_code {
int locctr;
char byte[5];
};
struct object_code code[200];

void main() {

  FILE *fp1, *fp2;
  
  char input[15];
  
  int i, len, n=0, count=0, inc=0, textloc, tlen, tloc=0, num=0, loc;
  
  clrscr();
  
  fp1=fopen(“lout.dat”, “r”);
  fp2=fopen(“loadout.dat”, “w”);
  rewind(fp1);
  rewind(fp2);
  
  fscanf(fp1, “%s”, input);

  if(strcmp(input, “H”)==0) {
    for(i=0; i<4; i++) {
      if(i==1)
        fscanf(fp1, “%x”, &loc);
      else
        fscanf(fp1, “%s”, input);
      }
  }

  tloc=loc;
  
  while(strcmp(input, “E”)!=0) {
  
    if(strcmp(input, “T”)==0) {
      fscanf(fp1, “%x”, &textloc);
    
      for(i=0; i<(textloc-(tloc+tlen)); i++) {
      
        strcpy(code[inc].byte, “xx”);
        code[inc++].locctr=loc++;
      }
      
      fscanf(fp1, “%x”, &tlen);
      tloc=textloc;
    }
    else {
    len=strlen(input);
    for(i=0; i<len; i++) {
      code[inc].byte[num++] = input[i];
      if(num>1) {
        code[inc].locctr=loc;
        loc++;
        inc++;   
        num=0; 
      }
    }
  }
  fscanf(fp1, “%s”, input);
  }
  n=0;
  i=0;
  count=0;
  fprintf(fp2, “%x\t”, code[i].locctr);
  for(i=0; i<inc; i++) {
    fprintf(fp2, “%s”, code[i].byte);
    n++;
    if(n>3){
      fprintf(fp2, “\t”);
      n=0;
      count++;
    if(count>3){
      fprintf(fp2, “\n%x\t”, code[i+1].locctr);
      count=0;
    }
  }
  getch();
}
