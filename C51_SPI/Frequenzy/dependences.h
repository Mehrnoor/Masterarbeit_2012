/*dependences*/


 /*Auflösung wählen*/
//#define MV_OUT
#define UV_OUT
//#define TEMP

/* wenn mit dem 4. Semesterboard gearbeitet wird, entkommentieren!*/
#define EVAL_BOARD


#define MISO_PIN P0_3

/*precondition ADC-Calculation)*/

#define CAL_VOLTAGE	114.6
#define CAL_TEMP	26.5

#define GRADIENT	0.379								//Steigung der Temperaturgeradengleichung in mV/°C 
#define OFFSET 		(CAL_VOLTAGE/(CAL_TEMP*GRADIENT))	//Temperaturachsenabschnitt bei °C gleich Null
#define REFERENCE	3337.0								//Referenzspannung in mV 
#define RESOLUTION	8388607.0							//entspricht (2^23)-1

#define STEP		(RESOLUTION/(REFERENCE*0.5))
#define SUBB		(OFFSET*STEP)
#define DIV			(GRADIENT*STEP)