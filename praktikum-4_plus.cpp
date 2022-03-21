#include <iostream>
#define MAXSTACK 5
typedef int ItemType;

using namespace std;

struct Stack
{
    int item[MAXSTACK] = {};
    int count = 0;
};

void push(ItemType x, Stack *S)
{
    // Check apakah stack penuh
    if (S->count == MAXSTACK)
        printf("Stack penuh! Data tidak dapat masuk!\n");
    else
    {
        S->item[S->count] = x;
        ++(S->count);
    }
}

void pop(Stack *S)
{
    // Check apakah stack kosong
    if (S->count == 0)
        printf("Stack masih kosong!\n");
    else
    {
        --(S->count);
        int nilai_yg_dikeluarkan;
        nilai_yg_dikeluarkan = S->item[S->count];
        S->item[S->count] = 0;
        printf("Int: %d telah dikeluarkan (pop) dari stack!\n", nilai_yg_dikeluarkan);
    }
}

void bacaStack(Stack *S)
{
    for (int i = 0; i < MAXSTACK; i++)
    {
        printf("Isi stack ke-%d: ", i);
        printf("%d\n", S->item[i]);
    }
}

int main()
{
    int pilihan, input, nilai;
    Stack tumpukan;

    bool running = true;
    while (running)
    {
        printf("=================\n");
        printf("   PRAKTIKUM 4\n");
        printf("=================\n");
        printf(">>> Pilih aksi\n");
        printf("1) Push item\n");
        printf("2) Pop item\n");
        printf("3) Print list item\n");
        printf("4) Keluar dari program\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        printf("--------------------\n");
        switch (pilihan)
        {
        case 1:
            printf(">>> Masukkan nilai integer yang ingin diinput ke dalam stack\n");
            printf("Nilai: ");
            scanf("%d", &input);
            push(input, &tumpukan);
            break;
        case 2:
            pop(&tumpukan);
            break;
        case 3:
            bacaStack(&tumpukan);
            break;
        case 4:
            printf("Terima kasih telah menggunakan program ini :)\n");
            running = false;
            break;
        default:
            printf("Pilih antara 1-4!\n");
        }
        system("pause");
        system("cls");
    }
    return 0;
}