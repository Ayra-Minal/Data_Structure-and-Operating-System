#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void displayfilecontents(const char *filename);
int main() {
    char a[10], ad[10], label[10], opcode[10], operand[10], symbol[10];
    int start, diff, i, address, add, len, actual_len, finaddr, prevaddr, j = 0;
    char mnemonic[15][15] = {"LDA", "STA", "LDCH", "STCH"};
    char code[15][15] = {"33", "44", "53", "57"};
    FILE *fp1, *fp2, *fp3, *fp4;

    // Open files
    fp1 = fopen("output.txt", "w");
    fp2 = fopen("symtab.txt", "r");
    fp3 = fopen("intermediate.txt", "r");
    fp4 = fopen("objcode.txt", "w");

    // Read the first line
    fscanf(fp3, "%s\t%s\t%s", label, opcode, operand);
    while (strcmp(opcode, "END") != 0) {
        prevaddr = address;
        fscanf(fp3, "%d%s%s%s", &address, label, opcode, operand);
    }
    finaddr = address;
    fclose(fp3);
    fp3 = fopen("intermediate.txt", "r");

    // Process START opcode
    fscanf(fp3, "\t%s\t%s\t%s", label, opcode, operand);
    if (strcmp(opcode, "START") == 0) {
        fprintf(fp1, "\t%s\t%s\t%s\n", label, opcode, operand);
        fprintf(fp4, "H^%s^00%s^00%d\n", label, operand, finaddr);
        fscanf(fp3, "%d%s%s%s", &address, label, opcode, operand);
        start = address;
        diff = prevaddr - start;
        fprintf(fp4, "T^00%d^%d", address, diff);
    }

    // Main loop for processing instructions
    while (strcmp(opcode, "END") != 0) 
    {
        if (strcmp(opcode, "BYTE") == 0) {
            fprintf(fp1, "%d\t%s\t%s\t%s\t", address, label, opcode, operand);
            len = strlen(operand);
            actual_len = len - 3;
            fprintf(fp4, "^");
            for (i = 2; i < (actual_len + 2); i++) {
                // Convert each byte to hexadecimal and print
                sprintf(ad, "%X", operand[i]);
                fprintf(fp1, "%s", ad);
                fprintf(fp4, "%s", ad);
            }
            fprintf(fp1, "\n");
        }
        else if (strcmp(opcode, "WORD") == 0) {
            // Convert the operand (integer) to a string with leading zeros
            sprintf(a, "%06X", atoi(operand));
            fprintf(fp1, "%d\t%s\t%s\t%s\t00000%s\n", address, label, opcode, operand, a);
            fprintf(fp4, "^00000%s", a);
        }
        else if ((strcmp(opcode, "RESB") == 0) || (strcmp(opcode, "RESW") == 0)) {
            fprintf(fp1, "%d\t%s\t%s\t%s\n", address, label, opcode, operand);
        }
        else {
            // Search for the corresponding opcode in mnemonic array
            while (strcmp(opcode, mnemonic[j]) != 0) j++;
            if (strcmp(operand, "COPY") == 0)
                fprintf(fp1, "%d\t%s\t%s\t%s\t%s0000\n", address, label, opcode, operand, code[j]);
            else {
                rewind(fp2);
                fscanf(fp2, "%s%d", symbol, &add);
                while (strcmp(operand, symbol) != 0) {
                    fscanf(fp2, "%s%d", symbol, &add);
                }
                // Write the instruction in output and objcode files
                fprintf(fp1, "%d\t%s\t%s\t%s\t%s%d\n", address, label, opcode, operand, code[j], add);
                fprintf(fp4, "^%s%d", code[j], add);
            }
        }
        fscanf(fp3, "%d%s%s%s", &address, label, opcode, operand);
    }

    // End of program (END opcode)
    fprintf(fp1, "%d\t%s\t%s\t%s\n", address, label, opcode, operand);
    fprintf(fp4, "\nE^00%d", start);

    // Close all files
    fclose(fp4);
    fclose(fp3);
    fclose(fp2);
    fclose(fp1);
    displayfilecontents("output.txt");
    displayfilecontents("intermediate.txt");
    displayfilecontents("objcode.txt");
    return 0;
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

