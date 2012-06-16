#include<iostream>
using namespace std;

class Compare
{
public:
    static bool compare(string a ,string b){
		int w=a.length();
		int i=0;
		while(i<w)
		if(a[i]==b[i]||(a[i]+32)==b[i]||(b[i]+32)==a[i])
			i++;
		else
			return false;
		return true;
    }
};