#K2Status

A K2/ETNA Status Monitoring Program for Earthworm

This K2 Status program is compiled for 64bit Intel, but can be compiled easily 
in any 32bit computer. It has been written in QT and C++ in order to have full 
compatibility for other platforms. A fully naitive 64bit (dinamically linked) 
version is provided and run in the newest Ubuntu distros. 

============
####Features:
* Shows updated status for every station (it automatically configures stations)
* Shows you a lot of statistics from stations provided directly from the station.
* Colors that indicate the different status, gives you 'at a glance' overview of the network
* Potential for a lot of features to be added (see below)

=============
#### Color Coding

1. Update Time:
  * Green: Less than 5min.
  * Light Green: 5min and 10min
  * Green Yellow: 10min and 30min
  * Light Yellow: 30min and 1 hr
  * Dark Yellow: 1hr and 6 hr
  * Red Yellow: 6hr and 12hr
  * Light Red: 12hr and 24hr
  * Red: More than 24 hrs
2. Time Src:
  * Green only on GPS
  * Red on RTC, Keyboard and (?)
  * Yellow on External Pulse
3. Voltage:
  * Green between 12 and 14, red otherwise,
4. Temperature:
  * Red on 45C and up
5. Hardware, Battery Status and Fault Code:
  * Green if OK or Charging
  * Blue if Not Charging and more than 12V (External batt)
  * Red otherwise
6. Disk Space:
  * Red if space goes under 10 Mb
7. Number of Events:
  * Red if more than 20 Events

=============
####Instructions:
In EW:

1. Add the TYPE_K2INFO_PACKET Message type to earthworm.d
2. Setup all the K2EW instances to transmit K2Info Packets. (Uncomment the injectInfo line) 
3. Setup a ringtocoax to transmit this particular packet(BroadcasLogo to TYPE_K2INFO_PACKET) to the computer which will run K2Status.

In K2Status:

1. In the Connections Menu:
2. Put the IP of the interface you are to recieve the UDP packets containing the K2 Info (or 0.0.0.0 which is self at all interfaces). 
3. That's it.

=============
####To Do:
1. Work out ~~various~~ bugs (Most are squashed).
2. ~~Test using multiple stations~~ (DONE).
3. ~~Improve Import/Export Communications.~~
4. ~~Add the ability to graph data.~~
5. Control graph time span (currently all is presented)
6. Add the ability to request information from the Rock Family of instruments.
7. Add the ability to request information from the telephone modem instruments.


=============
####Log File:
The log file does not have a header, it's a pure CSV file with the following columns:

 1. Local unix timestamp at which the readings were recorded.
 2. GMT Timestamp for excel sheet format. (Format to whatever time/date is better for you to visualize in excel)
 3. Temperature reading at the station.
 4. Voltage at the station.
 5. Charging status ( 'C' for Charging, 'NC' for Not Charging)

=============
If anyone is interested in this proyect or would like to help, contact me!

######Credits:
* The Puerto Rico Strong Motion Program for their help and support.
* The people over at Instrumental Software Technologies, Inc. (ISTI) @ http://www.isti.com/
* Everyone who has ever worked with in the development of earthworm @ http://earthwormcentral.org
* The QT Community @ http://qt-project.org/


Thanks,
Fran89.

