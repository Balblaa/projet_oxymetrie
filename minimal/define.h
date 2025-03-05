#ifndef DEFINE_H
#define DEFINE_H
#define MAXSIZE 51

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*! ------------------------------------------------------------
  
  \struct absorp
 
  \brief measures
  
  ------------------------------------------------------------*/

typedef struct{
		float acr;  /*!< AC R */
		float dcr;  /*!< DC R */
		float acir;  /*!< AC IR */
		float dcir;  /*!< DC IR */
	} absorp;

/*! ------------------------------------------------------------
  
  \struct oxy
 
  \brief   
  
  ------------------------------------------------------------*/

typedef struct{
		int spo2;  /*!< SPO2 */
		int pouls;  /*!< Pouls */
	} oxy;


typedef struct{
        absorp array[MAXSIZE];
        int front;
        int size;
} buffer;

typedef struct{
        int max_ACR;
        int min_ACR;
        int last_ACR;
        int max_ACIR;
        int min_ACIR;
        int counter_period;
        float period;
} onde;


#endif // DEFINE_H
