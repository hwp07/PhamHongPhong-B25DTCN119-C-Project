#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

struct Product {
	char productID[10];
	char name[50];
	char unit[10];
	int qty;
	int status;
};

struct Product prd[MAX] = {
    {"P001", "Gao ST25", "Kg", 100},
    {"P002", "Duong Cat Trang", "Kg", 50},
    {"P003", "Sua Tuoi Vinamilk", "Hop", 200},
    {"P004", "Mi Tom Hao Hao", "Thung", 30},
    {"P005", "Nuoc Ngot Pepsi", "Chai", 120}
};


struct Transaction {
	char transId[20];
	char productId[10];
	char type[5];
	char date[15];
};

void addProduct();
void updateProduct();
void statusProduct();
void searchProduct();
void listProduct();
void sortProduct();
void transaction();
void showHistory();


int size = 5;


int main(){
	int choice;
	
	for(int i = 0;i < MAX;i++){
		prd[i].status = 1;
	}
		
	do {
		printf("\n+---------------MENU-------------+\n");
		printf("|1. Them ma hang moi.            |\n");
		printf("|2. Cap nhat thong tin.          |\n");
		printf("|3. Quan ly trang thai.          |\n");
		printf("|4. Tra cuu.                     |\n");
		printf("|5. Danh sach.                   |\n");
		printf("|6. Sap xep danh sach.           |\n");
		printf("|7. Giao dich xuat/nhap hang hoa.|\n");
		printf("|8. Lich su xuat nhap.           |\n");
		printf("+--------------------------------+\n");
		
		printf("Nhap lua chon: ");
		scanf("%d",&choice);
		getchar();
		
		switch(choice){
			case 1:
            	addProduct();
            	break;

	        case 2:
				updateProduct();
	            break;
	
	        case 3:
	            
	            break;
	
	        case 4:
	            
	            break;
	
	        case 5:
	            
	            break;
	
	        case 6:
	            
	            break;
	
	        case 7:
	           
	            break;
	
	        case 8:
	            
	            break;
	
	        default:
	            printf("Lua chon khong hop le!\n");
	            break;
		} 
	} while(choice != 8);
	return 0;
}


void addProduct() {
    if (size == MAX) {
        printf("Danh sach day! Them moi hang hoa that bai!\n");
        return;
    }

    struct Product newPrd;

    while (1) {
        printf("\nNhap ma san pham: ");
        fgets(newPrd.productID, sizeof(newPrd.productID), stdin);
        newPrd.productID[strcspn(newPrd.productID, "\n")] = 0;

        if (strlen(newPrd.productID) == 0) {
            printf("Khong duoc de trong ma san pham!\n");
            continue;
        }

        int flag = 0;
        for (int i = 0; i < size; i++) {
            if (strcmp(newPrd.productID, prd[i].productID) == 0) {
                printf("Ma san pham bi trung! Nhap lai.\n");
                flag = 1;
                break;
            }
        }

        if (!flag) {
        	break;
		}
    }

    do {
        printf("Nhap ten san pham: ");
        fgets(newPrd.name, sizeof(newPrd.name), stdin);
        newPrd.name[strcspn(newPrd.name, "\n")] = 0;

        if (strlen(newPrd.name) == 0) {
            printf("Khong duoc de trong ten san pham!\n");
        }
    } while (strlen(newPrd.name) == 0);
    
    
	do {
	    printf("Nhap don vi (Cai/Kg/Hop): ");
	    fgets(newPrd.unit, sizeof(newPrd.unit), stdin);
	    newPrd.unit[strcspn(newPrd.unit, "\n")] = 0;
	
	    if (strlen(newPrd.unit) == 0) {
	        printf("Khong duoc de trong don vi!\n");
	        continue;
	    }
	
	    int hasDigit = 0;
	    for (int i = 0; i < sizeof(newPrd.unit); i++) {
	        if (newPrd.unit[i] == '\0') {
	        	break; 
			}
			
	        if (isdigit(newPrd.unit[i])) {
	            hasDigit = 1;
	            break;
	        }
	    }
	
	    if (hasDigit) {
	        printf("Don vi khong duoc chua so! Nhap lai.\n");
	        continue;
	    }
	
	    break;
	} while (1);


    do {
        printf("Nhap so luong: ");
        if (scanf("%d", &newPrd.qty) != 1) {
            printf("Vui long nhap so!\n");
            while(getchar() != '\n');
            continue;
        }
        getchar();

        if (newPrd.qty <= 0) {
            printf("So luong phai > 0!\n");
            continue;
        }

        break;
    } while (1);

    newPrd.status = 1; 
    prd[size] = newPrd;
    size++;

    printf("\nTHEM MOI THANH CONG!\n");
}



void updateProduct(){
    char id[10];
    printf("\nNhap ma san pham muon cap nhat: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = 0;

    int index = -1;
    for(int i = 0; i < size; i++){
        if(strcmp(prd[i].productID, id) == 0){
            index = i;
            break;
        }
    }

    if(index == -1){
    	printf("Khong tim thay hang hoa!\n");
        printf("Them moi hang hoa that bai!\n");
        return;
    }

    printf("\n    THONG TIN HIEN TAI    \n");
    printf("ID: %s\n", prd[index].productID);
    printf("Ten: %s\n", prd[index].name);
    printf("Don vi: %s\n", prd[index].unit);
    printf("So luong: %d\n", prd[index].qty);

    printf("\n    NHAP THONG TIN MOI    \n");

    char newName[50];
    printf("Nhap ten moi (de trong neu giu nguyen): ");
    fgets(newName, sizeof(newName), stdin);
    newName[strcspn(newName, "\n")] = 0;

    if(strlen(newName) == 0){
    	strcpy(newName, prd[index].name);
    }else if (strlen(newName) > 0){
        strcpy(prd[index].name, newName);
    }

	char newUnit[10];
	while (1) {
	    printf("Nhap don vi moi (de trong neu giu nguyen): ");
	    fgets(newUnit, sizeof(newUnit), stdin);
	    newUnit[strcspn(newUnit, "\n")] = 0;
	
	    if (strlen(newUnit) == 0) {
	        break;
	    }
	
	    int hasDigit = 0;
	    for (int i = 0; i < sizeof(newUnit); i++) {
	        if (newUnit[i] == '\0') break;
	        if (isdigit(newUnit[i])) {
	            hasDigit = 1;
	            break;
	        }
	    }
	
	    if (hasDigit) {
	        printf("Don vi khong duoc chua so!\n");
	        continue;
	    }
	
	    strcpy(prd[index].unit, newUnit);
	    break;
	}


	int newQty;
	while (1) {
	    printf("Nhap so luong moi (-1 de giu nguyen): ");
	    if (scanf("%d", &newQty) != 1) {
	        printf("Vui long nhap so!\n");
	        while (getchar() != '\n');
	        continue;
	    }
	    getchar();
	
	    if (newQty == -1) {
	        break;
	    } else if (newQty >= 0) {
	        prd[index].qty = newQty;
	        break;
	    } else {
	        printf("So luong khong hop le!\n");
	    }
	}


    printf("\nThem moi hang hoa thanh cong!\n");
}


 
