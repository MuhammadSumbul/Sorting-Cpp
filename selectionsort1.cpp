#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

int jml_mhs = 0,search;
struct mhs{
    string nama_mhs;
    int nim;
    float Partisipasi,nilai_tugas,nilai_UTS,nilai_UAS,nilai_akhir;
};mhs nilai[99];

COORD coord;
void gotoxy(int x,int y){
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void urutkan(){
    for (int a = 0; a < jml_mhs; a++) {
        search = a;
        for (int b = a+1; b < jml_mhs; b++) {
            if(nilai[b].nilai_akhir > nilai[search].nilai_akhir) {
                search = b;
            }
        }
        swap(nilai[search],nilai[a]);
    }
}

void tampilan(){
    cout<<"Nilai Akhir Mahasiswa"<<endl;
    gotoxy(0,1);cout<<"================================================================="<<endl;
    gotoxy(0,2);cout<<"No   Nama    Nim     Partisipasi  Tugas  UTS   UAS   Nilai Akhir"<<endl;
    gotoxy(0,3);cout<<"================================================================="<<endl;
    for(int a = 0;a<jml_mhs;a++){
        gotoxy(1,4+a);cout<<a+1<<endl;
        gotoxy(5,4+a);cout<<nilai[a].nama_mhs<<endl;
		gotoxy(13,4+a);cout<<nilai[a].nim<<endl;
        gotoxy(26,4+a);cout<<nilai[a].Partisipasi<<endl;
		gotoxy(35,4+a);cout<<nilai[a].nilai_tugas<<endl;
        gotoxy(41,4+a);cout<<nilai[a].nilai_UTS<<endl;
		gotoxy(47,4+a);cout<<nilai[a].nilai_UAS<<endl;
		gotoxy(57,4+a);cout<<nilai[a].nilai_akhir<<endl;
    }
}

int main(){
    lagi :
    cout<<"Nama Mahasiswa \t\t: "; getline(cin,nilai[jml_mhs].nama_mhs);
    cout<<"NIM Mahasiswa \t\t: "; cin>>nilai[jml_mhs].nim;
    cout<<"---------------------------------"<<endl;
    cout<<"Nilai Partisipasi \t: "; cin>>nilai[jml_mhs].Partisipasi;
    cout<<"Nilai Tugas \t\t: "; cin>>nilai[jml_mhs].nilai_tugas;
    cout<<"Nilai UTS \t\t: "; cin>>nilai[jml_mhs].nilai_UTS;
    cout<<"Nilai UAS \t\t: "; cin>>nilai[jml_mhs].nilai_UAS;cin.ignore();
    nilai[jml_mhs].nilai_akhir = (nilai[jml_mhs].Partisipasi*0.2+nilai[jml_mhs].nilai_tugas*0.3+nilai[jml_mhs].nilai_UTS*0.2+nilai[jml_mhs].nilai_UAS*0.3);
    jml_mhs++;
    cout<<"\nMenambah Mahasiswa (y)  : ";
    char x = getch();
    system("cls");
    if(x=='y'||x=='Y'){goto lagi;}
	
	cout<<"Sebelum di sorting"<<endl;
    tampilan();
    system("pause");
    urutkan();
    system("cls");
    tampilan();
    
}
