#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORY_SIZE 256
#define REGISTER_A_ADDR 102
#define REGISTER_B_ADDR 103
#define PC_ADDR 104
#define IR_ADDR 106

typedef struct memory_cell
{
    char mem[9];
} memory_cell;

memory_cell memory[MEMORY_SIZE];

typedef struct opcode
{
    char mnemonic[5];
    char code[9];
} opcode;

opcode ops[] = {
    {"ADD", "00000001"}, {"ADDI", "00000010"}, {"ADDM", "00000011"}, {"AND", "00000100"}, {"ANDI", "00000101"}, {"ANDM", "00000110"}, {"OR", "00000111"}, {"ORI", "00001000"}, {"ORM", "00001001"}, {"SUB", "00001010"}, {"SUBI", "00001011"}, {"SUBM", "00001100"}, {"INC", "00001101"}, {"DEC", "00001110"}, {"SHL", "00001111"}, {"SHR", "00010000"}, {"BRE", "00010001"}, {"BRN", "00010010"}, {"J", "00010011"}, {"NOR", "00010100"}, {"LDA", "00010101"}, {"STR", "00010110"}, {"SWP", "00010111"}, {"LESS", "00011000"}, {"GRT", "00011001"}, {"PRI", "00011010"}, {"PRII", "00011011"}, {"PRIM", "00011100"}, {"EXIT", "00011101"}};

char *int_to_binary(int decimal_number)
{
    char *binary = (char *)malloc(9);
    binary[8] = '\0';
    for (int i = 7; i >= 0; i--)
    {
        binary[i] = (decimal_number & 1) + '0';
        decimal_number >>= 1;
    }
    return binary;
}

int binary_to_decimal(const char binary_number[])
{
    int decimal_number = 0;
    for (int i = 0; i < 8; i++)
    {
        decimal_number <<= 1;
        decimal_number += binary_number[i] - '0';
    }
    return decimal_number;
}

char *find_opcode(opcode *ops, const char *mnemonic)
{
    for (int i = 0; i < 29; i++)
    {
        if (strcmp(ops[i].mnemonic, mnemonic) == 0)
        {
            return ops[i].code;
        }
    }
    return NULL;
}

void load_to_memory(int addr, const char *value)
{
    strcpy(memory[addr].mem, value);
}

void execute_instruction()
{
    int pc_value = binary_to_decimal(memory[PC_ADDR].mem);
    int ir_value = 0;
    

    char operand1[9], operand2[9];
    int reg1, reg2, imm, mem_addr;
    int reg1_addr, reg2_addr;

    while (ir_value < pc_value)
    {
        char *opcode = memory[ir_value].mem;
        strcpy(operand1, memory[ir_value + 1].mem);
        strcpy(operand2, memory[ir_value + 2].mem);

        printf("Executing instruction at PC=%d: %s %s %s\n", ir_value, opcode, operand1, operand2);

        if (strcmp(opcode, "00000001") == 0)
        {
            reg1_addr = (strcmp(operand1,int_to_binary(REGISTER_A_ADDR))==0==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            reg2_addr = (strcmp(operand2,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            int value1 = binary_to_decimal(memory[reg1_addr].mem);
            int value2 = binary_to_decimal(memory[reg2_addr].mem);
            char *sum = int_to_binary(value1 + value2);
            load_to_memory(reg1_addr, sum);
  
        }
        else if (strcmp(opcode, "00000010") == 0)
        {
            imm = binary_to_decimal(operand2);
            reg1_addr = (strcmp(operand1,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            int value1 = binary_to_decimal(memory[reg1_addr].mem);
            char *sum = int_to_binary(value1 + imm);
            load_to_memory(reg1_addr, sum);
  
        }
        else if (strcmp(opcode, "00000011") == 0)
        { 
            reg1_addr = (strcmp(operand1,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            reg2_addr = (strcmp(operand2,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            int value1 = binary_to_decimal(memory[reg1_addr].mem);
            mem_addr = binary_to_decimal(memory[reg2_addr].mem);
            int value2 = binary_to_decimal(memory[mem_addr].mem);
            char *sum = int_to_binary(value1 + value2);
            load_to_memory(reg1_addr, sum);
  
        }
        else if (strcmp(opcode, "00000100") == 0)
        { 
            reg1_addr = (strcmp(operand1,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            reg2_addr = (strcmp(operand2,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            int value1 = binary_to_decimal(memory[reg1_addr].mem);
            int value2 = binary_to_decimal(memory[reg2_addr].mem);
            char *result = int_to_binary(value1 & value2);
            load_to_memory(reg1_addr, result);
            
        }
        else if (strcmp(opcode, "00000101") == 0)
        { 
            imm = binary_to_decimal(operand2);
            reg1_addr = (strcmp(operand1,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            int value1 = binary_to_decimal(memory[reg1_addr].mem);
            char *result = int_to_binary(value1 & imm);
            load_to_memory(reg1_addr, result);
            
        }
        else if (strcmp(opcode, "00000110") == 0)
        { 
            reg1_addr = (strcmp(operand1,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            reg2_addr = (strcmp(operand2,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            int value1 = binary_to_decimal(memory[reg1_addr].mem);
            mem_addr = binary_to_decimal(memory[reg2_addr].mem);
            int value2 = binary_to_decimal(memory[mem_addr].mem);
            char *result = int_to_binary(value1 & value2);
            load_to_memory(reg1_addr, result);
            
        }
        else if (strcmp(opcode, "00000111") == 0)
        {
            reg1_addr = (strcmp(operand1,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            reg2_addr = (strcmp(operand2,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            int value1 = binary_to_decimal(memory[reg1_addr].mem);
            int value2 = binary_to_decimal(memory[reg2_addr].mem);
            char *result = int_to_binary(value1 | value2);
            load_to_memory(reg1_addr, result);
            
        }
        else if (strcmp(opcode, "00001000") == 0)
        {
            imm = binary_to_decimal(operand2);
            reg1_addr = (strcmp(operand1,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            int value1 = binary_to_decimal(memory[reg1_addr].mem);
            char *result = int_to_binary(value1 | imm);
            load_to_memory(reg1_addr, result);
            
        }
        else if (strcmp(opcode, "00001001") == 0)
        { 
            reg1_addr = (strcmp(operand1,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            reg2_addr = (strcmp(operand2,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            int value1 = binary_to_decimal(memory[reg1_addr].mem);
            mem_addr = binary_to_decimal(memory[reg2_addr].mem);
            int value2 = binary_to_decimal(memory[mem_addr].mem);
            char *result = int_to_binary(value1 | value2);
            load_to_memory(reg1_addr, result);
            
        }
        else if (strcmp(opcode, "00001010") == 0)
        { 
            reg1_addr = (strcmp(operand1,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            reg2_addr = (strcmp(operand2,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            int value1 = binary_to_decimal(memory[reg1_addr].mem);
            int value2 = binary_to_decimal(memory[reg2_addr].mem);
            char *result = int_to_binary(value1 - value2);
            load_to_memory(reg1_addr, result);
            
        }
        else if (strcmp(opcode, "00001011") == 0)
        { 
            imm = binary_to_decimal(operand2);
            reg1_addr = (strcmp(operand1,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            int value1 = binary_to_decimal(memory[reg1_addr].mem);
            char *result = int_to_binary(value1 - imm);
            load_to_memory(reg1_addr, result);
            
        }
        else if (strcmp(opcode, "00001100") == 0)
        { 
            reg1_addr = (strcmp(operand1,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            reg2_addr = (strcmp(operand2,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            int value1 = binary_to_decimal(memory[reg1_addr].mem);
            mem_addr = binary_to_decimal(memory[reg2_addr].mem);
            int value2 = binary_to_decimal(memory[mem_addr].mem);
            char *result = int_to_binary(value1 - value2);
            load_to_memory(reg1_addr, result);
            
        }
        else if (strcmp(opcode, "00001101") == 0)
        { 
            reg1_addr = (strcmp(operand1,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            reg2_addr = (strcmp(operand2,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            int value1 = binary_to_decimal(memory[reg1_addr].mem);
            char *result = int_to_binary(value1 + 1);
            load_to_memory(reg1_addr, result);
            
        }
        else if (strcmp(opcode, "00001110") == 0)
        { 
            reg1_addr = (strcmp(operand1,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            int value1 = binary_to_decimal(memory[reg1_addr].mem);
            char *result = int_to_binary(value1 - 1);
            load_to_memory(reg1_addr, result);
            
        }
        else if (strcmp(opcode, "00001111") == 0)
        {
            reg1_addr = (strcmp(operand1,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            int value1 = binary_to_decimal(memory[reg1_addr].mem);
            char *result = int_to_binary(value1 << 1);
            load_to_memory(reg1_addr, result);
            
        }
        else if (strcmp(opcode, "00010000") == 0)
        { 
            reg1_addr = (strcmp(operand1,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            int value1 = binary_to_decimal(memory[reg1_addr].mem);
            char *result = int_to_binary(value1 >> 1);
            load_to_memory(reg1_addr, result);
            
        }
        else if (strcmp(opcode, "00010001") == 0)
        { 

            imm = binary_to_decimal(operand2);
            reg1_addr = (strcmp(operand1,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            int value1 = binary_to_decimal(memory[reg1_addr].mem);
            if (value1 == 0)
            {
                char *new_pc_value = int_to_binary(imm);
                load_to_memory(PC_ADDR, new_pc_value);
            }
        }
        else if (strcmp(opcode, "00010010") == 0)
        { 
            imm = binary_to_decimal(operand2);
            reg1_addr = (strcmp(operand1,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            int value1 = binary_to_decimal(memory[reg1_addr].mem);
            if (value1 != 0)
            {
                char *new_pc_value = int_to_binary(imm);
                load_to_memory(PC_ADDR, new_pc_value);
            }
        }
        else if (strcmp(opcode, "00010011") == 0)
        { 
            imm = binary_to_decimal(operand1);
            char *new_pc_value = int_to_binary(imm);
            load_to_memory(PC_ADDR, new_pc_value);
        }
        else if (strcmp(opcode, "00010100") == 0)
        { 
            reg1_addr = (strcmp(operand1,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            reg2_addr = (strcmp(operand2,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            int value1 = binary_to_decimal(memory[reg1_addr].mem);
            int value2 = binary_to_decimal(memory[reg2_addr].mem);
            char *result = int_to_binary(~(value1 | value2));
            load_to_memory(reg1_addr, result);
            
        }
        else if (strcmp(opcode, "00010101") == 0)
        { 
            reg1_addr = (strcmp(operand1,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            reg2_addr = (strcmp(operand2,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            mem_addr = binary_to_decimal(memory[reg2_addr].mem);
            strcpy(memory[reg1_addr].mem, memory[mem_addr].mem);
        }
        else if (strcmp(opcode, "00010110") == 0)
        {
            reg1_addr = (strcmp(operand1,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            reg2_addr = (strcmp(operand2,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            mem_addr = binary_to_decimal(memory[reg2_addr].mem);
            strcpy(memory[mem_addr].mem, memory[reg1_addr].mem);
        }
        else if (strcmp(opcode, "00010111") == 0)
        { 
            reg1_addr = (strcmp(operand1,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            reg2_addr = (strcmp(operand2,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            char temp[9];
            strcpy(temp, memory[reg1_addr].mem);
            strcpy(memory[reg1_addr].mem, memory[reg2_addr].mem);
            strcpy(memory[reg2_addr].mem, temp);
        }
        else if (strcmp(opcode, "00011000") == 0)
        {
            reg1_addr = (strcmp(operand1,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            reg2_addr = (strcmp(operand2,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            int value1 = binary_to_decimal(memory[reg1_addr].mem);
            int value2 = binary_to_decimal(memory[reg2_addr].mem);
            char *result = int_to_binary(value1 < value2 ? 1 : 0);
            load_to_memory(reg1_addr, result);
            
        }
        else if (strcmp(opcode, "00011001") == 0)
        {
            reg1_addr = (strcmp(operand1,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            reg2_addr = (strcmp(operand2,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            int value1 = binary_to_decimal(memory[reg1_addr].mem);
            int value2 = binary_to_decimal(memory[reg2_addr].mem);
            char *result = int_to_binary(value1 > value2 ? 1 : 0);
            load_to_memory(reg1_addr, result);
            
        }
        else if (strcmp(opcode, "00011010") == 0)
        { 
            reg1_addr = (strcmp(operand1,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            int value1 = binary_to_decimal(memory[reg1_addr].mem);
            printf("Value in %c: %d\n", reg1, value1);
        }
        else if (strcmp(opcode, "00011011") == 0)
        { 
            imm = binary_to_decimal(operand1);
            printf("Immediate value: %d\n", imm);
        }
        else if (strcmp(opcode, "00011100") == 0)
        {
            reg1_addr = (strcmp(operand1,int_to_binary(REGISTER_A_ADDR))==0) ? REGISTER_A_ADDR : REGISTER_B_ADDR;
            mem_addr = binary_to_decimal(memory[reg1_addr].mem);
            int value1 = binary_to_decimal(memory[mem_addr].mem);
            printf("Value in memory[%d]: %d\n", mem_addr, value1);
        }
        else if (strcmp(opcode, "00011101") == 0)
        { // EXIT
            exit(0);
        }
        ir_value++;
        char *new_pc_value = int_to_binary(pc_value + 3);
        load_to_memory(PC_ADDR, new_pc_value);
        free(new_pc_value);
    }

    
}

void load_program(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    char line[50];
    int pc_value = 0;
    load_to_memory(PC_ADDR, int_to_binary(pc_value));

    while (fgets(line, sizeof(line), file))
    {
        line[strcspn(line, "\n")] = 0;

        char *token = strtok(line, " ");
        if (!token)
            continue;

        char *opcode = find_opcode(ops, token);
        if (!opcode)
            continue;

        load_to_memory(pc_value++, opcode);
        load_to_memory(IR_ADDR, opcode);

        char *operand1 = strtok(NULL, " ");
        if (operand1)
        {
            if (operand1[0] >= 'A' && operand1[0] <= 'Z')
            {
                int reg_addr = (operand1[0] == 'A') ? REGISTER_A_ADDR : REGISTER_B_ADDR;
                load_to_memory(pc_value++, int_to_binary(reg_addr));
                load_to_memory(IR_ADDR + 1, int_to_binary(reg_addr));
            }
            else
            {
                int imm = atoi(operand1);
                load_to_memory(pc_value++, int_to_binary(imm));
                load_to_memory(IR_ADDR + 1, int_to_binary(imm));
            }
        }
        else
        {
            load_to_memory(pc_value++, "00000000");
            load_to_memory(IR_ADDR + 1, "00000000");
        }

        char *operand2 = strtok(NULL, " ");
        if (operand2)
        {
            if (operand2[0] >= 'A' && operand2[0] <= 'Z')
            {
                int reg_addr = (operand2[0] == 'A') ? REGISTER_A_ADDR : REGISTER_B_ADDR;
                load_to_memory(pc_value++, int_to_binary(reg_addr));
                load_to_memory(IR_ADDR + 2, int_to_binary(reg_addr));
            }
            else
            {
                int imm = atoi(operand2);
                load_to_memory(pc_value++, int_to_binary(imm));
            }
        }
        else
        {
            load_to_memory(pc_value++, "00000000");
            load_to_memory(IR_ADDR + 2, "00000000");
        }
        load_to_memory(PC_ADDR, int_to_binary(pc_value));
    }

    fclose(file);
}

int main()
{
    char filename[50];
    while (1)
    {
        printf("Enter the name of the assembly code file (or '0' to exit): ");
        scanf("%s", filename);

        if (strcmp(filename, "0") == 0)
            break;

        if (strstr(filename, ".asm") == NULL)
        {
            printf("Error: File must have a '.asm' extension.\n");
            continue;
        }

        load_program(filename);
        int i = 0;
        for (i = 0; i < 120; i++)
        {
            printf("%d %s\n", i, memory[i].mem);
        }
        execute_instruction();
    }

    return 0;
}
