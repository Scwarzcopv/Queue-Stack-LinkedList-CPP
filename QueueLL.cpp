#include <iostream>
#include <string.h>
#include <conio.h> //GETCH
#include <windows.h> //POS
using namespace std;

struct Node{
    char nama[30];
    int umur;
    Node *next;
};
Node *head = NULL;
Node *tail = NULL;
Node *panggilan;
Node *r_head = NULL;
Node *r_tail = NULL;
int selesai = 0;
int no_antrean = 0;
int now = 0;
int maks = 3;

void gotoxy(int x, int y){
 	COORD pos = {x, y};
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int name(const char*s){
    int jumlah = 0;
    for (;*s!='\0';s++)
    ++jumlah;
	int x = 16 - (jumlah/2);
	if (jumlah == 1){
		return 16;
	}
	else if (jumlah > 1){
		return x;
	}
}
int no_antre(int i){
	if (i < 10) {return 16;}
	else if (i < 100) {return 15;}
	else if (i < 1000) {return 14;}
}
void box(){
	if (panggilan != NULL){
		gotoxy(no_antre(no_antrean)-6,15); cout <<"NO. ANTREAN "<<no_antrean;
		gotoxy(name(panggilan->nama),16); cout <<panggilan->nama;
		gotoxy(no_antre(panggilan->umur)-3,17); cout <<panggilan->umur<<" Tahun";
	}
	else{
		gotoxy(10,15); cout <<"NO. ANTREAN 0";
		gotoxy(15,16); cout <<"---";
		gotoxy(15,17); cout <<"---";
	}
	gotoxy(10,19); cout <<"TOTAL ANTREAN";
	gotoxy(no_antre(now),20); cout <<now;
}


//========================================================================= TAMBAH
void tambah(){
	if (now < maks){
		char a[30];
		int b;
		cout<<"Nama : "; cin>>a;
		cout<<"Umur : "; cin>>b;
		Node *baru;
		baru= new Node;
		strcpy(baru->nama,a);
		baru->umur=b;
		if(head==NULL){
			head=baru;	
			head->next=NULL;
			tail=head;
		}
		else{
			tail->next=baru;
			tail=baru;
			tail->next=NULL;
		}
		now++;
		box();
		gotoxy(00,13); getch();
	}
	else{
		box();
		gotoxy(1,19); cout <<"            ANTREAN             ";
		gotoxy(1,20); cout <<"             PENUH              ";
		gotoxy(00,13); getch();
	}
}

//========================================================================= PANGGIL
panggil(){
    if(head==NULL){
    	box();
		gotoxy(1,15); cout <<"         NO. ANTREAN 0          ";
		gotoxy(1,16); cout <<"              ---               ";
		gotoxy(1,17); cout <<"              ---               ";
    	gotoxy(00,13); getch();
	}
	else{
		delete panggilan;
		panggilan = new Node;
		strcpy(panggilan->nama,head->nama);
		panggilan->umur=head->umur;
		
		//MENAMBAH DATA KE RIWAYAT
			Node *baru;
			baru= new Node;
			strcpy(baru->nama,head->nama);
			baru->umur=head->umur;
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
			selesai++;
		
       	if(head==tail){ 
        	delete  head;  
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
        box();
        gotoxy(00,13); getch();
	}
}

//========================================================================= DISPLAY
void tampil(){	
	system("cls");
	int no_urut = 1;
    Node *bantu;
    bantu=head;
    if(head!=NULL){
        while(bantu!=NULL){
        	cout <<"=================================\n";
        	cout <<no_urut<<".)\t"
							<<bantu->nama<<"\n"
							<<"\t"<<bantu->umur<<" tahun\n";
            bantu=bantu->next;
            no_urut++;
        }
        cout <<"=================================\n";
    }
	else{
		cout <<"=================================\n";
		cout <<"DATA MASIH KOSONG\n";
		cout <<"=================================\n";
	}
	getch();
}

//========================================================================= RIWAYAT
void riwayat(){	
	system("cls");
	int no_urut = 1;
    Node *bantu;
    bantu=r_head;
    cout <<"SELESAI: ("<<selesai<<")\n";
    if(r_head!=NULL){
        while(bantu!=NULL){
        	cout <<"=================================\n";
        	cout <<no_urut<<".)\t"
							<<bantu->nama<<"\n"
							<<"\t"<<bantu->umur<<" tahun\n";
            bantu=bantu->next;
            no_urut++;
        }
        cout <<"=================================\n";
    }
	else{
		cout <<"=================================\n";
		cout <<"    DATA KOSONG\n";
		cout <<"=================================\n";
	}
	//---------------------------------------------------
	int no_urut2 = 1;
    Node *bantu2;
    bantu2=head;
    cout <<"\n\nAKAN DATANG: ("<<now<<")\n";
    if(head!=NULL){
        while(bantu2!=NULL){
        	cout <<"=================================\n";
        	cout <<no_urut2<<".)\t"
							<<bantu2->nama<<"\n"
							<<"\t"<<bantu2->umur<<" tahun\n";
            bantu2=bantu2->next;
            no_urut2++;
        }
        cout <<"=================================\n";
    }
	else{
		cout <<"=================================\n";
		cout <<"    DATA KOSONG\n";
		cout <<"=================================\n";
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
			 <<"\n--------Queue Linked List---------"
             <<"\n=================================="
             <<"\n|       1. Tambah Antrean        |"
             <<"\n|       2. Panggil Antrean       |"
             <<"\n|       3. Display Antrean       |"
             <<"\n|       4. History               |"
             <<"\n|       5. Exit                  |"
             <<"\n==================================";
			gotoxy(0,14); cout <<"==================================";
			gotoxy(0,15);cout<<"|";gotoxy(0,16);cout<<"|";gotoxy(0,17);cout<<"|";
			gotoxy(33,15);cout<<"|";gotoxy(33,16);cout<<"|";gotoxy(33,17);cout<<"|";
			gotoxy(0,18); cout << "----------------------------------"; 
			gotoxy(0,19);cout<<"|";gotoxy(0,20);cout<<"|";gotoxy(33,19);cout<<"|";gotoxy(33,20);cout<<"|";
			gotoxy(0,21); cout << "----------------------------------";
		gotoxy(0,9); cout <<"Pilih Nomor ==> "; cin>>pilih;
		
		if(pilih==1){tambah();}
		else if(pilih==2) {panggil();}
		else if(pilih==3) {tampil();}
		else if(pilih==4) {riwayat();}
		else if(pilih==5) {gotoxy(0,13);cout<<"--------------------------------";gotoxy(0,9);}
		else{
			gotoxy(0,11); cout<<"^^ NOMOR TIDAK TERSEDIA ^^";
			gotoxy(00,12); getch();
		}
	}
	while(pilih!=5);
	return 0;
}
