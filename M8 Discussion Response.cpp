#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Temperature {
    private:
        int temperature;

    public:
        int getTemperature() {
            return temperature;
        }

        void setTemperature(int newTemperature) {
            this->temperature = newTemperature;
        }
    
    // Overloading constructors - first is 0 parameters, second is 1 parameter
    Temperature() {}
    Temperature(int newTemperature) {
        this->temperature = newTemperature;
    }
};

class Weather {
    private:
        string weather;
    
    public:
        string getWeather() {
            return weather;
        }

        void setWeather(string newWeather) {
            this->weather = newWeather;
        }
    
    // Overloading constructors - first is 0 parameters, second is 1 parameter
    Weather() {}
    Weather(string newWeather) {
        this->weather = newWeather;
    }
};

int main() {
    Temperature temp1;
    Weather weather1;

    int todaysTemperature;
    string todaysWeather;

    cout << "What's the temperature today?" << endl;
    cin >> todaysTemperature;

    cout << "What's the weather like?" << endl;
    cin >> todaysWeather;

    temp1.setTemperature(todaysTemperature);
    weather1.setWeather(todaysWeather);

    cout << "The temperature today is " << temp1.getTemperature() << " degrees and it is " \
    << weather1.getWeather() << "." << endl;
    
    return 0;
}