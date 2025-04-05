# tACS-entrainment-model

## Entrainment by transcranial alternating current stimulation: Insights from models of cortical oscillations and dynamical systems theory

**Abstract**: ‎Signature of neuronal oscillations can be found in nearly every brain function. However, abnormal oscillatory activity is linked with several brain disorders. Transcranial alternating current stimulation (tACS) is a non-invasive brain stimulation technique that can potentially modulate neuronal oscillations and influence behavior both in health and disease. Yet, a complete understanding of how interacting networks of neurons are affected by tACS remains elusive. Entrainment effects by which tACS synchronizes neuronal oscillations is one of the main hypothesized mechanisms, as evidenced in animals and humans. Computational models of cortical oscillations may shed light on the entrainment effects of tACS, but current modeling studies lack specific guidelines to inform experimental investigations. This study addresses the existing gap in understanding the mechanisms of tACS effects on rhythmogenesis within the brain by providing a comprehensive overview of both theoretical and experimental perspectives. We explore the
intricate interactions between oscillators and periodic stimulation through the lens of dynamical systems theory. Subsequently, we present a synthesis of experimental findings that demonstrate the effects of tACS on both individual neurons and collective oscillatory patterns in animal models and humans. Our review extends to computational investigations that elucidate the interplay between tACS and neuronal dynamics across diverse cortical network models. To illustrate these concepts, we conclude with a simple oscillatory neuron model, showcasing how fundamental theories of oscillatory behavior derived from dynamical systems, such as phase response of neurons to external perturbation, can account for the entrainment effects observed with tACS. Studies reviewed here render the necessity of integrated experimental and computational approaches for effective neuromodulation by tACS in health and disease.

## Usage

- These codes reproduce data used to generate the figures in the manuscript. ```ML_neuron_membrane_voltage.cpp``` reproduces the membrane potential oscillation of type-I and type-II neurons for a full oscillation cycle, ```ML_neuron_PRC.cpp``` reproduces the corresponding phase response curve of neurons, and ```ML_neuron_Arnold_tongue.cpp``` reproduces the Arnold tongues or 1:1 frequency locking (entrainment) for type-I and type-II neurons.

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

- Madadi Asl, M., & Valizadeh, A. (2025). Entrainment by transcranial alternating current stimulation: Insights from models of cortical oscillations and dynamical systems theory. Physics of Life Reviews, 53: 147-176. [https://doi.org/10.1016/j.plrev.2025.03.008](https://doi.org/10.1016/j.plrev.2025.03.008).
