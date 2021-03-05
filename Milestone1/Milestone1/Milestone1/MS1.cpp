#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

void vectorPrint(vector<double>& V) {
	for (auto col : V) {
		cout << col << " ";
	}
	cout << "\n";
}

void matrixPrint(vector<vector<double>>& M) {
	for (auto row : M) {
		vectorPrint(row);
	}
}

void matTranspose(vector<vector<double>>& Y, vector<vector<double>>& X) {
	size_t rows = X.size();    //  number of rows    for matrix X
	size_t cols = X[0].size(); //  number of columns for matrix X
	Y.resize(cols);             // set nunber of rows for Y
	for (auto&e : Y) {             // set nunber of cols for each row of Y
		e.resize(rows);
	}
	for (size_t r = 0; r < rows; r++) {   // copy data
		for (size_t c = 0; c < cols; c++) {
			Y[c][r] = X[r][c];
		}
	}
}

void matMult(vector<double>& Y, vector<vector<double>>& M, vector<double>& X) {
	for (size_t i = 0; i < M.size(); i++) {
		Y[i] = inner_product(M[i].begin(), M[i].end(), X.begin(), 0.);
	}
}

class NeuralNetwork {
public:
	vector<double> synaptic_weights;
	NeuralNetwork(size_t s) {
		synaptic_weights.resize(s);
		srand(1);
		for (auto& e : synaptic_weights) {
			e = 2. * rand() / double(RAND_MAX) - 1.;
		}
	}
	double __sigmoid(double x) {
		return 1. / (1. + exp(-x));
	}
	vector<double> __sigmoid(vector<double>& V) {
		for (auto& e : V) {
			e = __sigmoid(e);
		}
		return V;
	}
	double __sigmoid_derivative(double x) {
		return x * (1. - x);
	};
	double think(vector <double>& input) {
		return __sigmoid(inner_product(input.begin(), input.end(), synaptic_weights.begin(), 0.));
	};
	void think(vector <double>& output, vector<vector<double>>& inputs) {
		matMult(output, inputs, synaptic_weights);
		for (auto&e : output) e = __sigmoid(e);
	};
	void train(vector<vector<double>>&training_set_inputs, vector<double>&training_set_outputs, int number_of_training_iterations) {
		vector<double> output(training_set_inputs.size());
		vector<double> error(training_set_inputs.size());
		vector<double> adjustments(training_set_inputs.size());
		vector<vector<double>> training_set_inputsT;
		matTranspose(training_set_inputsT, training_set_inputs);
		for (int iteration = 0; iteration < number_of_training_iterations; iteration++) {
			think(output, training_set_inputs);

			transform(training_set_outputs.begin(), training_set_outputs.end(),
				output.begin(), error.begin(), [](double t, double o) { return t - o; });

			transform(error.begin(), error.end(),
				output.begin(), output.begin(), [this](double e, double o) { return e * __sigmoid_derivative(o); });

			matMult(adjustments, training_set_inputsT, output);

			transform(synaptic_weights.begin(), synaptic_weights.end(),
				adjustments.begin(), synaptic_weights.begin(), [](double w, double a) { return w + a; });
		}
	}
};

int main() {
	NeuralNetwork neural_network(3);
	vector <vector<double>> training_set_inputs{ { 0,0,1 },
	{ 1,1,1 },
	{ 1,0,1 },
	{ 0,1,1 } };
	vector <double> training_set_outputs{ 0, 1, 1, 0 };

	cout << "Ramdom start synaptic weights";
	vectorPrint(neural_network.synaptic_weights);
	cout << "training_set_inputs\n";
	matrixPrint(training_set_inputs);
	cout << "training_set_outputs: ";
	vectorPrint(training_set_outputs);

	neural_network.train(training_set_inputs, training_set_outputs, 10000);

	cout << "New synapitc weights after training: ";
	vectorPrint(neural_network.synaptic_weights);

	cout << "Considereing new situation [1,0,0] -> ?: ";
	vector<double> input = { 1,0 ,0 };
	cout << setprecision(8) << neural_network.think(input) << "\n";

	return 0;
}