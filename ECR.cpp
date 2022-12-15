#include<string>
#include<vector>
#include<iostream>
#include <fstream>
using namespace std;
class ECR{
    private:
     vector<vector<string> > ecr;
    
   
    public:
    void init()
    {
    string input;

    // cout<<"enter a string: "<<endl;
    // getline(cin,input);
    std::ifstream infile("ecr.txt");
    while (std::getline(infile, input))
    {
        vector<string> separetedInput;
        int start = 0;
        string delim = " ";
        int end = input.find(delim);
            while (end != -1) {
                separetedInput.push_back(input.substr(start, end - start));
                //cout << input.substr(start, end - start) << endl;
                start = end + delim.size();
                end = input.find(delim, start);
            }
       // cout << input.substr(start, end - start)<<endl;
        separetedInput.push_back(input.substr(start, end - start));
        ecr.push_back(separetedInput);
    }
    
    }
   
    ECR()
    {
        init();
    }
    bool symanticAnalysis(vector<string> gramaticalKnowledge)
    {
        bool valid = false;
        for(int i=0;i<ecr.size();i++)
        {
            if(ecr.at(i).at(0)==gramaticalKnowledge.at(0))
            {
                for(int j = 1;j<ecr.at(i).size(); j++)
                {
                    if(ecr.at(i).at(j)==gramaticalKnowledge.at(1))
                    {
                        cout<<gramaticalKnowledge.at(1)<<" can be "<<gramaticalKnowledge.at(0)<<"+ ed"<<endl;
                        return true;
                        break;
                        
                    }
            
                }
                if(!valid)
                cout<<gramaticalKnowledge.at(1)<<" cannot be "<<gramaticalKnowledge.at(0)<<"ed"<<endl;


            }
            
        
    }
    return false;
    
  }

};


    
