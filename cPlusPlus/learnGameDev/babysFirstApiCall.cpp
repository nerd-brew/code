// A program that calls and API and outputs the response to a text file

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <curl/curl.h>

using namespace std;

// Function prototypes
void make_api_call(string url);

// Global variables
string baseURL {"https://pokeapi.co/api/v2/pokemon/"}; // Base URL for the API call

int main() {
    cout << "~~ API Call ~~" << endl;
    cout << "Enter the name of the file you want to write to: ";
    string output_file;
    cin >> output_file;

    ofstream out_file {output_file};

    if (!out_file) {
        cerr << "Error opening output file" << endl;
        return 1;
    }

    string pokemon_name;
    cout << "Enter the name of the pokemon you want to look up: ";
    cin >> pokemon_name;

    string url = baseURL + pokemon_name;
    make_api_call(url);

    out_file.close();
}

//Function that makes the API call to baseURL
void make_api_call(string url) {
    CURL *curl;
    CURLcode res;
    string readBuffer;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    cout << readBuffer << endl;
}