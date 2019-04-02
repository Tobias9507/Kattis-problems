#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


// Structs

struct car{
    string model;
    int caPrice, puPrice, kmPrice;
};

struct spy{
    string name;
    bool hasCar;
    string carModel;
    bool consistent;
    int bill;
    int timestamp;
};

struct testCase{
    vector<spy> spies;
};

struct eventParams{
    int timestamp;
    int spyIndex;
    string type;
    string sparam;      // To be used if type = p
    int iparam;         // To be used if type = r or a
};


// Vectors

vector<testCase> tCases;
vector<car> cars;
vector<spy> spies;
vector<eventParams> events;


// Functions

void saveTestCase(vector<spy> spies){
    vector<spy> save;
    for(int i = 0; i < spies.size(); i++)
        save.push_back(spies[i]);
    testCase t;
    t.spies = save;
    tCases.push_back(t);
}

bool eventSort(eventParams a, eventParams b){
    return a.timestamp < b.timestamp;
}

// Adds car to list of cars
void addCar(string model, int caPrice, int puPrice, int kmPrice){
    car c;
    c.model = model;
    c.caPrice = caPrice;
    c.puPrice = puPrice;
    c.kmPrice = kmPrice;
    cars.push_back(c); 
}

// Returns index of car, -1 if car doesn't exist
int getCarIndex(string model){
    for(int i = 0; i < cars.size(); i++){
        if(cars[i].model == model)
            return i;
    }
    return -1;
}

// Function for std::sort to sort spies alphabetically
bool spySort(spy a, spy b){
    return a.name < b.name;
}

// If new spy add to list
// Return index of spy in list
int getSpyIndex(string name){
    int i;
    for(i = 0; i < spies.size(); i++){
        if(name == spies[i].name)
            return i;
    }
    spy s;
    s.name = name;
    s.hasCar = false;
    s.consistent = true;
    s.bill = 0;
    spies.push_back(s);
    return i;
}


int main(){
    int nrOfCase;
    cin >> nrOfCase;

    // Loop all testcases
    for(int caseNr = 0; caseNr < nrOfCase; caseNr++){
        
        int nrOfCars, nrOfEvent;
        cin >> nrOfCars >> nrOfEvent;
 
        // Loop and register all car types
        for(int carNr = 0; carNr < nrOfCars; carNr++){
            string model;
            int caPrice, puPrice, kmPrice;
        
            cin >> model >> caPrice >> puPrice >> kmPrice;
        
            addCar(model, caPrice, puPrice, kmPrice);
        }

        for(int eventNr = 0; eventNr < nrOfEvent; eventNr++){
            int t;
            string name, type;

            cin >> t >> name >> type;
            int i = getSpyIndex(name);

            eventParams e;
            e.timestamp = t;
            e.spyIndex = i;
            e.type = type;
            if(e.type == "p"){
                string param;
                cin >> param;
                e.sparam = param;
                e.iparam = 0;
            }
            else{
                int param;
                cin >> param;
                e.iparam = param;
                e.sparam = "";
            }
            events.push_back(e);
        }

        sort(events.begin(), events.end(), eventSort);
        
        for(int eventNr = 0; eventNr < events.size(); eventNr++){
            int i = events[eventNr].spyIndex;
            
            if(!spies[events[eventNr].spyIndex].consistent)
                continue;

            if(events[eventNr].type == "p"){
                int cInd = getCarIndex(events[eventNr].sparam);
                if(cInd >= 0  && !spies[i].hasCar){
                    spies[i].bill += cars[cInd].puPrice;
                    spies[i].carModel = cars[cInd].model;
                    spies[i].hasCar = true;
                }
                else
                    spies[i].consistent = false;
            }
        
            else if(events[eventNr].type == "r"){
                if(spies[i].hasCar){
                    int cInd = getCarIndex(spies[i].carModel);
                    spies[i].bill += cars[cInd].kmPrice * events[eventNr].iparam;
                    spies[i].hasCar = false;
                }
                else 
                    spies[i].consistent = false;
            }

            else if(events[eventNr].type == "a"){
                if(spies[i].hasCar){
                    int cInd = getCarIndex(spies[i].carModel);
                    int cost = cars[cInd].caPrice * events[eventNr].iparam / 100;
                    if(cars[cInd].caPrice * events[eventNr].iparam % 100)
                        cost++;
                    spies[i].bill += cost;
                }
                else 
                    spies[i].consistent = false;
            }
        }
        saveTestCase(spies);
        spies.resize(0);
        cars.resize(0);
        events.resize(0);
    }

    for(int caseInd = 0; caseInd < tCases.size(); caseInd++){
        // Sort spies alfabeticly and print
        sort(tCases[caseInd].spies.begin(), tCases[caseInd].spies.end(), spySort);
        for(int i = 0; i < tCases[caseInd].spies.size(); i++){
            if(tCases[caseInd].spies[i].consistent && !tCases[caseInd].spies[i].hasCar){
                cout    << tCases[caseInd].spies[i].name << " " 
                        << tCases[caseInd].spies[i].bill << "\n";
            }
            else {
                cout    << tCases[caseInd].spies[i].name 
                        << " INCONSISTENT\n"; 
            }
        }
    }

    return 0;
}