#ifndef aquarium_n
#define aquarium_n

#include "Arduino.h"

class Aquarium {
  private:
    int _id;
    String _name;
    String _description;
    String _imageUrl;
    int _volume;
    bool _controlActive;
    float _temperature;
    float _setPointTemp;
    String _creationDate;
    String _status;
  
  public:
    Aquarium();
	Aquarium(String json);
	String tJson();

    int getId();
    String getName();
    String getDescription();
    String getImageUrl();
    int getVolume();
    bool getControlActive();
    float getTemperature();
    float getSetPointTemp();
    String getCreationDate();
    String getStatus();
	
	void setId(int id);
    void setName(String name);
    void setDescription(String description);
    void setImageUrl(String imageUrl);
    void setVolume(int volume);
    void setControlActive(bool controlActive);
    void setTemperature(float temperature);
    void setSetPointTemp(float setPointTemp);
    void setCreationDate(String creationDate);
    void setStatus(String status);
};

#endif
