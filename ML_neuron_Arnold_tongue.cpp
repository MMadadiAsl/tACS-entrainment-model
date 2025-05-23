
//*******************************************************************************************

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "functions.cpp"

using namespace std;

//*******************************************************************************************

const int T = 100000;			// Total time of simulation.		
const float dt = 0.05;			// Time steps in ms.
const float PI = 4.0 * atan(1.0);	// Time steps in ms.

int t = 0, num1_spikes = 0, num2_spikes = 0; 
float Vm1[T], n1[T], Vm2[T], n2[T], m1_inf, n1_inf, tau1_n, m2_inf, n2_inf, tau2_n, tACS_current, tACS_amp, tACS_freq, entrain1, entrain2;
float C = 20.0, Vth = -20.0, Iapp1 = 45.0, Iapp2 = 92.0, EL = -60.0, EK = -84.0, ECa = 120, gL = 2.0, gK = 8.0, V1 = -1.2, V2 = 18.0;
float phi1 = 0.067, phi2 = 0.04, gCa1 = 4.0, gCa2 = 4.4, V3_I = 12, V3_II = 2.0, V4_I = 17.4, V4_II = 30.0;

vector<int> spike_times_1;
vector<int> spike_times_2;

//*******************************************************************************************

int main(){

	ofstream outfile1("output1.txt");
	ofstream outfile2("output2.txt");

	Vm1[0] = 0.0;
	Vm2[0] = 0.0;
	n1[0] = 0.1;
	n2[0] = 0.8;

//*******************************************************************************************

	for (tACS_freq = 0.0; tACS_freq <= 20.1; tACS_freq = tACS_freq + 0.2){
	for (tACS_amp = 0.0; tACS_amp <= 10.1; tACS_amp = tACS_amp + 0.2){
	for (t = 0; t < T - 1; t++){

		tACS_current = tACS_amp * sin(2.0 * PI * tACS_freq * t * dt / 1000.0);

		m1_inf = 0.5 * (1.0 + tanh((Vm1[t] - V1) / V2));
		m2_inf = 0.5 * (1.0 + tanh((Vm2[t] - V1) / V2));
		n1_inf = 0.5 * (1.0 + tanh((Vm1[t] - V3_I) / V4_I));
		n2_inf = 0.5 * (1.0 + tanh((Vm2[t] - V3_II) / V4_II));
		tau1_n = 1.0 / (cosh((Vm1[t] - V3_I) / (2.0 * V4_I)));
		tau2_n = 1.0 / (cosh((Vm2[t] - V3_II) / (2.0 * V4_II)));

		Vm1[t + 1] = Vm1[t] + (dt / C) * (Iapp1 + tACS_current - (gL * (Vm1[t] - EL)) - (gK * n1[t] * (Vm1[t] - EK)) - (gCa1 * m1_inf * (Vm1[t] - ECa)));
		n1[t + 1] = n1[t] + dt * phi1 * ((n1_inf - n1[t]) / tau1_n);
    
		Vm2[t + 1] = Vm2[t] + (dt / C) * (Iapp2 + tACS_current - (gL * (Vm2[t] - EL)) - (gK * n2[t] * (Vm2[t] - EK)) - (gCa2 * m2_inf * (Vm2[t] - ECa)));
		n2[t + 1] = n2[t] + dt * phi2 * ((n2_inf - n2[t]) / tau2_n);
    
		if (Vm1[t] > Vth){
			if (Vm1[t] > Vm1[t - 1] && Vm1[t] > Vm1[t + 1]){
				spike_times_1.push_back(t);
				num1_spikes++;
			}
		}

		if (Vm2[t] > Vth){
			if (Vm2[t] > Vm2[t - 1] && Vm2[t] > Vm2[t + 1]){
				spike_times_2.push_back(t);
				num2_spikes++;
			}
		}
		
	}

		entrain1 = tACS_freq / float(MeanFiringRate(num1_spikes,T,dt));
		entrain2 = tACS_freq / float(MeanFiringRate(num2_spikes,T,dt));

		if (entrain1 <= 1.01 && entrain1 >= 0.99) entrain1 = 1.0;
		else entrain1 = 0.0;
		if (entrain2 <= 1.01 && entrain2 >= 0.99) entrain2 = 1.0;
		else entrain2 = 0.0;

		outfile1 << tACS_freq << '\t' << tACS_amp << '\t' << entrain1 << endl;
		outfile2 << tACS_freq << '\t' << tACS_amp << '\t' << entrain2 << endl;

		num1_spikes = 0;
		num2_spikes = 0;
		tACS_current = 0.0;
		spike_times_1.clear();
		spike_times_2.clear();
		Vm1[0] = 0.0;
  	      	Vm2[0] = 0.0;
        	n1[0] = 0.1;
    		n2[0] = 0.8;
	}
	}

//*******************************************************************************************

	outfile1.close();
	outfile2.close();

return 0;

}

//*******************************************************************************************
//*******************************************************************************************
