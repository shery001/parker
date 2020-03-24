#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>

using namespace std;

//-------------------------------------Edited by Bhavya Joshi---------------------------
int read_names_from_the_file(list<string> &file)
{
        ifstream input_files;
        string names;

        input_files.open("names.txt");				//Enter the path for the file names.txt

        //check if the file is found
        if(!input_files.is_open())
        {
		std::cout << "File not found" << std::endl ;
                return 0;
        }
        // read names from file, names.txt and push them into the list
        while( getline(input_files, names, ',') )
        {
                file.push_back(names);

        }
        input_files.close();
        return 0;
}

int alphabetical_values(list<string> &file1, list<long int> &file2)
{
        file2.clear();
        list<string> :: iterator p = file1.begin();
        int index = 0;
        for(p = file1.begin() ; p != file1.end() ; p++)
        {
                string s;
                s = *p;
                int score = 0;
                for(int j = 1 ; j != (s.length() - 1) ; j++)
                {
                        score += s[j]-'A'+1;


                }
                index += 1;
		file2.push_back(score*index);

        }
        return 0;
}

int show_list(list<string> &file)
{
        list<string> :: iterator p = file.begin();
        for(p = file.begin() ; p != file.end() ; p++)
        {
		std::cout << *p << std::endl;
        }
	std::cout << std::endl << std::endl;

        return 0;

}


int show_valuelist(list<long int> &file)
{
        list<long int> :: iterator p = file.begin();
        for(p = file.begin() ; p != file.end() ; p++)
        {
		std::cout << *p << std::endl;
        }
	std::cout << std::endl << std::endl;
        return 0;

}


//----------------------------------------------------------------------------



long compute_scores()
{
	long scores = 0;
	
	// Fill this function.


	//----------------------Edited by Bhavya Joshi---------------------------
	
	list<string> names_file;				//loads the names from names.txt into this list
	list<long int> alphabatic_values;			//loads alphabatical value of aphabatical sorted names 
      	read_names_from_the_file(names_file); 			//reads the file from names.txt	

	//show_list(names_file);	
	
	names_file.sort();					//sorts names into alphabatic order

	//show_list(names_file);

	alphabetical_values(names_file, alphabatic_values);	//comupts the alphabatic values
        //show_valuelist(alphabatic_values);


	//Here, I have computed the total alphabatic values, i.e. scores

        list<long int> :: iterator v = alphabatic_values.begin();
        for(v = alphabatic_values.begin(); v != alphabatic_values.end(); ++v)
        {
                long int a = *v;
                scores += a;
        }
	
	//------------------------------------------------------------------------
	

	return scores;
}

int main()
{
	auto scores = compute_scores();
	std::cout << "The total sum of all name scores is " << scores << std::endl;
	return 0;
}

