// #include <stdio.h>
// #include <stdlib.h>
// #include <strings.h>

// struct Token{

//     char address[100];
//     char label[100];
//     char opcode[100];
//     char operands[100];
// };


// struct SymbolTable{
//     char label[100];
//     int address;
// };

// struct SymbolTable sym[100];

// void tokenise(char line[1000],struct Token *token){
//     int res = 0;
//     res = sscanf(line, "%s %s %s %s", token->address, token->label, token->opcode, token->operands);
//     if(res==3){
//         strcpy(token->operands, "");
//     }else if (res==2)
//     {
//         strcpy(token->opcode, token->address);
//         strcpy(token->operands, token->label);
//     }
// }

// struct Token search_opcode(FILE *optab,char token[100]){

//     struct Token token2;
//     char line[100];
//     while(fgets(line,sizeof(line),optab)){
//         tokenise(line, &token2);
//         if(strcmp(token2.opcode,token)==0){
//             return token2;
//         }
//     }
// }

// int main(){
//     struct Token token;
//     struct Token token1;
//     struct Token token2;
//     int Line = 0, tar_address, address = 0, n = 1;
//     FILE *input, *output, *optab, *symtab, *object, *len;
//     char line[1000], start_label[10];

//     input = fopen("intermediate.txt", "r+");
//     output = fopen("output_pass2.txt", "w+");
//     optab = fopen("Optable.txt", "r+");
//     symtab = fopen("symtab.txt", "r+");
//     object = fopen("object.txt", "w+");
//     len = fopen("length.txt", "r+");


//     //read the symbolTable and store in the array
//     while(fscanf(symtab,"%s %x",sym[Line].label,&sym[Line].address))
//         Line++;

//     rewinf(symtab);

//     int input_line = 1;
//     //find the total lines in the intermediate file
//     while(fscanf(input,"%s %s %s %s",token.address,token.label,token.opcode,token.operands))
//         input_line++;

//     rewind(input);

//     //read the first Line
//     fgets(line, 1000, input);
//     tokenise(line, &token1);
//     fgets(line, 10, len);

// //intinalised the header record
//     int startAdress = atoi(token1.operands);
//     fprintf(output, "%-10x %-10s %-10s %-10s\n", token1.address, token1.label, token1.opcode, token1.operands);
//     fprintf(object, "H^%s^00%04d^%s\n", token1.label, token1.operands, line);
//     strcpy(start_label, token1.label);

//     int text_record_length = 0x00;

//     while(fgets(line,sizeof(line),input)!=NULL){
//         tokenise(line, &token);
//         if(text_record_length==0){
//             fprintf(object, "T^%s", token.address);
//         }
//         if(strcmp(token.opcode,"WORD")==0){

//         }else if(strcmp(token.opcode,"RSUB")==0){

//         }else if(strcmp(token.opcode,"RESB")==0||strcmp(token.opcode,"RESW")==0){

//         }else if(strcmp(token.opcode,"BYTE")==0){
//             if(token.operands[0]=='C'){

//             }else if(token.operands[0]='X'){

//             }
//         }else if(strcmp(token.opcode,"END")==0){
            
//         }else{
//             rewind(optab);
//             tar_address = 0;
//             int i;

//             for (i = 0; i < Line;i++){
//                 if(strcmp(token.label,sym[i].label)==0){
//                     tar_address = sym[i].address;
//                 }
//             }
//         }
//     }
// }


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct estab{
    char csname[10];
    char extsym[10];
    int address;
    int len;
} es[20];


int main(){
    char line[10],name[10];
    int programaddress, csaddr,count=0,add,len;
    FILE *input, *output;
    input = fopen("INPUT.txt", "r+");
    output = fopen("ESTAB.txt", "w+");
    printf("Enter the starting addressog linking:");
    scanf("%x", &programaddress);
    csaddr = programaddress;
    fscanf(input, "%s", line);

    while(strcmp(line,"END")!=0){

        if(strcmp(line,"H")==0){
            fscanf(input, "%s", name);
            strcpy(es[count].csname,name);
            strcpy(es[count].extsym, "  ");
            fscanf(input, "%x", &add);
            es[count].address = add+csaddr;
            fscanf(input, "%x", &len);
            es[count].len = len;
            fprintf(output, "%s ** %x %x\n", es[count].csname, es[count].address, es[count].len);
            count++;
        }else if(strcmp(line,"D")==0){
            fscanf(input, "%s", line);
            while (strcmp(line, "R") != 0)
            {
                strcpy(es[count].csname, "  ");
                strcpy(es[count].extsym, line);
                fscanf(input, "%x", &add);
                es[count].address = add + csaddr;
                fprintf(output, "** %s %x\n", es[count].extsym, es[count].address);
                count++;
                fscanf(input, "%s", line);
            }

            csaddr += len;
        }else if(strcmp(line,"T")==0){
            while(strcmp(line,"E")!=0)
                fscanf(input, "%s", line);
        }
        fscanf(input, "%s", line);
    }
    fclose(input);
    fclose(output);
    input= fopen("ESTAB.txt", "r");
    char ch = fgetc(input);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(input);
    }
    fclose(input);
    return 0;
}