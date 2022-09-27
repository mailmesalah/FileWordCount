
#include <iostream.h>
#include <fstream.h>
#include<string.h>
using namespace std;


int size;
int size2;
int a =0;
int b=0;
int f=0;
int fp=0;
int freq =1;
char * memblock;
char * memblock2;


char *arr;
char *arr2;

char *a1;
char *a2;
char *final;

int i=0;
int j=0;
int main(int c, char* arg[])
{
	ifstream file (arg[1], ios::in|ios::binary|ios::ate);
	if (file.is_open())
	{
		size = file.tellg();

		arr = new char [size];
		a1 = new string[size];

		file.close();
	}

ifstream f1 (arg[1], ios::in);
	if (f1.is_open())
  {
	memblock = new char [size];
	f1.read (memblock, size);
	f1.close();
	}



	for(int p=0;p<size-2;p++){

			arr[a]=memblock[p];
			a++;

	}
arr[a]='\0';



  char* tok;

	tok = strtok (arr," ");
	while (tok != NULL){

		a1[i]=tok;
		i++;

		 tok = strtok (NULL, " ");


	}
	a1[i] ='\0' ;






	ifstream file2 (arg[2], ios::in|ios::binary|ios::ate);
	if (file2.is_open())
  {
	 size2 = file2.tellg();

	arr2 = new char [size2];
    a2 = new string [size2];
    file2.close();




  }

ifstream f2 (arg[2], ios::in);
	if (f2.is_open())
  {
	memblock2 = new char [size2];
	f2.read (memblock2, size2);
	f2.close();
	}




	for(int n=0;n<size2;n++){


			arr2[b]=memblock2[n];
			b++;

	}
arr2[b]='\0';

int g =0;

char* tok2;

	tok2 = strtok (arr2," ");
	while (tok2 != NULL){

		a2[g]=tok2;
		g++;

		 tok2 = strtok (NULL, " ");


	}
	a2[g] ='\0' ;




	final =new string[size];
 ////////////////////////// starting task after reading from both files/////////////////////
 ///////////data of 1st file is in a1, 2nd in a2/////////////
cout<<"Data after stop words"<<endl;

 for(int z=0;z<size;z++){
	 string word = a1[z];
	 int flag =0;


	 for(int y=0;y<size2;y++){
		 if(word == a2[y]){
			 flag = 1;
		 }

	 }
	 if(flag==0){
		 cout<<word<<" ";
		 final[f] = word;
		 f++;

	 }
}
int tot = 1;
 //////////////////// two word freq////////////////////////////

string c1,c2,c3,c4;
 c1=final[0];
 c2 = final[1];
 c3 = final[2];
 c4 = final[3];

 for(int last = 0;last<f;last++){


	 if(fp>freq){
	  c1=final[last];
	  c2 = final[last+1];
	 }


	 for(int li=2;li<last;li++){

		 if(c1==final[li]&& c2==final[li+1]){
			 tot++;
			 freq++;
		 }

		 if(c3==final[li]&& c4==final[li+1]){
			 tot++;
			 fp++;
		 }

	 }


 }
	 int frequency = freq/tot;

	 cout<<"Most Frequence sequence is "<<c1<<" "<<c2<<" which comes "<<frequency<<" times.";



 }