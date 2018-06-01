#include <stdbool.h>

#include "constants.h"

static float cruiseSpeed = CRUISE_START_SPEED;

static float setCruiseSpeed(float newSpeed) {
	if (newSpeed < MAX_SPEED && newSpeed > MIN_SPEED) {
		cruiseSpeed = newSpeed;
	}
}

float getCruiseSpeed() {
	return cruiseSpeed;
}

void SetCruiseSpeed(const bool *SetSpeed, float newSpeed) {
	if (*SetSpeed) {
		setCruiseSpeed(cruiseSpeed + newSpeed);
	}
}

void IncreaseCruiseSpeed(const bool *AccelSpeed) {
	if (*AccelSpeed) {
		setCruiseSpeed(cruiseSpeed + SPEED_INC);
	}
}

void DecreaseCruiseSpeed(const bool *DecelSpeed) {
	if (*DecelSpeed) {
		setCruiseSpeed(cruiseSpeed - SPEED_INC);
	}
}
