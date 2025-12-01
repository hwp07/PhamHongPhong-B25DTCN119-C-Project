#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_PRODUCTS 100
#define MAX_HISTORY  200

struct Product {
    char productID[10];
    char name[50];
    char unit[10];
    int qty;
    int status;
};

struct Transaction {
    char transId[20];
    char productId[10];
    char type[5];  // IN / OUT
    char date[15]; // DD/MM/YYYY
    int qty;
};


struct Product prd[MAX_PRODUCTS] = {
    {"P001", "Gao ST25", "Kg", 100, 1},
    {"P002", "Duong Cat Trang", "Kg", 50, 0},
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

struct Transaction history[MAX_HISTORY];
int size = 25;
int count = 0;


void addProduct();
void updateProduct();
void changeStatus();
void findProduct();
void listProducts();
void sortProducts();
void transaction();
void showHistory();
void setDate(char *time, int day, int month, int year) {
    sprintf(time, "%02d/%02d/%04d", day, month, year);
}



int main() {
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

        switch(choice) {
            case 1:
                addProduct();
                break;
            case 2:
                updateProduct();
                break;
            case 3:
                changeStatus();
                break;
            case 4:
                findProduct();
                break;
            case 5:
                listProducts();
                break;
            case 6:
                sortProducts();
                break;
            case 7:
                transaction();
                break;
            case 8:
                showHistory();
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }

    } while(choice != 8);

    return 0;
}


// Them san pham moi
void addProduct() {
    if (size >= MAX_PRODUCTS) {
        printf("Danh sach day! Khong the them san pham moi.\n");
        return;
    }

    struct Product newPrd;
    char input[50];

    // Nhap ma san pham
    while (1) {
        printf("Nhap ma san pham: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        if (strlen(input) == 0) {
            printf("Khong duoc de trong ma san pham!\n");
            continue;
        }

        int exists = 0;
        for (int i = 0; i < size; i++) {
            if (strcmp(prd[i].productID, input) == 0) {
                exists = 1;
                break;
            }
        }

        if (exists) {
            printf("Ma san pham da ton tai!\n");
            continue;
        }

        strcpy(newPrd.productID, input);
        break;
    }

    // Nhap ten san pham
    while (1) {
        printf("Nhap ten san pham: ");
        fgets(newPrd.name, sizeof(newPrd.name), stdin);
        newPrd.name[strcspn(newPrd.name, "\n")] = 0;

        if (strlen(newPrd.name) == 0) {
            printf("Ten san pham khong duoc de trong!\n");
        } else {
            break;
        }
    }

    // Nhap don vi
    while (1) {
        printf("Nhap don vi: ");
        fgets(newPrd.unit, sizeof(newPrd.unit), stdin);
        newPrd.unit[strcspn(newPrd.unit, "\n")] = 0;

        if (strlen(newPrd.unit) == 0) {
            printf("Don vi khong duoc de trong!\n");
            continue;
        }

        int hasDigit = 0;
        for (int i = 0; newPrd.unit[i] != '\0'; i++) {
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
    }

    // Nhap so luong
    char temp[50];
    while (1) {
    	int num;
        printf("Nhap so luong: ");
        fgets(temp, 50, stdin);
        temp[strcspn(temp, "\n")] = 0;

	if(strlen(temp) == 0){
		printf("Khong duoc de trong so luong!\n");
		continue;
	}
		
    if (sscanf(temp, "%d", &num) != 1) {
        printf("So luong phai la so nguyen!\n");
        continue;
    }

    if (num < 0) { 
        printf("So luong phai >= 0!\n");
        continue;
    }
    
    	newPrd.qty = num;
        break;
    }

    newPrd.status = 1;
    prd[size++] = newPrd;

    printf("Them san pham thanh cong!\n");
}

// Cap nhat san pham
void updateProduct() {
    char id[10];
    printf("Nhap ma san pham can cap nhat: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = 0;

    int index = -1;
    for (int i = 0; i < size; i++) {
        if (strcmp(prd[i].productID, id) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Khong tim thay san pham!\n");
        return;
    }

    printf("Thong tin hien tai: %s | %s | %d | %s\n",
        prd[index].productID,
        prd[index].name,
        prd[index].qty,
        prd[index].status ? "Dang KD" : "Ngung KD");

    // Nhap ten moi
    char tmp[50];
    printf("Nhap ten moi (de trong neu giu nguyen): ");
    fgets(tmp, sizeof(tmp), stdin);
    tmp[strcspn(tmp, "\n")] = 0;
    if (strlen(tmp) > 0) {
        strcpy(prd[index].name, tmp);
    }

    // Nhap don vi moi
    while (1) {
        printf("Nhap don vi moi (de trong neu giu nguyen): ");
        fgets(tmp, sizeof(tmp), stdin);
        tmp[strcspn(tmp, "\n")] = 0;

        if (strlen(tmp) == 0) break;

        int ok = 1;
        for (int i = 0; tmp[i] != '\0'; i++) {
            if (isdigit(tmp[i])) {
                ok = 0;
                break;
            }
        }

        if (!ok) {
            printf("Don vi khong duoc chua so!\n");
            continue;
        }

        strcpy(prd[index].unit, tmp);
        break;
    }

    // Nhap so luong moi
    int qty;
    while (1) {
        printf("Nhap so luong moi (-1 giu nguyen): ");
        if (scanf("%d", &qty) != 1) {
            printf("Nhap sai!\n");
            while (getchar() != '\n');
            continue;
        }
        getchar();

        if (qty == -1) {
        	break;
		}
        if (qty >= 0) {
            prd[index].qty = qty;
            break;
        }
        printf("So luong khong hop le!\n");
    }

    printf("Cap nhat san pham thanh cong!\n");
}

// Doi trang thai
void changeStatus() {
    char id[10];
    printf("Nhap ma san pham can doi trang thai: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = 0;

    int index = -1;
    for (int i = 0; i < size; i++) {
        if (strcmp(prd[i].productID, id) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("San pham khong ton tai!\n");
        return;
    }

    if (prd[index].status == 0) {
        printf("San pham da ngung kinh doanh!\n");
        return;
    }

    prd[index].status = 0;
    printf("Da doi %s sang NGUNG KINH DOANH.\n", id);
}

// Tim kiem san pham
void findProduct() {
    char find[50];
    printf("Nhap ma hoac ten san pham: ");
    fgets(find, sizeof(find), stdin);
    find[strcspn(find, "\n")] = 0;

    char findLower[50];
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

        if (strcmp(prd[i].productID, find) == 0 || strstr(nameLower, findLower) != NULL) {
	       printf("+-----+------------------------------+----------+----------+----------+\n");
	       printf("|%-5s|%-30s|%-10s|%-10s|%-10s|\n", "ID", "Ten Hang hoa","Don vi","So luong","Trang thai");
	       printf("+-----+------------------------------+----------+----------+----------+\n");
	       for (int i = 0;i < size; i++) {
	           printf("|%-5s|%-30s|%-10s|%-10d|%-10d|\n", prd[i].productID, prd[i].name, prd[i].unit, prd[i].qty, prd[i].status);
	       }
	       printf("+-----+------------------------------+----------+----------+----------+\n");
        }
    }

    if (found == 0) {
        printf("Khong tim thay san pham!\n");
    }
}
                                                                                                                                                                                                                                                                                                                
// ------------------- Hien thi danh sach (phan trang) -------------------
void listProducts() {
    int page_size = 10;
    int total_pages = (size + page_size - 1) / page_size;
    int page_number;

    while (1) {
        printf("Nhap so trang can xem (1-%d): ", total_pages);
        if (scanf("%d", &page_number) != 1) {
            printf("Vui long nhap so!\n");
            while (getchar() != '\n');
            continue;
        }
        getchar();

        if (page_number < 1 || page_number > total_pages) {
            printf("So trang khong hop le!\n");
            continue;
        }

        int start = (page_number - 1) * page_size;
        int end = start + page_size;
        if (end > size) end = size;

        printf("\nTrang %d/%d:\n", page_number, total_pages);
        printf("+-----+------------------------------+----------+----------+----------+\n");
        printf("|%-5s|%-30s|%-10s|%-10s|%-10s|\n", "ID", "Ten", "Don vi", "So luong", "Trang thai");
        printf("+-----+------------------------------+----------+----------+----------+\n");

        for (int i = start; i < end; i++) {
            printf("|%-5s|%-30s|%-10s|%-10d|%-10s|\n",
                   prd[i].productID,
                   prd[i].name,
                   prd[i].unit,
                   prd[i].qty,
                   prd[i].status ? "Dang KD" : "Ngung KD");
        }

        printf("+-----+------------------------------+----------+----------+----------+\n");

        char ch;
        printf("Ban co muon thoat (y/n)? ");
        ch = getchar();
        getchar(); // Xoa newline
        if (ch == 'y' || ch == 'Y') {
        	break;
		}
    }
}

// ------------------- Sap xep san pham -------------------
void sortProducts() {
    int choice;
    printf("1. Sap xep theo ten\n");
    printf("2. Sap xep theo so luong\n");
    printf("Nhap lua chon: ");
    if (scanf("%d", &choice) != 1) {
        printf("Nhap sai!\n");
        while (getchar() != '\n');
        return;
    }
    getchar();

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            int swap = 0;
            if (choice == 1 && strcmp(prd[j].name, prd[j+1].name) > 0) {
                swap = 1;
            } else if (choice == 2 && prd[j].qty < prd[j+1].qty) {
                swap = 1;
            }
            if (swap) {
                struct Product tmp = prd[j];
                prd[j] = prd[j+1];
                prd[j+1] = tmp;
            }
        }
    }

    listProducts();
}

// ------------------- Giao dich nhap/xuat -------------------
void transaction() {
    int choice;
    char prdId[10];
    int qty;

    printf("1. Nhap vat tu\n");
    printf("2. Xuat vat tu\n");
    printf("Nhap lua chon: ");
    if (scanf("%d", &choice) != 1) {
        printf("Nhap sai!\n");
        while (getchar() != '\n');
        return;
    }
    getchar();

    // Nhap ma vat tu
    while (1) {
        printf("Nhap ma vat tu: ");
        fgets(prdId, sizeof(prdId), stdin);
        prdId[strcspn(prdId, "\n")] = 0;

        if (strlen(prdId) == 0) {
            printf("Khong duoc de trong ma vat tu!\n");
            continue;
        }
        break;
    }

    int index = -1;
    for (int i = 0; i < size; i++) {
        if (strcmp(prd[i].productID, prdId) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Khong tim thay ma vat tu!\n");
        return;
    }

    // Nhap so luong
	while (1) {
    switch (choice) {
        case 1:
            printf("So luong nhap: ");
            break;

        case 2:
            if (prd[index].status == 0) {
                printf("Mat hang da ngung kinh doanh!");
            	return; 
            }
            printf("So luong xuat: ");
            break;

        default:
            printf("Lua chon khong hop le!\n");
            return;
    }

    if (scanf("%d", &qty) != 1) {
        printf("Vui long nhap so nguyen!\n");
        while (getchar() != '\n'); 
        continue;
    }
    getchar(); // xóa ky tu xuong dong con lai 

    if (qty <= 0) {
        printf("So luong phai > 0!\n");
        continue;
    }

    if (choice == 2 && qty > prd[index].qty) {
        printf("So luong xuat lon hon so luong hien co!\n");
        continue;
    }

    break;
}


    // Thuc hien giao dich
    if (choice == 1) {
        prd[index].qty += qty;
        printf("Nhap vat tu thanh cong. So luong hien tai: %d\n", prd[index].qty);
    } else {
        prd[index].qty -= qty;
        printf("Xuat vat tu thanh cong. So luong hien tai: %d\n", prd[index].qty);
    }

    // Luu lich su 
    if (count < MAX_HISTORY) {
        sprintf(history[count].transId, "T%02d", count + 1);
        strcpy(history[count].productId, prd[index].productID);
        if (choice == 1) {
		    strcpy(history[count].type, "IN");
		} else {
		    strcpy(history[count].type, "OUT");
		}

		setDate(history[count].date, 01, 12, 2025);

		
		history[count].qty = qty;

        count++;
    }
}

// ------------------- Hien thi lich su giao dich -------------------
void showHistory() {
    if (count == 0) {
        printf("Chua co giao dich nao!\n");
        return;
    }

    printf("+-------+---------+------+------------+-------+\n");
    printf("|ID     | Product | Loai | Ngay       | SL    |\n"); 
    printf("+-------+---------+------+------------+-------+\n");

    for (int i = 0; i < count; i++) {
        printf("|%-7s|%-9s|%-6s|%-12s|%-7d|\n",
               history[i].transId,
               history[i].productId,
               history[i].type,
               history[i].date,
               history[i].qty
        );
    }

    printf("+-------+---------+------+------------+-------+\n");
}


