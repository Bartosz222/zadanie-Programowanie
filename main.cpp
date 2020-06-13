#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


class telefon{
	public:
		string aparat;
		string pamiec_wew;
};
class laptop{
	public:
		string dysk;
		string karta_graf;
};
class device:public telefon ,public laptop{
	
	public:
		vector <class device> Obiekty;
		string nazwa;
		string ram;
		string procesor;
	
};
class program:public device{
	public:
		program();
		~program();
		ifstream laptop;
		ifstream telefon;
		ofstream wyjscieJSON;
		ofstream wyjscie;
		void sprawdzPlik();
		void Menu();
		void wMenu(int wybor);
		void wczytaj();
		void wczytajTelefon();
		void wczytajLaptop();
		void wyszukaj();
		void dodaj();
		void dodajTelefon();
		void dodajLaptop();
		void zapis();
		void zapisJSON();
};
program::program(){
	laptop.open("laptop.txt");
	telefon.open("telefon.txt");
	wyjscie.open("wyjscie.txt");
	wyjscieJSON.open("wyjscieJSON.txt");
	wyjscieJSON<<"["<<endl;
}
program::~program(){
	wyjscieJSON<<"];"<<endl;
	laptop.close();
	telefon.close();
	wyjscie.close();
	wyjscieJSON.close();
}
void program::sprawdzPlik(){
	if(laptop.good()&&telefon.good()&&wyjscie.good()){}
	else {
		cout<<"Blad podczas sprawdzania plikow!!!!"<<endl;
		exit(0);
	}
}
void program::Menu(){
	int wybor;
	cout<<"1.Wczytaj"<<endl;
	cout<<"2.Wyszukaj"<<endl;
	cout<<"3.Dodaj"<<endl;
	cout<<"4.Zapisz"<<endl;
	cout<<"5.WypiszJSON"<<endl;
	cout<<"0.Koniec"<<endl;
	cout<<"Twoj wybor: ";
	cin>>wybor;
	system("cls");
	wMenu(wybor);
}
void program::wMenu(int wybor){
	switch(wybor){
		case 1:
			wczytaj();
			
		break;
		case 2:
			wyszukaj();
			
		break;
		case 3:
			dodaj();
			
		break;
		case 4:
			zapis();
			
		break;
		case 5:
			zapisJSON();
			
		break;
		case 0:
			exit(0);
			
		break;
		default:
			system("cls");
			cout<<"Nie ma takiej opcji !!!!!"<<endl;
			system("Pause");
			system("cls");
			Menu();
		break;
		
	}
}
void program::wczytaj(){
	int wybor;
	cout<<"Ktore urzadzenie chcesz wczytac ?"<<endl;
	cout<<"1.Telefon"<<endl;
	cout<<"2.Laptop"<<endl;
	cout<<"0.Powrot"<<endl;
	cout<<"Twoj wybor: ";
	cin>>wybor;
	system("cls");
	switch(wybor){
		case 1:
			wczytajTelefon();
			system("Pause");
			system("cls");
			Menu();
			break;
		case 2:
			wczytajLaptop();
			system("Pause");
			system("cls");
			Menu();
		break;	
		case 0:
			system("cls");
			Menu();
		break;
		default:
			system("cls");
			cout<<"Nie ma takiej opcji !!!!!"<<endl;
			system("Pause");
			system("cls");
			wczytaj();
		break;
	}
}
void program::wczytajTelefon(){
	class device wprowadzenie;
	cout<<"Wprowadzono"<<endl;
		while(!telefon.eof()){
			getline(telefon,wprowadzenie.nazwa);
			getline(telefon,wprowadzenie.ram);
			getline(telefon,wprowadzenie.procesor);
			getline(telefon,wprowadzenie.aparat);
			getline(telefon,wprowadzenie.pamiec_wew);
			cout<<"Nazwa: "<<wprowadzenie.nazwa<<endl;
			cout<<"Ram: "<<wprowadzenie.ram<<endl;
			cout<<"Procesor: "<<wprowadzenie.procesor<<endl;
			cout<<"Aparat: "<<wprowadzenie.aparat<<endl;
			cout<<"Pamiec Wewnetrzna: "<<wprowadzenie.pamiec_wew<<endl;
			cout<<"--------------"<<endl;
			Obiekty.push_back(wprowadzenie);
		}
		
}
void program::wczytajLaptop(){
	class device wprowadzenie;
	cout<<"Wprowadzono"<<endl;
		while(!laptop.eof()){
			getline(laptop,wprowadzenie.nazwa);
			getline(laptop,wprowadzenie.ram);
			getline(laptop,wprowadzenie.procesor);
			getline(laptop,wprowadzenie.dysk);
			getline(laptop,wprowadzenie.karta_graf);
			cout<<"Nazwa: "<<wprowadzenie.nazwa<<endl;
			cout<<"Ram: "<<wprowadzenie.ram<<endl;
			cout<<"Procesor: "<<wprowadzenie.procesor<<endl;
			cout<<"Dysk: "<<wprowadzenie.dysk<<endl;
			cout<<"Karta Graficzna: "<<wprowadzenie.karta_graf<<endl;
			cout<<"--------------"<<endl;
			Obiekty.push_back(wprowadzenie);
		}
}
void program::wyszukaj(){
	if(Obiekty.empty() == true){
		cout<<"Wektor jest Pusty dodaj dane lub wczytaj z pliku"<<endl;
		system("Pause");
		system("cls");
		Menu();
	}
	else{	
		string nazwaWyszukiwana;
		int dlugosc = Obiekty.size();
		cout<<"Podaj nazwe: ";
		cin>>nazwaWyszukiwana;
		system("cls");
		for(int i=0;i<=dlugosc;i++){
			if(Obiekty[i].nazwa == nazwaWyszukiwana){
				cout<<"Nazwa: "<<Obiekty[i].nazwa<<endl;
				cout<<"Ram: "<<Obiekty[i].ram<<endl;
				cout<<"Procesor: "<<Obiekty[i].procesor<<endl;
				if(Obiekty[i].aparat.empty() == true||Obiekty[i].pamiec_wew.empty() == true){
					cout<<"Dysk: "<<Obiekty[i].dysk<<endl;
					cout<<"Karta Graficzna: "<<Obiekty[i].karta_graf<<endl;
					system("Pause");
					system("cls");
					Menu();
				}
				else {
					cout<<"Aparat: "<<Obiekty[i].aparat<<endl;
					cout<<"Pamiec Wewnetrzna: "<<Obiekty[i].pamiec_wew<<endl;
					system("Pause");
					system("cls");
					Menu();
				}
			}
		}		
}	
}
void program::dodaj(){
	int wybor;
	cout<<"Co chcesz dodaæ?"<<endl;
	cout<<"1.Laptop"<<endl;
	cout<<"2.Telefon"<<endl;
	cout<<"0.Powrot"<<endl;
	cout<<"Twoj wybor: ";
	cin>>wybor;
	switch(wybor){
		case 1:
			system("cls");
			dodajLaptop();
			break;
		case 2:
			system("cls");
			dodajTelefon();
			break;
		case 0:
			system("cls");
			Menu();
			break;
		default:
			cout<<"Nie ma takiej opcji!!!"<<endl;
			system("Pause");
			system("cls");
			dodaj();
			break;
	}
}
void program::dodajLaptop(){
	class device wprowadzenie;
	int wybor;
	string lNazwa;
	string lRam;
	string lProcesor;
	string lDysk;
	string lKarta_graf;
	cout<<"Podaj nazwe: ";
	cin>>lNazwa;
	system("cls");
	cout<<"Podaj Ram: ";
	cin>>lRam;
	system("cls");
	cout<<"Podaj Procesor: ";
	cin>>lProcesor;
	system("cls");
	cout<<"Podaj Dysk: ";
	cin>>lDysk;
	system("cls");
	cout<<"Podaj Karte Graficzna: ";
	cin>>lKarta_graf;
	system("cls");
	cout<<"Nazwa: "<<lNazwa<<endl;
	cout<<"Ram: "<<lRam<<endl;
	cout<<"Procesor: "<<lProcesor<<endl;
	cout<<"Dysk: "<<lDysk<<endl;
	cout<<"Karta Graficzna: "<<lKarta_graf<<endl;
	cout<<"Czy chcesz to dodac ?"<<endl;
	cout<<"1.Tak"<<endl;
	cout<<"2.Nie"<<endl;
	cout<<"Twoj wybor: ";
	cin>>wybor;
	switch(wybor){
		case 1:
			wprowadzenie.nazwa = lNazwa;
			wprowadzenie.ram = lRam;
			wprowadzenie.procesor = lProcesor;
			wprowadzenie.dysk = lDysk;
			wprowadzenie.karta_graf = lKarta_graf;
			Obiekty.push_back(wprowadzenie);
			cout<<"Dodano!"<<endl;
			system("Pause");
			system("cls");
			Menu();
			break;
		case 2:
			system("cls");
			Menu();
			break;
		default:
			cout<<"Nie ma takiej opcji !!!!";
			system("Pause");
			system("cls");
			dodaj();
			break;
	}
	
}
void program::dodajTelefon(){
	class device wprowadzenie;
	int wybor;
	string lNazwa;
	string lRam;
	string lProcesor;
	string lAparat;
	string lPamiec;
	cout<<"Podaj nazwe: ";
	cin>>lNazwa;
	system("cls");
	cout<<"Podaj Ram: ";
	cin>>lRam;
	system("cls");
	cout<<"Podaj Procesor: ";
	cin>>lProcesor;
	system("cls");
	cout<<"Podaj Aparat: ";
	cin>>lAparat;
	system("cls");
	cout<<"Podaj Pamiec: ";
	cin>>lPamiec;
	system("cls");
	cout<<"Nazwa: "<<lNazwa<<endl;
	cout<<"Ram: "<<lRam<<endl;
	cout<<"Procesor: "<<lProcesor<<endl;
	cout<<"Aparat: "<<lAparat<<endl;
	cout<<"Pamiec: "<<lPamiec<<endl;
	cout<<"Czy chcesz to dodac ?"<<endl;
	cout<<"1.Tak"<<endl;
	cout<<"2.Nie"<<endl;
	cout<<"Twoj wybor: ";
	cin>>wybor;
	switch(wybor){
		case 1:
			wprowadzenie.nazwa = lNazwa;
			wprowadzenie.ram = lRam;
			wprowadzenie.procesor = lProcesor;
			wprowadzenie.aparat = lAparat;
			wprowadzenie.pamiec_wew = lPamiec;
			Obiekty.push_back(wprowadzenie);
			cout<<"Dodano!"<<endl;
			system("Pause");
			system("cls");
			Menu();
			break;
		case 2:
			system("cls");
			Menu();
			break;
		default:
			cout<<"Nie ma takiej opcji !!!!";
			system("Pause");
			system("cls");
			dodaj();
			break;
	}
}
void program::zapis(){
	if(Obiekty.empty() == true){
		cout<<"Wektor jest Pusty dodaj dane lub wczytaj z pliku"<<endl;
		
	}
	else {
	int dlugosc = Obiekty.size();
	int i = 0;
	while(i != dlugosc){
		wyjscie<<Obiekty[i].nazwa<<endl;
		wyjscie<<Obiekty[i].ram<<endl;
		wyjscie<<Obiekty[i].procesor<<endl;
		if(Obiekty[i].aparat.empty() == true||Obiekty[i].pamiec_wew.empty() == true){
			wyjscie<<Obiekty[i].dysk<<endl;
			wyjscie<<Obiekty[i].karta_graf<<endl;
		}
		else {
			wyjscie<<Obiekty[i].aparat<<endl;
			wyjscie<<Obiekty[i].pamiec_wew<<endl;
		}
		wyjscie<<"_____________________________________"<<endl;
		i++;
	}
	cout<<"Zapisano"<<endl;
	}
	system("Pause");
	system("cls");
	Menu();
}
void program::zapisJSON(){
	if(Obiekty.empty() == true){
		cout<<"Wektor jest Pusty dodaj dane lub wczytaj z pliku"<<endl;
		
	}
	else {
	int dlugosc = Obiekty.size();
	int i = 0;
	while(i != dlugosc){
		if(Obiekty[i].aparat.empty() == true||Obiekty[i].pamiec_wew.empty() == true){
			wyjscieJSON<<"{\"Nazwa\": \""+Obiekty[i].nazwa+"\", \"Ram\": \""+Obiekty[i].ram+"\", \"Procesor\": \""+Obiekty[i].procesor+"\", \"Dysk\": \""+Obiekty[i].dysk+"\", \"Karta Graficzna\": \""+Obiekty[i].karta_graf+"\"},"<<endl;
		}
		else{
			wyjscieJSON<<"{\"Nazwa\": \""+Obiekty[i].nazwa+"\", \"Ram\": \""+Obiekty[i].ram+"\", \"Procesor\": \""+Obiekty[i].procesor+"\", \"Aparat\": \""+Obiekty[i].aparat+"\", \"Pamiêæ Wewnêtrzna\": \""+Obiekty[i].pamiec_wew+"\"},"<<endl;
		}
		i++;
	}
	cout<<"Zapisano"<<endl;
	}
	system("Pause");
	system("cls");
	Menu();
}
int main() {
	program p1;
	p1.sprawdzPlik();
	p1.Menu();
	return 0;
}
