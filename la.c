#include <stdio.h>


struct SilverItem {
    int srNo;
    int quantity;
    int type;
    int price;
};


const char* getSilverName(int type) {
    switch (type) {
        case 1: return "Silver Kalash"; 
        case 2: return "Silver Samai";
        case 3: return "Silver Aarti";
        case 4: return "Silver Models";
        default: return "Unknown";
    }
}

int getSilverPrice(int type) {
    switch (type) {
        case 1: return 100000;
        case 2: return 50000;
        case 3: return 40000;
        case 4: return 20000;
        default: return 0;
    }
}

int main() {
    int n, totalAmount = 0;

    printf("Enter how many silver items you take: ");
    scanf("%d", &n);

    struct SilverItem items[n];

    for (int i = 0; i < n; i++) {
        printf("Enter sr.no:\n");
        scanf("%d", &items[i].srNo);

        printf("Enter quantity:\n");
        scanf("%d", &items[i].quantity);

        printf("Enter type (1-Kalash, 2-Samai, 3-Aarti, 4-Models):\n");
        scanf("%d", &items[i].type);

        items[i].price = getSilverPrice(items[i].type);
        totalAmount += items[i].price * items[i].quantity;
    }

    FILE *fptr;
    fptr = fopen("code.txt", "w");

    fprintf(fptr, "\n\t                          SHRI CHANDEKAR SHOP\n");
    fprintf(fptr, "                NEAR KARVENAGAR ROAD, SHOP NO:-321, PIN:-416704\n");
    fprintf(fptr, "                         TAL-HAWELI , DIST:PUNE\n");
    fprintf(fptr, "\t\t\t\t\t\t PHONE:-1196263456 \n");
    fprintf(fptr, "\t\t\t\t\t\t\t ||श्री गणेशाया नमः||\n");
    fprintf(fptr, "\t-----------------------------BILL-----------------------------\n");
    fprintf(fptr, "\tNAME:-PRATHAMESH TERDALE         \t\tCUSTOMER NO:-3435798765\n");
    fprintf(fptr, "\t--------------------------------------------------------------\n");
    fprintf(fptr, "\tSR.NO\tSILVER\t\tQUANTITY\tAMOUNT\n");

    for (int i = 0; i < n; i++) {
        fprintf(fptr, "\t%d\t%s\t\t%d\t\t₹%d\n",
                items[i].srNo,
                getSilverName(items[i].type),
                items[i].quantity,
                items[i].price * items[i].quantity);
    }

    fprintf(fptr, "\t--------------------------------------------------------------\n");
    fprintf(fptr, "\t\t\t\t\tTOTAL AMOUNT: ₹%d\n", totalAmount);

    fclose(fptr);

    printf("\nBill successfully generated in 'code.txt'\n");

    return 0;
}
