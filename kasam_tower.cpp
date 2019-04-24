Author Name: Kasam Dhakal
#include <iostream>
#include <string>
using namespace std;

void Hanoi(string init , string final);

string other(string from, string to);

int main(int argc, char** argv)
{       string init (argv[1]);
        string final (argv[2]);

        Hanoi(init, final);

}

void Hanoi(string init, string final){

    if (init.length()==0) {
        return;
    }

    else if(init.substr(0,1)==final.substr(0,1))
    {
        Hanoi(init.substr(1),final.substr(1));

    }

    else {

        string from(init.substr(0,1));
        string to(final.substr(0,1));
        string spare(other(from,to));
        string ic("");

        for(int i=1; i<init.length();i++){
            ic.append(spare);

        }
        Hanoi(init.substr(1),ic);

        cout<< "Move "<< from<<" to " <<to<< endl;

        Hanoi(ic,final.substr(1));

    }

}


string other(string from, string to){
    if(from=="A"){
         if (to=="B"){
             return "C";
         }
       else {
           return "B";
       }
    }

    if(from=="B"){
        if(to=="A"){
            return "C";

        }
        else{
            return "A";

        }
    }

    if(from=="C"){
        if(to=="A"){
          return "B";
        }
         else{
             return "A";
         }
    }
 return "";
}
