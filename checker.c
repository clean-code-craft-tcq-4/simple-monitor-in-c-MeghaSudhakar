#include <stdio.h>
#include <assert.h>

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

int soccheckWARNING(float soc)
{
    if(soc <= 24)
    {
        printf("Warning: Approaching discharge\n");
        
        return 1;
    }
    else if(soc >= 76)
    {
        printf("Warning: Approaching charge-peak\n");
        return 1;
    }
    
}

int soccheckPOS(float soc)
{
    if(soc >= 20)
    {
        int result = soccheckWARNING(soc);
        return result;
    }
    else if(soc <=80)
    {
        int result = soccheckWARNING(soc);
        return result;
    }
    else
    {
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

float ConvertToCelcius(float farenheit) 
{
    float celcius = (farenheit - 32) * 5 / 9;
    printf("\nconverted: %.1f celcius.\n",celcius);
    return celcius;
}


float temperature_Unit_Check(float unit)
{
    float converted_temperature =0;
    if(unit <= 100 && unit >= 0)
    {
        printf("\n converted temperatur: %f celcius.\n",unit);
        return unit;
    }
    else 
    {
        converted_temperature = ConvertToCelcius(unit);
        printf("\n converted temperatur: %.1f celcius.\n",converted_temperature);
        return converted_temperature;
    }
      
}

int batteryIsOk(float temperature, float soc, float chargeRate)
{
    int  temp = 0;
    int socc = 0;
    int charge = 0;
    int result =0;
    float unit =0;
    
    unit = temperature_Unit_Check(temperature);
    
    temp = temperaturecheckNEG(unit);
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
    batteryIsOk(100, 81, 0.7);
    printf("\n\n");
    batteryIsOk(401, 81, 0.7);
    printf("\n\n");
}
