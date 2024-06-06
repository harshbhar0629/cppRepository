#include<iostream>
using namespace std;

int main(int argc, char* argv[]){
	std::cout<<"Hello world!\n";
	//std::cout<<sizeof argv<<" : ";
	std::cout<<argc<<" ";
	try
	{
		argv[2] ? cout<<argv[2]<<" " : throw"Error";
	}catch(...){
		cout<<"Error aya h:";
	}

	std::cout<<argv[0]<<" "<<argv[1]<<" "<<"\n";
	return 0;
}
