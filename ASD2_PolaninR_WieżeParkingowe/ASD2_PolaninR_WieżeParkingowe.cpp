#include<iostream>

using namespace std;

class Parking
{
public:
	long sizeWys_;
	long sizeDlug_;
	//tablica parking
	long **tabpark_;
	long z_;
	long y_;

	Parking()
	{
		z_ = 0;
		y_ = 0;
		sizeWys_ = 0;
		sizeDlug_ = 0;
		tabpark_ = 0;
	}
	~Parking()
	{
		for (int i = 0; i < sizeWys_; i++)
		{
			delete[] tabpark_[i];
		}

		delete[] tabpark_;
	}
	void AddTab(long _indexi,long _indexj, long _numer)
	{
		tabpark_[_indexi][_indexj] = _numer;
	}
	void SetSize(long _sizeWys, long _sizeDlug)
	{
		sizeWys_=_sizeWys;
		sizeDlug_=_sizeDlug;
	}
	void CreateTable()
	{
		if (tabpark_)
		{
			/*for (int i = 0; i < sizeWys_; i++)
			{
				delete[] tabpark_[i];
			}*/
			delete[] tabpark_;
			//cout << "break" << endl;
		}

		tabpark_ = new long*[sizeWys_];
		for (int i = 0; i < sizeWys_; i++)
		{
			tabpark_[i] = new long[sizeDlug_];
		}

	}
	void PrintParking()
	{
		for (long i = 0; i < sizeWys_; i++)
		{
			for (long j = 0; j < sizeDlug_; j++)
			{
				cout << tabpark_[i][j]<<" ";
			}
			cout << endl;
		}
	}
	void ParkOut()
	{
		long *tabpom = new long[sizeDlug_];
		long windaY = 0;
		long windaX = 0;
		long pom = 0;
		long czas = 0;
		long czas1 = 0;
		long czas2 = 0;


		long max = MaxElemTab();
		for (long x = 1; x < max+1; x++)
		{
			Szukaj(x);
			//poziomo
			{
				czas1 = 5 * (y_ - windaY);
				czas2 = 5 * (sizeDlug_ - y_);
				if (czas1 >= czas2)
				{
					czas += czas2;
				}
				else
				{
					czas += czas1;
				}
				czas1 = 0;
				czas2 = 0;
			}
			//pionowo
			{
				czas += 2 * 10*z_;
			}
			pom= sizeDlug_-y_;
			//cout <<"y= "<< y_ <<"z= "<<z_<< endl;
			//cout << "czas = " << czas << endl;
			for (long i = 0; i < pom; i++)
			{
				tabpom[i] = tabpark_[z_][y_];
				y_++;
			}
			y_ = 0;
			for (long i = pom; i < sizeDlug_; i++)
			{
				tabpom[i] = tabpark_[z_][y_];
				y_++;
			}
			
			for (long i = 0; i < sizeDlug_; i++)
			{
				tabpark_[z_][i]=tabpom[i];
			}
		}
		
		cout << czas << endl;
		delete[] tabpom;
	}
	void Szukaj(long _x)
	{
		long szuk = _x;

		for (long i = 0; i < sizeWys_; i++)
		{
			for (long j = 0; j < sizeDlug_; j++)
			{
				if (tabpark_[i][j]==szuk)
				{
					szuk = tabpark_[i][j];
					z_ = i;
					y_ = j;
				}
			}
		}
	}
	long MaxElemTab()
	{
		long max = 0;
		
		for (long i = 0; i < sizeWys_; i++)
		{
			for (long j = 0; j < sizeDlug_; j++)
			{
				if (tabpark_[i][j]>max)
				{
					max = tabpark_[i][j];
				}
			}
		}
		return max;
	}
	
	
		
	
};




int main()
{
	Parking parking;
	long lPrzypTestowych = 0;
	//h
	long lWysokosc = 0;
	//l
	long lDlugosc = 0;
	
	cin >> lPrzypTestowych;
	// lPrzypTestowych = 1;
	for (int x = 0; x < lPrzypTestowych; x++)
	{
		long pom = 0;
		cin >> lWysokosc;
		cin >> lDlugosc;
		//cout << lWysokosc << " " << lDlugosc << endl;
		parking.SetSize(lWysokosc, lDlugosc);
		//cout << "size" << endl;
		parking.CreateTable();
		//cout << "create"<<endl;

		for (long i = 0; i < lWysokosc; i++)
		{
			for (long j = 0; j < lDlugosc; j++)
			{
				cin >> pom;
				parking.AddTab(i, j, pom);
			}
		}
		//parking.PrintParking();
		parking.ParkOut();
		//cout << endl << endl;
		//parking.PrintParking();
	}
	


	return 0;
}