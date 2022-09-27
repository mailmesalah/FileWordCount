#include<iostream>
#include<fstream>
#include<string>
#include <list>
using namespace std;

class Sequence
{

	public:
	
	string FirstString;
	string SecondString;
	int count;
	
	Sequence(void)
	{
		FirstString=("");
		SecondString=("");
		count=0;
	}  
};


int main(int argc, char *argv[])
{
	string line;
	
	list<Sequence> mylist;
  	list<Sequence>::iterator it;
  	
	string seqWord("");
	string tempWord("");
     
	if(argc==2)
	{
          	ifstream myfile(argv[1]);
		if(myfile.is_open())
		{
			
			while(myfile.good())
			{
				getline(myfile,line);
				int i=0;
				while(i<(int)line.length())
				{
					if(line.at(i)==' ')
					{
						
						if(tempWord=="")
						{
							//Skipping initial word
							tempWord.assign(seqWord);							
							seqWord.clear();
						}
						else
						{

						//Check if the sequence already added
							int status=0;
							for (it=mylist.begin(); it!=mylist.end(); ++it)
							{
								if(((*it).FirstString.compare(tempWord)==0) && ((*it).SecondString.compare(seqWord)==0) )
								{
									(*it).count=(*it).count+1;
									status=1;
									tempWord.assign(seqWord);
									seqWord.clear();
									break;
								}

							}

						    	if(status==0)
							{								
								Sequence s;
								s.FirstString=tempWord;
								s.SecondString=seqWord;
								s.count=1;
								
								mylist.push_back (s);

								tempWord.assign(seqWord);
								seqWord.clear();
							}
						
						}

					}
					else
					{
						seqWord.append(1,line.at(i));
					}
					i++;

					
					//Including the last word
					if(((int)line.length())==i)
					{					
						if(tempWord=="")
						{
							//Skipping initial word
							tempWord.assign(seqWord);							
							seqWord.clear();
						}
						else
						{

						//Check if the sequence already added
							int status=0;
							for (it=mylist.begin(); it!=mylist.end(); ++it)
							{
								if(((*it).FirstString.compare(tempWord)==0) && ((*it).SecondString.compare(seqWord)==0) )
								{
									(*it).count=(*it).count+1;
									status=1;
									seqWord.clear();
									break;
								}

							}

						    	if(status==0)
							{								
								Sequence s;
								s.FirstString=tempWord;
								s.SecondString=seqWord;
								s.count=1;
								
								mylist.push_back (s);

								tempWord.assign(seqWord);
								seqWord.clear();
							}
						
						}

					}

				}


			}
			myfile.close();

			
			for (it=mylist.begin(); it!=mylist.end(); ++it)
			{
				cout<< " " <<endl;
				cout<< "Sequence Start" <<endl;
				cout<< "First Word  :"<< (*it).FirstString <<endl;
				cout<< "Second Word :"<< (*it).SecondString <<endl;
				cout<< "Count       :"<< (*it).count <<endl;
				cout<< "Sequence End" <<endl;
				cout<< " " <<endl;

			}

		}
		else cout<< "Unable to open file";

	
	}
        else if(argc==3)
	{
		ifstream myfile("Example.txt");
		if(myfile.is_open())
		{
			while(myfile.good())
			{
				getline(myfile,line);
				cout<< line <<endl;
			}
			myfile.close();
		}
		else cout<< "Not yet done";
	}
	

	return 0;
}
