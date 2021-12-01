#include <iostream>
#include <string.h>
#include <conio.h> //GETCH
#include <windows.h> //POS
using namespace std;

struct Node{
    char nama[30];
    int umur;
    Node *next;
    Node *prev;
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
	else if (10 < i < 100) {return 15;}
	else if (100 < i < 1000) {return 14;}
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
	if (now==maks){
		gotoxy(7,19); cout <<"ANTREAN SUDAH PENUH";
		gotoxy(no_antre(now),20); cout <<now;
	}
}


//========================================================================= TAMBAH
void tambah(){
	if (now < maks){
		string aa; fflush(stdin); 
		char a[30];
		int b;
		gotoxy(0,10); cout<<"Nama : "; getline(cin, aa); strcpy(a, aa.c_str());
		gotoxy(0,11); cout<<"Umur : "; cin>>b;
		Node *baru;
		baru= new Node;
		strcpy(baru->nama,a);
		baru->umur=b;
		
	    baru->next = NULL;
	    baru->prev = NULL;
		if(head==NULL){
			head=tail=baru;
		}
		else{
			tail->next=baru;
			baru->prev=tail;
			tail=baru;
		}
		now++;
	}
	else{
		gotoxy(0,11); cout <<"==ANTREAN FULL=="; 
		gotoxy(0,13); getch();
	}
}

//========================================================================= PANGGIL
panggil(){
    if(head==NULL){
    	gotoxy(0,11); cout <<"==ANTREAN KSNG=="; 
		gotoxy(0,13); getch();
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
			
		    baru->next = NULL;
		    baru->prev = NULL;
			if(r_head==NULL){
				r_head=r_tail=baru;
			}
			else{
				r_tail->next=baru;
				baru->prev=r_tail;
				r_tail=baru;
			}
		//-------------------------
		
		Node *hapus;
       	if(head==tail){ 
        	delete head;  
			head = NULL;
			tail = NULL;
    	}
	    else{
	        hapus = head;
	        head = head->next;
	        head->prev = NULL;
	        delete hapus;
	    }
        no_antrean++;
        now--;
	}
}

//========================================================================= DISPLAY
void tampil(int pilihan){	
	gotoxy(0,8);
	int no_urut = 1;
    Node *bantu;
    if (head!=NULL){
	    if (pilihan==1){
		    bantu=head;
	        while(bantu!=NULL){
	        	cout <<"==================================\n";
	        	cout <<no_urut<<".)\t"
								<<bantu->nama<<"\n"
								<<"\t"<<bantu->umur<<" tahun\n";
	            bantu=bantu->next;
	            no_urut++;
	        }
	        cout <<"==================================\n";
		}
		else if (pilihan==2){
		    bantu=tail;
	        while(bantu!=NULL){
	        	cout <<"==================================\n";
	        	cout <<no_urut<<".)\t"
								<<bantu->nama<<"\n"
								<<"\t"<<bantu->umur<<" tahun\n";
	            bantu=bantu->prev;
	            no_urut++;
	        }
	        cout <<"==================================\n";
		}		
	}
	else{
		cout <<"==================================\n";
		cout <<"DATA MASIH KOSONG\n";
		cout <<"==================================\n";
	}
}
d_naikturun(){
	int pilih;
	int pilihan = 1;
	do{
		system("cls");
		cout <<"---------------------------\n"
			 <<"|  1. Antrean Descending  |\n"
			 <<"|  2. Antrean Ascending   |\n"
			 <<"|  3. Kembali             |\n"
			 <<"---------------------------\n";
			 tampil(pilihan);
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

//========================================================================= RIWAYAT
void riwayat(int pilihan){	
	int no_urut = 1;
    Node *bantu;
    if (pilihan==1){
    	gotoxy(0,8);
	    bantu=r_head;
	    cout <<"SELESAI: ("<<no_antrean<<")\n";
	    if(r_head!=NULL){
	        while(bantu!=NULL){
	        	cout <<"==================================\n";
	        	cout <<no_urut<<".)\t"
								<<bantu->nama<<"\n"
								<<"\t"<<bantu->umur<<" tahun\n";
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
    	gotoxy(0,8);
	    bantu=r_tail;
	    cout <<"SELESAI: ("<<no_antrean<<")\n";
	    if(r_tail!=NULL){
	        while(bantu!=NULL){
	        	cout <<"==================================\n";
	        	cout <<no_urut<<".)\t"
								<<bantu->nama<<"\n"
								<<"\t"<<bantu->umur<<" tahun\n";
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
    cout <<"\nAKAN DATANG: ("<<now<<")\n";
    if(head!=NULL){
        while(bantu2!=NULL){
        	cout <<"==================================\n";
        	cout <<no_urut2<<".)\t"
							<<bantu2->nama<<"\n"
							<<"\t"<<bantu2->umur<<" tahun\n";
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
void r_naikturun(){
	int pilih;
	int pilihan = 1;
	do{
		system("cls");
		cout <<"---------------------------\n"
			 <<"|  1. Selesai Descending  |\n"
			 <<"|  2. Selesai Ascending   |\n"
			 <<"|  3. Kembali             |\n"
			 <<"---------------------------\n";
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
			 <<"\n--------Queue Linked List---------"
             <<"\n=================================="
             <<"\n|       1. Tambah Antrean        |"
             <<"\n|       2. Panggil Antrean       |"
             <<"\n|       3. Display Antrean       |"
             <<"\n|       4. History               |"
             <<"\n|       5. Exit                  |"
             <<"\n==================================";
        box();
			gotoxy(0,14); cout <<"==================================";
			gotoxy(0,15);cout<<"|";gotoxy(0,16);cout<<"|";gotoxy(0,17);cout<<"|";
			gotoxy(33,15);cout<<"|";gotoxy(33,16);cout<<"|";gotoxy(33,17);cout<<"|";
			gotoxy(0,18); cout << "----------------------------------"; 
			gotoxy(0,19);cout<<"|";gotoxy(0,20);cout<<"|";gotoxy(33,19);cout<<"|";gotoxy(33,20);cout<<"|";
			gotoxy(0,21); cout << "----------------------------------";
		gotoxy(0,9); cout <<"Pilih Nomor ==> "; cin>>pilih;
		
		if(pilih==1){tambah();}
		else if(pilih==2) {panggil();}
		else if(pilih==3) {d_naikturun();}
		else if(pilih==4) {r_naikturun();}
		else if(pilih==5) {gotoxy(0,13);cout<<"--------------------------------";gotoxy(0,9);}
		else{
			gotoxy(0,11); cout<<"^^ NOMOR TIDAK TERSEDIA ^^";
			gotoxy(00,12); getch();
		}
	}
	while(pilih!=5);
	return 0;
}
