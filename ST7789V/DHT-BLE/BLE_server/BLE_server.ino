/*
    Based on Neil Kolban example for IDF: https://github.com/nkolban/esp32-snippets/blob/master/cpp_utils/tests/BLE%20Tests/SampleServer.cpp
    Ported to Arduino ESP32 by Evandro Copercini
    updates by chegewara
    changed by Adrian Reimer
*/

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include "DHTesp.h"

#define PIN_DHT 27
#define BTLE_NAME "ESP32 DHT"
#define BAUDRATE 115200
#define LOOP_DELAY_MS 2000

// See the following for generating UUIDs:
// https://www.uuidgenerator.net/
#define SERVICE_UUID        "d61b7e40-0baa-46ed-851a-ebda879c3fc8"
#define TEMP_CHARACTERISTIC_UUID "bc17ed50-bb86-4117-8f1c-7fdf04fd8446"
#define HUMIDITY_CHARACTERISTIC_UUID "9f992b9a-0b0d-406f-81cd-77942d753718"


static DHTesp dht;
static TaskHandle_t tempTaskHandle = NULL;
static TempAndHumidity lastValues;
static BLECharacteristic *tempCharact;
static BLECharacteristic *humiCharact;

void
setup()
{
  Serial.begin(BAUDRATE);
  dht.setup(PIN_DHT, DHTesp::DHT11);
  BLEDevice::init(BTLE_NAME);
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);
  tempCharact = pService->createCharacteristic(TEMP_CHARACTERISTIC_UUID,
                                               BLECharacteristic::PROPERTY_READ |
                                               BLECharacteristic::PROPERTY_WRITE);
  humiCharact = pService->createCharacteristic(HUMIDITY_CHARACTERISTIC_UUID,
                                               BLECharacteristic::PROPERTY_READ |
                                               BLECharacteristic::PROPERTY_WRITE);
  pService->start();
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
}

void
loop()
{
  lastValues = dht.getTempAndHumidity(); 
  tempCharact->setValue(String(lastValues.temperature,0).c_str());
  humiCharact->setValue(String(lastValues.humidity,0).c_str());
  delay(LOOP_DELAY_MS);
}
