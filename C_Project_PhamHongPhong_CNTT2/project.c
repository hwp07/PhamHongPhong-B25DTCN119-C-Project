#include <stdio.h>
#include <string.h>
#define MAX 100

struct Product {
	char productID[10];
	char name[50];
	char unit[10];
	int qty;
	int status;
};

struct Product prd[MAX] = {
    {"P001", "Gao ST25", "Kg", 100, 1},
    {"P002", "Duong Cat Trang", "Kg", 50, 1},
    {"P003", "Sua Tuoi Vinamilk", "Hop", 200, 1},
    {"P004", "Mi Tom Hao Hao", "Thung", 30, 0},
    {"P005", "Nuoc Ngot Pepsi", "Chai", 120, 1}
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
struct Product prd[MAX];

int main(){
	int choice;
	
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


void addProduct(){
	struct Product newPrd;
	
	if(size >= MAX){
		printf("Mang day!");
		return;
	}
	
	printf("\nNhap ma san pham: ");
	fgets(newPrd.productID, sizeof(newPrd.productID), stdin);
	newPrd.productID[strcspn(newPrd.productID, "\n")] = 0;
	if(strlen(newPrd.productID) == 0){
		printf("Khong duoc de trong ma san pham!");
		return;
	}
	
	for(int i = 0; i < size;i++){
		if(strcmp(newPrd.productID, prd[i].productID) == 0){
			printf("Ma san pham bi trung!!!");
			return;
		}
	}
	
	
	printf("Nhap ten san pham: ");
	fgets(newPrd.name, sizeof(newPrd.name), stdin);
	newPrd.name[strcspn(newPrd.name, "\n")] = 0;
    if(strlen(newPrd.name) == 0){
	    printf("Khong duoc de trong ten san pham!\n");
        return;
    }
	
	
	printf("Nhap don vi (Cai/Kg/Hop): ");
	fgets(newPrd.unit, sizeof(newPrd.unit), stdin);
	newPrd.unit[strcspn(newPrd.unit, "\n")] = 0;
	if(strlen(newPrd.unit) == 0){
        printf("Khong duoc de trong don vi!\n");
        return;
    }
    
	
	printf("Nhap so luong: ");
	scanf("%d", &newPrd.qty);
	getchar();
	if(newPrd.qty <= 0){
        printf("So luong phai > 0!\n");
        return;
    }
    
	
	printf("Nhap trang thai (1-Con hang, 0-Het hang): ");
	scanf("%d", &newPrd.status);
	getchar();
	
	prd[size] = newPrd;
	size++;
	
	printf("THEM MOI THANH CONG!\n\n");
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
        printf("Cap nhat that bai! Khong tim thay ma san pham.\n");
        return;
    }

    printf("\n--- THONG TIN HIEN TAI ---\n");
    printf("ID: %s\n", prd[index].productID);
    printf("Ten: %s\n", prd[index].name);
    printf("Don vi: %s\n", prd[index].unit);
    printf("So luong: %d\n", prd[index].qty);

    printf("\n--- NHAP THONG TIN MOI ---\n");

    char newName[50];
    printf("Nhap ten moi (de trong neu giu nguyen): ");
    fgets(newName, sizeof(newName), stdin);
    newName[strcspn(newName, "\n")] = 0;

    if(strlen(newName) == 0){
    	strcpy(newName, prd[index].name); //
    }else if (strlen(newName) > 0){
        strcpy(prd[index].name, newName);
    }

    char newUnit[10];
    printf("Nhap don vi moi (de trong neu giu nguyen): ");
    fgets(newUnit, sizeof(newUnit), stdin);
    newUnit[strcspn(newUnit, "\n")] = 0;

    if(strlen(newUnit) == 0){
    	
    }else if (strlen(newUnit) > 0){
        strcpy(prd[index].unit, newUnit);
    }

    int newQty;
    printf("Nhap so luong moi (-1 de giu nguyen): ");
    scanf("%d", &newQty);
    getchar();

    if(newQty >= 0){
        prd[index].qty = newQty;
    }else if (newQty < -1){
        printf("Cap nhat that bai! So luong phai >= 0.\n");
        return;
    }

    printf("\nCap nhat thong tin thanh cong!\n");
}


 
