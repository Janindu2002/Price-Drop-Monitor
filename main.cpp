#include <iostream>
#include <curl/curl.h>
#include <regex>

using namespace std;

/*
WriteCallback Function
----------------------
This function receives downloaded data from libcurl.

The data arrives in chunks and is appended to a buffer string.
*/
size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* data)
{
    data->append((char*)contents, size * nmemb);
    return size * nmemb;
}


/*
fetchURL Function
-----------------
Downloads webpage or JSON data from the given URL.

A browser User-Agent is added to prevent websites from blocking
the request.
*/
string fetchURL(string url)
{
    CURL* curl;
    string buffer;

    curl = curl_easy_init();

    if(curl)
    {
        // Target URL
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        // Function to handle received data
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        // Store received data in buffer
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);

        // Set browser user agent to bypass simple bot protection
        curl_easy_setopt(curl, CURLOPT_USERAGENT,
        "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) "
        "AppleWebKit/537.36 (KHTML, like Gecko) "
        "Chrome/120.0 Safari/537.36");

        // Perform request
        curl_easy_perform(curl);

        // Cleanup curl resources
        curl_easy_cleanup(curl);
    }

    return buffer;
}


/*
extractPrice Function
---------------------
Searches the response data for product price using regex.

Example match:
"price":"2950.00"
*/
double extractPrice(string json)
{
    regex price_regex("\"price\"\\s*:\\s*\"?([0-9]+\\.?[0-9]*)\"?");

    smatch match;

    if(regex_search(json, match, price_regex))
    {
        return stod(match[1]);
    }

    return -1;
}


/*
Main Function
-------------
Controls the entire program workflow.
*/
int main()
{
    // Shopify product JSON endpoint
    string url =
    "https://libera.lk/products/rfid-bifold-leather-wallet-navy-blue.json";

    // Price alert threshold
    double threshold = 2500;

    // Download webpage response
    string json = fetchURL(url);

    // Extract price
    double price = extractPrice(json);

    cout << "Current Price: Rs " << price << endl;

    if(price != -1 && price <= threshold)
        cout << "ALERT: Price dropped below Rs " << threshold << endl;

    else if(price == -1)
        cout << "Price not found in JSON response." << endl;

    else
        cout << "Price still above threshold." << endl;

    return 0;
}