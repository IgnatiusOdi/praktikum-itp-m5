#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int randomCard(string &draw)
{
	int acak=rand()%13+2;
	
	if(acak==2)
		draw=" mendapatkan kartu 2!\n";
	else if(acak==3)
		draw=" mendapatkan kartu 3!\n";
	else if(acak==4)
		draw=" mendapatkan kartu 4!\n";
	else if(acak==5)
		draw=" mendapatkan kartu 5!\n";
	else if(acak==6)
		draw=" mendapatkan kartu 6!\n";
	else if(acak==7)
		draw=" mendapatkan kartu 7!\n";
	else if(acak==8)
		draw=" mendapatkan kartu 8!\n";
	else if(acak==9)
		draw=" mendapatkan kartu 9!\n";
	else if(acak==10)
		draw=" mendapatkan kartu 10!\n";
	else if(acak==11)
		draw=" mendapatkan kartu J!\n";
	else if(acak==12)
		draw=" mendapatkan kartu Q!\n";
	else if(acak==13)
		draw=" mendapatkan kartu K!\n";
	else if(acak==14)
		draw=" mendapatkan kartu As!\n";
	
	if(acak==11||acak==12||acak==13)
		acak=10;
	else if(acak==14)
		acak=11;
	
	return acak;
}

void deck(int cardP1,int cardP2,int cardC1,int cardC2,bool gg)
{
	for(int b=1;b<=5;b++)
	{
		for(int k=1;k<=5;k++)
		{
			if(b==1||k==1||b==5||k==5)
				cout<<"# ";
			else if(cardC1>9)
			{
				if(b==3&&k==2)
					cout<<cardC1/10<<" ";
				else if(b==3&&k==3)
					cout<<cardC1%10<<" ";
				else
					cout<<"  ";
			}
			else if(cardC1<=9)
			{
				if(b==3&&k==3)
					cout<<cardC1<<" ";
				else
					cout<<"  ";
			}
			else
				cout<<"  ";
		}
		
		cout<<" ";
		
		for(int k=1;k<=5;k++)
		{
			if(b==1||k==1||b==5||k==5)
				cout<<"# ";
			else if(b==3 &&k==3)
				cout<<"? ";
			else
				cout<<"  ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"                 COM"<<endl;
	cout<<"--------------------"<<endl;
	cout<<"PLAYER"<<endl;
	cout<<endl;
	for(int b=1;b<=5;b++)
	{
		for(int k=1;k<=5;k++)
		{
			if(b==1||k==1||b==5||k==5)
				cout<<"# ";
			else if(cardP1>9)
			{
				if(b==3&&k==2)
					cout<<cardP1/10<<" ";
				else if(b==3&&k==3)
					cout<<cardP1%10<<" ";
				else
					cout<<"  ";
			}
			else if(cardP1<=9)
			{
				if(b==3&&k==3)
					cout<<cardP1<<" ";
				else
					cout<<"  ";
			}
			else
				cout<<"  ";
		}
		cout<<" ";
		for(int k=1;k<=5;k++)
		{
			if(b==1||k==1||b==5||k==5)
				cout<<"# ";
			else if(cardP2>9)
			{
				if(b==3&&k==2)
					cout<<cardP2/10<<" ";
				else if(b==3&&k==3)
					cout<<cardP2%10<<" ";
				else
					cout<<"  ";
			}
			else if(cardP2<=9)
			{
				if(b==3&&k==3)
					cout<<cardP2<<" ";
				else
					cout<<"  ";
			}
			else
				cout<<"  ";
		}
		cout<<endl;
	}
}

void checkCard(int cardP1,int cardP2,int cardC1,int cardC2,bool &player,bool &com,bool &gg)
{
	if(cardP1+cardP2==21 && cardC1+cardC2==21)
	{
		cout<<"Player Draw dengan COM"<<endl;
		cout<<cardP1+cardP2<<":"<<cardC1+cardC2<<endl;
		player=false;
		com=false;
		gg=true;
	}
	else if(cardP1+cardP2==21)
	{
		cout<<"COM Kalah dengan jumlah kartu "<<cardC1+cardC2<<endl;
		cout<<"Pemenangnya adalah Player dengan jumlah kartu "<<cardP1+cardP2<<endl;
		player=false;
		com=false;
		gg=true;
	}
	else if(cardC1+cardC2==21)
	{
		cout<<"Player Kalah dengan jumlah kartu "<<cardP1+cardP2<<endl;
		cout<<"Pemenangnya adalah COM dengan jumlah kartu "<<cardC1+cardC2<<endl;
		player=false;
		com=false;
		gg=true;
	}
	else if(cardP1+cardP2>21 && cardC1+cardC2>21)
	{
		if(cardP1+cardP2==cardC1+cardC2)
		{
			cout<<"Player Draw dengan COM"<<endl;
			cout<<cardP1+cardP2<<":"<<cardC1+cardC2<<endl;
			player=false;
			com=false;
			gg=true;
		}
	}
	else if(cardP1+cardP2>21)
	{
		cout<<"Player Kalah dengan jumlah kartu "<<cardP1+cardP2<<endl;
		cout<<"Pemenangnya adalah COM dengan jumlah kartu "<<cardC1+cardC2<<endl;
		player=false;
		com=false;
		gg=true;
	}
	else if(cardC1+cardC2>21)
	{
		cout<<"COM Kalah dengan jumlah kartu "<<cardC1+cardC2<<endl;
		cout<<"Pemenangnya adalah Player dengan jumlah kartu "<<cardP1+cardP2<<endl;
		player=false;
		com=false;
		gg=true;
	}
}

void Menu()
{
	cout<<"Turn : Player"<<endl;
	cout<<"1. Hit"<<endl;
	cout<<"2. Surrend"<<endl;
	cout<<">>> ";
}

void Menu2P(int cardP1,int cardP2,int cardC1,int cardC2,bool &player,bool &com,bool &gg)
{
	cout<<"Player Menyerah dengan jumlah kartu "<<cardP1+cardP2<<endl;
	cout<<"Pemenangnya adalah COM dengan jumlah kartu "<<cardC1+cardC2<<endl;
	player=false;
	com=false;
	gg=true;
}

void Menu2C(int cardP1,int cardP2,int cardC1,int cardC2,bool &player,bool &com,bool &gg)
{
	cout<<"COM Menyerah dengan jumlah kartu "<<cardC1+cardC2<<endl;
	cout<<"Pemenangnya adalah Player dengan jumlah kartu "<<cardP1+cardP2<<endl;
	player=false;
	com=false;
	gg=true;
}

void Menu69(int cardP1,int cardP2,int cardC1,int cardC2)
{
	cout<<"Player is a Cheater"<<endl;
	cout<<"Kartu Kanan Com     : "<<cardC1<<endl;
	cout<<"Kartu Kiri Com      : "<<cardC2<<endl;
	cout<<"Jumlah Kartu Com    : "<<cardC1+cardC2<<endl;
	cout<<"Kartu Kanan Player  : "<<cardP1<<endl;
	cout<<"Kartu Kiri Player   : "<<cardP2<<endl;
	cout<<"Jumlah Kartu Player : "<<cardP1+cardP2<<endl;
}

void Menu99(int cardC2)
{
	cout<<"Player is a Cheater"<<endl;
	cout<<"Kartu Kiri Com : "<<cardC2<<endl;
}

int main()
{
	srand(time(0));
	
	bool gg=false,player=true,com=false;
	int menu;
	
	int acak;
	string draw;
	
	int cardP1 = randomCard(draw);
	int cardP2 = randomCard(draw);
	int cardC1 = randomCard(draw);
	int cardC2 = randomCard(draw);
	
	do
	{
		gg=false;
		system("cls");
		deck(cardP1,cardP2,cardC1,cardC2,gg);
		checkCard(cardP1,cardP2,cardC1,cardC2,player,com,gg);
		
		while(player)
		{
			system("cls");
			deck(cardP1,cardP2,cardC1,cardC2,gg);
			menu=0;
			
			Menu();
			cin>>menu;
			if(menu==1)
			{
				acak=randomCard(draw);
				cardP1+=acak;
				cout<<"Player"<<draw;
				player=false;
				com=true;
				checkCard(cardP1,cardP2,cardC1,cardC2,player,com,gg);
			}
			else if(menu==2)
			{
				Menu2P(cardP1,cardP2,cardC1,cardC2,player,com,gg);
			}
			else if(menu==69)
			{
				Menu69(cardC1,cardC2,cardP1,cardP2);
			}
			else if(menu==99)
			{
				Menu99(cardC2);
			}
			else
				cout<<"Pilihan tidak ada!";
			
			system("pause");
		}
		
		while(com)
		{
			system("cls");
			deck(cardP1,cardP2,cardC1,cardC2,gg);
			menu=0;
			
			cout<<"Turn : COM"<<endl;
			menu=rand()%2+1;
			
			if(menu==1)
			{
				cout<<"COM memilih Hit!"<<endl;
				acak=randomCard(draw);
				cardC2+=acak;
				cout<<"COM"<<draw;
				player=true;
				com=false;
				checkCard(cardP1,cardP2,cardC1,cardC2,player,com,gg);
			}
			else if(menu==2)
			{
				Menu2C(cardP1,cardP2,cardC1,cardC2,player,com,gg);
			}
			
			system("pause");
		}
		
	}while(!gg);
	
	return 0;
}
