#ifndef CASERVICE_H_
#define CASERVICE_H_

#include <boost/thread.hpp>
#include <utility/CommunicationReceiver.h>
#include <utility/CommunicationSender.h>
#include <buffers/build/data.pb.h>
#include <buffers/build/cam.pb.h>
#include <buffers/build/gps.pb.h>
#include <buffers/build/obd2.pb.h>
#include <boost/asio.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <mutex>

class CaService {
public:
	CaService();
	~CaService();

	void init();
	void receive();
	void logDelay(string byteMessage);
	void send();
	void triggerCam(const boost::system::error_code &ec);
	camPackage::CAM generateCam();
	dataPackage::DATA generateData(camPackage::CAM cam);
	void receiveGpsData();
	void receiveObd2Data();
	double getHeading(double lat1, double lon1, double lat2, double lon2);
	double getDistance(double lat1, double lon1, double lat2, double lon2);

private:
	CommunicationReceiver* mReceiverFromDcc;
	CommunicationSender* mSenderToDcc;
	CommunicationSender* mSenderToLdm;

	CommunicationReceiver* mReceiverGps;

	boost::thread* mThreadReceive;
	boost::thread* mThreadGpsDataReceive;

	LoggingUtility* mLogger;

	boost::asio::io_service mIoService;
	boost::asio::deadline_timer* mTimer;

	long mIdCounter;
	double mCamTriggerInterval;

	gpsPackage::GPS mLatestGps;
	mutex mMutexLatestGps;

	obd2Package::OBD2 mLatestObd2;
	mutex mMutexLatestObd2;

	camPackage::CAM mLastSentCam;
};

#endif
