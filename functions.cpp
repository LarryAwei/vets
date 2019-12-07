//
// Created by weizihan on 2019/12/1.
//

#include "functions.h"

void readFile(std::string s, std::vector<Animal> &animal){
    Animal a;
    std::ifstream file;
    file.open(s,std::ios::in);
    if(!file)
    {
        std::cout<<"open error！"<<std::endl;
        exit(1);
    }
    std::cout<<"file Animal"<<std::endl;
    std::string str;
    std::string sst;
    std::string parameter[4]={"","","",""};
    int j=0,i=0,t=0;
    while(getline(file,str))
    {
        if(str.find(".")==-1||str.find(":")==-1){
            std::cout<<"this line's format is not true."<<std::endl;
            continue;
        }
        for(;i<str.length();i++){
            if(str[i]!=':'&&str[i]!='.'){
                parameter[j]+=str[i];
            }
            else{
                j++;
                if(str[i]=='.')break;
            }
        }
        a.Name=parameter[0];
        a.Type=parameter[1];
        a.Registration=parameter[2];
        a.Problem=std::stoi(parameter[3]);
        animal.push_back(a);
        std::cout<<a.Name<<":"<<a.Type<<":"<<a.Registration<<":"<<a.Problem<<"."<<std::endl;
        i=0,j=0;
        parameter[0]="",parameter[1]="",parameter[2]="",parameter[3]="";

    }
    std::cout<<std::endl;
    file.close();
}
void readFile(std::string s, std::vector<Vets> &vets){
    Vets v;
    std::ifstream file;
    file.open(s,std::ios::in);
    if(!file)
    {
        std::cout<<"open error！"<<std::endl;
        exit(1);
    }
    std::cout<<"file Vets"<<std::endl;
    std::string str;
    std::string parameter[2]={"",""};
    int j=0,i=0,t=0;
    while(getline(file,str))
    {
        if(str.find(".")==-1||str.find(":")==-1){
            std::cout<<"this line's format is not true."<<std::endl;
            continue;
        }
        for(;i<str.length();i++){
            if(str[i]!=':'&&str[i]!='.'){
                parameter[j]+=str[i];
            }
            else{
                j++;
                if(str[i]=='.')break;
            }
        }
        v.Name=parameter[0];
        v.Quality=std::stoi(parameter[1]);

        vets.push_back(v);
        std::cout<<v.Name<<":"<<v.Quality<<"."<<std::endl;
        i=0,j=0;
        parameter[0]="",parameter[1]="";
    }
    std::cout<<std::endl;
    file.close();
}
void readFile(std::string s, std::vector<Problems> &problems){
    Problems p;
    std::ifstream file;
    file.open(s,std::ios::in);
    if(!file)
    {
        std::cout<<"open error！"<<std::endl;
        exit(1);
    }
    std::cout<<"file Problems"<<std::endl;
    std::string str;
    std::string sst;
    std::string parameter[4]={"","","",""};
    int j=0,i=0,t=0;
    while(getline(file,str))
    {
        if(str.find(".")==-1||str.find(":")==-1){
            std::cout<<"this line's format is not true."<<std::endl;
            continue;
        }
        for(;i<str.length();i++){
            if(str[i]!=':'&&str[i]!='.'){
                parameter[j]+=str[i];
            }
            else{
                j++;
                if(str[i]=='.')break;
            }
        }
        p.Name=parameter[0];
        p.determinationComplexity=std::stoi(parameter[1]);
        p.treatmentComplexity=std::stoi(parameter[2]);
        p.Treatment=std::stoi(parameter[3]);
        std::cout<<p.Name<<":"<<p.determinationComplexity<<":"<<p.treatmentComplexity<<":"<<p.Treatment<<"."<<std::endl;
        problems.push_back(p);
        i=0,j=0;
        parameter[0]="",parameter[1]="",parameter[2]="",parameter[3]="";

    }
    std::cout<<std::endl;
    file.close();
}
void readFile(std::string s, std::vector<Treatments> &treatments){
    Treatments t;
    std::ifstream file;
    file.open(s,std::ios::in);
    if(!file)
    {
        std::cout<<"open error！"<<std::endl;
        exit(1);
    }
    std::cout<<"file Treatments"<<std::endl;
    std::string str;
    std::string parameter="";
    int j=0,i=0;
    while(getline(file,str))
    {
        if(str.find(".")==-1){
            std::cout<<"this line's format is not true."<<std::endl;
            continue;
        }
        for(;i<str.length();i++){
            if(str[i]!='.'){
                parameter+=str[i];
            }
            else{
                break;
            }
        }
        t.Name=parameter;
        std::cout<<t.Name<<std::endl;
        treatments.push_back(t);
        i=0,j=0;
        parameter="";
    }
    std::cout<<std::endl;
    file.close();
}
//generate random int number
int randomInt(int a, int b){
    return rand()%(b-a+1)+a;
}
//check animal's problem
bool check(Vets vet, Problems problem){
    std::cout<<vet.Name<<" try to check this problem. (" << problem.Name <<")..."<<std::endl;
    float probability = float(vet.Quality/problem.determinationComplexity)*50;
    if(probability>=randomInt(1,100)){
        std::cout<<"check success!"<<std::endl;
        return true;
    } else{
        std::cout<<"check wrong! he needs to guess."<<std::endl;
        return false;
    }
}
//treat animal's problem
bool treat(Vets vet, Problems problem, Treatments treat, int i, int j){
    //std::cout<<"he think the problem is "<<problem.Name<<std::endl;
    if(i==j){
        std::cout<<"problem is correct. start treat. he will use: "<<treat.Name<<std::endl;
        float probability = float(vet.Quality/problem.treatmentComplexity)*50;
        if(probability>=randomInt(1,100)){
            std::cout<<"treat success!"<<std::endl;
            return true;
        } else{
            std::cout<<"treat fail!"<<std::endl;
            return false;
        }
    }
    else{
        std::cout<<"problem is wrong. start treat. he will use: "<<treat.Name<<std::endl;
        float probability = float(vet.Quality/problem.treatmentComplexity)*50*0.25;
        if(probability>=randomInt(1,100)){
            std::cout<<"treat success!"<<std::endl;
            return true;
        } else{
            std::cout<<"treat fail!"<<std::endl;
            return false;
        }
    }
}