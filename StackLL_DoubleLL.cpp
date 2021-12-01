#include <iostream>
#include <string.h>
#include <conio.h> //GETCH
#include <windows.h> //POS
using namespace std;

struct Node{
    char nama[30];
    int harga;
    Node *next;
    Node *prev;
};
Node *head = NULL;
Node *tail = NULL;
Node *r_head = NULL;
Node *r_tail = NULL;
int no_antrean = 0;
int now = 0;
int maks = 5;

void gotoxy(int x, int y){
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int no_disp(int i){
	if (i < 10) {return 43;}
	else if (10 < i < 100) {return 42;}
	else if (100 < i < 1000) {return 41;}
}
Node *t_head = NULL;
Node *t_tail = NULL;

//========================================================================= TAMBAH
void tambah(){
	if (now < maks){
		string aa; fflush(stdin);
		char a[30];
		int b;
		gotoxy(0,10); cout<<"Judul Buku : "; getline(cin, aa); strcpy(a, aa.c_str());
		gotoxy(0,11); cout<<"Harga Buku : "; cin>>b;
		Node *baru;
		baru= new Node;
		strcpy(baru->nama,a);
		baru->harga=b;
		
	    baru->next = NULL;
	    baru->prev = NULL;
		if (head==NULL){
			head=tail=baru;
		}
		else {
			tail->next=baru;
			baru->prev=tail;
			tail=baru;
		}
		now++;
	}
	else{
		gotoxy(0,10); cout<<"==STACK PENUH==";
		gotoxy(00,11); getch();
	}
}

//========================================================================= PANGGIL
panggil(){
    if(head==NULL){
		gotoxy(0,10); cout<<"==DATA KOSONG==";
		gotoxy(00,11); getch();
	}
	else{
		//MENAMBAH DATA KE RIWAYAT
			Node *baru;
			baru= new Node;
			strcpy(baru->nama,tail->nama);
			baru->harga=tail->harga;
			
		    baru->next = NULL;
		    baru->prev = NULL;
			if (r_head==NULL){
				r_head=r_tail=baru;
			}
			else {
				r_tail->next=baru;
				baru->prev=r_tail;
				r_tail=baru;
			}
		//--------------------------
		Node *hapus;
		if(head==tail){
            delete head;
            head = NULL;
            tail = NULL;
		}
		else{
	        hapus = tail;
	        tail = tail->prev;
	        tail->next = NULL;
	        delete hapus;
		}
        no_antrean++;
        now--;
	}
}

//========================================================================= DISPLAY
void tampil(){
	int no_urut = 1;
	int urut = 0;
    Node *bantu;
    bantu=head;
    if(head!=NULL){
        while(bantu!=NULL){
        	gotoxy(40,0); cout <<"==================================";
			gotoxy(40,urut+1); cout<<"|";gotoxy(40,urut+2);cout<<"|";gotoxy(73,urut+1);cout<<"|";gotoxy(73,urut+2);cout<<"|";
			gotoxy(46,urut+1); cout<<"|";gotoxy(46,urut+2);cout<<"|";
			gotoxy(40,urut+3); cout << "----------------------------------";
        	gotoxy(no_disp(no_urut),urut+1); cout <<no_urut;
				gotoxy(49,urut+1); cout <<bantu->nama;
				gotoxy(49,urut+2); cout <<"Rp "<<bantu->harga<<",-";
            bantu=bantu->next;
            no_urut++;
            urut=urut+3;
        }
        gotoxy(40,urut+1); cout <<"==================================";
        if (now == maks){
        	gotoxy(40,urut+2); cout <<"|            DATA PENUH          |";
        	gotoxy(40,urut+3); cout <<"==================================";
		}
    }
	else{
		gotoxy(40,0); cout <<"==================================";
		gotoxy(40,1); cout <<"|           DATA KOSONG          |";
		gotoxy(40,2); cout <<"==================================";
	}
}

//========================================================================= RIWAYAT
void riwayat(int pilihan){	
	gotoxy(0,8);
	int no_urut = 1;
    Node *bantu;
    if (pilihan==1){
	    bantu=r_head;
	    cout <<"DATA POP: ("<<no_antrean<<")\n";
	    if(r_head!=NULL){
	        while(bantu!=NULL){
	        	cout <<"==================================\n";
	        	cout <<no_urut<<".)\t"
								<<bantu->nama<<"\n"
								<<"\tRp "<<bantu->harga<<",-\n";
	            bantu=bantu->next;
	            no_urut++;
	        }
	        cout <<"==================================\n";
	    }
		else{
			cout <<"==================================\n";
			cout <<"\tDATA KOSONG\n";
			cout <<"==================================\n";
		}
	}
	else if (pilihan==2){
	    bantu=r_tail;
	    cout <<"DATA POP: ("<<no_antrean<<")\n";
	    if(r_tail!=NULL){
	        while(bantu!=NULL){
	        	cout <<"==================================\n";
	        	cout <<no_urut<<".)\t"
								<<bantu->nama<<"\n"
								<<"\tRp "<<bantu->harga<<",-\n";
	            bantu=bantu->prev;
	            no_urut++;
	        }
	        cout <<"==================================\n";
	    }
		else{
			cout <<"==================================\n";
			cout <<"\tDATA KOSONG\n";
			cout <<"==================================\n";
		}
	}

	//---------------------------------------------------
	int no_urut2 = 1;
    Node *bantu2;
    bantu2=head;
    cout <<"\nDATA STACK: ("<<now<<")\n";
    if(head!=NULL){
        while(bantu2!=NULL){
        	cout <<"==================================\n";
        	cout <<no_urut2<<".)\t"
							<<bantu2->nama<<"\n"
							<<"\tRp "<<bantu2->harga<<",-\n";
            bantu2=bantu2->next;
            no_urut2++;
        }
        cout <<"==================================\n";
    }
	else{
		cout <<"==================================\n";
		cout <<"\tDATA KOSONG\n";
		cout <<"==================================\n";
	}
}
void naikturun(){
	int pilih;
	int pilihan = 1;
	do{
		system("cls");
		cout <<"-----------------------\n"
			 <<"|  1. POP Descending  |\n"
			 <<"|  2. POP Ascending   |\n"
			 <<"|  3. Kembali         |\n"
			 <<"-----------------------\n";
			 riwayat(pilihan);
		gotoxy(0,5); cout <<"Pilih Nomor ==> ";cin>>pilih;
		if (pilih==1){
			pilihan = 1;
		}
		else if (pilih==2){
			pilihan = 2;
		}
	}
	while(pilih!=3);
}

//========================================================================= MAIN
int main()
{
	int pilih;
	do
	{
		system("cls");
        cout <<  "=================================="
			 <<"\n--------Stack Linked List---------"
             <<"\n=================================="
             <<"\n|        1. PUSH Stack           |"
             <<"\n|        2. POP Stack            |"
             <<"\n|        3. History              |"
             <<"\n|        4. Exit                 |"
             <<"\n==================================";
             tampil();
		gotoxy(0,8); cout <<"Pilih Nomor ==> "; cin>>pilih;
		
		if(pilih==1){tambah();}
		else if(pilih==2) {panggil();}
		else if(pilih==3) {naikturun();}
		else if(pilih==4) {gotoxy(0,13);cout<<"--------------------------------";gotoxy(0,9);}
		else{
			gotoxy(0,11); cout<<"^^ NOMOR TIDAK TERSEDIA ^^";
			gotoxy(00,12); getch();
		}
	}
	while(pilih!=4);
	return 0;
}
