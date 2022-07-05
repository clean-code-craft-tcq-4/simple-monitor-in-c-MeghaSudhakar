#include <stdio.h>
#include <assert.h>

/*int batteryIsOk(float temperature, float soc, float chargeRate) 
{
  if(temperature < 0 || temperature > 45) 
  {
    printf("Temperature out of range!\n");
    return 0;
  } else if(soc < 20 || soc > 80) 
  {
    printf("State of Charge out of range!\n");
    return 0;
  } else if(chargeRate > 0.8) 
  {
    printf("Charge Rate out of range!\n");
    return 0;
  }
  return 1;
}*/
int soccheckPOS(float soc);
int temperaturecheckPOS(temperature);

int temperaturecheckNEG(float temperature)
{
    if(temperature < 0 || temperature > 45)
    {
        printf("Temperature out of range!\n");
        return 0;
    }
    else
    {
        int result = temperaturecheckPOS(temperature);
        return result;
    }
    
}

int temperaturecheckPOS(temperature)
{
    if(temperature >= 0 || temperature <= 45)
    {
        return 1;
    }
}

int soccheckNEG(float soc)
{
    if(soc < 20 || soc > 80)
    {
        printf("State of Charge out of range!\n");
        return 0;
    }
    else
    {
        int result = soccheckPOS(soc);
        return result;
    }
    
}

int soccheckPOS(float soc)
{
    if(soc >= 20 || soc <= 80)
    {
        return 1;
    }
}


int chargeRatecheckNEG(float chargeRate )
{
    if(chargeRate <= 0.8) 
    {
        return 1;
    }
    else
    {
        printf("Charge Rate out of range!\n");
        return 0;
    }
}

int batteryIsOk(float temperature, float soc, float chargeRate)
{
    int  temp = 0;
    int socc = 0;
    int charge = 0;
    int result =0;
    temp = temperaturecheckNEG(temperature);
    socc = soccheckNEG(soc);
    charge = chargeRatecheckNEG(chargeRate);
    printf("temp = %d socc = %d  charge = %d\n",temp,socc,charge);
    result = (temp && socc && charge);
    
    checkendresult(result);
    
    
    
    return result;
}

checkendresult(int result)
{
    if(result)
    {
        assert(result == 1);
        printf("Battery is ok\n\n");
    }
    else
    {
        assert(result == 0);
        printf("Battery was not ok due to above reasons:");
    }
}

int main()
{
    
    batteryIsOk(25, 70, 0.7);
    printf("\n\n");
    batteryIsOk(50, 85, 0);
    printf("\n\n");
    batteryIsOk(0, 20, 0.8);
    printf("\n\n");
    batteryIsOk(45, 80, 0.8);
    printf("\n\n");
    batteryIsOk(1, 19, 0.7);
    printf("\n\n");
    batteryIsOk(44, 79, 0.7);
    printf("\n\n");
    batteryIsOk(46, 81, 0.7);
    printf("\n\n");
}
