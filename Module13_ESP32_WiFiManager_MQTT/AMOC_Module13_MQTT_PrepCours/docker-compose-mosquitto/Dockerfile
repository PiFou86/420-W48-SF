FROM eclipse-mosquitto:2.0.18
COPY mosquitto.conf /mosquitto/config/mosquitto.conf
RUN touch /mosquitto/config/passwd
RUN mosquitto_passwd -b /mosquitto/config/passwd esp32_demo Bonjour01.+
RUN mosquitto_passwd -b /mosquitto/config/passwd mqttexplorer Bonjour01.+
RUN chmod 0700 /mosquitto/config/passwd
RUN chown root /mosquitto/config/passwd