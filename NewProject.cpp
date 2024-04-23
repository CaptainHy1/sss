#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring> 
#include <ctime>
#include <sstream>
#include <vector>
#include <conio.h>
using namespace std;
struct Date{
	int day;
	int month;
	int year; 
};
typedef struct Date DATE;
void Read_Date(ifstream &filein,DATE &x){
	filein >> x.day;filein.ignore();
	filein >> x.month;filein.ignore();
	filein >> x.year;filein.ignore();
}
struct Distance{
	string tendiaphuong;
	string shipper;
};
typedef struct Distance DISTANCE;

struct NodeDistance{
	DISTANCE data;
	NodeDistance* next;
};
typedef struct NodeDistance* NODEDISTANCE; 

struct ListDistance{
	NodeDistance* head;
	NodeDistance* tail;
};
typedef struct ListDistance LISTDISTANCE;

void InsertLastDistance(LISTDISTANCE &l, NODEDISTANCE x){
	if(l.head == NULL) l.head = l.tail = x;
	else{
		l.tail->next = x;
		l.tail = x;
	}
}

NODEDISTANCE createdistance(DISTANCE x){
	NODEDISTANCE newnode = new NodeDistance;
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

struct BuuKien{
	int code;
	string item;
	string receiver;
	string sender;
	string address;
	int price;
	int dongia;
	int mass;
	DATE time;
	int status;
	string sdtr;
	string sdts;
	string shipperr;
};
typedef struct BuuKien BK;

struct Node{
	BK data;
	Node *next;
};
typedef struct Node* NODE;

struct list{
	NODE head;
	NODE tail;
};
typedef struct list LIST;

NODE create(BK x){
	NODE newnode = new Node;
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void InitListBK(LIST &l){
	l.head = NULL;
	l.tail = NULL;
}

void InitListDistance(LISTDISTANCE &l){
	l.head = NULL;
	l.tail = NULL;
}
void InsertLast(LIST &l, NODE x) {
	if (l.head == NULL) { 
        l.head = l.tail = x; 
    } else {
        l.tail->next = x; 
        l.tail = x;
    }
}
void DeleteSelect(LIST &l,int x){
	NODE prev = NULL;
	NODE temp = l.head;
	if(temp==NULL){
		cout << "Danh Sach Trong!"<<endl;return;
	}
	if (temp != NULL && temp->data.code == x) { //Kiem tra neu ma buu kien can xoa la node dau
		l.head = temp->next;
		delete temp;cout << "Xoa Thanh Cong!"<<endl;
		return;
	}
	while(temp!=NULL && temp->data.code != x){
		prev = temp;
		temp = temp->next;
	}
	if(temp==NULL) cout << "Khong tim thay ma buu kien can xoa!"<<endl;
	else{
	prev->next = temp->next;
	delete(temp);
	cout << "Xoa Thanh Cong!"<<endl;}
}
void Read_Distance(ifstream &filein,DISTANCE &x){
	getline(filein,x.tendiaphuong,',');
	getline(filein,x.shipper,',');
}
void Read_All_Distance(ifstream &filein,LISTDISTANCE &l){
	while(!filein.fail()){
		DISTANCE x;
		Read_Distance(filein,x);
		if (filein.fail())
        break;
		NODEDISTANCE newnode = createdistance(x);
		InsertLastDistance(l,newnode);
	}
}


void Display(LIST l){
	if (l.head == NULL) cout << "DANH SACH RONG!" <<endl;
	else{
	NODE temp = l.head;
		while(temp!=NULL){
		cout <<endl<< "       		Thong tin don hang:  "<<endl;
		cout << "Ma buu kien   : " << temp->data.code <<endl;
		cout << "Ten hang      : " << temp->data.item<<endl;
		cout << "Ten nguoi gui : " << temp->data.sender<<endl;
		cout << "SDT           : " << temp->data.sdts<<endl;
		cout << "Ten nguoi nhan: " << temp->data.receiver<<endl;cout << "SDT           : "<< temp->data.sdtr<<endl;
		cout << "Dia diem giao : " << temp->data.address<<endl;
		cout << "Thanh tien    : " << temp->data.price<<" VND"<<endl;
		cout << "Khoi luong    : " <<temp->data.mass<<" kg"<<endl;
		cout << "Ngay gui      : " << setw(2)<<setfill('0')	<<temp->data.time.day<<"/"<< setw(2)<<setfill('0')<<temp->data.time.month<<"/"<<temp->data.time.year<< endl;
		cout << "Shipper       : " << temp->data.shipperr<<endl;
		if(temp->data.status == 0) cout << "Tinh trang    : Dang giao!"<<endl;
		else if(temp->data.status == 1) cout << "Tinh trang    : Da giao!"<<endl;
		temp = temp->next;
	}
 }
}

void out(){
	cout << endl;
	cout << "--------- QUAN LI BUU KIEN TAI BUU CUC --------"<<endl;
	cout << "              1.Nhap buu kien"<<endl;cout<<endl;
	cout << "              2.Xoa buu kien"<<endl;cout<<endl;
	cout << "              3.Xem buu kien"<<endl;cout<<endl;
	cout << "              4.Thong ke buu kien o cac quan,huyen"<<endl;cout<<endl;
	cout << "       	      5.Chinh sua buu kien"<<endl;cout<<endl;
	cout << "       	      6.Cap nhat trang thai buu kien"<<endl;cout<<endl;
	cout << "       	      7.Save"<<endl;cout<<endl;
	cout << "       	      0.Thoat"<<endl;cout<<endl;
	cout << "-----------------------------------------------"<<endl;
	cout << "Nhap lua chon : ";
}

string Address(BK x){int luachon;
	cout << "-------- Khu vuc giao hang --------"<<endl;
	cout << "              QUAN:            "<<endl;
	cout << "          1.Hai Chau"<<endl;
	cout << "          2.Lien Chieu"<<endl;
	cout << "          3.Thanh Khe"<<endl;
	cout << "          4.Cam Le"<<endl;
	cout << "          5.Son Tra"<<endl;
	cout << "          6.Ngu Hanh Son"<<endl;
	cout << "              HUYEN:        "<<endl;
	cout << "          7.Hoa Vang"<<endl;
	cout << "          8.Hoang Sa"<<endl;
	cout << "Chon khu vuc : ";cin>>luachon;
	switch(luachon){
		case 1: x.address="Hai Chau";break;
		case 2: x.address="Lien Chieu";break;
		case 3: x.address="Thanh Khe";break;
		case 4: x.address="Cam Le";break;
		case 5: x.address="Son Tra";break;
		case 6: x.address="Ngu Hanh Son";break;
		case 7: x.address="Hoa Vang";break;
		case 8: x.address="Hoang Sa";break;
		default:cout<<"Vui long nhap dung STT!"<<endl;x.address = Address(x);
	}
	return x.address;
}
string LoaiBoXuongDongODau(string &s) {
    while (!s.empty() && s.front() == '\n') {
        s.erase(0, 1); 
    }
    return s;
}
string NguoiGiao(BK &x,string s,LISTDISTANCE ld){
	ifstream filein;
	filein.open("danhsachnhanviengiaohang.txt",ios::in);
	Read_All_Distance(filein,ld);
	NODEDISTANCE temp = ld.head;
	while(temp!=NULL){
		if(LoaiBoXuongDongODau(temp->data.tendiaphuong)==s){
		x.shipperr=temp->data.shipper;break;
		}
		temp=temp->next;
	}
	return x.shipperr;
}


bool Read(ifstream &filein, BK &x,LISTDISTANCE &ld) {
    if (!(filein >> x.code)) return false;
    filein.ignore();
    getline(filein, x.item, ',');
    getline(filein, x.sender, ',');
    getline(filein, x.sdts, ',');
    getline(filein, x.receiver, ',');
    getline(filein, x.sdtr, ',');
    getline(filein, x.address, ',');
    if (!(filein >> x.price)) return false;
    filein.ignore();
    if (!(filein >> x.mass)) return false;
    filein.ignore();
    Read_Date(filein, x.time);
    if (!(filein >> x.status)) return false;
    filein.ignore();
    x.shipperr=NguoiGiao(x,x.address,ld);
	return true;
}


void Doc_File(ifstream &filein,LIST &l,LISTDISTANCE &ld){
	BK x;
	while(Read(filein,x,ld)){
		NODE newnode = create(x);
		InsertLast(l,newnode);
	}
}


void Save(LIST &l){
	cin.ignore(); string s;cout <<"Nhap ngay lam viec :";getline(cin,s);
	ofstream fileout; int demdagiao=0,demdanggiao=0,tongtien=0;
	fileout.open((s + ".txt").c_str(), ios::out); 
	NODE temp = l.head;
	    		   fileout << setw(5) << "Ma Buu Kien" << " | "
                    << setw(10) << "Ten Hang" << " | "
                    << setw(20) << "Ten Nguoi Gui" << " | "
                    << setw(12) << "SDT " << " | "
                    << setw(20) << "Ten Nguoi Nhan" << " | "
                    << setw(12) << "SDT " << " | "
                    << setw(18) << "Dia Diem Giao Hang" << " | "
                    << setw(10) << "Thanh Tien" << " | "
                    << setw(11) << "Khoi Luong" << " | "
                    << setw(10) << "Ngay Gui" << " | "
                    << setw(16) << "Shipper" << " | "
                    << setw(10) << "Tinh Trang" << endl;
    fileout << setfill('-') << setw(196) << "-" << setfill(' ') << endl;
	while(temp != NULL){
 fileout << right << setw(11) << temp->data.code << " | "
		 << setw(10) << temp->data.item << " | "
		 << setw(20) << temp->data.sender << " | "
		 << setw(12) << temp->data.sdts << " | "
		 << setw(20) << temp->data.receiver << " | "
		 << setw(12) << temp->data.sdtr << " | "
		 << setw(18) << temp->data.address << " | "
 		 << setw(6) << temp->data.price<<" VND" << " | "
		 << setw(8) << temp->data.mass<<" kg" << " | "
		 << setfill('0') << setw(2) << temp->data.time.day << "/" << setw(2) << temp->data.time.month << "/" << temp->data.time.year << " | ";
         fileout << setfill(' ');
         fileout << setw(16) << temp->data.shipperr << " | ";
		if(temp->data.status==1){
			fileout<< setw(9) << "Da Giao!" << endl;demdagiao++;tongtien+= temp->data.price;}
	   	 else if(temp->data.status==0) 
			{fileout<< setw(9) << "Dang Giao!" << endl;demdanggiao++;}
	temp = temp->next;
	}
	fileout <<endl<< "THONG KE"<<endl;
	fileout<< "Da giao  : "<<demdagiao<<endl<<endl;
	fileout <<"Dang giao: "<<demdanggiao<<endl<<endl;
	fileout<< "Tong so tien da nhan : "<<tongtien<<" VND"<<endl;
	fileout.close();
}

bool CHECK(LIST &l){
	bool check = true;
	if(l.head==NULL){
		check = false;
	 cout << "DANH SANH RONG!"<<endl;}
}

void PhanLoai(LIST l, int x) {
	switch(x){
		case 1:
    		{
			NODE temp = l.head;bool find=false;
    						cout << "                                                                         DANH SACH CAC BUU KIEN : DA GIAO "<<endl<<endl;
				while(temp!=NULL){
    			if(temp->data.status==1){
				cout <<endl<< "       		Thong tin don hang:  "<<endl;
			cout << "Ma buu kien   : " << temp->data.code <<endl;
			cout << "Ten hang      : " << temp->data.item<<endl;
			cout << "Ten nguoi gui : " << temp->data.sender<<endl;
			cout << "SDT           : " << temp->data.sdts<<endl;
			cout << "Ten nguoi nhan: " << temp->data.receiver<<endl;cout << "SDT           : "<< temp->data.sdtr<<endl;
			cout << "Dia diem giao : " << temp->data.address<<endl;
			cout << "Thanh tien    : " << temp->data.price<<" VND"<<endl;
			cout << "Khoi luong    : " <<temp->data.mass<<" kg"<<endl;
			cout << "Ngay gui      : " << setw(2)<<setfill('0')	<<temp->data.time.day<<"/"<< setw(2)<<setfill('0')<<temp->data.time.month<<"/"<<temp->data.time.year<< endl;
			cout << "Shipper       : " << temp->data.shipperr<<endl;
			if(temp->data.status == 0) cout << "Tinh trang    : Dang giao!"<<endl;
			else if(temp->data.status == 1) cout << "Tinh trang    : Da giao!"<<endl<<endl;;find=true;
				}
				temp=temp->next;
    			}
			if(!find) cout << "Khong tim thay buu kien co TRANG THAI : Da Giao!"<<endl;}
			break;
		case 2:
    		{NODE temp = l.head;bool find=false;
    						cout << "                                                                        DANH SACH CAC BUU KIEN : DANG GIAO "<<endl<<endl;
   
			while(temp!=NULL){
    			if(temp->data.status==0){

				cout <<endl<< "       		Thong tin don hang:  "<<endl;
			cout << "Ma buu kien   : " << temp->data.code <<endl;
			cout << "Ten hang      : " << temp->data.item<<endl;
			cout << "Ten nguoi gui : " << temp->data.sender<<endl;
			cout << "SDT           : " << temp->data.sdts<<endl;
			cout << "Ten nguoi nhan: " << temp->data.receiver<<endl;cout << "SDT           : "<< temp->data.sdtr<<endl;
			cout << "Dia diem giao : " << temp->data.address<<endl;
			cout << "Thanh tien    : " << temp->data.price<<" VND"<<endl;
			cout << "Khoi luong    : " <<temp->data.mass<<" kg"<<endl;
			cout << "Ngay gui      : " << setw(2)<<setfill('0')	<<temp->data.time.day<<"/"<< setw(2)<<setfill('0')<<temp->data.time.month<<"/"<<temp->data.time.year<< endl;
			cout << "Shipper       : " << temp->data.shipperr<<endl;
			if(temp->data.status == 0) cout << "Tinh trang    : Dang giao!"<<endl;
			else if(temp->data.status == 1) cout << "Tinh trang    : Da giao!"<<endl<<endl;;find=true;}temp=temp->next;
    			}
			if(!find) cout << "Khong tim thay buu kien co TRANG THAI : Dang Giao!"<<endl;}
			break;
	}
}

void ChinhSua(LIST &l,int x){
	NODE temp=l.head;LISTDISTANCE ld;
	while(temp!=NULL && temp->data.code!=x){
		temp=temp->next;
	}
	if(temp==NULL) cout << "Khong tim thay ma buu kien can sua!"<<endl;
	else{
		int luaChon;
        cout << "Chon thong tin can chinh sua:" << endl;
        cout << "1. Ten hang" << endl;
        cout << "2. Nguoi gui" << endl;
        cout << "3. Nguoi nhan" << endl;
        cout << "4. Dia chi giao hang" << endl;
        cout << "5. Khoi luong" << endl;
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        cin.ignore(); 
        switch(luaChon){
            case 1:
                cout << "Nhap ten hang moi: ";
                getline(cin, temp->data.item);
                break;
            case 2:
                cout << "Nhap ten nguoi gui moi: ";
                getline(cin, temp->data.sender);
                break;
            case 3:
                cout << "Nhap ten nguoi nhan moi: ";
                getline(cin, temp->data.receiver);
                break;
            case 4:
                temp->data.address = Address(temp->data);
                break;
            case 5:
                cout << "Nhap khoi luong moi: ";
                cin >> temp->data.mass;
                temp->data.price = (temp->data.mass * 250)+temp->data.dongia;
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
        }
       
		 cout << "Cap Nhat Thanh Cong!" << endl;
}

}
void ThayDoi(LIST &l,int xy){
	BK x;
	NODE temp=l.head;
	while(temp!=NULL && temp->data.code!=xy) temp = temp->next;
	if(temp == NULL ) cout << "Khong tim thay ma buu kien can thay doi!"<<endl;
	else{ 
		
		int thay;
		cout << "-----------Lua chon-----------"<<endl;
		cout << "         0.Dang Giao!"<<endl;
		cout << "         1.Da Giao!"<<endl;
		cout << "Nhap lua chon : ";cin>>thay;
		switch(thay){
			case 0:temp->data.status=0;cout<<"Cap Nhat Thanh Cong!"<<endl;break;
			case 1:temp->data.status=1;cout<<"Cap Nhat Thanh Cong!"<<endl;break;
			default:cout<<"Vui long nhap 0 hoac 1!"<<endl;break;
		}
}
}

void TimKiem(LIST &l){
	NODE temp = l.head;NODE tempp = l.head;NODE temppp=l.head;int demHC=0,demLC=0,demTK=0,demCL=0,demST=0,demNHS=0,demHV=0,demHS=0,option;string address;
	while(temp!=NULL){
		if     (temp->data.address=="Hai Chau") demHC++;
		else if(temp->data.address=="Lien Chieu") demLC++;
		else if(temp->data.address=="Thanh Khe") demTK++;
		else if(temp->data.address=="Cam Le") demCL++;
		else if(temp->data.address=="Son Tra") demST++;
		else if(temp->data.address=="Ngu Hanh Son") demNHS++;
		else if(temp->data.address=="Hoa Vang") demHV++;
		else if(temp->data.address=="Hoang Sa") demHS++;
		temp=temp->next;
	}
		cout << "Danh sach cac buu kien o cac QUAN , HUYEN : "<<endl;
		cout << "1. Hai Chau     : " << demHC << " buu kien"<<endl<<endl;
		cout << "2. Lien Chieu   : " << demLC << " buu kien"<<endl<<endl;
		cout << "3. Thanh Khe    : " << demTK << " buu kien"<<endl<<endl;
		cout << "4. Cam Le       : " << demCL << " buu kien"<<endl<<endl;
		cout << "5. Son Tra      : " << demST << " buu kien"<<endl<<endl;
		cout << "6. Ngu Hanh Son : " << demNHS << " buu kien"<<endl<<endl;
		cout << "7. Hoa Vang     : " << demHV << " buu kien"<<endl<<endl;
		cout << "8. Hoang Sa     : " << demHS << " buu kien"<<endl<<endl;
		bool check =false;
		while(!check){
		cout <<endl<< "Nhap STT de xem chi tiet cac don hang : ";cin>>option;
		switch(option){
		case 1: address="Hai Chau";check=true;break;
		case 2: address="Lien Chieu";check=true;break;
		case 3: address="Thanh Khe";check=true;break;
		case 4: address="Cam Le";check=true;break;
		case 5: address="Son Tra";check=true;break;
		case 6: address="Ngu Hanh Son";check=true;break;
		case 7: address="Hoa Vang";check=true;break;
		case 8: address="Hoang Sa";check=true;break;
		default:cout<<"Vui long nhap dung STT!"<<endl;
		}
	}
	if((option==1 && demHC==0) || (option==2 && demLC==0) || (option==3 && demTK==0) || (option==4 && demCL==0) || (option==5 && demST==0) || (option==6 && demNHS==0) || (option==7 && demHV==0) || (option==8 && demHS==0))
	cout << "Khong co buu kien nao o khu vuc nay!!"<<endl<<endl;
	else{
		while(tempp!=NULL){
			if(tempp->data.address==address)
			{
			
			cout <<endl<< "       		Thong tin don hang:  "<<endl;
			cout << "Ma buu kien   : " << tempp->data.code <<endl;
			cout << "Ten hang      : " << tempp->data.item<<endl;
			cout << "Ten nguoi gui : " << tempp->data.sender<<endl;
			cout << "SDT           : " << tempp->data.sdts<<endl;
			cout << "Ten nguoi nhan: " << tempp->data.receiver<<endl;cout << "SDT           : "<< tempp->data.sdtr<<endl;
			cout << "Dia diem giao : " << tempp->data.address<<endl;
			cout << "Thanh tien    : " << tempp->data.price<<" VND"<<endl;
			cout << "Khoi luong    : " <<tempp->data.mass<<" kg"<<endl;
			cout << "Ngay gui      : " << setw(2)<<setfill('0')	<<tempp->data.time.day<<"/"<< setw(2)<<setfill('0')<<tempp->data.time.month<<"/"<<tempp->data.time.year<< endl;
			cout << "Shipper       : " << tempp->data.shipperr<<endl;
			if(tempp->data.status == 0) cout << "Tinh trang    : Dang giao!"<<endl;
			else if(tempp->data.status == 1) cout << "Tinh trang    : Da giao!"<<endl<<endl;
			
		}
		tempp=tempp->next;
}
}
}


void OPTION(){
	LIST l;InitListBK(l);
	LISTDISTANCE ld;InitListDistance(ld);
	int option;ifstream filein;filein.open("danhsachbuukien.txt",ios::in);Doc_File(filein,l,ld);
	while(1){
		char cont = _getch();
    	system("cls");
		out();
		cin >> option;
		system("cls");
		switch(option){
			case 1:
//				cout << "------- Nhap thong tin buu kien -------" <<endl;
//				Nhap(l,ld);
				if(!filein.is_open()) cout << "Ko the mo tep!";
				else cout << "Doc thanh cong!";
				
				
				break;
			case 2:
				if(CHECK(l)==true){
				
				Display(l);
				int find;cout<<"Nhap ma buu kien can xoa : ";cin>>find;
				DeleteSelect(l,find);}
				break;
			case 3:
				int option3;
				cout << "--------------- Lua chon ------------"<<endl;
				cout << "     1 Xem toan bo danh sach. "<<endl;
				cout << "     2 Xem buu kien theo phan loai."<<endl;
				cout << "Nhap lua chon : ";cin>>option3;
				if(option3 == 1) Display(l);
				else if(option3==2){
				int option33;
				cout << "---------------- Lua chon ---------------------" <<endl;
				cout << "     1 Phan loai theo TINH TRANG: Da giao!"  << endl;
				cout << "     2 Phan loai theo TINH TRANG: Dang giao!"  << endl;
				cout << "-----------------------------------------------"<<endl;
				cout << "Nhap lua chon : ";cin>>option33;
				if(CHECK(l)==true) {
					
						
				PhanLoai(l,option33);}
				}
				break;
			case 4:
//				int option4;
//				if(CHECK(l)){
//				
//				cout<<  "Nhap ma buu kien can tim : ";cin>>option4;
//				
//				TimKiem(l,option4);}
				if(CHECK(l)==true){
					TimKiem(l);
				}
				break;
			case 5:
				if(CHECK(l)==true){
				
				Display(l);
				cout << "Nhap ma buu kien can chinh sua : ";int x;cin>>x;
				ChinhSua(l,x);}
				break;
			case 6:
				if(CHECK(l)==true) {
				
				Display(l);
				int xy;cout <<"Nhap ma buu kien can thay doi trang thai : ";cin>>xy;
				ThayDoi(l,xy);}
			
				break;
			case 7:
				if(l.head == NULL) cout << "DANH SACH CON TRONG!" <<endl;
				else {
				Save(l);
				cout << "Luu Thanh Cong!"<<endl;}
				break;
			
      		case 0:
      			exit(0);
			
			
				}
}
}









int main(){
	system("color 3");
	OPTION();
}

