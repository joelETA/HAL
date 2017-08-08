// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef _HAL_Sensor_H_
#define _HAL_Sensor_H_
#include <Arduino.h>
#include <Wire.h>
//add your includes for the project HAL_Sensor here


//end of add your includes here
#define PURE_VIRTUAL 0
//add your function definitions for the project HAL_Sensor here
namespace HAL {

	typedef void overridden_return_type;

	struct SensorData {
		SensorData();
		void reserve(uint8_t n);
		void *_data;
	};

	enum sensor_type_t {
		BUTTON,
		TCS34725,
		MCP23017,
	};

	class Sensor {
		public:
			// construct a Sensor of a specific type to set appropriate SensorData
			explicit Sensor();
			virtual ~Sensor() = PURE_VIRTUAL;
			virtual bool begin(uint8_t address_offset) = PURE_VIRTUAL;
			// data_t will change with sensor_type
			virtual overridden_return_type read(void) = PURE_VIRTUAL;
			// SensorData will change with sensor_type
			SensorData report(void);
		protected:
		private:
			uint8_t _address = 0;
			SensorData _data;
	};
}


//Do not add code below this line
#endif /* _HAL_Sensor_H_ */
