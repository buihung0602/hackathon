#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int s = 1, n, a, even = 0, odd = 0;
    int arr[100];
    while (s == 1) {
        printf("1. Nhap so phan tu va gia tri cho mang\n");
        printf("2. In ra gia tri cac phan tu trong mang theo dang(arr[0]=1, arr[1]=5...)\n");
        printf("3. Dem so luong cac phan tu chan le trong mang\n");
        printf("4. Tim gia tri lon thu hai trong mang\n");
        printf("5. Them mot phan tu vao dau mang\n");
        printf("6. Xoa phan tu tai mot vi tri cu the\n");
        printf("7. Sap xep mang theo thu tu giam dan (Insertion sort)\n");
        printf("8. Nhap vao mot phan tu va tim kiem\n");
        printf("9. In ra toan bo so nguyen to trong mang da duoc binh phuong\n");
        printf("10. Sap xep mang theo thu tu giam dan (Bubble sort)\n");
        printf("\nVui long nhap lua chon: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                printf("Vui long nhap so luong phan tu: ");
                scanf("%d", &a);
                while (a <= 0) {
                    printf("Vui long nhap so luong phan tu > 0: ");
                    scanf("%d", &a);
                }
                for (int i = 0; i < a; i++) {
                    printf("Nhap gia tri cho phan tu thu %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                break;

            case 2:
                for (int i = 0; i < a; i++) {
                    printf("arr[%d] = %d, ", i, arr[i]);
                }
                printf("\n");
                break;

            case 3:
                for (int i = 0; i < a; i++) {
                    if (arr[i] % 2 == 0) {
                        even++;
                    } else {
                        odd++;
                    }
                }
                printf("So luong so chan: %d\n", even);
                printf("So luong so le: %d\n", odd);
                break;

            case 4: {
                int largest = arr[0], secondLargest = -1;
                if (a < 2) {
                    printf("Khong co gia tri lon thu hai\n");
                } else {
                    for (int i = 1; i < a; i++) {
                        if (arr[i] > largest) {
                            secondLargest = largest;
                            largest = arr[i];
                        } else if (arr[i] > secondLargest && arr[i] < largest) {
                            secondLargest = arr[i];
                        }
                    }
                    if (secondLargest == -1) {
                        printf("Khong co gia tri lon thu hai\n");
                    } else {
                        printf("Gia tri lon thu hai: %d\n", secondLargest);
                    }
                }
                break;
            }

            case 5: {
                int newElement;
                printf("Nhap phan tu moi: ");
                scanf("%d", &newElement);
                for (int i = a; i > 0; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[0] = newElement;
                a++;
                break;
            }

            case 6: {
                int pos;
                printf("Nhap vi tri muon xoa: ");
                scanf("%d", &pos);
                if (pos < 0 || pos >= a) {
                    printf("Vi tri khong hop le\n");
                } else {
                    for (int i = pos; i < a - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    a--;
                }
                break;
            }

            case 7: {
                for (int i = 1; i < a; i++) {
                    int key = arr[i];
                    int j = i - 1;
                    while (j >= 0 && arr[j] < key) {
                        arr[j + 1] = arr[j];
                        j--;
                    }
                    arr[j + 1] = key;
                }
                printf("Mang sau khi sap xep theo thu tu giam dan: ");
                for (int i = 0; i < a; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }

            case 8: {
                int target;
                printf("Nhap phan tu can tim: ");
                scanf("%d", &target);
                int left = 0, right = a - 1;
                int found = 0;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (arr[mid] == target) {
                        printf("Phan tu %d ton tai trong mang tai vi tri %d\n", target, mid);
                        found = 1;
                        break;
                    } else if (arr[mid] < target) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                if (!found) {
                    printf("Phan tu %d khong ton tai trong mang\n", target);
                }
                break;
            }

            case 9: {
                int primeFound = 0;
                printf("Cac so nguyen to trong mang sau khi binh phuong: ");
                for (int i = 0; i < a; i++) {
                    int isPrimeFlag = 1;
                    if (arr[i] < 2) {
                        isPrimeFlag = 0;
                    } else {
                        for (int j = 2; j <= sqrt(arr[i]); j++) {
                            if (arr[i] % j == 0) {
                                isPrimeFlag = 0;
                                break;
                            }
                        }
                    }
                    if (isPrimeFlag) {
                        primeFound = 1;
                        printf("%d ", arr[i] * arr[i]);
                    }
                }
                if (!primeFound) {
                    printf("Khong co so nguyen to nao trong mang\n");
                }
                printf("\n");
                break;
            }

            case 10: {
                for (int i = 0; i < a - 1; i++) {
                    for (int j = i + 1; j < a; j++) {
                        if (arr[i] < arr[j]) {
                            int temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }
                printf("Mang sau khi sap xep theo thu tu giam dan: ");
                for (int i = 0; i < a; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }

            default:
                printf("Lua chon khong hop le.\n");
                break;
        }
    }
    return 0;
}

