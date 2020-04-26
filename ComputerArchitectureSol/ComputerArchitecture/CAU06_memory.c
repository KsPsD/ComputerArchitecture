#include<stdio.h>
#include<stdlib.h>
 unsigned char progMEM[0x100000], dataMEM[0x100000], stakMEM[0x100000];

int main()
{
   
    int b_read, hw_read, w_read;


    MEM(0x00400001, 11, 1, 0);
    b_read = MEM(0x00400001, 124, 0, 0);

    MEM(0x00400001, 124, 1, 1);
    hw_read = MEM(0x00400001, 124, 0, 1);

    MEM(0x00400001, 124, 1, 2);
    w_read=MEM(0x00400001, 124, 0, 2);
    
   /* printf("byte value : %d \n", b_read);

    printf("half word value: %d \n", hw_read);
    
    printf("word value : %d \n", w_read);*/

    
	return 0;
}

int MEM(unsigned int A, int V, int nRW, int S) {
    unsigned int sel, offset;
    unsigned char* pM;
    sel = A >> 20;    offset = A & 0xFFFFF;
    if (sel == 0x004) pM = progMEM;         // program memory

    else if (sel == 0x100) pM = dataMEM;  // data memory

    else if (sel == 0x7FF) pM = stakMEM;  // stack

    else {

        printf("No memory\n");
        exit (1);
    }
    if (S == 0) { 
        // byte
        if (nRW == 0) { // read
            //printf("%d \n",*(pM+offset));
            printf("byte read size is %d \n", sizeof(*(pM + offset)));
            printf("byte read address: %x \n", (pM + offset));

            return *(pM + offset);
        }
        else if (nRW == 1) { // write
            *(pM + offset) = V;
            printf("byte write value : %d \n", *(pM + offset));
        }
    }
    else if (S == 1) { // half word

        if (nRW == 0) { // read
            //printf("%x", *(short*)(pM + offset));
            printf("half word read size is %d \n", sizeof(*(short*)(pM + offset)));
            printf("half word address: %x \n", (short*)(pM + offset));
            return *(short*)(pM + offset);
        }
        else if (nRW == 1) { // write
            *(pM + offset) = V;
           printf("half word write value : %x \n", *(pM + offset));
           return 0;

        }
    }
    else if (S == 2) {// word 여기서는 워드니까 4개 읽어야됨 //char 포인터 가져와서(int)캐스팅 변환 해도됨
    

        if (nRW == 0) { // read
            //printf("%x\n ", *(int*)(pM + offset));
            printf("word read size is %d \n", sizeof(*(int*)(pM + offset)));

            printf("word address: %x \n", (int*)(pM + offset));

            return *(int*)(pM + offset);

        }
        else if (nRW == 1) { // write
            *(pM + offset) = V;
            printf("word write value %x\n", *(pM + offset));
            return 0;
        }
    
    
    }
    else {
        printf("no Size");
            exit(1);
    }
}