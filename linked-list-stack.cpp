#include <iostream>
using namespace std;

// Deklarasi linked list node
struct Node
{
	int data;
	Node *link;
};

Node *top;

// Fungsi untuk menambah elemen ke atas stack
void push(int data)
{
	// Buat node sementara untuk mengalokasi memori di heap
	Node *temp = new Node();

	// Cek jika heap penuh
	if (!temp)
	{
		cout << "Tumpukan penuh!\n";
		exit(1);
	}

	// Inisialisasi data ke data field sementara
	temp->data = data;

	// Taro reference top pointer ke link sementara
	temp->link = top;

	// Jadikan temp sebagai top of stack
	top = temp;
}

// Cek jika stack kosong atau tidak
int isEmpty()
{
	// Jika top == NULL, berarti tidak ada elemen pada stack
	return top == NULL;
}

// Fungsi untuk mereturn top elemen pada stack
int peek()
{
	// Jika stack tidak kosong, return top element
	if (!isEmpty())
		return top->data;
	else
		exit(1);
}

// Fungsi untuk menghapus elemen paling atas dari stack
void pop()
{
	Node *temp;

	// Cek apakah stack kosong
	if (isEmpty())
	{
		cout << "Stack kosong!" << endl;
	}
	else
	{
		// Jadikan temp sebagai top
		temp = top;

		// Jadikan node kedua menjadi top
		top = top->link;

		// Hilangkan memory top node
		free(temp);
	}
}

// Fungsi untuk print semua elemen pada stack
void display()
{
	Node *temp;

	// Cek jika stack kosong
	if (isEmpty())
	{
		cout << "Stack kosong!" << endl;
	}
	else
	{
		temp = top;
		while (temp != NULL)
		{

			// Print data node
			cout << temp->data << "->";

			// Jadikan temp sebagai temp link
			temp = temp->link;
		}
		cout << endl;
	}
}

// ===== Fungsi Main =====
int main()
{
	int pilihan, input;

	bool running = true;
	while (running)
	{
		printf("=======================\n");
		printf("   LINKED LIST STACK\n");
		printf("=======================\n");
		printf(">>> Pilih aksi\n");
		printf("1) Push item\n");
		printf("2) Pop item\n");
		printf("3) Print list item\n");
		printf("4) Keluar dari program\n");
		printf("Pilihan: ");
		cin >> pilihan;
		printf("--------------------\n");
		switch (pilihan)
		{
		case 1:
			printf(">>> Masukkan nilai integer yang ingin diinput ke dalam stack\n");
			printf("Nilai: ");
			cin >> input;
			push(input);
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
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
