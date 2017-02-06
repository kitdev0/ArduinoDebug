#ifndef _ArduinoDebug_h
#define _ArduinoDebug_h

#define use_mega2560

#include <Arduino.h>
#include <Time.h>
// #include <SoftwareSerial.h>

//#define _SD_CARD_CONNECT  //comment this if don't connect sd card

#ifndef _LOG_DEBUG_SERIAL_PORT
#define _LOG_DEBUG_SERIAL_PORT Serial //Serial
#endif

#ifndef _LOG_DEBUG_SERIAL_BAUD
#define _LOG_DEBUG_SERIAL_BAUD 115200
#endif

#ifndef _LOG_DIR
#define _LOG_DIR		"log"
#endif

#ifndef _LOG_OVER
#define _LOG_OVER		3
#endif

#define ROOT_PATH
#define _LOG_SIZE_MAX		32768 //32Kyte
#define _LOG_FILE_NUM_MAX	9999

#ifndef _DEBUG_SAY_ONLY
#define _DEBUG_SAY_ONLY 0
#endif //_DEBUG_SAY_ONLY

#ifndef _DEBUG_WRITE_ONLY //Set write to se card
#define _DEBUG_WRITE_ONLY 1
#endif //_DEBUG_WRITE_ONLY

#ifndef _DEBUG_SAY_AND_WRITE
#define _DEBUG_SAY_AND_WRITE 2
#endif //_DEBUG_PRINT_AND_WRITE

// #define _USE_CUSTOM_SOFTWARE_SERAIL //Uncomment this if use Software serial
// #define _USE_SOFTWARE_SERAIL //Uncomment this if use Software serial

#if defined(_USE_CUSTOM_SOFTWARE_SERAIL)
#include <CustomSoftwareSerial.h>
#endif // defined(_USE_CUSTOM_SOFTWARE_SERAIL)
#if defined(_USE_SOFTWARE_SERAIL)
#include <SoftwareSerial.h>
#endif // defined(_USE_SOFTWARE_SERAIL)
#if defined(_USE_SOFTWARE_SERAIL) ||  defined(_USE_CUSTOM_SOFTWARE_SERAIL)
#ifndef _SOFTWARE_SERIAL_RX_PIN
#define	_SOFTWARE_SERIAL_RX_PIN	62
#endif // !_SOFTWARE_SERIAL_RX_PIN
#ifndef _SOFTWARE_SERIAL_TX_PIN
#define	_SOFTWARE_SERIAL_TX_PIN	63
#endif // !_SOFTWARE_SERIAL_TX_PIN
//----------------------------------------------------------------//
////----------------------------------------------------------------//
#endif // _USE_SOFTWARE_SERAIL

class ArduinoDebug
{
private:
#if defined(_USE_SOFTWARE_SERAIL)
	SoftwareSerial *serial_port;
#elif defined(_USE_CUSTOM_SOFTWARE_SERAIL)
	CustomSoftwareSerial *serial_port;
#else
	HardwareSerial *serial_port;
#endif // _USE_SOFTWARE_SERAIL
	char *log_dir;
	uint32_t serial_baud;
	String log_path;
	String header;
	String setFormat(String _data);
	String to2Digits(int _digits);
	String to4Digits(int _digits);
	bool checkExistDir(void);
	bool checkFileOverSize(String _file_name);
	String dirName(void);
	String fileName(void);
	String lastFileName(void);


public:
  ArduinoDebug(String _header);
  ~ArduinoDebug();
  bool init(void);
  void setHeader(String _header);
  void setLogPath(String _data);
	void setLogDir(char *_dir);
  void say(String _data);
	void sayln(String _data);
  void writeLog(String _data);
  void sayAndWriteLog(String _data);
	void check2DelLogOver(int _size,String _data);
	String currentTime(void);
	String currentDay(void);
};

#if defined(_USE_SOFTWARE_SERAIL)
extern SoftwareSerial _MY_SOFTWARE_SERIAL;
#elif defined(_USE_CUSTOM_SOFTWARE_SERAIL)
extern CustomSoftwareSerial _MY_SOFTWARE_SERIAL;
#endif

#endif // _ArduinoDebug_h
