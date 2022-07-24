#include<stdio.h>
#define bits 4
#define size 16

void Minterm() {

    char variables[bits];
    printf("Enter the variable names\n");
    for (int i = 0;i < bits;i++) {
        scanf("%c", variables[i]);
    }
    int minterms[size + 1] = { -2 };
    int dontcares[size + 1] = { -2 };
    printf("Enter the minterms and enter -1 when done:\n");
    int i = 0;
    while (1) {
        scanf("%d", minterms[i]);
        if (minterms[i] == -1) {
            break;
        }
    }
    printf("Enter the dontcares and enter -1 when done:\n");
    int j = 0;
    while (1) {
        scanf("%d", dontcares[j]);
        if (dontcares[j] == -1) {
            break;
        }
    }

    int grp0[1] = { -1 };
    int grp1[4] = { -1 };
    int grp2[6] = { -1 };
    int grp3[4] = { -1 };
    int grp4[1] = { -1 };

    for (int i = 0;i <= size;i++) {
        if (minterms[i] != -1) {
            int s = bits;
            int count = 0;
            while (s--) {
                if (minterms[i] & 1 == 1) {
                    count++;
                }
                minterms[i] = minterms[i] >> 1;
            }
            switch (count) {
            case 0:  grp0[0] = minterms[i]; break;
            case 1: for (int k = 0;k < 4;k++) {
                if (gpr1[k] == -1) { grp1[k] = minterms[i]; break; }
            } break;
            case 2: for (int k = 0;k < 6;k++) {
                if (gpr2[k] == -1) { grp2[k] = minterms[i]; break; }
            } break;

            case 3: for (int k = 0;k < 4;k++) {
                if (gpr3[k] == -1) { grp3[k] = minterms[i]; break; }
            } break;

            case 4: grp4[0] = minterms[i]; break;
            }
        }
        else if(minterms[i]==-1){
            break;
        }
    }
}


int main()
{
    return 0;
}