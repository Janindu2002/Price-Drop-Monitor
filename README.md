# Price Drop Monitor

Price Drop Monitor is a C++ web scraping project that monitors the price of an online product and alerts the user when the price drops below a defined threshold.

The project demonstrates:

- Web scraping using **libcurl**
- Pattern matching using **C++ regex**
- Price monitoring automation
- Structured software documentation

This project is useful for tracking price drops on e-commerce websites.

---

## Features

- Fetch webpage or JSON data using HTTP request
- Extract product price using regex
- Compare current price with threshold
- Display alert when price drops

---

## Technologies Used

- C++
- libcurl
- Regex
- HTTP requests

---

## Example

Product URL:

https://libera.lk/products/rfid-bifold-leather-wallet-navy-blue.json

Output example:

Current Price: Rs 3690  
Price still above threshold.

---

## Compile

```bash
g++ main.cpp -o pricedrop -lcurl
