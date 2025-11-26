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
    {"P001", "Gao ST25", "Kg", 100, 1},
    {"P002", "Duong Cat Trang", "Kg", 50, 1},
    {"P003", "Sua Tuoi Vinamilk", "Hop", 200, 1},
    {"P004", "Mi Tom Hao Hao", "Thung", 30, 1},
    {"P005", "Nuoc Ngot Pepsi", "Chai", 120, 1},
    {"P006", "Dau An Tuong An", "Chai", 80, 1},
	{"P007", "Bot Ngot Ajinomoto", "Goi", 150, 1},
	{"P008", "Nuoc Mam Nam Ngu", "Chai", 60, 1},
	{"P009", "Tra Xanh 0 Do", "Chai", 90, 1},
	{"P010", "Sua Ong Tho", "Lon", 70, 1},
	{"P011", "Banh Quy OREO", "Hop", 40, 1},
	{"P012", "Keo Deo Alpenliebe", "Goi", 55, 1},
	{"P013", "Ca Phe Trung Nguyen", "Goi", 110, 1},
	{"P014", "Gao Jasmine", "Kg", 300, 1},
	{"P015", "Duong Den Huu Co", "Kg", 45, 1},
	{"P016", "Nuoc Loc Lavie", "Thung", 25, 1},
	{"P017", "Nuoc Ep Cam Twister", "Chai", 65, 1},
	{"P018", "Thung Bia Saigon", "Thung", 18, 1},
	{"P019", "Thung Bia Heineken", "Thung", 15, 1},
	{"P020", "Cha Lua Vissan", "Kg", 35, 1},
	{"P021", "Xuc Xich Duc Viet", "Goi", 50, 1},
	{"P022", "Banh Mi Tuoi", "Cai", 120, 1},
	{"P023", "Dau Phu Trang", "Mieng", 200, 1},
	{"P024", "Trung Ga CP", "Khay", 30, 1},
	{"P025", "Hat Dieu Rang Muoi", "Goi", 75, 1}

    
    
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
void findProduct();
void listProduct();
void sortProduct();
void transaction();
void showHistory();


int size = 25;


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
	            statusProduct();
	            break;
	
	        case 4:
	            findProduct();
	            break;
	
	        case 5:
	            listProduct();
	            break;
	
	        case 6:
	            sortProduct();
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
                printf("Ma san pham bi trung!\n");
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
	        printf("Don vi khong duoc chua so!\n");
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


void statusProduct() {
    char id[10];
    printf("Nhap ma vat tu can doi trang thai: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = 0;

    int index = -1;
    for (int i = 0; i < size; i++) {
        if (strcmp(id, prd[i].productID) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Vat tu %s khong ton tai!\n", id);
        return;
    }

    if (prd[index].status == 0) {
        printf("Hang hoa %s dang o trang thai NGUNG KINH DOANH!\n", id);
        printf("Khong the doi trang thai!\n");
        return;
    }

    prd[index].status = 0;

    printf("Da doi trang thai cua %s sang NGUNG KINH DOANH.\n", prd[index].productID);
}


void findProduct() {
    char find[100];
    printf("Ma hang hoa hoac ten can tim kiem: ");
    fgets(find, 100, stdin);
    find[strcspn(find, "\n")] = 0;

    char findLower[100];
    strcpy(findLower, find);

    for (int i = 0; findLower[i] != '\0'; i++) {
        findLower[i] = tolower(findLower[i]);
    }

    int found = 0;

    for (int i = 0; i < size; i++) {
        char nameLower[50];
        strcpy(nameLower, prd[i].name);

        for (int k = 0; nameLower[k] != '\0'; k++) {
            nameLower[k] = tolower(nameLower[k]);
        }

        if (strcmp(prd[i].productID, find) == 0 ||
            strstr(nameLower, findLower) != NULL) {

            found++;
            printf("\nTim thay hang hoa:\n");
            printf("ID: %s\n", prd[i].productID);
            printf("Ten: %s\n", prd[i].name);
            printf("Don vi: %s\n", prd[i].unit);
            printf("So luong: %d\n", prd[i].qty);
        }
    }

    if (found == 0) {
        printf("\nKhong tim thay hang hoa!\n");
    } else {
        printf("\nTim thay %d ket qua.\n", found);
    }
}

void listProduct() {
    int page_number = 1;
    int page_size =10;
    // Tính t?ng s? trang
    int kq = size/page_size;
    int total_pages = (size % page_size == 0)? kq : kq+1;

   while (1) {
       printf("Moi ban chon so trang can xem (1-%d) : ", total_pages);
       scanf("%d", &page_number);

       // kiem tra dieu kien

       // Tính v? tri bat dau v ket thu
       int start = (page_number-1)*page_size;
       int end = start + page_size;
       printf("Trang %d/%d :\n\n", page_number, total_pages); // trang 1/5
       printf("+-----+------------------------------+----------+----------+----------+\n");
       printf("|%-5s|%-30s|%-10s|%-10s|%-10s|\n", "ID", "Ten Hang hoa","Don vi","So luong","Trang thai");
       printf("+-----+------------------------------+----------+----------+----------+\n");
       for (int i = start; i < end && i < size; i++) {
           printf("|%-5s|%-30s|%-10s|%-10d|%-10d|\n", prd[i].productID, prd[i].name, prd[i].unit, prd[i].qty, prd[i].status);
       }
       printf("+-----+------------------------------+----------+----------+----------+\n");
        fflush(stdin);
       printf("Ban co muon thoat hay ko ? (y/n)");
       char ch = getchar();
       if (ch == 'y' || ch == 'Y') {
           break;
       }
   }

};

void sortProduct(){
	int choice;
	printf("	1. Xap xep theo ten.\n");
	printf("	2. Xap xep theo so luong.\n");
	printf("Nhap lua chon cua ban: ");
	scanf("%d",&choice);
	
	if(choice == 2){
		for(int i = 0; i < size;i++){
			for(int j = 0;j < size - 1 - i;j++){
				if(prd[j].qty < prd[j+1].qty){
					int temp = prd[j].qty;
					prd[j].qty = prd[j+1].qty;
					prd[j+1].qty = temp;
				}
			}
		}
	}
	
	if(choice == 1){
		for(int i = 0; i < size;i++){
			for(int j = 0;j < size - 1 - i;j++){
				if(strcmp(prd[j].name, prd[j+1].name) > 0){
					struct Product temp = prd[j];
					prd[j] = prd[j+1];
					prd[j+1] = temp;
				}
			}
		}
	}
	
	listProduct();

}




