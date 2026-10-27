#include <iostream>
using namespace std;

int main() {
    // Input values
    double claim_mean = 1000.0;     
    double sample_mean = 980.0;     
    double std_dev = 60.0;          
    double sample_sqrt = 6.0;  

    // z-score formula
    double z_score = (sample_mean - claim_mean) / (std_dev / sample_sqrt);

    // Critical Z-value for left-tailed test at alpha = 0.05
    double z_critical = -1.645;

    cout << "--- HYPOTHESIS TEST RESULTS ---" << endl;
    cout << "Claimed Mean: " << claim_mean << " hours" << endl;
    cout << "Sample Mean:  " << sample_mean << " hours" << endl;
    cout << "Z-Score:      " << z_score << endl;
    cout << "Z-Critical:   " << z_critical << endl;
    
	cout << "\nNULL Hypothesis: M >= 1000" << endl;
	cout << "ALTERNATE Hypothesis: M < 1000"<< endl;

    // Decision
    if (z_score < z_critical) {
        cout << "\nDecision: Reject NULL Hypothesis." << endl;
        cout << "Conclusion: Battery lifetime is significantly less than 1000 hours." << endl;
    } else {
        cout << "\nDecision: Failed to reject NULL Hypothesis." << endl;
        cout << "Conclusion: Not enough evidence to reject the manufacturer's claim." << endl;
    }
    
    return 0;
}

