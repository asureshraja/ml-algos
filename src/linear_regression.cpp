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




    mat weights,calculated_outputs,ideal_outputs;
    int batch_size=1;int learning_rate=0.1;

    calculated_outputs = mat(batch_size,1); //initialization
    weights = randu<mat>(1,data.n_cols);
    weights.col(0).fill(1); //bias
    data.insert_cols(0,true); //to match with bias
    data.col(0).fill(1);//setting to 1
    weights.print("weights");
    ideal_outputs = data.col(4);
    ideal_outputs.print("ideal outputs");

    data.shed_col(4); //remove class feature
    data.print("data");
    int iter=0;
    while(iter<100) {
        for (int i = 0; i < data.n_rows; i++) {
            calculated_outputs=data.row(i)*weights.t();
            (learning_rate*(calculated_outputs-ideal_outputs.row(i))*data.row(i)).print("sss");
            weights.print("prev");
            weights=weights+(learning_rate*(calculated_outputs-ideal_outputs.row(i))*data.row(i));
            weights.print("new");
            //printf("%d\n\n\n", i);
            // calculated_outputs.print("calc_output");
            // ideal_outputs.row(i).print("ideal");
        }
        iter++;
    }


}
