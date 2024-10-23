
//*******************************************************************************************

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "functions.cpp"

using namespace std;

//*******************************************************************************************

const int T = 20000;		// Total time of simulation.		
const float dt = 0.05;		// Time steps in ms.

int t = 0, num1_spikes = 0, num2_spikes = 0, t1_stim, t2_stim, pulse_duration = 20; 
float Vm1[T], n1[T], Vm2[T], n2[T], m1_inf, n1_inf, tau1_n, m2_inf, n2_inf, tau2_n, stim1, stim2, PRC1, PRC2;
float C = 20.0, Vth = -20.0, Iapp1 = 45.0, Iapp2 = 92.0, EL = -60.0, EK = -84.0, ECa = 120, gL = 2.0, gK = 8.0, V1 = -1.2, V2 = 18.0;
float phi1 = 0.067, phi2 = 0.04, gCa1 = 4.0, gCa2 = 4.4, V3_I = 12, V3_II = 2.0, V4_I = 17.4, V4_II = 30.0;

vector<int> spike_times_unperturbed_1;
vector<int> spike_times_unperturbed_2;
vector<int> spike_times_perturbed_1;
vector<int> spike_times_perturbed_2;

//*******************************************************************************************

int main(){

	ofstream outfile3("output3.txt");
	ofstream outfile4("output4.txt");

	Vm1[0] = 0.0;
	Vm2[0] = 0.0;
	n1[0] = 0.8;
	n2[0] = 0.8;

//*******************************************************************************************

	for (t = 0; t < T - 1; t++){

		m1_inf = 0.5 * (1.0 + tanh((Vm1[t] - V1) / V2));
		m2_inf = 0.5 * (1.0 + tanh((Vm2[t] - V1) / V2));
		n1_inf = 0.5 * (1.0 + tanh((Vm1[t] - V3_I) / V4_I));
		n2_inf = 0.5 * (1.0 + tanh((Vm2[t] - V3_II) / V4_II));
		tau1_n = 1.0 / (cosh((Vm1[t] - V3_I) / (2.0 * V4_I)));
		tau2_n = 1.0 / (cosh((Vm2[t] - V3_II) / (2.0 * V4_II)));

		Vm1[t + 1] = Vm1[t] + (dt / C) * (Iapp1 - (gL * (Vm1[t] - EL)) - (gK * n1[t] * (Vm1[t] - EK)) - (gCa1 * m1_inf * (Vm1[t] - ECa)));
		n1[t + 1] = n1[t] + dt * phi1 * ((n1_inf - n1[t]) / tau1_n);
    
		Vm2[t + 1] = Vm2[t] + (dt / C) * (Iapp2 - (gL * (Vm2[t] - EL)) - (gK * n2[t] * (Vm2[t] - EK)) - (gCa2 * m2_inf * (Vm2[t] - ECa)));
		n2[t + 1] = n2[t] + dt * phi2 * ((n2_inf - n2[t]) / tau2_n);
    
		if (Vm1[t] > Vth && t > 10){
			if (Vm1[t] > Vm1[t - 1] && Vm1[t] > Vm1[t + 1]){
				spike_times_unperturbed_1.push_back(t);
				num1_spikes++;
			}
		}

		if (Vm2[t] > Vth && t > 10){
			if (Vm2[t] > Vm2[t - 1] && Vm2[t] > Vm2[t + 1]){
				spike_times_unperturbed_2.push_back(t);
				num2_spikes++;
			}
		}
	}

	num1_spikes = 0;
	num2_spikes = 0;

	for (t1_stim = spike_times_unperturbed_1[2]; t1_stim <= spike_times_unperturbed_1[3]; t1_stim = t1_stim + 1){
		for (t = 0; t < T; t++){

		if (t >= t1_stim && t <= (t1_stim + pulse_duration)) stim1 = 40.0;
		else stim1 = 0.0;

		m1_inf = 0.5 * (1.0 + tanh((Vm1[t] - V1) / V2));
		n1_inf = 0.5 * (1.0 + tanh((Vm1[t] - V3_I) / V4_I));
		tau1_n = 1.0 / (cosh((Vm1[t] - V3_I) / (2.0 * V4_I)));

		Vm1[t + 1] = Vm1[t] + (dt / C) * (Iapp1 + stim1 - (gL * (Vm1[t] - EL)) - (gK * n1[t] * (Vm1[t] - EK)) - (gCa1 * m1_inf * (Vm1[t] - ECa)));
		n1[t + 1] = n1[t] + dt * phi1 * ((n1_inf - n1[t]) / tau1_n);

		if (Vm1[t] > Vth){
			if (Vm1[t] > Vm1[t - 1] && Vm1[t] > Vm1[t + 1]){
				spike_times_perturbed_1.push_back(t);
				num1_spikes++;
			}
		}

		if (num1_spikes == 4) break;
		}

		PRC1 = 1.0 - ((spike_times_perturbed_1[3] - spike_times_perturbed_1[2]) / float(spike_times_unperturbed_1[3] - spike_times_unperturbed_1[2]));
		outfile3 << t1_stim  << '\t' << PRC1 << endl;

		spike_times_perturbed_1.clear();
		num1_spikes = 0;
		Vm1[0] = 0.0;
		n1[0] = 0.8;
	}


	for (t2_stim = spike_times_unperturbed_2[2]; t2_stim <= spike_times_unperturbed_2[3]; t2_stim = t2_stim + 1){
		for (t = 0; t < T; t++){

		if (t >= t2_stim && t <= (t2_stim + pulse_duration)) stim2 = 40.0;
		else stim2 = 0.0;

		m2_inf = 0.5 * (1.0 + tanh((Vm2[t] - V1) / V2));
		n2_inf = 0.5 * (1.0 + tanh((Vm2[t] - V3_II) / V4_II));
		tau2_n = 1.0 / (cosh((Vm2[t] - V3_II) / (2.0 * V4_II)));

		Vm2[t + 1] = Vm2[t] + (dt / C) * (Iapp2 + stim2 - (gL * (Vm2[t] - EL)) - (gK * n2[t] * (Vm2[t] - EK)) - (gCa2 * m2_inf * (Vm2[t] - ECa)));
		n2[t + 1] = n2[t] + dt * phi2 * ((n2_inf - n2[t]) / tau2_n);
    
		if (Vm2[t] > Vth){
			if (Vm2[t] > Vm2[t - 1] && Vm2[t] > Vm2[t + 1]){
				spike_times_perturbed_2.push_back(t);
				num2_spikes++;
			}
		}

		if (num2_spikes == 4) break;
		}

		PRC2 = 1.0 - ((spike_times_perturbed_2[3] - spike_times_perturbed_2[2]) / float(spike_times_unperturbed_2[3] - spike_times_unperturbed_2[2]));
		outfile4 << t2_stim  << '\t' << PRC2 << endl;

		spike_times_perturbed_2.clear();
		num2_spikes = 0;
		Vm2[0] = 0.0;
		n2[0] = 0.8;
	}


//*******************************************************************************************

	outfile3.close();
	outfile4.close();

return 0;

}

//*******************************************************************************************
//*******************************************************************************************
