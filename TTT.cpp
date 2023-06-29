#include <iostream>
using namespace std;

class Symbol
{
private:
    char symbolX='X';
    char symbolO='O';
public:
    char getX()
    {
        return symbolX;
    }
    char getO()
    {
        return symbolO;
    }
};

class Mapa
{
private:
    char board[3][3]={{'_','_','_'},{'_','_','_'},{'_','_','_'}};
    int ruch=0;
public:
    void wstaw(int x, int y, char znak)
    {
        board[x-1][y-1]=znak;
        ruch++;
    }

    void display()
    {
        system("cls");
        for(int i=0;i<3;i++)
		{
			cout<<"|";
			for(int j=0;j<3;j++)
			{
				cout<<board[i][j]<<"|";
			}
			cout<<endl;
		}
    }

    bool full()
    {
        if(ruch<9)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    bool czyWygrana(char symbol)
    {
        for(int i=0;i<3;i++) //po x
		{   if(board[i][0]==symbol && board[i][1]==symbol && board[i][2]==symbol)
			{   return true;}}
		for(int i=0;i<3;i++) //po y
        {   if(board[0][i]==symbol && board[1][i]==symbol && board[2][i]==symbol)
			{   return true;}}

        if(board[0][0]==symbol && board[1][1]==symbol && board[2][2]==symbol) //na ukos
        {   return true;}

		if(board[1][3]==symbol && board[3][1]==symbol && board[2][2]==symbol)
        {   return true;}

        return false;
    }

    bool czyPusty(int x, int y){
        if(board[x-1][y-1]=='_')
        {
            return true;
        }
        else
        {
           return false;
        }

    }
};

class Koniec
{
public:
    bool czyKoniec(Mapa mapa, Symbol symbol)
    {
        if(mapa.full()==true || mapa.czyWygrana(symbol.getO())==true || mapa.czyWygrana(symbol.getX())==true )
        {
            return true;
        }
    }
};

class Gra
{
private:
    int x,y;
    int licznik;
    Symbol symbol;
    Mapa mapa;
    Koniec fin;

public:
    void cykl()
    {
        licznik=0;
        mapa.display();
        while(fin.czyKoniec(mapa, symbol)!=true)
        {
            cin>>x;
            cin>>y;
            if(mapa.czyPusty(x,y)==1)
            {
                if(licznik%2==0)
                {
                    mapa.wstaw(x,y,symbol.getX());
                }
                else if(licznik%2==1)
                {
                    mapa.wstaw(x,y,symbol.getO());
                }
                licznik++;
            }
            mapa.display();
    }}
};


int main()
{
    Gra gra;
    gra.cykl();
}
