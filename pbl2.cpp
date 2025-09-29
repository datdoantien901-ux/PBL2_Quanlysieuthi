#include <iostream>
#include "my_cstring.h"
using namespace std;    

class Date{
    private:
        int ngay;
        int thang;
        int nam;
    public:
        Date(){
            ngay = 1;
            thang = 1;
            nam = 2000;
        }
        Date(int dd, int mm, int yy){
            ngay = dd;
            thang = mm;
            nam = yy;
        }
        void nhap(){
            cout << " nhap ngay:" ; cin >> ngay;
            cout << " nhap thang:" ; cin >> thang;
            cout << " nhap nam:" ; cin >> nam;
        }
        void xuat() const{
            cout << ngay << "|" << thang << "|" << nam;
        }
        bool hopLe(if ngay < 1 || ngay > 31 || thang < 1 || thang > 12 || nam < 0) { return false;}
        else { if ( nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0){
            
        }
    }
};
class sanpham{
    private:
        int maSP;
        char* tenSP;
        float giaSP;
        int soluongSP;
    public:
        sanpham(){
            maSP = 0;
            tenSP = nullptr;
            giaSP = 0;
            soluongSP =0;
        }
        ~sanpham(){ delete[] tenSP;
    }
    void setTen(const char *ten){
        delete[] tenSP;
        tenSP = new char[my_strlen(ten) + 1 ];
        my_strcpy(tenSP, ten);
    }


void nhap(){
    cout << " Nhap ma Sp "; cin >> maSP;
    cin.ignore();
    cout << " Ten Sp"; 
    char buf[1000];
    cin.getline(buf, 1000);
    setTen(buf);
    cout << " Gia Sp "; cin >> giaSP;
    cout << " So luong Sp "; cin >> soluongSP;
}
void xuat() const{
    cout << " Ma Sp " << maSP << " | Ten Sp: " << (tenSP ? tenSP : "") << "| Gia Sp: " << giaSP << " | So luong Sp: " << soluongSP << endl;
}
int getMaSP() const { return maSP;}
const char* gettenSP() const { return tenSP;}
float getgiaSP() const { return giaSP;}
int getsoluongSP() const { return soluongSP;}
void setsoluongSP(int SL) { soluongSP = SL;}
};

class KH{
    private:
        int maKH;
        char* tenKH;
        int sodiem;
    public:
        KH(){
            maKH = 0;
            tenKH = nullptr;
            sodiem = 0;
        }
        ~KH(){ delete[] tenKH;}
        void setTen(const char* ten){
            delete[] tenKH;
            tenKH = new char[my_strlen(ten)+1];
            my_strcpy(tenKH, ten);
        }
        void nhap(){
            cout << " Nhap ma Kh"; cin >> maKH;
            cin.ignore();
            cout <<" Nhap ten KH ";
            char buf[1000];
            cin.getline(buf, 1000);
            setTen(buf);
        }
        void xuat() const{
            cout << " Ma KH: " << maKH << " | Ten KH: " << (tenKH ? tenKH : "")<<"| Diem:" << sodiem << endl;         
        }
        int getmaKH() const { return maKH;}
};

class NV{
    private:
        int maNV;
        char* tenNV;
        char* ca;

    public:
        NV(){
            maNV = 0;
            tenNV = nullptr;
            ca = nullptr;
        }
        ~NV(){ delete[] tenNV;
            delete[] ca;
        }
        void setTen(const char* ten){
            delete[] tenNV;
            tenNV = new char[my_strlen(ten) +1];
            my_strcpy(tenNV, ten);
        }
        void setCa(const char* c){
            delete[] ca;
            ca = new char[my_strlen(c) + 1];
            my_strcpy(ca, c);
        }
        void nhap(){
            cout << " Nhap ma NV"; cin >> maNV;
            cin.ignore();
            cout << " Nhap ten Nv"; 
            char buf[1000]; cin.getline(buf, 1000);
            setTen(buf);
            cout << " nhap ca lam:"; cin.getline(buf, 1000);
            setCa(buf);        
        }
        void xuat() const{
            cout << " Ma NV: " << maNV << "| ten NV "<< (tenNV ? tenNV: "") << " | Ca lam" << ( ca ? ca : "")<< endl;
        }
};
class HD{
    private:
        int maHD;
        int maKH;
        int maNV;
        char* ngaytao;
        sanpham* dsSP;
        int* soluongMua;
        int luongSP;
    public:
        HD(){
            maHD = 0;
            maKH = 0;
            maNV = 0;
            ngaytao = nullptr;
            dsSP = nullptr;
            soluongMua = nullptr;
            luongSP = 0;
        }
        ~HD(){
            delete[] ngaytao;
            delete[] dsSP;
            delete[] soluongMua;
        }
        void setNgay(const char* ngay){
            delete[] ngaytao;
            ngaytao = new char[my_strlen(ngay) + 1];
            my_strcpy(ngaytao, ngay);
        }
        void taoHD(int mahd, int kh, int nv, const char* ngay){
            maHD = mahd;
            maKH = kh;
            maNV = nv;
            setNgay(ngay);
        }
        void themSanPham(const sanpham &sp, int sl) {
        sanpham *newDS = new sanpham[luongSP+1];
        int *newSL = new int[luongSP+1];
        for (int i = 0; i < luongSP; i++) {
            newDS[i] = dsSP[i];
            newSL[i] = soluongMua[i];
        }
        newDS[luongSP] = sp;
        newSL[luongSP] = sl;

        delete[] dsSP;
        delete[] soluongMua;
        dsSP = newDS;
        soluongMua = newSL;
        luongSP++;
    }

    float tinhTong() const {
        float tong = 0;
        for (int i=0; i<luongSP; i++) tong += dsSP[i].getgiaSP() * soluongMua[i];
        return tong;
    }

    void xuat() const {
        cout << "=== HOA DON #" << maHD << " (" << ngaytao << ") ===\n";
        for (int i=0; i<luongSP; i++) {
            cout << "- " << dsSP[i].gettenSP()
                 << " | SL: " << soluongMua[i]
                 << " | Gia: " << dsSP[i].getgiaSP() << endl;
        }
        cout << "Tong tien: " << tinhTong() << endl;
    }
};
class Thongke{
    private:

};

class QL{
    private:

        
};