#ifndef _ETS2TELEMETRY_H_
#define _ETS2TELEMETRY_H_

#include <windows.h>
#include <mem.h>

#ifndef e2t_nullptr
    #define e2t_nullptr (void*)0
#endif

typedef unsigned char e2t_bool;
enum {e2t_false, e2t_true};

#define MAPPED_FILENAME "Local\\SimTelemetryETS2"

typedef struct et2_telemetry_map_t
{
	unsigned int time;
	unsigned int paused;


	struct
	{
		unsigned int ets2_telemetry_plugin_revision;
		unsigned int ets2_version_major;
		unsigned int ets2_version_minor;
	} tel_revId;

	struct
	{
		e2t_bool engine_enabled;
		e2t_bool trailer_attached;

		// vehicle dynamics
		float speed;
		
		float accelerationX;
		float accelerationY;
		float accelerationZ;
	
		float coordinateX;
		float coordinateY;
		float coordinateZ;
	
		float rotationX;
		float rotationY;
		float rotationZ;
	
		// drivetrain essentials
		int gear;
		int gears;
		int gearRanges;
		int gearRangeActive;

		float engineRpm;
		float engineRpmMax;
		
		float fuel;
		float fuelCapacity;
		float fuelRate;				// ! Not working
		float fuelAvgConsumption;
		
		// user input
		float userSteer;
		float userThrottle;
		float userBrake;
		float userClutch;
		
		float gameSteer;
		float gameThrottle;
		float gameBrake;
		float gameClutch;
	
		// truck & trailer
		float truckWeight;
		float trailerWeight;
		
		int modelType[2];
		int trailerType[2];			// ! deprecated

	} tel_rev1;

	struct
	{
		long time_abs;
		int gears_reverse;

		// Trailer ID & display name
		float trailerMass;
		char trailerId[64];
		char trailerName[64];
		
		// Job information
		int jobIncome;
		int time_abs_delivery;
		char citySrc[64];
		char cityDst[64];
		char compSrc[64];
		char compDst[64];

	} tel_rev2;	

	struct
	{
		int retarderBrake;
		int shifterSlot;
		int shifterToggle;
		int fill;

		e2t_bool cruiseControl;
		e2t_bool wipers;

		e2t_bool parkBrake;
		e2t_bool motorBrake;

		e2t_bool electricEnabled;
		e2t_bool engineEnabled;

		e2t_bool blinkerLeftActive;
		e2t_bool blinkerRightActive;
		e2t_bool blinkerLeftOn;
		e2t_bool blinkerRightOn;

		e2t_bool lightsParking;
		e2t_bool lightsBeamLow;
		e2t_bool lightsBeamHigh;
		e2t_bool lightsAuxFront;
		e2t_bool lightsAuxRoof;
		e2t_bool lightsBeacon;
		e2t_bool lightsBrake;
		e2t_bool lightsReverse;

		e2t_bool batteryVoltageWarning;
		e2t_bool airPressureWarning;
		e2t_bool airPressureEmergency;
		e2t_bool adblueWarning;
		e2t_bool oilPressureWarning;
		e2t_bool waterTemperatureWarning;

		float airPressure;
		float brakeTemperature;
		int fuelWarning;
		float adblue;
		float adblueConsumption;
		float oilPressure;
		float oilTemperature;
		float waterTemperature;
		float batteryVoltage;
		float lightsDashboard;
		float wearEngine;
		float wearTransmission;
		float wearCabin;
		float wearChassis;
		float wearWheels;
		float wearTrailer;
		float truckOdometer;
		float cruiseControlSpeed;

		// General info about the truck etc;
		char truckMake[64];
		char truckMakeId[64];
		char truckModel[64];


	} tel_rev3;

	struct
	{
		float speedLimit;
		float routeDistance;
		float routeTime;
		float fuelRange;
		float gearRatiosForward[24];
		float gearRatiosReverse[8];
		float gearDifferential;
		int gearDashboard;
	} tel_rev4; // added in sdk1.5

	struct
	{
		e2t_bool onJob;
		e2t_bool jobFinished;
	} tel_rev5;

} e2t_telemetry_map;


e2t_bool e2t_get_telemetry_data(e2t_telemetry_map* map);

#endif // _ETS2TELEMETRY_H_
