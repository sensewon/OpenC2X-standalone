#!/bin/sh
mkdir -p build
protoc --proto_path=./ --cpp_out=build/ cam.proto 

protoc --proto_path=./ --cpp_out=build/ denm.proto

protoc --proto_path=./ --cpp_out=build/ data.proto 

protoc --proto_path=./ --cpp_out=build/ gps.proto 

protoc --proto_path=./ --cpp_out=build/ obd2.proto 

protoc --proto_path=./ --cpp_out=build/ trigger.proto 

protoc --proto_path=./ --cpp_out=build/ dccInfo.proto 

protoc --proto_path=./ --cpp_out=build/ camInfo.proto 

protoc --proto_path=./ --cpp_out=build/ ldmData.proto 
