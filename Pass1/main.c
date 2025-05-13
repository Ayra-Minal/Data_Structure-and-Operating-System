#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void passone();
void displayfilecontents(const char *filename);
int main()
{
    passone();
    return 0;
} 
void passone()
{
    FILE *fp1=fopen("input.txt","r");
    FILE *fp2=fopen("optab.txt","r");
    FILE *fp3=fopen("symtab.txt","w");
    FILE *fp4=fopen("intermediate.txt","w");
    FILE *fp5=fopen("length.txt","w");
    if(!fp1 ||!fp2 ||!fp3 ||!fp4 ||!fp5)
    {
        printf("cant open");
        exit(1);
    }
    char label[10],opcode[10],operand[10],code[10],mnemonic[3];
    int locctr=0,start=0,length=0;
    
    fscanf(fp1,"%s%s%s",label,opcode,operand);
    if(strcmp(opcode,"START")==0)
    {
        start=atoi(operand);
        locctr=start;
        fprintf(fp4,"\t%s\t%s\t%s\n",label,opcode,operand);
        fscanf(fp1,"%s%s%s",label,opcode,operand);
    }
    while(strcmp(opcode,"END")!=0)
    {
        //write to intermediate and then check other files
        fprintf(fp4,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
        //symtab shit
        if(strcmp(label,"")!=0)
        {
            fprintf(fp3,"%s\t%d\n",label,locctr);
        }
        //optab shit
        
        rewind(fp2);
        int found=0;
        while(fscanf(fp2,"%s%s",code,mnemonic)!=EOF)
        {
            if(strcmp(opcode,code)==0)
            {
                locctr+=3;
                found=1;
                break;
            }
        }
        //if not found in optab
        if(!found)
        {
            if(strcmp(opcode,"WORD")==0)
            {
                locctr+=3;
            }
            else if(strcmp(opcode,"RESW")==0)
            {
                locctr+=3*atoi(operand);
            }
            else if(strcmp(opcode,"RESB")==0)
            {
                locctr+=atoi(operand);
            }
            else if(strcmp(opcode,"BYTE")==0)
            {
                if(operand[0]=='C')
                {
                    locctr+=strlen(operand)-3;
                }
                if(operand[0]=='X')
                {
                    locctr+=(strlen(operand)-3)/2;
                }
            }
        }
        fscanf(fp1, "%s %s %s", label, opcode, operand);
    }
    fprintf(fp4,"%d\t%s\t%s\t%s",locctr,label,opcode,operand);
    length=locctr-start;
    fprintf(fp5,"%d",length);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);
    
    displayfilecontents("input.txt");
    displayfilecontents("intermediate.txt");
    displayfilecontents("symtab.txt");
    printf("\nthe length of file is :%d\n",length);    
}

void displayfilecontents(const char *filename)
{
    FILE *fp=fopen(filename,"r");
    if(!fp)
    {
        printf("cant open");
        return;
    }
    char ch;
    printf("\ncontent of %s:\n\n",filename);
    while((ch=fgetc(fp))!=EOF)
    {
        printf("%c",ch);
    }
    fclose(fp);
}
