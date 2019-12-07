student: Zihan Wei
student number: 2018124079
put all files in the same directory and use this command to compile:
g++ -o VET main.cpp functions.cpp
then you can run it using VET, for example:
./VET 10 Animals.txt Vets.txt Problems.txt Treatments.txt outfile.txt

the code shows all information in 4 files first. then you can see the whole process.

in function readFile, if the line doesn't have ":" or "." , its format is wrong. we will pass this line.
in function check and treat, we calculate the probability by:
vet's quality / determination complexity * 50
and
vet's quality / treatment complexity * 50
compare it with random number ( range 1 to 100 ) to determine if it success.