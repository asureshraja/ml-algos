#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main(int argc, char** argv){

    mat data;
    bool status = data.load("src/datasets/numerical.csv");
    if(status == true){
        cout << "loaded successfully!!" << endl;
    }else{
        cout << "problem with loading..!" << endl;
    }

    data.print("Loaded Data:");

    //removing headers and record numbers
    data.shed_col(0);
    data.shed_row(0);

    data.print("Trimmed Data:");

    cout<<"Data summary"<<endl;
    cout<<"No of Rows "<< data.n_rows <<endl;
    cout<<"No of Cols "<< data.n_cols <<endl;

    cout<<"No of Rows "<< data.mem <<endl;
}
