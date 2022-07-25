#include<stdio.h>
#define bits 4
#define size 16

struct step2grps {
    int n;
    int arr1[20];
    int arr2[20];
    char str[20][4];
};

struct step3grps {
    int n;
    int arr1[20];
    int arr2[20];
    int arr3[20];
    int arr4[20];
    char str[20][4];
};

void assignstr(int t, char s[][4], int c, int nn) {

    switch (c) {
    case 1: if (!((t >> 3) & 1)) { s[nn][0] = '0'; }
          else { s[nn][0] = '1'; }
          if (!((t >> 2) & 1)) { s[nn][1] = '0'; }
          else { s[nn][1] = '1'; }
          if (!((t >> 1) & 1)) { s[nn][2] = '0'; }
          else { s[nn][2] = '1'; }
          s[nn][3] = '_';
          break;
    case 2: if (!((t >> 3) & 1)) { s[nn][0] = '0'; }
          else { s[nn][0] = '1'; }
          if (!((t >> 2) & 1)) { s[nn][1] = '0'; }
          else { s[nn][1] = '1'; }
          s[nn][2] = '_';
          if (!(t & 1)) { s[nn][3] = '0'; }
          else { s[nn][3] = '1'; }
          break;
    case 4: if (!((t >> 3) & 1)) { s[nn][0] = '0'; }
          else { s[nn][0] = '1'; }
          s[nn][1] = '_';
          if (!((t >> 1) & 1)) { s[nn][2] = '0'; }
          else { s[nn][2] = '1'; }
          if (!(t & 1)) { s[nn][3] = '0'; }
          else { s[nn][3] = '1'; }
          break;
    case 8:  s[nn][0] = '_';
        if (!((t >> 2) & 1)) { s[nn][1] = '0'; }
        else { s[nn][1] = '1'; }
        if (!((t >> 1) & 1)) { s[nn][2] = '0'; }
        else { s[nn][2] = '1'; }
        if (!(t & 1)) { s[nn][3] = '0'; }
        else { s[nn][3] = '1'; }
        break;

    }
}

void comparegrpsVer2(int a[], int b[], int m, int n, struct step2grps* grp) {

    int nn = 0;

    for (int i = 0;i < m;i++) {
        for (int j = 0;j < n;j++) {
            int s = a[i] ^ b[j];
            int t = a[i] & b[j];

            switch (s) {
            case 1:  grp->arr1[nn] = a[i]; grp->arr2[nn] = b[j];
                assignstr(t,grp->str, 1, nn);
                nn++; break;
            case 2:  grp->arr1[nn] = a[i]; grp->arr2[nn] = b[j];
                assignstr(t,grp->str, 2, nn);
                nn++; break;
            case 4:  grp->arr1[nn] = a[i]; grp->arr2[nn] = b[j];
                assignstr(t,grp->str, 4, nn);
                nn++; break;
            case 8:  grp->arr1[nn] = a[i]; grp->arr2[nn] = b[j];
                assignstr(t,grp->str, 8, nn);
                nn++; break;
            default: break;
            }
        }
    }
    grp->n = nn;
}

bool comparestep3(char s1[4],char s2[4],struct step3grps* grp){
    int cnt=0;
    for(int i=0;i<4;i++){
        if(cnt>1){
            break;
        }
        if(!(s1[i]==s2[i])){
            cnt++;
        }  
    }
    if(cnt==1){
   return true;
    }
    else{
        return false;
    }
}

void assignstep3(struct step2grps *grp1, struct step2grps *grp2,struct step3grps *grp){
int m=0;
for(int )
}
void Minterm() {

    char variables[bits];
    printf("Enter the variable names\n");
    for (int i = 0;i < bits;i++) {
        scanf(" %c", &variables[i]);
    }
    int minterms[size] = { -2 };
    int dontcares[size] = { -2 };
    printf("Enter the minterms and enter -1 when done:\n");
    int m = 0;
    while (1 && m < size) {
        scanf("%d", &minterms[m]);
        if (minterms[m] == -1) {
            break;
        }
        m++;
    }
    printf("Enter the dontcares and enter -1 when done:\n");
    int d = 0;
    while (1 && d < size) {
        scanf("%d", &dontcares[d]);
        if (dontcares[d] == -1) {
            break;
        }
        if (minterms[d] == dontcares[d]) {
            printf("This number is already a minterm, enter another element:\n");
            dontcares[d] = -2;
            d--;
        }
        d++;
    }

    int grp0[1] = { -1 };
    int grp1[4] = { -1,-1,-1,-1 };
    int grp2[6] = { -1,-1,-1,-1,-1,-1 };
    int grp3[4] = { -1,-1,-1,-1 };
    int grp4[1] = { -1 };

    for (int i = 0;i < size;i++) {
        if (minterms[i] != -1) {
            int s = bits;
            int count = 0;
            int ele = minterms[i];
            while (s--) {
                if (minterms[i] & 1 == 1) {
                    count++;
                }
                minterms[i] = minterms[i] >> 1;
            }
            switch (count) {
            case 0:  grp0[0] = ele; break;
            case 1: for (int k = 0;k < 4;k++) {
                if (grp1[k] == -1) { grp1[k] = ele; break; }
            } break;
            case 2: for (int k = 0;k < 6;k++) {
                if (grp2[k] == -1) { grp2[k] = ele; break; }
            } break;

            case 3: for (int k = 0;k < 4;k++) {
                if (grp3[k] == -1) { grp3[k] = ele; break; }
            } break;

            case 4: grp4[0] = ele; break;
            }
        }
        else if (minterms[i] == -1) {
            break;
        }
    }

    printf("\n");
    printf("STEP 1:\n");
    int size0 = 0;
    if (grp0[0] != -1) {
        printf("group0: %d", grp0[0]);
        size0++;
    }
    int size1 = 0;
    if (grp1[0] != -1)
    {
        printf("\ngroup1:");
    }    for (int i = 0;i < 4;i++) {
        if (grp1[i] == -1) {
            break;
        }
        printf(" %d", grp1[i]);
        size1++;
    }
    int size2 = 0;
    if (grp2[0] != -1)
    {
        printf("\ngroup2:");
    }
    for (int i = 0;i < 6;i++) {
        if (grp2[i] == -1) {
            break;
        }
        printf(" %d", grp2[i]);
        size2++;
    }
    int size3 = 0;
    if (grp3[0] != -1)
    {
        printf("\ngroup3:");
    }

    for (int i = 0;i < 4;i++) {
        if (grp3[i] == -1) {
            break;
        }
        printf(" %d", grp3[i]);
        size3++;
    }
    int size4 = 0;
    if (grp4[0] != -1) {
        printf("\ngroup4: %d\n", grp4[0]);
        size4++;
    }

    printf("\n");
    printf("\nSTEP 2:\n");

    if (size0 > 0 && size1 > 0) {


        struct step2grps step2g1;
        comparegrpsVer2(grp0, grp1, size0, size1, &step2g1);
        for (int r = 0;r < step2g1.n;r++) {
            printf("%d,%d  ", step2g1.arr1[r], step2g1.arr2[r], step2g1.n);
            for (int k = 0;k < 4;k++) {
                printf("%c", step2g1.str[r][k]);
            }
            printf("\n");
        }
    }
    if (size1 > 0 && size2 > 0) {

        struct step2grps step2g2;
        comparegrpsVer2(grp1, grp2, size1, size2, &step2g2);
        for (int r = 0;r < step2g2.n;r++) {
            printf("%d,%d  ", step2g2.arr1[r], step2g2.arr2[r], step2g2.n);
            for (int k = 0;k < 4;k++) {
                printf("%c", step2g2.str[r][k]);
            }
            printf("\n");
        }
    }
    if (size2 > 0 && size3 > 0) {

        struct step2grps step2g3;
        comparegrpsVer2(grp2, grp3, size2, size3, &step2g3);
        for (int r = 0;r < step2g3.n;r++) {
            printf("%d,%d  ", step2g3.arr1[r], step2g3.arr2[r], step2g3.n);
            for (int k = 0;k < 4;k++) {
                printf("%c", step2g3.str[r][k]);
            }
            printf("\n");
        }
    }
    if (size3 > 0 && size4 > 0) {

        struct step2grps step2g4;
        comparegrpsVer2(grp3, grp4, size3, size4, &step2g4);
        for (int r = 0;r < step2g4.n;r++) {
            printf("%d,%d  ", step2g4.arr1[r], step2g4.arr2[r], step2g4.n);
            for (int k = 0;k < 4;k++) {
                printf("%c", step2g4.str[r][k]);
            }
            printf("\n");
        }
    }

    printf("\n");
    printf("\nSTEP 3:\n");
    if(step2g1.n>0 && step2g2.n>0){
        struct step3grps step3g1;
        for(int i=0;i<step2g1.n;i++){
            for(int j=0;j<step2g2.n;j++){

            }
        }
    }

}


int main()
{
    Minterm();
    return 0;
}
