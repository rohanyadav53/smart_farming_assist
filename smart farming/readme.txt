SMART FARMING ASSIST (IoT-BASED MONITORING AND AUTOMATION)

PROJECT OVERVIEW
Smart Farming Assist is an IoT-based project designed to monitor soil moisture and environmental conditions in real time and automate irrigation decisions. The system helps reduce water wastage, minimize manual effort, and improve agricultural productivity. Sensor data is collected using ESP8266/ESP32 and monitored remotely through a Streamlit-based web dashboard.

OBJECTIVES

Monitor soil moisture, temperature, and humidity in real time

Automate irrigation based on sensor data

Optimize water usage in farming

Enable remote monitoring of field conditions

Improve efficiency and productivity for farmers

TECH STACK

Hardware Components

ESP8266 or ESP32

Soil Moisture Sensor

DHT11 or DHT22 (Temperature and Humidity Sensor)

Relay module or water pump (LED used for demo)

Breadboard and jumper wires

Software Technologies

Arduino IDE

Embedded C / Arduino C++

Wi-Fi communication

REST API (JSON data)

Python

Streamlit (Web Dashboard)

SYSTEM ARCHITECTURE
Sensors collect soil moisture, temperature, and humidity data.
ESP8266/ESP32 processes this data and makes irrigation decisions.
The ESP hosts a REST API over Wi-Fi and sends data in JSON format.
Streamlit frontend fetches the data and displays it on a web dashboard.

HARDWARE CONNECTIONS (ESP8266)
Soil Moisture Sensor AO connected to A0
DHT11/DHT22 Data pin connected to D4
Relay or LED connected to D1
VCC connected to 3.3V
GND connected to GND

WORKING PRINCIPLE
The soil moisture sensor measures the water content in the soil.
The DHT sensor measures temperature and humidity.
ESP8266 continuously reads sensor values.
If soil moisture is below a predefined threshold, irrigation is turned ON.
If soil moisture is above the threshold, irrigation is turned OFF.
Sensor data and pump status are sent via Wi-Fi as JSON.
Streamlit displays live data on a web dashboard.

STREAMLIT MONITORING
The Streamlit dashboard provides real-time visualization of:

Temperature

Humidity

Soil moisture value

Irrigation pump ON or OFF status

This allows remote monitoring using a web browser.

PROJECT STRUCTURE
Smart-Farming-Assist
esp_code.ino – ESP8266/ESP32 firmware
app.py – Streamlit frontend
README.txt – Project documentation

HOW TO RUN THE PROJECT

Step 1: Upload ESP Code
Open Arduino IDE
Select ESP8266 or ESP32 board
Enter Wi-Fi credentials
Upload code
Note the IP address from Serial Monitor

Step 2: Run Streamlit Dashboard
Install dependencies using pip
Run the Streamlit application
Open the provided local URL in the browser

FEATURES

Real-time sensor monitoring

Automated irrigation control

Remote monitoring via web dashboard

REST API based communication

Modular and scalable design

FUTURE ENHANCEMENTS

Cloud deployment

Historical data visualization

SMS or email alerts

Mobile app integration

AI/ML based irrigation prediction

AUTHOR
Rohan Yadav
Computer Science Student
IoT | Embedded Systems | Python | Streamlit