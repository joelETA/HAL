#ifndef BUTTON_INCLUDED
#define BUTTON_INCLUDED

#include "HAL_Sensor.h"

namespace HAL {
	class Button : public Sensor {
		public:
		// construct a Sensor of a specific type to set appropriate SensorData
		explicit Button();
		virtual ~Button() = PURE_VIRTUAL;
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
#endif
