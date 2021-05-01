#include "Arduino.h"
#include "Aquarium.h"

String splt(String data, char separator, int index) {
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
};

bool toBool(String value) {
  if (value == "true" || value == "TRUE" || value == "True") {
    return true;
  } else if (value == "false" || value == "FALSE" || value == "False") {
    return false;
  }
};

String fromBoolean(bool value) {
  if (value == true) {
    return "true";
  } else if (value == false) {
    return "false";
  }
};

Aquarium::Aquarium() {
}

Aquarium::Aquarium(String json) {
  String noBrackets = json.substring(1, json.length() - 1);
  
  _id = splt(splt(noBrackets, ',', 0), ':', 1).toInt();    
  _name = splt(splt(noBrackets, ',', 1), ':', 1);
  _description = splt(splt(noBrackets, ',', 2), ':', 1);
  
  String imgUrl = splt(noBrackets, ',', 3);
  _imageUrl = (splt(imgUrl, ':', 1) == "\"assets/imgs/aquarium/placeholder-image.png\"") ? splt(imgUrl, ':', 1) : splt(imgUrl, ':', 1) + ":" + splt(imgUrl, ':', 2);

  _volume = splt(splt(noBrackets, ',', 4), ':', 1).toInt();
  _temperature = splt(splt(noBrackets, ',', 5), ':', 1).toFloat();
  _controlActive = toBool(splt(splt(noBrackets, ',', 6), ':', 1));
  _setPointTemp = splt(splt(noBrackets, ',', 7), ':', 1).toFloat();
  
  String crDt = splt(noBrackets, ',', 8);
  _creationDate = splt(crDt, ':', 1) + ":" + splt(crDt, ':', 2) + ":" + splt(crDt, ':', 3);

  _status = splt(splt(noBrackets, ',', 9), ':', 1);
};

String Aquarium::tJson() {
  String _id = String(Aquarium::getId());
  String _name = Aquarium::getName();
  String _description = Aquarium::getDescription();
  String _imageUrl = Aquarium::getImageUrl();
  String _volume = String(Aquarium::getVolume());
  String _temperature = String(Aquarium::getTemperature());
  String _controlActive = fromBoolean(Aquarium::getControlActive());
  String _setPointTemp = String(Aquarium::getSetPointTemp());
  String _creationDate = Aquarium::getCreationDate();
  String _status = Aquarium::getStatus();
  
  return "{ \"id\": " + _id + ", \"name\": " + _name + ", \"description\": " + _description + ", \"imageUrl\": " + _imageUrl + ", \"volume\": " + _volume + ", \"temperature\": \"" + _temperature + "\", \"controlActive\": " + _controlActive + ", \"setPointTemp\": " + _setPointTemp + ", \"creationDate\": " + _creationDate + ", \"status\": " + _status + " }";
};

int Aquarium::getId() {
	return this -> _id;
};

String Aquarium::getName() {
	return this -> _name;
};

String Aquarium::getDescription() {
	return this -> _description;
};

String Aquarium::getImageUrl() {
	return this -> _imageUrl;
};

int Aquarium::getVolume() {
	return this -> _volume;
};

bool Aquarium::getControlActive() {
	return this -> _controlActive;
};

float Aquarium::getTemperature() {
	return this -> _temperature;
};

float Aquarium::getSetPointTemp() {
	return this -> _setPointTemp;
};

String Aquarium::getCreationDate() {
	return this -> _creationDate;
};

String Aquarium::getStatus() {
	return this -> _status;
};

void Aquarium::setId(int id) {
	this -> _id = id;
};

void Aquarium::setName(String name) {
	this -> _name = name;
};

void Aquarium::setDescription(String description) {
	this -> _description = description;
};

void Aquarium::setImageUrl(String imageUrl) {
	this -> _imageUrl = imageUrl;
};

void Aquarium::setVolume(int volume) {
	this -> _volume = volume;
};

void Aquarium::setControlActive(bool controlActive) {
	this -> _controlActive = controlActive;
};

void Aquarium::setTemperature(float temperature) {
	this -> _temperature = temperature;
};

void Aquarium::setSetPointTemp(float setPointTemp) {
	this -> _setPointTemp = setPointTemp;
};

void Aquarium::setCreationDate(String creationDate) {
	this -> _creationDate = creationDate;
};

void Aquarium::setStatus(String status) {
	this -> _status = status;
};
