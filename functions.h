//
// Created by awei on 2019/12/1.
//
#include <iostream>
#include <fstream>
#include <vector>
#ifndef A1_FUNCTIONS_H
#define A1_FUNCTIONS_H

#endif //A1_FUNCTIONS_H
struct Animal{
    std::string Name;
    std::string Type;
    std::string Registration;
    int Problem;
};
struct Vets
{
    std::string Name;
    int Quality;
};
struct Problems{
    std::string Name;
    int determinationComplexity;
    int treatmentComplexity;
    int Treatment;

};
struct Treatments{
    std::string Name;
};
struct Abstract{
    std::string name;
    std::string vet;
    std::string problem;
    std::string check;
    std::string treat;
    std::string result;
};
void readFile(std::string s, std::vector<Animal> &animal);
void readFile(std::string s, std::vector<Vets> &vets);
void readFile(std::string s, std::vector<Problems> &problems);
void readFile(std::string s, std::vector<Treatments> &treatments);
int randomInt(int a, int b);
bool check(Vets vet, Problems problem);
bool treat(Vets vet, Problems problem,Treatments treat,int i,int j );