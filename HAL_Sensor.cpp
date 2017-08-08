
#include "HAL_Sensor.h"

HAL::SensorData::SensorData(){
	// don't use this until you call reserve()
	_data = NULL;
}
void HAL::SensorData::reserve(uint8_t n_bytes){
	// set aside the number of bytes you need for your data
	_data = realloc(_data, n_bytes);
}

HAL::Sensor::Sensor(){
	// derived class will need its own implementation
}

HAL::Sensor::~Sensor(){
	// derived class will need its own implementation
}

bool HAL::Sensor::begin(uint8_t address_offset = 0){
	_address += address_offset;
	//derived class should add functionality here
	return true;
}

HAL::overridden_return_type HAL::Sensor::read(void){
	//derived class should change return type and cast _data._data to that, then
	//populate the array with the right data.
}

HAL::SensorData HAL::Sensor::report(void){
	// this is a struct containing a void * pointing to memory allocated for data
	return _data;
}
