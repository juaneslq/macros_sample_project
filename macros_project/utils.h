#ifndef	UTILS_H_
#define	UTILS_H_

#define __APP_NAME__	"macros_projec"
#define __DEBUG__		1


#define LOGGER(log_tipe, message)		cout << __TIMESTAMP__ << "-" << __APP_NAME__ << "-" << log_tipe << message << endl;
#define ERROR_LOG(message)				LOGGER("ERROR >", message)

#if __DEBUG__ == 1
#define DEBUG_LOG(message)				LOGGER("DEBUG >" #message": ", message)
#define INFO_LOG(message)				LOGGER("INFO >", message)
#else
#define DEBUG_LOG(message)
#define INFO_LOG(message)
#endif



#endif	UTILS_H_