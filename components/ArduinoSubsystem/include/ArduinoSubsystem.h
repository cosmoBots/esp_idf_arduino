#pragma once

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC 
#endif

EXTERNC void ArduinoSubsystem_start(void);
