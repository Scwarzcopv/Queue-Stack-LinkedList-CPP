#include <iostream>
#include <string.h>
#include <conio.h> //GETCH
#include <windows.h> //POS
using namespace std;

struct Node{
    char nama[30];
    int harga;
    Node *next;
};
Node *head = NULL;
Node *tail = NULL;
Node *panggilan;
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
		if(head==NULL){
			head=baru;	
			head->next=NULL;
			tail=head;
		}
		else{
			baru->next = head;
			head = baru;
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
		delete panggilan;
		panggilan = new Node;
		strcpy(panggilan->nama,head->nama);
		panggilan->harga=head->harga;
		
		//MENAMBAH DATA KE RIWAYAT
			Node *baru;
			baru= new Node;
			strcpy(baru->nama,head->nama);
			baru->harga=head->harga;
			if(r_head==NULL){
				r_head=baru;	
				r_head->next=NULL;
				r_tail=r_head;
			}
			else{
				r_tail->next=baru;
				r_tail=baru;
				r_tail->next=NULL;
			}
		
       	if(head==tail){ 
            delete head;
            head = NULL;
            tail = NULL;
    	}
	    else{
			Node *hapus;
			hapus = head;
			head = head->next;
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
void riwayat(){	
	system("cls");
	int no_urut = 1;
    Node *bantu;
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
	//---------------------------------------------------
	int no_urut2 = 1;
    Node *bantu2;
    bantu2=head;
    cout <<"\n\nDATA STACK: ("<<now<<")\n";
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
	getch();
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
		else if(pilih==3) {riwayat();}
		else if(pilih==4) {gotoxy(0,13);cout<<"--------------------------------";gotoxy(0,9);}
		else{
			gotoxy(0,11); cout<<"^^ NOMOR TIDAK TERSEDIA ^^";
			gotoxy(00,12); getch();
		}
	}
	while(pilih!=4);
	return 0;
}
