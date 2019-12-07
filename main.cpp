#include "functions.h"
#include<ctime>

int main(int argc, char *argv[]) {
    srand((unsigned)time(NULL));
    std::vector<Animal> animal;
    std::vector<Vets> vets;
    std::vector<Problems> problems;
    std::vector<Treatments> treatments;
    std::vector<Abstract> abstract;
    readFile(std::string(argv[2]), animal);
    readFile(std::string(argv[3]),vets);
    readFile(std::string(argv[4]),problems);
    readFile(std::string(argv[5]),treatments);
    int limit = atoi(std::string(argv[1]).c_str());
    std::ofstream ofile;
    ofile.open(argv[6]);

    Abstract ab;
    limit = animal.size()<limit?animal.size():limit;
    for(int i=0;i<limit;i++){
        std::cout<<"----------------------"<<std::endl;
        std::cout<<i+1<<" animal coming."<<std::endl;

        ab.name=animal[i].Name;
        ab.problem = problems[animal[i].Problem-1].Name;
        std::cout<<"name:"<<animal[i].Name<<"   type:"<<animal[i].Type<<"   Registration:"<<animal[i].Registration<<std::endl;
        int person = randomInt(0, vets.size()-1);
        ab.vet = vets[person].Name;
        if(check(vets[person], problems[animal[i].Problem-1])){
            ab.check = ab.problem;
            ab.treat = treatments[problems[animal[i].Problem-1].Treatment-1].Name;
            if(treat(vets[person], problems[animal[i].Problem-1],treatments[problems[animal[i].Problem-1].Treatment-1],animal[i].Problem-1, animal[i].Problem-1))
                ab.result = "success";
            else
                ab.result="fail";
        }
        else{
            int guess = randomInt(0, problems.size()-1);
            ab.check = problems[guess].Name;
            ab.treat =treatments[problems[guess].Treatment-1].Name;
            std::cout<<"he guess the problem is "<<problems[guess].Name<<std::endl;

            if(treat(vets[person], problems[animal[i].Problem-1],treatments[problems[guess].Treatment-1],animal[i].Problem-1,guess))
                ab.result = "success";
            else
                ab.result = "fail";
        }
        std::cout<<"animal leave."<<std::endl;
        std::cout<<"-----------------------------"<<std::endl;

        ofile<<i+1<<" name:"<<ab.name<<"    vet:"<<ab.vet<<"    problem:"<<ab.problem<<"    problem diagnosed:"<<ab.check<<"    treatment:"<<ab.treat<<"    result:"<<ab.result<<std::endl;
    }
    ofile.close();
    return 0;
}