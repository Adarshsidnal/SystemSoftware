#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char bitmask[4];
char binary_mask[13];

void convert_binary(char bitmask[4])
{
    strcpy(binary_mask, "");

    for (int i = 0; i < strlen(bitmask); i++)
    {
        switch (bitmask[i])
        {
        case '0':
            strcat(binary_mask, "0000");
            break;
        case '1':
            strcat(binary_mask, "0001");
            break;
        case '2':
            strcat(binary_mask, "0010");
            break;
        case '3':
            strcat(binary_mask, "0011");
            break;
        case '4':
            strcat(binary_mask, "0100");
            break;
        case '5':
            strcat(binary_mask, "0101");
            break;
        case '6':
            strcat(binary_mask, "0110");
            break;
        case '7':
            strcat(binary_mask, "0111");
            break;
        case '8':
            strcat(binary_mask, "1000");
            break;
        case '9':
            strcat(binary_mask, "1001");
            break;
        case 'A':
            strcat(binary_mask, "1010");
            break;
        case 'B':
            strcat(binary_mask, "1011");
            break;
        case 'C':
            strcat(binary_mask, "1100");
            break;
        case 'D':
            strcat(binary_mask, "1101");
            break;
        case 'E':
            strcat(binary_mask, "1110");
            break;
        case 'F':
            strcat(binary_mask, "1111");
            break;
        }
    }
}

int main()
{
    int start, final_add, opcode, address, text_rec_len;
    char prog_name[10], rec_type, rec_add[6], length[10], obj_code[6];

    FILE *fp1;
    fp1 = fopen("inputbit.txt", "r");

    if (fp1 == NULL)
    {
        printf("error in opening the file");
        return 1;
    }
    printf("\n enter the start address ");
    scanf("%x", &start);

    while (fscanf(fp1, "%c", &rec_type) != EOF)
    {
        if (rec_type == 'H')
        {
            fscanf(fp1, "%s %s %s", prog_name, rec_add, length);
        }
        else if (rec_type == 'T')
        {
            fscanf(fp1, "%x %x %s", &address, &text_rec_len, bitmask);
            address = address + start;
            convert_binary(bitmask);
            int j = 0;
            for (int i = 3; i <= text_rec_len; i = i + 3)
            {
                fscanf(fp1, "%6s", obj_code);

                opcode = (int)strtol(obj_code, NULL, 16) >> 16;
                final_add = (int)strtol(obj_code, NULL, 16) & 0xFFFF;

                if (binary_mask[j] == '1')
                    final_add = final_add + start;
                printf("%x \t %x%04x\n", address, opcode, final_add);
                address = address + 3;
                j++;
            }
        }
    }
    fclose(fp1);
    return 0;
}