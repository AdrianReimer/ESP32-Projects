/**
 * A BLE client example that is rich in capabilities.
 * There is a lot new capabilities implemented.
 * author unknown
 * updated by chegewara
 * changed by Adrian Reimer
 */

#include <TFT_eSPI.h>
#include <SPI.h>
#include "BLEDevice.h"

#define BAUDRATE 115200
#define TEMP_TEXT ("C Temp: ")
#define HUMI_TEXT ("% Humidity: ")
#define LOOP_DELAY_MS 1000


// The remote service we wish to connect to.
static BLEUUID serviceUUID("d61b7e40-0baa-46ed-851a-ebda879c3fc8");
// The characteristic of the remote service we are interested in.
static BLEUUID tempUUID("bc17ed50-bb86-4117-8f1c-7fdf04fd8446");
static BLEUUID humiUUID("9f992b9a-0b0d-406f-81cd-77942d753718");

static boolean doConnect = false;
static boolean connected = false;
static boolean doScan = false;
static BLERemoteCharacteristic* pRemoteTempCharacteristic;
static BLERemoteCharacteristic* pRemoteHumiCharacteristic;
static BLEAdvertisedDevice* myDevice;
static TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h

void 
notifyCallback(BLERemoteCharacteristic* pBLERemoteCharacteristic,
               uint8_t* pData,
               size_t length,
               bool isNotify) 
{
  Serial.print("Notify callback for characteristic ");
  Serial.print(pBLERemoteCharacteristic->getUUID().toString().c_str());
  Serial.print(" of data length ");
  Serial.println(length);
  Serial.print("data: ");
  Serial.println((char*)pData);
}

class MyClientCallback : public BLEClientCallbacks {
  void onConnect(BLEClient* pclient) {
  }

  void onDisconnect(BLEClient* pclient) {
    connected = false;
    Serial.println("onDisconnect");
  }
};

bool
connectToServer()
{
    Serial.print("Forming a connection to ");
    Serial.println(myDevice->getAddress().toString().c_str()); 
    BLEClient*  pClient  = BLEDevice::createClient();
    Serial.println(" - Created client");
    pClient->setClientCallbacks(new MyClientCallback());

    // Connect to the remove BLE Server.
    pClient->connect(myDevice);  
    Serial.println(" - Connected to server");

    // Obtain a reference to the service we are after in the remote BLE server.
    BLERemoteService* pRemoteService = pClient->getService(serviceUUID);
    if (pRemoteService == nullptr) {
      Serial.print("Failed to find our service UUID: ");
      Serial.println(serviceUUID.toString().c_str());
      pClient->disconnect();
      return false;
    }
    Serial.println(" - Found our service");

    // Obtain a reference to the characteristic in the service of the remote BLE server.
    pRemoteTempCharacteristic = pRemoteService->getCharacteristic(tempUUID);
    if (pRemoteTempCharacteristic == nullptr) {
      Serial.print("Failed to find our characteristic UUID: ");
      Serial.println(tempUUID.toString().c_str());
      pClient->disconnect();
      return false;
    }
    pRemoteHumiCharacteristic = pRemoteService->getCharacteristic(humiUUID);
    if (pRemoteHumiCharacteristic == nullptr) {
      Serial.print("Failed to find our characteristic UUID: ");
      Serial.println(humiUUID.toString().c_str());
      pClient->disconnect();
      return false;
    }
    Serial.println(" - Found our characteristic");

    // Read the value of the characteristic.
    if(pRemoteTempCharacteristic->canRead()) {
      std::string value = pRemoteTempCharacteristic->readValue();
      Serial.print("The characteristic value was: ");
      Serial.println(value.c_str());
    }
    if(pRemoteHumiCharacteristic->canRead()) {
      std::string value = pRemoteHumiCharacteristic->readValue();
      Serial.print("The characteristic value was: ");
      Serial.println(value.c_str());
    }

    if(pRemoteTempCharacteristic->canNotify())
      pRemoteTempCharacteristic->registerForNotify(notifyCallback);
    if(pRemoteHumiCharacteristic->canNotify())
      pRemoteHumiCharacteristic->registerForNotify(notifyCallback);

    connected = true;
}

/**
 * Scan for BLE servers and find the first one that advertises the service we are looking for.
 */
class MyAdvertisedDeviceCallbacks:
  public BLEAdvertisedDeviceCallbacks {
 /**
   * Called for each advertising BLE server.
   */
  void
  onResult(BLEAdvertisedDevice advertisedDevice)
  {
    Serial.print("BLE Advertised Device found: ");
    Serial.println(advertisedDevice.toString().c_str());

    // We have found a device, let us now see if it contains the service we are looking for.
    if (advertisedDevice.haveServiceUUID() &&
        advertisedDevice.isAdvertisingService(serviceUUID)) {
          BLEDevice::getScan()->stop();
          myDevice = new BLEAdvertisedDevice(advertisedDevice);
          doConnect = true;
          doScan = true;
    }
  }
};

void
setup()
{
  Serial.begin(BAUDRATE);
  Serial.println("Starting Arduino BLE Client application...");
  BLEDevice::init("");
  tft.init();
  tft.fillScreen(TFT_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(TFT_WHITE);
  tft.setRotation(1);
  
  // Retrieve a Scanner and set the callback we want to use to be informed when we
  // have detected a new device.  Specify that we want active scanning and start the
  // scan to run for 5 seconds.
  BLEScan* pBLEScan = BLEDevice::getScan();
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  pBLEScan->setInterval(1349);
  pBLEScan->setWindow(449);
  pBLEScan->setActiveScan(true);
  pBLEScan->start(5, false);
}

void
loop()
{
  if (doConnect == true) {
    if (connectToServer()) {
      Serial.println("We are now connected to the BLE Server.");
    } else {
      Serial.println("We have failed to connect to the server; there is nothin more we will do.");
    }
    doConnect = false;
  }

  if (connected) {
    tft.setCursor(0, 0);
    tft.fillScreen(TFT_BLACK);
    tft.print(TEMP_TEXT);
    tft.println(pRemoteTempCharacteristic->readValue().c_str());
    tft.print(HUMI_TEXT);
    tft.println(pRemoteHumiCharacteristic->readValue().c_str());
  } else if (doScan) {
    BLEDevice::getScan()->start(0);
  }
  delay(LOOP_DELAY_MS);
}
