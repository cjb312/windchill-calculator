#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
//functions
void input_data(double &temp, double &windspeed, double &dewPoint);
double wind_chill(double temp, double windSpeed);
double cloud_base(double temp, double windSpeed);
void output_data(double temp, double windSpeed, double dewPoint, double wc, double cb);

int main()
{   //Variables
    double temp, windSpeed, dewPoint, wc, cb;
    //Calling functions
    input_data(temp, windSpeed, dewPoint);

    wc = wind_chill(temp, windSpeed);

    cb = cloud_base(temp, dewPoint);

    output_data(temp, windSpeed, dewPoint, wc, cb);

    return 0;
}

//Function calculations input/output
void input_data(double &temp, double &windSpeed, double &dewPoint)
{
    cout << " -----------------------------------------------------------" << endl;
    cout << "|" << setw(60) << "|" << endl;
    cout << "|" << "    This program determines wind chill using temperature   " << "|" << endl;
    cout << "|" << "    in Farenheit and win speed in mph, and computes    " << setw(5) << "|" << endl;
    cout << "|" << "    the cloud base using the dew point in Farenheit.       " << "|" <<endl;
    cout << "|" << setw(60) << "|" << endl;
    cout << " -----------------------------------------------------------" << endl;

    cout << "\nEnter the temperature in degrees Farenheit: ";
    cin >> temp;
    cout << "Enter the wind speed in mph: ";
    cin >> windSpeed;
    cout << "Enter the dew point in degrees Fahrenheit: ";
    cin >> dewPoint;
}

double wind_chill(double temp, double windSpeed)
{
    const double PW = pow( windSpeed, 0.16 ); //made pow a constant for cleaner looking formula
    double wc = 35.74 + .6215 * temp -35.75 * PW + 0.4275 * temp * PW;
    return wc;
}


double cloud_base(double temp, double dewPoint)
{
    double tempSpread = temp - dewPoint;
    double cb = (tempSpread/4.4)*1000;
    return cb;
}

void output_data(double temp, double windSpeed, double dewPoint, double wc, double cb)
{
    cout << fixed << setprecision(1);

    cout << "\nTemperature    " << "Wind speed" << "    Dew Point" << "     Wind Chill" << "    Cloud Base";
    cout << "\n--------------------------------------------------------------------" << endl;

    if( temp <= 50.0 && windSpeed > 3.0) //Display wind chill
    {
        cout << setw(5) << temp << " dF" << setw(12) << windSpeed << " mph" << setw(12) << dewPoint << " dF" << setw(10) << wc << " dF"<< setw(12) << cb << " ft" << endl;
    }else // wind chill wont be calculated
    {
        cout << setw(5) << temp << " dF" << setw(12) << windSpeed << " mph" << setw(9) << dewPoint << " dF" << setw(12) << "***" << setw(15) << cb << " ft" << endl;
        cout << "\n*** Temperature must be 50 degrees or less, and wind speed" << endl;
        cout << setw(52) << "must be > than 3 mph to compute wind chill." << endl;
    }
}

