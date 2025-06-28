#include<iostream>
#include<string>
using namespace std;

class laptop {
	private:
		string name;
		float price;
		string processor;
	
	public:
			laptop(string n, float p , string pro)
			{
				name = n;
				price = p;
				processor = pro;
			}

void displayinfo(){
	cout<< "laptop name: "<< name << endl;
	cout<<" price:"<< price << endl;
	cout<<"	processor:"<<processor << endl;
    }

};
int main()
{
	laptop mylaptop ("asus vivobook 16x",60000,"intel i5");
	 mylaptop.displayinfo();
}
/*
output:
laptop name: asus vivobook 16x
 price:60,000
processor:intel i5*/