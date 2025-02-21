#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int randomX()
{
	int x=rand()%13+2;
	return x;
}

int randomY()
{
	int y=rand()%5+2;
	return y;
}

void map1(int xp,int yp,int x1,int y1,int x2,int y2,int x3,int y3)
{
	for(int y=1;y<=7;y++)
	{
		for(int x=1;x<=15;x++)
		{
			if(x==xp && y==yp)
				cout<<"P ";
			else if( (x==x1 && y==y1) || (x==x2 && y==y2) || (x==x3 && y==y3))
				cout<<"X ";
			else if((y==1||y==7)&&(x==1||x==15))
				cout<<"+ ";
			else if((y==1&&x>1&&x<15) || (y==7&&((x>1&&x<7)||(x>9&&x<15))))
				cout<<"- ";
			else if((x==1||x==15)&&(y>1&&y<15))
				cout<<"| ";
			else if(y==2 && x==2)
				cout<<"# ";
			else
				cout<<"  ";
		}
		cout<<endl<<endl;
	}
}

void map2(int xp,int yp,int x1,int y1,int x2,int y2,int x3,int y3)
{
	for(int y=1;y<=7;y++)
	{
		for(int x=1;x<=15;x++)
		{
			if( (x==x1 && y==y1) || (x==x2 && y==y2) || (x==x3 && y==y3))
				cout<<"X ";
			else if(x==xp && y==yp)
				cout<<"P ";
			else if((y==1||y==7)&&(x==1||x==15))
				cout<<"+ ";
			else if((y==1||y==7)&&x>1&&x<15)
				cout<<"- ";
			else if((x==1||x==15)&&(y>1&&y<15))
				cout<<"| ";
			else if(y==2 && x==2)
				cout<<"# ";
			else
				cout<<"  ";
		}
		cout<<endl<<endl;
	}
}

void status(int dungeon,int gold,int xp,int yp,int x1,int y1,int x2,int y2,int x3,int y3)
{
	cout<<"Dungeon : "<<dungeon<<endl;
	cout<<"Stamina : 100/100"<<endl;
	cout<<"Gold    : "<<gold<<"G"<<endl;
	if(dungeon==1)
		map1(xp,yp,x1,y1,x2,y2,x3,y3);
	else
		map2(xp,yp,x1,y1,x2,y2,x3,y3);
}

void mainmenu()
{
	cout<<"MENU UTAMA"<<endl;
	cout<<"------------------------"<<endl;
	cout<<"1. Movement"<<endl;
	cout<<"2. Bag"<<endl;
	cout<<"3. Back To First Dungeon"<<endl;
	cout<<"0. Exit Program"<<endl;
	cout<<">>> ";
}

void movemenu()
{
	cout<<"MENU MOVEMENT"<<endl;
	cout<<"---------------"<<endl;
	cout<<"1. Move Up"<<endl;
	cout<<"2. Move Left"<<endl;
	cout<<"3. Move Down"<<endl;
	cout<<"4. Move Right"<<endl;
	cout<<"5. Mine"<<endl;
	cout<<"0. Back"<<endl;
	cout<<">>> ";
}

void bagmenu(int stone,int mythrill,int crystal)
{
	cout<<"BAG"<<endl;
	cout<<"-----------------"<<endl;
	
	cout<<"Stone     - ";
	if(stone<10) cout<<"   ";
	else if(stone<100) cout<<"  ";
	else if(stone<1000) cout<<" ";
	cout<<stone<<"x"<<endl;
	
	cout<<"Mythrill  - ";
	if(mythrill<10) cout<<"   ";
	else if(mythrill<100) cout<<"  ";
	else if(mythrill<1000) cout<<" ";
	cout<<mythrill<<"x"<<endl;
		
	cout<<"Crystal   - ";
	if(crystal<10) cout<<"   ";
	else if(crystal<100) cout<<"  ";
	else if(crystal<1000) cout<<" ";
	cout<<crystal<<"x"<<endl;
}

void store(int &stone,int &mythrill,int &crystal,int &gold,bool &out)
{
	int menu=-1;
	int jumlah=0;
	cout<<"STORE"<<endl;
	cout<<"---------------------------------"<<endl;
	cout<<"1. Stone"<<endl;
	cout<<"2. Mythrill"<<endl;
	cout<<"3. Crystal"<<endl;
	cout<<"0. Back Mining"<<endl;
	cout<<">>> "; cin>>menu;
	if(menu==1)
	{
		cout<<"Berapa banyak yang ingin dijual?"<<endl;
		cout<<">>> "; cin>>jumlah;
		if(jumlah<=stone)
		{
			cout<<"Berhasil menjual stone sebanyak "<<jumlah<<"."<<endl;
			cout<<"Gold +"<<jumlah*10<<"G"<<endl;
			cout<<"Stone -"<<jumlah<<endl;
				stone -= jumlah;
				gold += jumlah*10;
		}
		else
		{
			cout<<"Gagal menjual, stone anda hanya "<<stone<<"."<<endl;
		}
	}
	else if(menu==2)
	{
		cout<<"Berapa banyak yang ingin dijual?"<<endl;
		cout<<">>> "; cin>>jumlah;
		if(jumlah<=mythrill)
		{
			cout<<"Berhasil menjual mythrill sebanyak "<<jumlah<<"."<<endl;
			cout<<"Gold +"<<jumlah*200<<"G"<<endl;
			cout<<"Mythrill -"<<jumlah<<endl;
				mythrill -= jumlah;
				gold += jumlah*200;
		}
		else
		{
			cout<<"Gagal menjual, mythrill anda hanya "<<mythrill<<"."<<endl;
		}
	}
	else if(menu==3)
	{
		cout<<"Berapa banyak yang ingin dijual?"<<endl;
		cout<<">>> "; cin>>jumlah;
		if(jumlah<=crystal)
		{
			cout<<"Berhasil menjual crystal sebanyak "<<jumlah<<"."<<endl;
			cout<<"Gold +"<<jumlah*500<<"G"<<endl;
			cout<<"Crystal -"<<jumlah<<endl;
				crystal -= jumlah;
				gold += jumlah*500;
		}
		else
		{
			cout<<"Gagal menjual, crystal anda hanya "<<crystal<<"."<<endl;
		}
	}
	else if(menu==0)
	{
		out=true;
	}
	else
	{
		cout<<"Pilihan tidak ada!"<<endl;
	}
	system("pause");
}

void up(int xp,int &yp,int x1,int y1,int x2,int y2,int x3,int y3)
{
	if(yp>2)
	{
		if(xp!=x1 && xp!=x2 && xp!=x3)
			yp--;
		else if( (xp==x1&&(yp>y1+1||yp<y1)) || (xp==x2&&(yp>y2+1||yp<y2)) || (xp==x3&&(yp>y3+1||yp<y3)) )
			yp--;
	}	
}

void left(int &xp,int yp,int x1,int y1,int x2,int y2,int x3,int y3)
{
	if(xp>2)
	{
		if(yp!=y1 && yp!=y2 && yp!=y3)
			xp--;
		else if( ((xp>x1+1||xp<x1)&&yp==y1) || ((xp>x2+1||xp<x2)&&yp==y2) || ((xp>x3+1||xp<x3)&&yp==y3) )
			xp--;
	}
}

void down(int xp,int &yp,int x1,int y1,int x2,int y2,int x3,int y3,int dungeon)
{
	if(dungeon==1 && yp==6 && xp>=7 && xp<=9)
	{
		yp++;
	}
	else if(yp<6)
	{
		if(xp!=x1 && xp!=x2 && xp!=x3)
			yp++;
		else if( (xp==x1&&(yp>y1||yp<y1-1)) || (xp==x2&&(yp>y2||yp<y2-1)) || (xp==x3&&(yp>y3||yp<y3-1)) )
			yp++;
	}
}

void right(int &xp,int yp,int x1,int y1,int x2,int y2,int x3,int y3)
{
	if(xp<14)
	{
		if(yp!=y1 && yp!=y2 && yp!=y3)
			xp++;
		else if( ((xp>x1||xp<x1-1)&&yp==y1) || ((xp>x2||xp<x2-1)&&yp==y2) || ((xp>x3||xp<x3-1)&&yp==y3) )
			xp++;
	}
}

void randomMine(int &stone,int &mythrill,int &crystal)
{
	int jenis=rand()%3+1;
	if(jenis==1)
	{
		stone+=rand()%6+5;
	}
	else if(jenis==2)
	{
		mythrill+=rand()%2+1;
	}
	else if(jenis==3)
	{
		crystal+=rand()%1+1;
	}
}

void randomStone(int xp,int yp,int &x1,int &y1,int &x2,int &y2,int &x3,int &y3)
{
	x1=randomX(),y1=randomY();
	x2=randomX(),y2=randomY();
	x3=randomX(),y3=randomY();
	while( (x1==xp&&y1==yp) || (x1==x2&&y1==y2) || (x1==x3&&y1==y3) || (x1==2&&y1==2) )
	{
		x1 = randomX(),y1 = randomY();
	}
	while( (x2==xp&&y2==yp) || (x2==x1&&y2==y1) || (x2==x3&&y2==y3) || (x2==2&&y2==2) )
	{
		x2=randomX(),y2=randomY();
	}
	while( (x3==xp&&y3==yp) || (x3==x2&&y3==y2) || (x3==x1&&y3==y1) || (x3==2&&y3==2) )
	{
		x3=randomX(),y3=randomY();
	}
}

void mine(int xp,int yp,int &x1,int &y1,int &x2,int &y2,int &x3,int &y3,int &stone,int &mythrill,int &crystal)
{
	if( (xp-1==x1 && yp==y1) || (xp+1==x1 && yp==y1) || (xp==x1 && yp-1==y1) || (xp==x1 && yp+1==y1) )
	{
		randomMine(stone,mythrill,crystal);
		x1=-1,y1=-1;
		/*
		x1=randomX(),y1=randomY();
		while( (x1==xp&&y1==yp) || (x1==x2&&y1==y2) || (x1==x3&&y1==y3) || (x1==2&&y1==2) )
		{
			x1 = randomX(),y1 = randomY();
		}
		*/
	}
	
	if( (xp-1==x2 && yp==y2) || (xp+1==x2 && yp==y2) || (xp==x2 && yp-1==y2) || (xp==x2 && yp+1==y2) )
	{
		randomMine(stone,mythrill,crystal);
		x2=-1,y2=-1;
		/*
		x2=randomX(),y2=randomY();
		while( (x2==xp&&y2==yp) || (x2==x1&&y2==y1) || (x2==x3&&y2==y3) || (x2==2&&y2==2) )
		{
			x2=randomX(),y2=randomY();
		}
		*/
	}
	
	if( (x3-1==xp&&y3==yp) || (x3+1==xp&&y3==yp) || (x3==xp&&y3-1==yp) || (x3==xp&&y3+1==yp) )
	{
		randomMine(stone,mythrill,crystal);
		x3=-1,y3=-1;
		/*
		x3=randomX(),y3=randomY();
		while( (x3==xp&&y3==yp) || (x3==x2&&y3==y2) || (x3==x1&&y3==y1) || (x3==2&&y3==2) )
		{
			x3=randomX(),y3=randomY();
		}
		*/
	}
}

void check(int &xp,int &yp,int &x1,int &y1,int &x2,int &y2,int &x3,int &y3,int &dungeon,bool &back)
{
	if(xp==2 && yp==2)
	{
		dungeon++,xp=8,yp=6;
		randomStone(xp,yp,x1,y1,x2,y2,x3,y3);
		back=true;
	}
}

int main()
{
	srand(time(0));
	int menu;
	
	int dungeon=1,gold=500;
	
	int stone=0,mythrill=0,crystal=0;
	
	int xp=8,yp=6;
	int x1,y1,x2,y2,x3,y3;
	randomStone(xp,yp,x1,y1,x2,y2,x3,y3);
	
	bool exit=false;
	bool back;
	bool out;
	do
	{
		menu=-1;
		back=false;
		system("cls");
		status(dungeon,gold,xp,yp,x1,y1,x2,y2,x3,y3);
		mainmenu(); cin>>menu;
		
		if(menu==1)
		{
			do
			{
				menu=-1;
				system("cls");
				status(dungeon,gold,xp,yp,x1,y1,x2,y2,x3,y3);
				movemenu(); cin>>menu;
				
				if(menu==1)
				{
					up(xp,yp,x1,y1,x2,y2,x3,y3);
					check(xp,yp,x1,y1,x2,y2,x3,y3,dungeon,back);
				}
				
				else if(menu==2)
				{
					left(xp,yp,x1,y1,x2,y2,x3,y3);
					check(xp,yp,x1,y1,x2,y2,x3,y3,dungeon,back);
				}
				
				else if(menu==3)
				{
					down(xp,yp,x1,y1,x2,y2,x3,y3,dungeon);
					if(xp>=7&&xp<=9 && yp==7)
					{
						out=false;
						do
						{
							system("cls");
							store(stone,mythrill,crystal,gold,out);
							randomStone(xp,yp,x1,y1,x2,y2,x3,y3);
						}while(!out);
						xp=8;
						yp=6;
					}
				}
				
				else if(menu==4)
				{
					right(xp,yp,x1,y1,x2,y2,x3,y3);
				}
				
				else if(menu==5)
				{
					mine(xp,yp,x1,y1,x2,y2,x3,y3,stone,mythrill,crystal);
				}
				
				else if(menu==0)
					back=true;
				
				else
				{
					cout<<"Pilihan tidak ada!"<<endl;
					system("pause");
				}
			}while(!back);
		}
		
		else if(menu==2)
		{
			system("cls");
			bagmenu(stone,mythrill,crystal);
			system("pause");
		}
		
		else if(menu==3)
		{
			dungeon=1,xp=8,yp=6;
			randomStone(xp,yp,x1,y1,x2,y2,x3,y3);
			/*if(dungeon>1)
			{
				dungeon=1,xp=8,yp=6;
				randomStone(xp,yp,x1,y1,x2,y2,x3,y3);
			}*/	
		}
		
		else if(menu==0)
		{
			cout<<"Permainan berakhir, Bye Bye~";
			exit=true;
		}
		
		else
		{
			cout<<"Pilihan tidak ada!"<<endl;
			system("pause");
		}
	}while(!exit);
	
	return 0;
}
