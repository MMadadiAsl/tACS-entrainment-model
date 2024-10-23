# tACS-entrainment-model

## Entrainment by transcranial alternating current stimulation: Insights from models of cortical oscillations and dynamical systems theory

**Abstract**: ‎Signature of neuronal oscillations can be found in nearly every brain function such as perception‎, ‎attention‎,‎ motor control as well as ‎learning ‎and‎ ‎memory‎. However, ‎‎‎abnormal oscillatory activity is linked with several brain disorders like Parkinson's disease (PD)‎, ‎Alzheimer's disease (AD)‎, ‎attention-deficit/hyperactivity disorder (ADHD)‎, ‎autism spectrum disorder (ASD), depression and schizophrenia. ‎‎‎‎Transcranial alternating current stimulation (tACS) is a non-invasive brain stimulation technique that can potentially modulate neuronal oscillations and influence ‎behavior‎ both in health and disease‎. Yet‎‎, ‎‎a complete understanding of how ‎interacting networks of neurons are affected by tACS remains elusive‎.‎ ‎Entrainment effects by which tACS synchronizes neuronal oscillations ‎‎‎is one of the main hypothesized mechanisms, as evidenced in animals and humans. Computational models of cortical oscillations may shed light on the entrainment effects‎‎ of tACS‎, but ‎current modeling studies lack specific guidelines to inform experimental investigations‎. To address this gap‎, ‎we first ‎provide an overview on the general principles of rhythmogenesis in the brain and the role of neuronal oscillations in brain functions, and ‎‎‎‎describe the interaction of oscillators and periodic stimulation from dynamical systems ‎point ‎of ‎view. Then‎, ‎we‎ ‎‎summarize experimental evidence for entrainment by tACS at the level of single neurons and collective oscillations in animals and humans, and comprehensively review computational studies investigating how tACS interacts with neuronal dynamics in a variety of cortical network models‎. ‎Finally‎, ‎we conclude with an example of a simple oscillatory neuron model to demonstrate how fundamental theories of oscillatory behavior rooted in dynamics systems can explain entrainment effects of tACS‎. ‎Studies reviewed here render the necessity of combined experimental and computational approaches for the development of effective neuromodulation paradigms in health and disease.

## Usage

- These codes reproduce data used to generate the figures in the manuscript. ```ML_neuron_membrane_voltage.cpp``` reproduces the membrane potential oscillation of type-I and type-II neurons for a full oscillation cycle (as shown in Fig. 2A), ```ML_neuron_PRC.cpp``` reproduces the corresponding phase response curve of neurons (as shown in Fig. 2B), and ```ML_neuron_Arnold_tongue.cpp``` reproduces the Arnold tongues or 1:1 frequency locking (entrainment) for type-I and type-II neurons (as shown in Fig. 3A and B).

#### Compilation

- Compile and execute either of the scripts with the following syntax:

```
g++ -std=c++11 file_name.cpp
./a.out
```

#### Requirements

- C++11,
- g++ compiler,
- ```functions.cpp```.

## Citation

- Madadi Asl, M., & Valizadeh, A. (2024). Entrainment by transcranial alternating current stimulation: Insights from models of cortical oscillations and dynamical systems theory.
