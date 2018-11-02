// Auto generated code by esphomeyaml
#include "esphomelib/application.h"

using namespace esphomelib;

class RoombaSensor: public Component, public sensor::Sensor {
 public:
  RoombaSensor(const std::string &name, uint32_t update_interval)
   : sensor::PollingSensorComponent(name, update_interval) {}

  void setup() override {
    // This will be called by App.setup()
  }
  
  void update() override {
    publish_state(42.0);  // 42°C
  }

  std::string unit_of_measurement() override { return "°C"; }
  int8_t accuracy_decimals() override { return 2; } // 2 decimal places of accuracy.
};

void setup() {
  // ===== DO NOT EDIT ANYTHING BELOW THIS LINE =====
  // ========== AUTO GENERATED CODE BEGIN ===========
  App.set_name("roomba");
  App.set_compilation_datetime(__DATE__ ", " __TIME__);
  LogComponent *logcomponent = App.init_log(115200);
  WiFiComponent *wificomponent = App.init_wifi();
  wificomponent->set_sta(WiFiAp{
      .ssid = "Wiggle",
      .password = "123!@#abc",
      .channel = -1,
      .manual_ip = ManualIP{
      .static_ip = IPAddress(192, 168, 1, 34),
      .gateway = IPAddress(192, 168, 1, 1),
      .subnet = IPAddress(255, 255, 255, 0),
      .dns1 = IPAddress(0, 0, 0, 0),
      .dns2 = IPAddress(0, 0, 0, 0),
    },
  });
  OTAComponent *otacomponent = App.init_ota();
  otacomponent->set_auth_password("update");
  otacomponent->start_safe_mode();
  mqtt::MQTTClientComponent *mqtt_mqttclientcomponent = App.init_mqtt("192.168.1.51", 1883, "", "");
  mqtt_mqttclientcomponent->set_discovery_info("homeassistant_autogen", true);
  Application::MakeWiFiSignalSensor application_makewifisignalsensor = App.make_wifi_signal_sensor("WiFi Signal Sensor", 15000);
  sensor::Sensor *sensor_sensor = application_makewifisignalsensor.wifi;
  sensor::MQTTSensorComponent *sensor_mqttsensorcomponent = application_makewifisignalsensor.mqtt;
  // =========== AUTO GENERATED CODE END ============
  // ========= YOU CAN EDIT AFTER THIS LINE =========
  //App.setup();
  
  auto *roomba_sensor = new RoombaSensor("My Roomba Sensor", 5000); // update every 5000ms or every 5 seconds.
  App.register_component(roomba_sensor);
  App.register_sensor(roomba_sensor);
 
  App.setup();
}

void loop() {
  App.loop();
  delay(16);
}
