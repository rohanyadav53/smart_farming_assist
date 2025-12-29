import streamlit as st
import requests
import time

ESP_URL = "http://192.168.1.105/data"

st.set_page_config(page_title="Smart Farming Assist")
st.title("🌱 Smart Farming Assist Dashboard")

placeholder = st.empty()

if st.button("Start Monitoring"):
    while True:
        try:
            data = requests.get(ESP_URL, timeout=2).json()

            with placeholder.container():
                col1, col2, col3 = st.columns(3)
                col1.metric("🌡 Temp (°C)", data["temperature"])
                col2.metric("💧 Humidity (%)", data["humidity"])
                col3.metric("🌱 Soil", data["soil"])
                st.success(f"Pump Status: {data['pump']}")

            time.sleep(3)

        except:
            st.error("ESP not reachable")
            time.sleep(3)
