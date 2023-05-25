#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Define a structure to represent a hospital with its name, location, and rating
struct Hospital
{
    string name;
    string location;
    int rating;
};

// Define a structure to represent a medical facility with its name, location, and rating
struct MedicalFacility
{
    string name;
    string location;
    int rating;
};

// Function to prompt the user and get their preference
string getPreference()
{
    string preference;
    cout << "Enter your preference (hospital/medical facility): ";
    getline(cin, preference);
    return preference;
}

// Function to find the best hospital based on user preference and location
string findBestHospital(const unordered_map<string, Hospital> &hospitals, const string &location)
{
    // Find the hospital with the highest rating in the specified location
    string bestHospital;
    int maxRating = 0;

    for (const auto &pair : hospitals)
    {
        const Hospital &hospital = pair.second;
        if (hospital.location == location && hospital.rating > maxRating)
        {
            bestHospital = hospital.name;
            maxRating = hospital.rating;
        }
    }

    return bestHospital;
}

// Function to find the best medical facility based on user preference and location
string findBestMedicalFacility(const unordered_map<string, MedicalFacility> &medicalFacilities, const string &location)
{
    // Find the medical facility with the highest rating in the specified location
    string bestMedicalFacility;
    int maxRating = 0;

    for (const auto &pair : medicalFacilities)
    {
        const MedicalFacility &facility = pair.second;
        if (facility.location == location && facility.rating > maxRating)
        {
            bestMedicalFacility = facility.name;
            maxRating = facility.rating;
        }
    }

    return bestMedicalFacility;
}

int main()
{
    // Define a knowledge base of hospitals and medical facilities
    unordered_map<string, Hospital> hospitals = {
        {"A", {"Hospital A", "pune", 3}},
        {"B", {"Hospital B", "pune", 5}},
        {"c", {"Hospital C", "pune", 4}},
        {"D", {"Hospital D", "nashik", 4}},
        {"E", {"Hospital E", "nashik", 5}},
        {"F", {"Hospital F", "mumbai", 2}},
        {"G", {"Hospital G", "mumbai", 4}},
        {"H", {"Hospital H", "mumbai", 3}}
        };

    unordered_map<string, MedicalFacility> medicalFacilities = {
        {"1", {"Medical Facility 1","pune", 3}},
        {"2", {"Medical Facility 2", "mumbai", 3}},
        {"3", {"Medical Facility 3", "nashik", 4}},
        {"4", {"Medical Facility 4", "mumbai", 4}},
        {"5", {"Medical Facility 5",  "mumbai", 2}},
        {"6", {"Medical Facility 6", "pune", 4}},
        {"7", {"Medical Facility 7",  "nashik", 5}},
        {"8", {"Medical Facility 8",  "pune", 5}}};

    // Prompt the user for their preference and location
    string preference = getPreference();
    string location;
    cout << "Enter your location: ";
    getline(cin, location);

    // Find the best hospital or medical facility based on user preference and location
    string bestOption;
    if (preference == "hospital")
    {
        bestOption = findBestHospital(hospitals, location);
    }
    else if (preference == "medical facility")
    {
        bestOption = findBestMedicalFacility(medicalFacilities, location);
    }
    else
    {
        cout << "Invalid preference." << endl;
        return 1;
    }

    // Display the result
    if (bestOption.empty())
    {
        cout << "No option found that meets the requirements." << endl;
    }
    else
    {
        cout << "Best option is: " << bestOption << endl;
    }

    return 0;
}
