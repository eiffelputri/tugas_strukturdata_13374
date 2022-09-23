#include<iostream>
#include<conio.h>
#include<windows.h>
#define max 5

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


using namespace std;
struct paket
{
    char jenis_brg[30];
    int berat;
    char kota[30];
};

struct paket kirim[100];

/*******************************************/
void bersihlayar()
{
    for(int a=0;a<80;a++)
    {
        for(int b=0;b<=24;b++)
        {
            gotoxy(a,b);cout<<" ";
        }
    }
}

void pushdata(int x)
{
    if(x < max){
        gotoxy(20,15);cout<<"Inputkan Jenis Barang    :";
        cin>>kirim[x].jenis_brg;
        gotoxy(20,16);cout<<"Inputkan Berat           :";
        cin>>kirim[x].berat;
        gotoxy(20,17);cout<<"Inputkan Kota Tujuan     :";
        cin>>kirim[x].kota;
    }else{
        cout << "Stack Penuh" << endl;
    }
    gotoxy(40,20);cout<<"Press Any Key...";
    getch();
}

void tampildata(int x)
{
    gotoxy(40,10);cout<<"Daftar Kiriman Paket"<<endl;
    for(int a=1; a<x; a++)
    {
        gotoxy(40,19-a);
        cout<<a<<" ";
        cout<<kirim[a].jenis_brg<<" ";
        cout<<kirim[a].berat<<" ";
        cout<<kirim[a].kota<<endl;
    }
    gotoxy(40,20);
    cout<<"Press Any Key...";
    getch();
    /*harus Ijin --> #include<conio.h>*/
}

void popdata(int x)
{
    if(x >= 1){
        gotoxy(40,12);cout<<"Data Terakhir yang anda Hapus Adalah :"<<endl;
        gotoxy(40,13);cout<<kirim[x].jenis_brg<<" ";
        cout<<kirim[x].berat << " ";
        cout<<kirim[x].kota<<endl<<endl;
    }else{
        cout << "Stack kosong" << endl;
    }

    gotoxy(40,15);cout<<"Press Any Key...";
    getch();


}

int main()
{
    int pilih;
    int datake=1;
    do
    {
        bersihlayar();
        gotoxy(1,1);cout<<"MENU UTAMA";
        gotoxy(1,2);cout<<"1. PUSH Data";
        gotoxy(1,3);cout<<"2. POP Data"<<endl;
        gotoxy(1,4);cout<<"3. Tampil Data"<<endl;
        gotoxy(1,5);cout<<"9. Keluar"<<endl;

        gotoxy(1,7);cout<<"Pilihan Anda [1-9] : ";
        cin>>pilih;
        if(pilih==1)
            { /*Menambah data baru diletakan di DATAKE*/
                pushdata(datake);
                datake++;
            }
        if(pilih==2)
            { /*Menghapus Data Terakhir (DATAKE-1*/
                popdata(datake-1);
                datake--;
            }
        if(pilih==3) /*Menampilkan Data mulai
                        data ke-1 hingga DATAKE*/
            tampildata(datake);

    }
    while(pilih!=9);
    return 0;
}
