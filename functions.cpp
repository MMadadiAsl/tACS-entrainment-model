
//******************************************************************************************
//******************************************************************************************

float MeanFiringRate (int num_spikes, int duration, float dt){
	
	float meanFiringRate = 0.0;

    if (num_spikes > 0) meanFiringRate = num_spikes / float (duration * dt / 1000.0) ;

    return meanFiringRate;
}

//******************************************************************************************
//******************************************************************************************
